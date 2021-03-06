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
	CPrImage m_OutputImg;
	afx_msg void OnBnClickedBtnLinkImage();
	void PImageParamToCPrImage(CPrImage* Dest, ImageParam*str);
	void UpdateImage(CPrImage &ImgSrc, CPrImage &ImgDsr, int index);
	CComboBox m_combox_image;

	CButton m_Button;
	CComboBox m_ComboBox;
	afx_msg void OnBnClickedCheck1();
//	afx_msg void OnCbnKillfocusCombo1();
	virtual BOOL OnInitDialog();
	CComboBox m_ComboBox2;
	afx_msg void OnCbnSetfocusCombo2();
	afx_msg void OnCbnSelchangeCombo2();
};
