// GetLocalPicture.h : GetLocalPicture DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CKColorConverApp
// �йش���ʵ�ֵ���Ϣ������� GetLocalPicture.cpp
//

class CKColorConverApp : public CWinApp
{
public:
	CKColorConverApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
