// GetLocalPictureDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CKImageProcess.h"
#include "CKImageProcessDlg.h"
#include "afxdialogex.h"
#include <atlimage.h>
#include <gdiplus.h>
#include "ToolControl.h"

CKImageProcessDlg* pCKImageProcessDlg = NULL;
using namespace Gdiplus;
IMPLEMENT_DYNAMIC(CKImageProcessDlg, CDialogEx)

CKImageProcessDlg::CKImageProcessDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG, pParent)
{
	pCKImageProcessDlg = this;

}

CKImageProcessDlg::~CKImageProcessDlg()
{

}

void CKImageProcessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_TAB1, m_Tab);
}

BEGIN_MESSAGE_MAP(CKImageProcessDlg, CDialogEx)
	ON_WM_DESTROY()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CKImageProcessDlg::OnTcnSelchangeTab1)
	ON_BN_CLICKED(IDC_BTN_OK, &CKImageProcessDlg::OnBnClickedBtnOk)
	ON_BN_CLICKED(IDC_BTN_CANCLE, &CKImageProcessDlg::OnBnClickedBtnCancle)
END_MESSAGE_MAP()

BOOL CKImageProcessDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//ѡ���ʼ��
	m_Tab.InsertItem(0, _T("��������"));
	m_Tab.InsertItem(1, _T("��������"));

	m_Page1.Create(IDD_PAGE1, GetDlgItem(IDC_TAB1));
	m_Page2.Create(IDD_PAGE2, GetDlgItem(IDC_TAB1));

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
	m_Page2.MoveWindow(&rs);

	//�ֱ��������غ���ʾ 
	m_Page1.ShowWindow(true);
	m_Page2.ShowWindow(false);
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

	//�������γ�ʼ��
	m_sRectROI.left = 100;
	m_sRectROI.top = 100;
	m_sRectROI.right = 500;
	m_sRectROI.bottom = 400;
	m_sRectROI.SetPenColor(RGB(255, 0, 0));
	m_sRectROI.SetVisible(false);

	//������ת�����ʼ��
	m_sRotBoxROI.center.x = 100;
	m_sRotBoxROI.center.y = 100;
	m_sRotBoxROI.width = 100;
	m_sRotBoxROI.height = 100;
	m_sRotBoxROI.angle = 60;
	m_sRotBoxROI.SetPenColor(RGB(255, 0, 0));
	m_sRotBoxROI.SetVisible(false);

	UpdateData();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}




void CKImageProcessDlg::OnDestroy()
{
	CDialogEx::OnDestroy();
}










/***********************************************************
*FunctionName:	OnBnClickedOKButton()
*Description:	���ȷ����ťʱ�� ������������� 0�� �ļ�  1:Ŀ¼  2�����
*parameter  :	��
*return		:	void
************************************************************/
void CKImageProcessDlg::OnBnClickedOKButton()
{

	CKImageProcessDlg::OnOK();
}


void CKImageProcessDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int CurSel = m_Tab.GetCurSel();
	switch (CurSel)
	{
	case 0:
		m_Page1.ShowWindow(true);
		m_Page2.ShowWindow(false);

		break;
	case 1:
		m_Page1.ShowWindow(false);
		m_Page2.ShowWindow(true);
		break;

	default:
		;
	}
	*pResult = 0;
}




void CKImageProcessDlg::OnBnClickedBtnOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CDialogEx::OnOK();
}


void CKImageProcessDlg::OnBnClickedBtnCancle()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CDialogEx::OnCancel();
}
