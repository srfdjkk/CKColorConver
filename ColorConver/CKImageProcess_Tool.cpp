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
	TCHAR pParaName[MAX_PATH] = _T("预处理");
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
*Description:	将 CPrImage 类型的图片数据转成 ImageParam 类型图片数据，方便存储
*parameter  :	无
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
*Description:	将 CImage 类型的图片数据转成 ImageParam 类型图片数据，方便存储
*parameter  :	无
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
	if (m_Cimge.GetPitch() < 0)//有的图片如jpg是从左上角，而bmp图片是从左下角开始的
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
		//CK提供的 CPrImage 数据读取图片。
		USES_CONVERSION;
		m_Image.Clear();
		m_Image.LoadBmp(W2A(Path.GetBuffer()));
		SetImageParamByCPImage(m_imagepinT, &m_Image);
	}
}

