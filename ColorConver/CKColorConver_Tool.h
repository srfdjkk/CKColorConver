#pragma once
#include "Tool.h"
#include "CKColorConverDlg.h"


//������Ϣ�ṹ��
typedef struct stt_Param {
	TCHAR	szDocName[MAX_PATH];
	int		nNodeID;
	TCHAR	szNodeName[MAX_PATH];
	TCHAR	szParaName[MAX_PATH];//�������֣����飩
	int		nType;				//�������ͣ������ڲ�����ֵ���ͣ�
	int		nIndex;				//����ĽǱ���
}STTP,*PSTTP;



class CKColorConver_Tool
{
public:
	CKColorConver_Tool(TCHAR * pDocName, int nNodeID, TCHAR * pNodeName);
	~CKColorConver_Tool();
	//��д���캯��
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

