#pragma once
//�� Ÿ���� �԰��� 32�� �Ѵ�
#define TILESIZE 32

//Ÿ�� ���� X Axis 20, Y Axis 20
#define TILEX 100
#define TILEY 100

//Ÿ�� ���̴� ����
#define TILEAREAX 20
#define TILEAREAY 20

//Ÿ�� �� ������ 
#define TILESIZEX TILESIZE * TILEX
#define TILESIZEY TILESIZE * TILEY

//Ÿ�� ���̴� ���� ������
#define TILEAREASIZEX TILESIZE * TILEAREAX
#define TILEAREASIZEY TILESIZE * TILEAREAY



//Ÿ�ϼ�(����Ÿ��) ����
#define SAMPLETILEX 24
#define SAMPLETILEY 14

//Ÿ���� �Ӽ��� �ο��غ��ô�
//Ÿ�� �Ӽ��� �̳����� �ص� �����ϴ�

//�������� �� ��Ʈ�ʵ� ���� �����µ�... �޸� �ɴ޷���
//������ 8�Ⱑ �� ���������� ����...
#define ATTR_UNMOVE 0x00000001		//��
#define ATTR_SWAMP	0x00000002		//�̼� �������� Ÿ��
#define ATTR_POISON 0x00000004		//�� Ÿ��
#define ATTR_FROZEN 0x00000008		//���� Ÿ��

enum MapMode
{
	MAP_FULL,
	MAP_WATER,
	MAP_GRASS
};

//������ ���� ����
enum TERRAIN
{
	TR_CEMENT,				//�ø�Ʈ
	TR_DESERT,				//��
	TR_GRASS,				//�ܵ� 
	TR_WATER,				//�̵��Ұ����� ��
	TR_HALF_LEFT_WATER,		//�ݸ� ��������
	TR_HALF_RIGHT_WATER,	
	TR_HALF_UP_WATER,
	TR_HALF_DOWN_WATER
	, TR_RESPONE
	, TR_END				//��������

};
//������Ʈ �� ���� ����
enum OBJECT
{
	OBJ_TREE1, 
	OBJ_BLOCK1, OBJ_BLOCK3, OBJ_BLOCKS,
	OBJ_FLAG1, OBJ_FLAG2,
	OBJ_RESPONE,
	OBJ_NONE
};

//������ (���� �ε��� ������ ������ �Ҵ��� �� �����ǿ���)
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