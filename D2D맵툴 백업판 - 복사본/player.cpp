#include "stdafx.h"
#include "player.h"
#include "tileMap.h"


player::player()
{
}


player::~player()
{

}


HRESULT player::init()
{
	D2DRt->CreateCompatibleRenderTarget(&Rt);
	_player.x= WINSIZEX/2;
	_player.y= WINSIZEY/2;


	_player.userFocus.x = _player.x / 32;
	_player.userFocus.y = _player.y / 32;

	_player.rc = RectMakeCenter(_player.x, _player.y,
		32, 32);

	_limitFocus.x= _player.x;
	_limitFocus.y= _player.y;


	_reLimitFocus.x = _player.x;
	_reLimitFocus.y = _player.y;

	_tm->setFocus(_player.userFocus);

	test = false;
	return S_OK;
}
void player::release()
{

}
void player::update() 
{

	bool isKeyDown =false ;
	bool isKeyDown2=false ;

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_player.x-=3; 
		_limitFocus.x -= 3;

		isKeyDown = true;
	}
	else if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_player.x += 3;
		_limitFocus.x += 3;
		isKeyDown = true;
	}
	else if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_player.y -= 3;
		_limitFocus.y -= 3;
		isKeyDown2 = true;
	}
	else if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_player.y += 3;
		_limitFocus.y += 3;
		isKeyDown2 = true;
	}
	_player.userFocus.x = _player.x / 32;
	_player.userFocus.y = _player.y / 32;
	 //_limitFocus.x = _player.x;
	//limitFocus.y = _player.y;

	
	if (_limitFocus.x <= 200)
	{
		_limitFocus.x = 200;
		_reLimitFocus.x = -200;
	}
	else if (_limitFocus.x >= WINSIZEX - 200)
	{
		_limitFocus.x = WINSIZEX - 200;
		_reLimitFocus.x = 200;
	}
	else
	{
		_reLimitFocus.x = 0;
	}


	if (_limitFocus.y <= 200)
	{
		_limitFocus.y = 200;
		_reLimitFocus.y = -200;
	}
	else if (_limitFocus.y >= WINSIZEX - 200)
	{
		_limitFocus.y = WINSIZEY - 200;
		_reLimitFocus.y = 200;
	}
	else
	{
		_reLimitFocus.y = 0;
	}

	



	if (_reLimitFocus.x != 0 && _reLimitFocus.y == 0 && isKeyDown)
	{
		if(-WINSIZEX / 2 + _player.x - _reLimitFocus.x >= 0)
		_tm->getTileRt()->SetTransform(Matrix3x2F::Translation(WINSIZEX / 2 - _player.x + _reLimitFocus.x, WINSIZEY / 2 - _player.y - (WINSIZEX / 2 - _limitFocus.y)));
	}
	else if (_reLimitFocus.y != 0 && _reLimitFocus.x == 0 && isKeyDown2)
	{
		if (-WINSIZEX / 2 + _player.y - _reLimitFocus.y >= 0)
		_tm->getTileRt()->SetTransform(Matrix3x2F::Translation(WINSIZEX / 2 - _player.x - (WINSIZEX / 2 - _limitFocus.x), WINSIZEY / 2 - _player.y + _reLimitFocus.y));
	}
	else  if (_reLimitFocus.x != 0 && _reLimitFocus.y != 0)
	{
		_tm->getTileRt()->SetTransform(Matrix3x2F::Translation(WINSIZEX / 2 - _player.x + _reLimitFocus.x, WINSIZEY / 2 - _player.y + _reLimitFocus.y));
	}
	
	

	
	_tm->setFocus(_player.userFocus);
	_player.rc = RectMakeCenter(_player.x, _player.y,	32, 32);
	_renderRc = RectMakeCenter(_limitFocus.x, _limitFocus.y, 32, 32);	
}
void player::render() 
{
	RECT tempRc;
	

	_tm->getTileRt()->BeginDraw();
	for(int i = 0; i < TILEX * TILEY; i++)
	{
		if (IntersectRect(&tempRc, &_tm->getTile()[i].rc, &_player.rc))
		{
			D2DRectDraw(_tm->getTileRt(), _tm->getTile()[i].rc.left,
				_tm->getTile()[i].rc.top, _tm->getTile()[i].rc.right, _tm->getTile()[i].rc.bottom);
			
			
			D2DRectDraw(_tm->getTileRt(), 0,0,32,32);
		}
	}
	_tm->getTileRt()->EndDraw();
	ID2D1Bitmap* tempbit;
	_tm->getTileRt()->GetBitmap(&tempbit);
	D2DRt->DrawBitmap(tempbit);




	Rt->BeginDraw();
	Rt->Clear(ColorF(ColorF(0,0, 0, 0)));
	D2DRectDraw(Rt, _renderRc);
	wchar_t str[128];
	swprintf_s(str, 128, L"%f", -WINSIZEX / 2 + _player.x - _reLimitFocus.x);
	D2DWrite(str, Rt,0,0);
	swprintf_s(str, 128, L"%d", _limitFocus.y);
	D2DWrite(str, Rt, 0, 20);



	Rt->EndDraw();

	Rt->GetBitmap(&tempbit);

	D2DRt->DrawBitmap(tempbit);
}