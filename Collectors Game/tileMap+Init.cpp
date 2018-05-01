#include "stdafx.h"
#include "tileMap.h"


void tileMap::allInit()
{
	this->variableInit();
	this->imageInit();//이미지들을 추가해준다.
	this->tileInit();//깔릴 타일들의 초기화
	this->RtInit();
}

void tileMap::variableInit()
{
	_currentSelect = SEL_TR;
	_currentSmTrSel = TR_GRASS;
	_currentMapMode = MAP_GRASS;
	_currentFrameX = 0;
	_currentFrameY = 0;


	//프레임스피드으으으으!!
	_currentSpeed = 2;

	_userFocusPoint.x = 0;
	_userFocusPoint.y = 0;
	_userFocus = (_userFocusPoint.x %TILEAREAX)  + _userFocusPoint.y*TILEX;

	_frameCount		= 0;
	_gifFrame		= 0;


	_isGameStart = false; //시작 안됨
}

void tileMap::imageInit()
{
	//샘플 타일과 그려질 타일을 위한 진짜배기 이미지
	IMAGEMANAGER->D2DAddFrameimage("타일1", L".//Image//tileMap.bmp",  13, 8);
	IMAGEMANAGER->D2DAddFrameimage("타일2", L".//Image//tileMap2.png", 23, 14);
	IMAGEMANAGER->D2DAddGifFrameImage("타일3",   L".//Image//tileMap3.gif",9,13);
}



void tileMap::tileInit()
{
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		_tiles[i].rc = RectMake
		(
			25 + (TILESIZE * (i%TILEX)),
			25 + (TILESIZE * (i / TILEX)),
			TILESIZE, TILESIZE
		);
		_tiles[i].mapMode = MAP_GRASS;

		_tiles[i].terrain = TR_GRASS;
		_tiles[i].terrainFrameX = 0;
		_tiles[i].terrainFrameY = 0;

		_tiles[i].obj = OBJ_NONE;
		_tiles[i].objFrameX = 0;
		_tiles[i].objFrameY = 0;

		_tiles[i].gifFrame = 0;
		_tiles[i].gifCount = 0;
		_tiles[i].gifSpeed = _currentSpeed;

	}
}




void tileMap::RtInit()
{
	D2DRt->CreateCompatibleRenderTarget(SizeF(2000,2000),&_rtTile);
	_rtTile->SetTransform(Matrix3x2F::Translation(0, 0));
}