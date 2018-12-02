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

// CKImageProcessDlg 对话框

typedef struct tagToolGetPicParam {
	TCHAR	szDocName[MAX_PATH];
	int		nNodeID;
	TCHAR	szNodeName[MAX_PATH];
	TCHAR	szParaName[MAX_PATH];//变量名字（数组）
	int		nType;				//变量类型（数组内部的数值类型）
	int		nIndex;				//数组的角标编号
}ToolGetPicParam, *pToolGetPicParam;


class CKImageProcessDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CKImageProcessDlg)

public:
	CKImageProcessDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CKImageProcessDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedOKButton();

public:

	//搜索区域
	CGdiRect m_sRectROI;
	CGdiRotBox  m_sRotBoxROI;

	CGdiView m_GdiView;
	CPrImage m_Image;
	COverlay m_Overlay;
	COverlay m_Results;

	CTabCtrl m_Tab;
	CPage1 m_Page1;
	CPage2 m_Page2;

	//计消耗算法的时间
	LARGE_INTEGER m_BeginTime;
	LARGE_INTEGER m_EndTime;

	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBtnOk();
	afx_msg void OnBnClickedBtnCancle();
};
