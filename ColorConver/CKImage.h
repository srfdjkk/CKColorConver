/************************************************************
* Module:		CKBase.dll
* File:			CKImage.h
*************************************************************/
#ifndef _CK_IMAGE_H_
#define _CK_IMAGE_H_

#include "CKFileStore.h"

namespace CKVision
{

/* 图像像素格式 */
enum ImagePixelFormat 
{
	IpfNull		= 0,		// 未知
	IpfGray		= 1,		// 8位灰度
	IpfColor	= 3			// 24位彩色
};

/* 图像基本功能类 */
class CKVISION_EXPORT CPrImage
{
public:
	CPrImage();

	// 构造+复制
	CPrImage( const CPrImage& imgSrc );

	// 构造+创建( 宽度， 高度， 图像像素格式 )
	CPrImage( int nWidth, int nHeight, int nFormat=1 );

	// 析构函数
	virtual	~CPrImage();

public:	// 数据访问

	// 获取宽度
	int GetWidth() const;

	// 获取高度
	int	GetHeight() const;

	// 获取像素格式
	int GetFormat() const;

	// 获取行字节数
	int GetLineByte() const;

	// 获取总字节数
	UINT GetSizeByte() const;

	// 获取数据地址
	BYTE* GetBits() const;

public:	// 功能函数

	/*
	功能:	创建一张图像( 宽度， 高度， 图像像素格式 )
	参数:	
			[in]	nWidth	图像宽度
			[in]	nHeight	图像高度
			[in]	nFormat	图像像素格式 { IpfNull= 0 (未知), IpfGray= 1 (8位灰度), IpfColor= 3 (24位彩色) }

	返回:	成功 true, 失败 false
	*/ 
	bool Create( int nWidth, int nHeight, int nFormat=1 );
	

	/*
	功能:	装载BMP文件
	参数:	
			[in]	strFileName	全路径名称

	返回:	成功 true, 失败 false
	*/ 
	bool LoadBmp( const char* strFileName );

	/*
	功能:	保存BMP文件
	参数:	
			[in]	strFileName	全路径名称

	返回:	成功 true, 失败 false
	*/
	bool SaveBmp( const char* strFileName ) const;

	/*
	功能:	设置图像数据
	参数:	
			[in]	pData	图像数据缓冲区
			[in]	bFlip	是否镜像

	返回:	成功 true, 失败 false
	*/ 
	bool SetBits( const BYTE* pData, bool bFlip=true );

	/*
	功能:	复制图像
	参数:	
			[in]	imgSrc	来源图像

	返回:	成功 true, 失败 false
	*/ 
	bool Copy( const CPrImage& imgSrc );

	/*
	功能:	粘贴图像
	参数:	
			[in]	imgSrc	来源图像
			[in]	x		粘贴位置x
			[in]	y		粘贴位置x

	返回:	成功 true, 失败 false
	*/ 
	bool Paste( const CPrImage& imgSrc, int x, int y );

	/*
	功能:	裁剪矩形区域
	参数:	
			[in]	imgSrc	来源图像
			[in]	roi		裁剪区域

	返回:	成功 true, 失败 false
	*/ 
	bool Cut( const CPrImage& imgSrc, const IRECT& roi );

	/*
	功能:	裁剪旋转矩形区域
	参数:	
			[in]	imgSrc	来源图像
			[in]	roi		裁剪区域

	返回:	成功 true, 失败 false
	*/
	bool Cut( const CPrImage& imgSrc, const ROTRECT& roi );

	/*
	功能:	彩色转灰度
	参数:	
			[in]	imgSrc	来源图像
			[in]	index	转换通道 0~4 { 0(蓝色) ,1(绿色), 2(红色), 3(最小值)，4(最大值)}

	返回:	成功 true, 失败 false
	*/
	bool Gray( const CPrImage& imgSrc, int index );

	/*
	功能:	设置一个像素值
	参数:	
			[in]	x		位置x
			[in]	y		位置y
			[in]	value	灰度值 (0~255)

	返回:	成功 true, 失败 false
	*/
	bool SetPixel( int x, int y, int value );

	/*
	功能:	获取一个像素值
	参数:	
			[in]	x		位置x
			[in]	y		位置y
			[out]	value	灰度值 (0~255)

	返回:	成功 true, 失败 false
	*/
	bool GetPixel( int x, int y, int& value ) const;

	// 清除
	bool Clear( BYTE nVal=0 );

	// 反转
	bool Reverse();

	// 存储功能
	bool Exchange( CFileStore& fs );

	// 释放
	void Release();

protected:

	int		m_nWidth;		// 宽度
	int		m_nHeight;		// 高度
	int		m_nFormat;		// 像素格式
	int		m_nLineByte;	// 行字节数
	UINT	m_nSizeByte;	// 总字节数
	BYTE*	m_pDataBits;	// 图像数据

};	// CPrImage

};	// CKVision

/* 类型变更定义 */
#define CPvImage CPrImage

#endif	// _CK_IMAGE_H_
