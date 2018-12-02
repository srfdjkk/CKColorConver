#pragma once
#include "Tool.h"
#include "CKColorConverDlg.h"


//参数信息结构体
typedef struct stt_Param {
	TCHAR	szDocName[MAX_PATH];
	int		nNodeID;
	TCHAR	szNodeName[MAX_PATH];
	TCHAR	szParaName[MAX_PATH];//变量名字（数组）
	int		nType;				//变量类型（数组内部的数值类型）
	int		nIndex;				//数组的角标编号
}STTP,*PSTTP;



class CKColorConver_Tool
{
public:
	CKColorConver_Tool(TCHAR * pDocName, int nNodeID, TCHAR * pNodeName);
	~CKColorConver_Tool();
	//重写构造函数
	void Save(CArchive &ar);
	void Load(CArchive &ar);
	void ShowPropertyDialog();
	void Do();
	void DoCreate();
	void ReadpCharA(CArchive &ar, TCHAR* pchar);
	void ReadDouble(CArchive &ar, double& dbVal);
	void WritepCharA(CArchive &ar, TCHAR* pchar);
	void WriteDouble(CArchive &ar, double dbVal);
	
	void SetImageParamByCPImage(ImageParam* pImageParam, CPrImage* pho_Img);
	void SetImageParamByCImage(ImageParam* pImageParam, CImage* pho_Img);

	void CKColorConver_Tool::LoadBmpJpgImage(IMG_TYPE ImgType, CString Path);


	CPrImage m_Image;	//
	CImage m_Cimge;

	STTP m_Toolparam;

	PImageParam m_pCImage;
	//GetLocalPictureParam m_GetLocalPictureParam;

	PImageParam m_imagepinT;
	//CKVision::CPrImage m_ckImage;

};

