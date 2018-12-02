// CPage1.cpp: 实现文件
//

#include "stdafx.h"
#include "CKImageProcess.h"
#include "CPage1.h"
#include "afxdialogex.h"
#include "CKImageProcessDlg.h"

// CPage1 对话框
extern CKImageProcessDlg* pCKImageProcessDlg;
IMPLEMENT_DYNAMIC(CPage1, CDialogEx)

CPage1::CPage1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PAGE1, pParent)
{

}

CPage1::~CPage1()
{
}

void CPage1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BTN_LINK_IMAGE, m_combox_image);
	DDX_Control(pDX, IDC_COMBO_IMAGE, m_combox_image);
}


BEGIN_MESSAGE_MAP(CPage1, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_NULL, &CPage1::OnBnClickedBtnNull)
	ON_BN_CLICKED(IDC_BTN_RECT1, &CPage1::OnBnClickedBtnRect1)
	ON_BN_CLICKED(IDC_BTN_RECT2, &CPage1::OnBnClickedBtnRect2)
	ON_BN_CLICKED(IDC_BTN_LINK_IMAGE, &CPage1::OnBnClickedBtnLinkImage)
END_MESSAGE_MAP()


/*
清楚ROI绘制
*/
void CPage1::OnBnClickedBtnNull()
{
	// TODO: 在此添加控件通知处理程序代码
	pCKImageProcessDlg->m_sRectROI.SetVisible(false);
	pCKImageProcessDlg->m_sRotBoxROI.SetVisible(false);
	pCKImageProcessDlg->m_GdiView.Redraw();
}


void CPage1::OnBnClickedBtnRect1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!pCKImageProcessDlg->m_sRectROI.GetVisible())
	{
		pCKImageProcessDlg->m_sRectROI.SetVisible(true);

	}
	else {
		pCKImageProcessDlg->m_sRectROI.SetVisible(false);

	}
	pCKImageProcessDlg->m_GdiView.Redraw();
}


void CPage1::OnBnClickedBtnRect2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!pCKImageProcessDlg->m_sRotBoxROI.GetVisible())
	{
		pCKImageProcessDlg->m_sRotBoxROI.SetVisible(true);

	}
	else
	{
		pCKImageProcessDlg->m_sRotBoxROI.SetVisible(false);
	}
	pCKImageProcessDlg->m_GdiView.Redraw();
}


void CPage1::OnBnClickedBtnLinkImage()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR cDocName[MAX_PATH], cNodeName[MAX_PATH], cParamName[MAX_PATH];
	int iNodeID, iIndex, iType;
	int irt = HIDBSelectLink(cDocName, &iNodeID, cNodeName, cParamName, &iType, &iIndex);
	if (iType == NODETYPE_PIMAGE)
	{
		m_iNodeID = iNodeID;
		m_iIndex = iIndex;
		_tcscpy_s(m_cDocName, MAX_PATH, cDocName);
		_tcscpy_s(m_cNodeName, MAX_PATH, cNodeName);
		_tcscpy_s(m_cParamName, MAX_PATH, cParamName);

		PImageParam imagep;
		int n = 1;
		int irt = HIDBGetImagePointer(cDocName, iNodeID, cNodeName, cParamName, &imagep, &n, iIndex);

		//如果取图成功
		if (irt >= 0)
		{
			//转格式
			PImageParamToCPrImage(&m_prImage, imagep);
			//图片显示
			CString strImgInfo;
			strImgInfo.Format(_T("%d*%d,bit=%d"), m_prImage.GetHeight(), m_prImage.GetWidth(), m_prImage.GetFormat() * 8);
			pCKImageProcessDlg->SetDlgItemText(IDC_EDIT_IMGINFO, strImgInfo);

			pCKImageProcessDlg->m_Image.Copy(m_prImage);
			pCKImageProcessDlg->m_GdiView.FitSize();
			pCKImageProcessDlg->m_GdiView.FitScale();
			m_combox_image.AddString(cNodeName);
			m_combox_image.SelectString(0, cNodeName);


			//保存状态
			//pCKImageProcessDlg->m_GetMatchParam.str_ImageName = cNodeName;
		}

		HIDBDeleteBuf(imagep);
	}
}


void CPage1::PImageParamToCPrImage(CPrImage* Dest, ImageParam*str)
{
	//int m_nWidth;//图片宽
	//int m_nHeight;//图片高
	//int m_nChannel;//图片通道数
	//int m_nSize;//m_pData指向的数据大小（byte）
	//int m_nPtrType;//指针类型0=byte* ;1=HObject*
	//void* m_pData;//图片数据

	Dest->Create(str->m_nWidth, str->m_nHeight, str->m_nChannel);
	Dest->SetBits((BYTE*)str->m_pData, false);
}