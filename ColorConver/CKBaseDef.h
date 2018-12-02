/************************************************************
* Module:		CKBase.dll
* File:			CKBaseDef.h
*************************************************************/
#ifndef _CK_BASE_DEF_H_
#define _CK_BASE_DEF_H_

// 导出/导入
#ifdef CKVISION_DLL
#define CKVISION_EXPORT __declspec(dllexport)
#else
#define CKVISION_EXPORT __declspec(dllimport)
#endif

/* API导出定义 */
#define CKVISION_API		CKVISION_EXPORT

/* CKVision dll 标识 */
#define	CKDll

/* 矩形相关定义 */
#define RECT_WIDTH(r)		(r.right-r.left)
#define RECT_HEIGHT(r)		(r.bottom-r.top)

/* 圆周率 */
#define PI					3.1415926535897932384626433832795

/* 最大范围 */
#define MaxROI				_maxRect

/* 类型变更定义 */
#define Frame2D				FRAME2D

/* MCPNT标记 */
#define MCP_START			0x01	// 起始标记
#define MCP_CLOSE			0x02	// 闭合标记

#ifndef _WINDEF_

typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef unsigned int        UINT;
typedef unsigned long       DWORD;

#endif

// 名称空间
namespace CKVision
{

/* 点 */
typedef struct tagIPNT 
{
	int		x;			// X
	int		y;			// Y
} IPNT;

/* 点 */
typedef struct tagDPNT
{
	double	x;			// X
	double	y;			// Y
} DPNT;

/* 线段 */
typedef struct tagDLINE
{
	DPNT	st;			// 起点
	DPNT	ed;			// 终点
} DLINE;

/* 矩形 */
typedef struct tagIRECT 
{
	int		left;		// 左边
	int		top;		// 上边
	int		right;		// 右边
	int		bottom;		// 下边
} IRECT;

/* 矩形 */
typedef struct tagDRECT 
{
	double	left;		// 左边
	double	top;		// 上边
	double	right;		// 右边
	double	bottom;		// 下边
} DRECT;

/* 旋转矩形 */
typedef struct tagROTRECT
{
	DPNT	center;		// 中心
	double	width;		// 宽度
	double	height;		// 高度
	double	angle;		// 角度
} ROTRECT, RRECT;

/* 圆形 */
typedef struct tagCIRCLE 
{
	DPNT	center;		// 中心
	double	radius;		// 半径
} CIRCLE;

/* 圆环形 */
typedef struct tagRING 
{
	DPNT	center;		// 中心
	double	radius;		// 半径
	double	range;		// 半径范围
	double	angle;		// 角度
	double	sweep;		// 角度范围
} RING;

/* 椭圆形 */
typedef struct tagELLIPSE
{
	DPNT	center;		// 中心
	double	radiusX;	// 半径X
	double	radiusY;	// 半径Y
	double	angle;		// 角度
} ELLIPSE;

/* 多边形 */
typedef struct tagPOLYGON
{
	int		count;		// 数量
	DPNT*	vertex;		// 顶点
} POLYGON;

/* 轮廓点 */
typedef struct tagMPNT
{
	double	x;			// X
	double	y;			// Y
	double	a;			// 角度
	BYTE	m;			// 标记
} MPNT;

/* 轮廓数据 */
typedef struct tagCONTOUR
{
	int		count;		// 数量
	MPNT*	points;		// 点数据
} CONTOUR;

/* 2D坐标系框架 */
typedef struct tagFRAME2D
{
	DPNT	point;		// 原点
	double	angle;		// 角度
} FRAME2D;

/* 3D坐标点 */
typedef struct tagPNT3D
{
	double x;
	double y;
	double z;
} PNT3D;

/* 3D平面系数 */
typedef struct tagPLANE
{
	double a;
	double b;
	double c;
} PLANE;


/* 最大矩形 */
const IRECT _maxRect = { 0, 0, 0x7FFFFFFF, 0x7FFFFFFF };

};	// End

#endif	// _CK_BASE_DEF_H_
