#include "stdafx.h"
#include "enemy.h"

enemy::enemy()
{
}


enemy::~enemy()
{
}

HRESULT	enemy::init()
{
	IMAGEMANAGER->D2DAddGifImage("파이브", L"image//파이브.NPK");

	create("파이브", WINSIZEX / 2, WINSIZEY / 2);

	return S_OK;
}

void enemy::create(string strkey, float centerX, float centerY)
{
	_width = IMAGEMANAGER->D2DfindFrameImage(strkey)->getWidth();
	_height = IMAGEMANAGER->D2DfindFrameImage(strkey)->getHeight();
	_centerX = centerX;
	_centerY = centerY;
	_x = centerX - _width;
	_y = centerY - _height;

	_currentFrame = 0;

	_rc = RectMake(_x, _y, _x + _width, _y + _height);

	_maxFrame = IMAGEMANAGER->D2DfindFrameImage(strkey)->getMaxFrame();

}

void enemy::release()
{

}
void enemy::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_x -= 5;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_x += 5;
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_y -= 5;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_y += 5;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_ADD))
	{
		_currentFrame++;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SUBTRACT))
	{
		_currentFrame--;
	}
	_rc = RectMake(_x, _y, _x + _width, _y + _height);
}
void enemy::render()
{
}
