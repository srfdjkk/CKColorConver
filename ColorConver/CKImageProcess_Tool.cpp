#include "stdafx.h"
#include "CKImageProcess_Tool.h"


CKImageProcess_Tool::CKImageProcess_Tool(TCHAR * pDocName, int nNodeID, TCHAR * pNodeName)
{
	if (_tcslen(pDocName) > 0)
	{
		_tcscpy_s(m_Toolparam.szDocName, MAX_PATH, pDocName);
		_tcscpy_s(m_Toolparam.szNodeName, MAX_PATH, pNodeName);
		m_Toolparam.nNodeID = nNodeID;
	}
	TCHAR pParaName[MAX_PATH] = _T("Ԥ����");
	_tcscpy_s(m_Toolparam.szParaName, MAX_PATH, pParaName);
	m_Toolparam.nIndex = 0;
	m_Toolparam.nType = NODETYPE_PIMAGE;

}


CKImageProcess_Tool::~CKImageProcess_Tool()
{


}

void CKImageProcess_Tool::Save(CArchive &ar)
{

}
void CKImageProcess_Tool::Load(CArchive &ar)
{
	CString str;

}
void CKImageProcess_Tool::ShowPropertyDialog()
{
	CKImageProcessDlg dlg;
	//dlg.m_GLPP = m_GetLocalPictureParam;
	dlg.DoModal();
	//m_GetLocalPictureParam = dlg.m_GLPP;
	//m_VectImgFileNameT 
	//m_GetLocalPictureParam.ImgFileNameVect_Count=m_GetLocalPictureParam.ImgFileNameVect.size();

	DoCreate();
}
void CKImageProcess_Tool::Do()
{
	DoCreate();
}

void CKImageProcess_Tool::DoCreate()
{

}

/***********************************************************
*FunctionName:	SetImageParamByCPImage()
*Description:	�� CPrImage ���͵�ͼƬ����ת�� ImageParam ����ͼƬ���ݣ�����洢
*parameter  :	��
*return		:	void
************************************************************/
void CKImageProcess_Tool::SetImageParamByCPImage(ImageParam* pImageParam, CPrImage* pho_Img)
{

	pImageParam->m_nChannel = pho_Img->GetFormat();
	pImageParam->m_nWidth = pho_Img->GetWidth();
	pImageParam->m_nHeight = pho_Img->GetHeight();
	pImageParam->m_nSize = pho_Img->GetSizeByte();
	pImageParam->m_nPtrType =0;
	pImageParam->m_pData = pho_Img->GetBits();

}

/***********************************************************
*FunctionName:	SetImageParamByCImage()
*Description:	�� CImage ���͵�ͼƬ����ת�� ImageParam ����ͼƬ���ݣ�����洢
*parameter  :	��
*return		:	void
************************************************************/
void CKImageProcess_Tool::SetImageParamByCImage(ImageParam* pImageParam, CImage* pho_Img)
{
	int ImageFormat = pho_Img->GetBPP();
	if (ImageFormat = 8)
		pImageParam->m_nChannel = 1;
	if (ImageFormat = 24)
		pImageParam->m_nChannel = 3;

	pImageParam->m_nWidth = pho_Img->GetWidth();
	pImageParam->m_nHeight = pho_Img->GetHeight();
	pImageParam->m_nSize = abs(pho_Img->GetPitch())*pho_Img->GetHeight();
	pImageParam->m_nPtrType = 0;
	if (m_Cimge.GetPitch() < 0)//�е�ͼƬ��jpg�Ǵ����Ͻǣ���bmpͼƬ�Ǵ����½ǿ�ʼ��
		pImageParam->m_pData = (BYTE *)m_Cimge.GetBits() + (m_Cimge.GetPitch()*(m_Cimge.GetHeight() - 1));
	else
		pImageParam->m_pData = (BYTE *)m_Cimge.GetBits();

}

void CKImageProcess_Tool::ReadpCharA(CArchive &ar, TCHAR* pchar)
{
	//USES_CONVERSION;
	CString strRd;
	ar.ReadString(strRd);
	_tcscpy_s(pchar,256, strRd.GetBuffer());
}

void CKImageProcess_Tool::ReadDouble(CArchive &ar, double& dbVal)
{
	CString str;
	ar.ReadString(str);
	dbVal = _wtof(str.GetBuffer());
}

void CKImageProcess_Tool::WritepCharA(CArchive &ar, TCHAR* pchar)
{
	CString strWt(pchar);
	ar.WriteString(strWt + _T("\r\n"));
}

void CKImageProcess_Tool::WriteDouble(CArchive &ar, double dbVal)
{
	CString str;
	str.Format(_T("%lf"), dbVal);
	ar.WriteString(str + _T("\r\n"));
}


void CKImageProcess_Tool::LoadBmpJpgImage(IMG_TYPE ImgType,CString Path)
{
	if (ImgType == IMG_JPG)
	{
		m_Cimge.Load(Path);
		SetImageParamByCImage(m_imagepinT, &m_Cimge);
	}
	if (ImgType == IMG_BMP)
	{
		//CK�ṩ�� CPrImage ���ݶ�ȡͼƬ��
		USES_CONVERSION;
		m_Image.Clear();
		m_Image.LoadBmp(W2A(Path.GetBuffer()));
		SetImageParamByCPImage(m_imagepinT, &m_Image);
	}
}

