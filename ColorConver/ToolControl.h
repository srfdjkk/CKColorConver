typedef struct tagEntityInfoParam
{
	TCHAR szEntityType[MAX_PATH];//实体类型
	TCHAR szEntityName[MAX_PATH];//实体名字
	BOOL bCheckWeldContour;//是否焊接轮廓
	BOOL bCheckWeldHatch;//焊接填充区域
	int nLoopWeldCount;//循环焊接次数
	int nBeatWeldCount;//焊接次数
	double dbBeatOffset;//焊接偏移
	int nArrayCountX;//阵列X方向数量
	int nArrayCountY;//阵列Y方向数量
	double dbArrayIncX;//阵列X方向的间隔
	double dbArrayIncY;//阵列Y方向的间隔
	BOOL bCheckCluster;//是否组合
	BOOL bCheckPenPath;//
	BOOL bCheckOutAsBitmap;//作为像素位图
	double dbEditSpeed;//速度
	double dbEditAcceleration;//加速度
	double dbEditVoidSpeed; //空程速度
	double dbEditVoidAcceleration;//空程加速度
	int nCoordNum;		//坐标系序号; 1 or 2
	int nAxisX;			//X轴序号
	int nAxisY;			//Y轴序号
	int nAxisZ;			//Z轴序号
	int nAxisA;			//A轴序号
	int nGasStartDelay;	//开激光延时
	int nGasCloseDelay;	//关激光延时
	int nWav; //波形号
}EntityInfoParam, *pEntityInfoParam;


typedef struct tagControlParam
{
	int nDeviceID;
	int nFuncID;
	int nCoordNum;
	int nNodeID;
	TCHAR szDocName[MAX_PATH];
	TCHAR szNodeName[MAX_PATH];
	void * pToolParam;
	pEntityInfoParam pEntityInfoParam;
}ControlParam, *pControlParam;




typedef int (WINAPI *fHWDO				 )(int, int, void*, void*);
typedef int (WINAPI *fGetIDNum			 )();
typedef int (WINAPI *fGetAllID			 )(int*);

extern fHWDO					HWDO;
extern fGetIDNum				GetIDNum;
extern fGetAllID				GetAllID;