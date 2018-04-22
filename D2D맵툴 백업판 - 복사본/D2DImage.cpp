#include "stdafx.h"
#include "D2DImage.h"


TagD2DImage::TagD2DImage()
{
}


TagD2DImage::~TagD2DImage()
{
}


HRESULT TagD2DImage::init(float x, float y, float width, float height)
{
	_x = x;
	_y = y;
	_width = width;
	_height = height;
	_centerX = x + width / 2;
	_centerY = y + height / 2;

	_rc.left	=	x;
	_rc.right	=	x+ width;
	_rc.top		=	y;
	_rc.bottom	=	y + height;
	return S_OK;
}



HRESULT TagD2DImage::init(float x, float y, float width, float height, int frameX, int frameY)
{
	_x = x;
	_y = y;
	_width = width;
	_height = height;

	_frameX = frameX;
	_frameY = frameY;

	_frameWidht = width / frameX;
	_frameHeight = height / frameY;

	_centerX = x + _frameWidht / 2;
	_centerY = y + _frameHeight / 2;


	_rc.left = x;
	_rc.right = x + width;
	_rc.top = y;
	_rc.bottom = y + height;
	return S_OK;
}