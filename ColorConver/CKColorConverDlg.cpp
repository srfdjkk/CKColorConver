// GetLocalPictureDlg.cpp : ʵ���ļ�
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
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//ѡ���ʼ��
	m_Tab.InsertItem(0, _T("��������"));

	m_Page1.Create(IDD_PAGE1, GetDlgItem(IDC_TAB1));


	//���IDC_TABTEST�ͻ�����С 
	CRect rs;
	m_Tab.GetClientRect(&rs);
	//�����ӶԻ����ڸ������е�λ�� 
	rs.top = rs.top + 40;
	rs.left = rs.left + 10;
	rs.bottom = rs.bottom - 10;
	rs.right = rs.right - 10;

	//�����ӶԻ���ߴ粢�ƶ���ָ��λ�� 
	m_Page1.MoveWindow(&rs);


	//�ֱ��������غ���ʾ 
	m_Page1.ShowWindow(true);

	//����Ĭ�ϵ�ѡ� 
	m_Tab.SetCurSel(0);



	//��ʼ��ͼƬ�ؼ���
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
				  // �쳣: OCX ����ҳӦ���� FALSE
}




void CKColorConverDlg::OnDestroy()
{
	CDialogEx::OnDestroy();
}










/***********************************************************
*FunctionName:	OnBnClickedOKButton()
*Description:	���ȷ����ťʱ�� ������������� 0�� �ļ�  1:Ŀ¼  2�����
*parameter  :	��
*return		:	void
************************************************************/
void CKColorConverDlg::OnBnClickedOKButton()
{

	CKColorConverDlg::OnOK();
}


void CKColorConverDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CDialogEx::OnOK();
}


void CKColorConverDlg::OnBnClickedBtnCancle()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CDialogEx::OnCancel();
}
