#pragma once
#include "gameNode.h"

#define CELL_WIDTH 100		//타일의 가로크기
#define CELL_HEIGHT 50		//타일의 세로크기

#define RADIUS_WIDTH	CELL_WIDTH / 2
#define RADIUS_HEIGHT	CELL_HEIGHT / 2
#define INIT_X 400		//초기화 좌표
#define INIT_Y 20

#define TILE_COUNT_X 30	//타일 갯수
#define TILE_COUNT_Y 30

class isoMetricScene : public gameNode
{
private:
	int _tileMap[TILE_COUNT_X][TILE_COUNT_X];
	int _isoX, _isoY;
	int _corner;
	char str[128];

public:
	HRESULT init();
	void release();
	void update();
	void render();

	//타일맵 그려주는 함수
	void drawTileMap();
	//마름모 그려주는 함수
	void drawRhombus(int left, int top);
	//코너 검출(1 ~ 4분면)
	int getCornerIndex(int isoX, int isoY);
	//코너안에 왔는지 검출하는 함수
	bool isInRhombus(int corner, int isoX, int isoY);


	isoMetricScene();
	~isoMetricScene();
};

