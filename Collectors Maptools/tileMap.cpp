#include "stdafx.h"
#include "tileMap.h"
#include "Resource.h"

tileMap::tileMap()
{
}


tileMap::~tileMap()
{

}


HRESULT tileMap::init()
{
	_rtTile = NULL;
	_rtUI = NULL;
	this->allInit();

	return S_OK;
}
void tileMap::release()
{

}
void tileMap::update() 
{
	if (_currentSelect == SEL_SMSPEED)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			_currentSpeed++;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			_currentSpeed--;
		}
	}



	if (_currentSelect== SEL_TR)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT) && _userFocusPoint.x != 0)
		{
			_userFocusPoint.x--;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) && _userFocusPoint.x + TILEAREAX != TILEX)
		{
			_userFocusPoint.x++;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && _userFocusPoint.y + TILEAREAY != TILEY)
		{
			_userFocusPoint.y++;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP) && _userFocusPoint.y != 0)
		{
			_userFocusPoint.y--;
		}
	}
	
	_userFocus = (_userFocusPoint.x %TILEX) + _userFocusPoint.y*TILEX;


	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
			_currentSelect = SEL_DELOBJ;
			this->tileSetting();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F4))
	{
		_currentSelect = SEL_FILL;
		this->tileSetting();
	}

	if (KEYMANAGER->isStayKeyDown(MK_LBUTTON))
	{
		if (PtInRect(&_saveBtn.rc, _ptMouse))
			this->save();

		if (PtInRect(&_loadBtn.rc, _ptMouse))
			this->load();
		if (PtInRect(&_selSmSetBtn.rc, _ptMouse))
			_currentSelect = SEL_SMTR;
		if (PtInRect(&_selTileSetBtn.rc, _ptMouse))
			_currentSelect = SEL_TR;
		if (PtInRect(&_selOBJSetBtn.rc, _ptMouse))
			_currentSelect = SEL_SMOBJ;
		if (PtInRect(&_selSmTileFrameSpeed.rc, _ptMouse))
			_currentSelect = SEL_SMSPEED;

		if (PtInRect(&_selTileMap[0].rc, _ptMouse))
		{
			_currentMapMode = MAP_GRASS;
			this->smTileChange();
		}
		else if (PtInRect(&_selTileMap[1].rc, _ptMouse))
		{
			_currentMapMode = MAP_FULL;
			this->smTileChange();
		}
		else if (PtInRect(&_selTileMap[2].rc, _ptMouse))
		{
			_currentMapMode = MAP_WATER;
			this->smTileChange();
		}
		this->tileSetting();
	}



	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		for (int i = 0; i < TILEX * TILEY; i++)
		{
			_tiles[i].gifFrame = 0;
		}
	}
	tileUpdate();
}
void tileMap::render() 
{

	if (!_isGameStart)
	{
		this->allDraw();
	}
	else
	{
		D2DRt->Clear(ColorF(ColorF(0, 0, 0)));
		this->gameRender();
	}
}


