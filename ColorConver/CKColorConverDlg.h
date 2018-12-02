#pragma once
#include "CKImageProcess.h"
#include "afxcmn.h"
#include "afxwin.h"
#include "Tool.h"
#include "CPage1.h"
#include "CPage2.h"
struct StatePara
{
	int svae_ReadType;

};

using namespace std;

// CKColorConverDlg �Ի���

typedef struct tagToolGetPicParam {
	TCHAR	szDocName[MAX_PATH];
	int		nNodeID;
	TCHAR	szNodeName[MAX_PATH];
	TCHAR	szParaName[MAX_PATH];//�������֣����飩
	int		nType;				//�������ͣ������ڲ�����ֵ���ͣ�
	int		nIndex;				//����ĽǱ���
}ToolGetPicParam, *pToolGetPicParam;


class CKColorConverDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CKColorConverDlg)

public:
	CKColorConverDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CKColorConverDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedOKButton();

public:

	//��������
	CGdiRect m_sRectROI;
	CGdiRotBox  m_sRotBoxROI;

	CGdiView m_GdiView;
	CPrImage m_Image;
	COverlay m_Overlay;
	COverlay m_Results;

	CTabCtrl m_Tab;
	CPage1 m_Page1;


	//�������㷨��ʱ��
	LARGE_INTEGER m_BeginTime;
	LARGE_INTEGER m_EndTime;

	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBtnOk();
	afx_msg void OnBnClickedBtnCancle();
};
