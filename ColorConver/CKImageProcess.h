// GetLocalPicture.h : GetLocalPicture DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CKImageProcessApp
// �йش���ʵ�ֵ���Ϣ������� GetLocalPicture.cpp
//

class CKImageProcessApp : public CWinApp
{
public:
	CKImageProcessApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
