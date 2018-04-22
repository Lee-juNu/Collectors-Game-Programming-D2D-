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

	this->load();

	return S_OK;
}
void tileMap::release()
{

}
void tileMap::update() 
{
	if ((_userFocusPoint.x) <= 20) 
		_userFocusPoint.x = 0;
	else  _userFocusPoint.x -= 20;
	if ((_userFocusPoint.y) <= 20)
		_userFocusPoint.y = 0;
	else  _userFocusPoint.y -= 20;



	if (_userFocusPoint.x + TILEAREAY >= TILEX) _userFocusPoint.x = TILEX - TILEAREAX;
	
	if (_userFocusPoint.y + TILEAREAY >= TILEY) _userFocusPoint.y = TILEY - TILEAREAY;

	_userFocus = (_userFocusPoint.x) + _userFocusPoint.y*TILEX;

		tileUpdate();
}
void tileMap::render() 
{
	this->allDraw();
}


