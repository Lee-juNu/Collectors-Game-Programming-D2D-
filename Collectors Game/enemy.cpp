#include "stdafx.h"
#include "enemy.h"
#include "tileMap.h"

enemy::enemy()
{
}


enemy::~enemy()
{
}

HRESULT	enemy::init(ID2D1BitmapRenderTarget* Rt)
{

	D2DRt->CreateCompatibleRenderTarget(&_Rt);
	return S_OK;
}



void enemy::release()
{
	_Rt->Release();
}
void enemy::update()
{
	_rc = RectMake(_x, _y, _x + _width, _y + _height);
	//_Rt->SetTransform(Matrix3x2F::Rotation(45, Point2F(150, 150)));
}
void enemy::render(ID2D1BitmapRenderTarget* Rt)
{
	ID2D1Bitmap* bitmap;
	_Rt->BeginDraw();
	_Rt->Clear(ColorF(ColorF(0, 0, 0, 0)));
	D2DRectDraw(_Rt, 100,100,200,200);
	_Rt->EndDraw();


	_Rt->GetBitmap(&bitmap);

	Rt->DrawBitmap(bitmap);
}
