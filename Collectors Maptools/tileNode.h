#pragma once
//한 타일의 규격은 32로 한다
#define TILESIZE 32

//타일 갯수 X Axis 20, Y Axis 20
#define TILEX 100
#define TILEY 100

//타일 보이는 영역
#define TILEAREAX 20
#define TILEAREAY 20

//타일 총 사이즈 
#define TILESIZEX TILESIZE * TILEX
#define TILESIZEY TILESIZE * TILEY

//타일 보이는 영역 사이즈
#define TILEAREASIZEX TILESIZE * TILEAREAX
#define TILEAREASIZEY TILESIZE * TILEAREAY



//타일셋(샘플타일) 갯수
#define SAMPLETILEX 24
#define SAMPLETILEY 14

//타일의 속성을 부여해봅시다
//타일 속성은 이넘으로 해도 무방하다

//예전에는 참 비트필드 많이 썻었는뎅... 메모리 쪼달려서
//요즘은 8기가 막 꽂혀나오고 막막...
#define ATTR_UNMOVE 0x00000001		//벽
#define ATTR_SWAMP	0x00000002		//이속 느려지는 타일
#define ATTR_POISON 0x00000004		//독 타일
#define ATTR_FROZEN 0x00000008		//빙결 타일

enum MapMode
{
	MAP_FULL,
	MAP_WATER,
	MAP_GRASS
};

//지형에 대한 정의
enum TERRAIN
{
	TR_CEMENT,				//시멘트
	TR_DESERT,				//모래
	TR_GRASS,				//잔디 
	TR_WATER,				//이동불가지역 물
	TR_HALF_LEFT_WATER,		//반만 물인지역
	TR_HALF_RIGHT_WATER,	
	TR_HALF_UP_WATER,
	TR_HALF_DOWN_WATER
	, TR_RESPONE
	, TR_END				//끝인지역

};
//오브젝트 에 대한 정의
enum OBJECT
{
	OBJ_TREE1, 
	OBJ_BLOCK1, OBJ_BLOCK3, OBJ_BLOCKS,
	OBJ_FLAG1, OBJ_FLAG2,
	OBJ_RESPONE,
	OBJ_NONE
};

//포지션 (맵을 로드해 왔을때 실제로 할당이 될 포지션영역)
enum POS
{
	POS_FLAG1, POS_FLAG2, POS_TANK1, POS_TANK2
};

struct tagTile
{
	MapMode mapMode;
	TERRAIN terrain;
	OBJECT obj;
	RECT rc;
	int tileMapNum;
	int terrainFrameX;
	int terrainFrameY;
	int objFrameX;
	int objFrameY;

	int gifCount;
	float gifSpeed;
	int gifFrame;
};

struct tagSampleTile
{
	RECT rcTile;
	TERRAIN terrain;
	OBJECT obj;
	int terrainFrameX;
	int terrainFrameY;

	int gifSpeed;
};

struct tagCurrentTile
{
	int x;
	int y;
};