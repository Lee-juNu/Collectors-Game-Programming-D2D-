#include "stdafx.h"
#include "tileMap.h"



//1. tileFill
//2. tileSave&Load


//1�� Ÿ��ä���(tileFill)
void tileMap::fillMap()
{
	bool isClick = false; //Ŭ���� �������� �ٷ� �����ϰ� �ϱ� ���Ͽ�

	if (KEYMANAGER->isOnceKeyDown(MK_LBUTTON))
	{
		isClick = true;
		for (int i = 0; i < SAMPLETILEX * SAMPLETILEY; i++)
		{
			if (PtInRect(&_smTile[i].rcTile, _ptMouse))
			{
				_currentFrameX = _smTile[i].terrainFrameX;
				_currentFrameY = _smTile[i].terrainFrameY;
			}
		}
	}
	if (!isClick)
	{
		return;
	}
	else
	{
		for (int i = 0; i < TILEX * TILEY; i++)
		{
			_tiles[i].terrainFrameX = _currentFrameX;
			_tiles[i].terrainFrameY = _currentFrameY;
			_tiles[i].mapMode = _currentMapMode;
			_tiles[i].gifFrame = 0;
		}
		_currentSelect = SEL_TR;
	}
}

