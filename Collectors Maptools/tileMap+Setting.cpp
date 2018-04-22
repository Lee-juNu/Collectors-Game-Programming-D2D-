#include "stdafx.h"
#include "tileMap.h"
#include "Resource.h"


void tileMap::tileSetting()
{
	switch (_currentSelect)
	{
	case SEL_TR:
		this->smTileSelect();
		this->tileSelect();
		break;

	case SEL_OBJ:
		break;

	case SEL_SMTR:	
		smTerrainSet();
			if(PtInRect(&_selSmTileGRASS.rc, _ptMouse))
			{
				_currentSmTrSel = TR_GRASS;
			}
			if (PtInRect(&_selSmTileWATER.rc, _ptMouse))
			{
				_currentSmTrSel = TR_WATER;
			}
	
		break;
	case SEL_SMOBJ:
		smObjSet();
		if (PtInRect(&_selSmObjNONE.rc, _ptMouse))
		{
			_currentSmObjSel = OBJ_NONE;
		}
		if (PtInRect(&_selSmObjBLOCK.rc, _ptMouse))
		{
			_currentSmObjSel = OBJ_BLOCK1;
		}
		if (PtInRect(&_responeBtn.rc, _ptMouse))
		{
			_currentSmObjSel = OBJ_RESPONE;
		}
		break;
	case SEL_FILL:
		fillMap();
		break;

	case SEL_SMSPEED:
		smSpeedSet();
		break;
	case SEL_DELOBJ:
		this->tileSelect();
		break;

	}
}

void tileMap::tileSelect()
{
	RECT rc = RectMake(25, 25, 20 * 32, 20 * 32);
	
	if (KEYMANAGER->isStayKeyDown(MK_LBUTTON) && PtInRect(&rc, _ptMouse))
	{ 
		for (int i = 0; i < TILEX * TILEY; i++)
		{
			if (PtInRect(&_tiles[i].rc, _ptMouse))
			{
				if (_currentSelect == SEL_DELOBJ)
				{
						_tiles[i].obj = OBJ_NONE;
						_tiles[i].objFrameX = 1;
						_tiles[i].objFrameY = 1;
						_tiles[i].mapMode = MAP_GRASS;
						break;
				}
				if (_smTile[_currentFrameX + _smTileX * _currentFrameY].obj == OBJ_NONE)
				{
					_tiles[i].terrainFrameX = _currentFrameX;
					_tiles[i].terrainFrameY = _currentFrameY;
					_tiles[i].mapMode = _currentMapMode;
					_tiles[i].gifSpeed = _smTile[_currentFrameX + _smTileX * _currentFrameY].gifSpeed;
				}
				else
				{
					_tiles[i].obj =		  _smTile[_currentFrameX + _smTileX * _currentFrameY].obj;
					_tiles[i].objFrameX = _currentFrameX;
					_tiles[i].objFrameY = _currentFrameY;
					_tiles[i].mapMode = _currentMapMode;
					_tiles[i].gifSpeed = _smTile[_currentFrameX + _smTileX * _currentFrameY].gifSpeed;

				}
			}
		}
	}

}
void tileMap::smTileSelect()
{
	switch (_currentMapMode)
	{
	case MAP_GRASS:
		_smTileX = IMAGEMANAGER->D2DfindImage("鸥老1")->getFrameX();
		_smTileY = IMAGEMANAGER->D2DfindImage("鸥老1")->getFrameY();
		break;
	case MAP_FULL:
		_smTileX = IMAGEMANAGER->D2DfindImage("鸥老2")->getFrameX();
		_smTileY = IMAGEMANAGER->D2DfindImage("鸥老2")->getFrameY();
		break;
	case MAP_WATER:
		_smTileX = IMAGEMANAGER->D2DfindFrameImage("鸥老3")->getFrameX();
		_smTileY = IMAGEMANAGER->D2DfindFrameImage("鸥老3")->getFrameY();
		break;
	default:
		break;
	}
	if (KEYMANAGER->isStayKeyDown(MK_LBUTTON))
	{
		for (int i = 0; i < _smTileX *_smTileY; i++)
		{
			if (PtInRect(&_smTile[i].rcTile, _ptMouse))
			{
				_currentFrameX = _smTile[i].terrainFrameX;
				_currentFrameY = _smTile[i].terrainFrameY;
			}
		}
	}
}

void tileMap::smTerrainSet()
{
		for (int i = 0; i < SAMPLETILEX *SAMPLETILEY; i++)
		{
			if (PtInRect(&_smTile[i].rcTile, _ptMouse))
			{
				_smTile[i].terrain = _currentSmTrSel;
			}
		}
}


void tileMap::smObjSet()
{
	for (int i = 0; i < SAMPLETILEX *SAMPLETILEY; i++)
	{
		if (PtInRect(&_smTile[i].rcTile, _ptMouse))
		{
			_smTile[i].obj = _currentSmObjSel;
		}
	}
}


void tileMap::tileUpdate()
{

	_frameCount++;
	for (int i = 0; i < TILEX * TILEY; i++)
	{

		
		_tiles[i].rc = RectMake
		(
			25 + (TILESIZE * (i%TILEX)) - _userFocusPoint.x * TILESIZE,
			25 + (TILESIZE * (i / TILEX) - _userFocusPoint.y * TILESIZE),
			TILESIZE, TILESIZE
		);

		if (_frameCount % ((int)_tiles[i].gifSpeed*10)== 0)
		{
			_tiles[i].gifFrame++;
			if (_tiles[i].gifFrame >= 2)
			{
				_tiles[i].gifFrame = 0;
			}
		}
	}
}

void tileMap::smTileChange()
{
	int tileX;
	int tileY;

	switch (_currentMapMode)
	{
	case MAP_GRASS:
		tileX = IMAGEMANAGER->D2DfindImage("鸥老1")->getFrameX();
		tileY = IMAGEMANAGER->D2DfindImage("鸥老1")->getFrameY();
		break;
	case MAP_FULL:
		tileX = IMAGEMANAGER->D2DfindImage("鸥老2")->getFrameX();
		tileY = IMAGEMANAGER->D2DfindImage("鸥老2")->getFrameY();
		break;
	case MAP_WATER:
		tileX = IMAGEMANAGER->D2DfindFrameImage("鸥老3")->getFrameX();
		tileY = IMAGEMANAGER->D2DfindFrameImage("鸥老3")->getFrameY();
		break;
	default:
		break;
	}

	for (int i = 0; i < tileX * tileY; i++)
	{
		_smTile[i].rcTile = RectMake
		(690 +
			(TILESIZE * (i%tileX)+ i % tileX) + _smStartX,
			TILESIZE*(i / tileX) + i / tileX + _smStartY,
			TILESIZE,
			TILESIZE);

		_smTile[i].terrainFrameX = i % tileX;
		_smTile[i].terrainFrameY = i / tileX;

	}
}

void tileMap::smSpeedSet()
{
	for (int i = 0; i < SAMPLETILEX *SAMPLETILEY; i++)
	{
		if (PtInRect(&_smTile[i].rcTile, _ptMouse))
		{
			_smTile[i].gifSpeed = _currentSpeed;
		}
	}
}

