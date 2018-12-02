#pragma once

#include "Tool.h"
// CPage1 对话框

class CPage1 : public CDialogEx
{
	DECLARE_DYNAMIC(CPage1)

public:
	CPage1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CPage1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PAGE1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:

	//输入数据信息
	TCHAR m_cDocName[MAX_PATH], m_cNodeName[MAX_PATH], m_cParamName[MAX_PATH];
	int m_iNodeID, m_iIndex;
	CPrImage m_prImage;
	afx_msg void OnBnClickedBtnNull();
	afx_msg void OnBnClickedBtnRect1();
	afx_msg void OnBnClickedBtnRect2();
	afx_msg void OnBnClickedBtnLinkImage();
	void PImageParamToCPrImage(CPrImage* Dest, ImageParam*str);
	
	CComboBox m_combox_image;
};
