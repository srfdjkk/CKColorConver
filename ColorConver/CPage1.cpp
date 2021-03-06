// CPage1.cpp: 实现文件
//

#include "stdafx.h"
#include "CKImageProcess.h"
#include "CPage1.h"
#include "afxdialogex.h"
#include "CKColorConverDlg.h"

// CPage1 对话框
extern CKColorConverDlg* pCKColorConverDlg;
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
	DDX_Control(pDX, IDC_COMBO_IMAGE, m_combox_image);
	//DDX_Control(pDX, IDC_COMBO1, m_ComboBox);
	//DDX_Control(pDX, IDC_CHECK2, m_Button);
	DDX_Control(pDX, IDC_CHECK1, m_Button);
	DDX_Control(pDX, IDC_COMBO2, m_ComboBox);

}


BEGIN_MESSAGE_MAP(CPage1, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_LINK_IMAGE, &CPage1::OnBnClickedBtnLinkImage)
	ON_BN_CLICKED(IDC_CHECK1, &CPage1::OnBnClickedCheck1)
//	ON_CBN_KILLFOCUS(IDC_COMBO2, &CPage1::OnCbnKillfocusCombo1)
	ON_CBN_SETFOCUS(IDC_COMBO2, &CPage1::OnCbnSetfocusCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CPage1::OnCbnSelchangeCombo2)

END_MESSAGE_MAP()




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
			pCKColorConverDlg->SetDlgItemText(IDC_EDIT_IMGINFO, strImgInfo);

			pCKColorConverDlg->m_Image.Copy(m_prImage);
			pCKColorConverDlg->m_GdiView.FitSize();
			pCKColorConverDlg->m_GdiView.FitScale();
			m_combox_image.AddString(cNodeName);
			m_combox_image.SelectString(0, cNodeName);


			//保存状态
			//pCKColorConverDlg->m_GetMatchParam.str_ImageName = cNodeName;
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


void CPage1::UpdateImage(CPrImage &ImgSrc,CPrImage &ImgDsr,int index)
{
	if (m_Button.GetCheck() == 1)
	{
		ImgGetChannel(ImgSrc, ImgDsr, index);		// 通道索引，0 - 蓝，1 - 绿，2 - 红
		pCKColorConverDlg->m_GdiView.SetDisplayImage(&ImgDsr);
		pCKColorConverDlg->m_GdiView.Redraw();
	}
	else
		return;
}




void CPage1::OnBnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码

	if (m_Button.GetCheck() == 1)
	{
		int i = m_ComboBox.GetCurSel();
		if (i < 3)
		{
			i++;
			UpdateImage(m_prImage, m_OutputImg, i);
		}
	}
	else
		return;
}


//void CPage1::OnCbnKillfocusCombo1()
//{
//	// TODO: 在此添加控件通知处理程序代码
//
//}


BOOL CPage1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_ComboBox.AddString(__T("蓝色"));
	m_ComboBox.AddString(__T("绿色"));
	m_ComboBox.AddString(__T("红色"));
	m_ComboBox.AddString(__T("最小值"));
	m_ComboBox.AddString(__T("最大值"));
	m_ComboBox.AddString(__T("平均值"));

	m_ComboBox.SetCurSel(0);
	m_Button.SetCheck(0);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CPage1::OnCbnSetfocusCombo2()
{
	// TODO: 在此添加控件通知处理程序代码

}


void CPage1::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
	int i = m_ComboBox.GetCurSel();
	if (i < 3)
	{
		i++;
		UpdateImage(m_prImage, m_OutputImg, i);
	}
}
