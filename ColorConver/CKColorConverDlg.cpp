// GetLocalPictureDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CKImageProcess.h"
#include "CKColorConverDlg.h"
#include "afxdialogex.h"
#include <atlimage.h>
#include <gdiplus.h>
#include "ToolControl.h"

CKColorConverDlg* pCKColorConverDlg = NULL;
using namespace Gdiplus;
IMPLEMENT_DYNAMIC(CKColorConverDlg, CDialogEx)

CKColorConverDlg::CKColorConverDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG, pParent)
{
	pCKColorConverDlg = this;

}

CKColorConverDlg::~CKColorConverDlg()
{

}

void CKColorConverDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_TAB1, m_Tab);
}

BEGIN_MESSAGE_MAP(CKColorConverDlg, CDialogEx)
	ON_WM_DESTROY()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CKColorConverDlg::OnTcnSelchangeTab1)
	ON_BN_CLICKED(IDC_BTN_OK, &CKColorConverDlg::OnBnClickedBtnOk)
	ON_BN_CLICKED(IDC_BTN_CANCLE, &CKColorConverDlg::OnBnClickedBtnCancle)
END_MESSAGE_MAP()

BOOL CKColorConverDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此添加额外的初始化
	//选项卡初始化
	m_Tab.InsertItem(0, _T("基本设置"));

	m_Page1.Create(IDD_PAGE1, GetDlgItem(IDC_TAB1));


	//获得IDC_TABTEST客户区大小 
	CRect rs;
	m_Tab.GetClientRect(&rs);
	//调整子对话框在父窗口中的位置 
	rs.top = rs.top + 40;
	rs.left = rs.left + 10;
	rs.bottom = rs.bottom - 10;
	rs.right = rs.right - 10;

	//设置子对话框尺寸并移动到指定位置 
	m_Page1.MoveWindow(&rs);


	//分别设置隐藏和显示 
	m_Page1.ShowWindow(true);

	//设置默认的选项卡 
	m_Tab.SetCurSel(0);



	//初始化图片控件；
	CRect rect;
	GetDlgItem(IDC_PIC_RECT)->GetWindowRect(&rect);
	ScreenToClient(&rect);

	m_GdiView.Create(m_hWnd, rect);
	m_GdiView.SetBackColor(RGB(0, 0, 64));
	m_GdiView.SetDisplayImage(&m_Image);
	m_GdiView.SetActiveOverlay(&m_Overlay);
	m_GdiView.SetStaticOverlay(&m_Results);

	m_Overlay.AddItem(&m_sRectROI);
	m_Overlay.AddItem(&m_sRotBoxROI);


	UpdateData();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}




void CKColorConverDlg::OnDestroy()
{
	CDialogEx::OnDestroy();
}










/***********************************************************
*FunctionName:	OnBnClickedOKButton()
*Description:	点击确定按钮时， 分三种情况处理， 0： 文件  1:目录  2：相机
*parameter  :	无
*return		:	void
************************************************************/
void CKColorConverDlg::OnBnClickedOKButton()
{

	CKColorConverDlg::OnOK();
}


void CKColorConverDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	int CurSel = m_Tab.GetCurSel();
	switch (CurSel)
	{
	case 0:
		m_Page1.ShowWindow(true);
	

		break;
	case 1:
		m_Page1.ShowWindow(false);

		break;

	default:
		;
	}
	*pResult = 0;
}




void CKColorConverDlg::OnBnClickedBtnOk()
{
	// TODO: 在此添加控件通知处理程序代码

	CDialogEx::OnOK();
}


void CKColorConverDlg::OnBnClickedBtnCancle()
{
	// TODO: 在此添加控件通知处理程序代码

	CDialogEx::OnCancel();
}
