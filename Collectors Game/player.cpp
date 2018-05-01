#include "stdafx.h"
#include "player.h"
#include "tileMap.h"
#include "enemyManager.h"


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


	_reLimitFocus.x = _limitFocus.x = _player.x;
	_reLimitFocus.y = _limitFocus.y = _player.y;

	_tm->setFocus(_player.userFocus);
	return S_OK;
}
void player::release()
{

}
void player::update() 
{
	this->keyInput();
	this->focusSetting();
}




void player::render() 
{
	
	tempRender();
	ID2D1Bitmap* tempbit;


	Rt->BeginDraw();
	Rt->Clear(ColorF(ColorF(0,0, 0, 0)));
	D2DRectDraw(Rt, _renderRc);

	//플레이어의 좌표를 알아보기 위하여 적어놓은것
	wchar_t str[128];
	swprintf_s(str, 128, L"%f", _player.x);
	D2DWrite(str, Rt,0,0);
	swprintf_s(str, 128, L"%f", _player.y);
	D2DWrite(str, Rt, 0, 20);



	Rt->EndDraw();

	Rt->GetBitmap(&tempbit);

	D2DRt->DrawBitmap(tempbit);
}



//이건 플레이어의 렉트와 타일이 잘 맞아떨어지고 있는가를 재보기 위한 랜더링 나중에 삭제예정 솔직히 플레이어에서 뭔 타일맵 랜더링중이야 안되 돌아갓!
void player::tempRender()
{
	RECT tempRc;


	_tm->getTileRt()->BeginDraw();
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (IntersectRect(&tempRc, &_tm->getTile()[i].rc, &_player.rc))
		{
			D2DRectDraw(_tm->getTileRt(), _tm->getTile()[i].rc.left,
				_tm->getTile()[i].rc.top, _tm->getTile()[i].rc.right, _tm->getTile()[i].rc.bottom);


			D2DRectDraw(_tm->getTileRt(), 0, 0, 32, 32);
		}
	}
	_tm->getTileRt()->EndDraw();
	ID2D1Bitmap* tempbit;
	_tm->getTileRt()->GetBitmap(&tempbit);
	D2DRt->DrawBitmap(tempbit);
}


void player::keyInput()
{


	//기본적으로 업데이트 될때마다 키입력 불값을 초기화
	isKeyDown = false;
	isKeyDown2 = false;


	
	//키입력을 받으면 좌표조정과 함께
	//해당 불값을 true로 바꿔준다
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (_player.x - TILESIZE / 2 > 0)
		{
			_player.x -= 3;
			_limitFocus.x -= 3;
		}

		isKeyDown = true;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (_player.x + TILESIZE / 2 < TILEX*TILESIZE)
		{
			_player.x += 3;
			_limitFocus.x += 3;
		}
		isKeyDown = true;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		if (_player.y - TILESIZE / 2 > 0)
		{
			_player.y -= 3;
			_limitFocus.y -= 3;
		}
		isKeyDown2 = true;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		if (_player.y + TILESIZE / 2 < TILEX*TILESIZE)
		{
			_player.y += 3;
			_limitFocus.y += 3;
			isKeyDown2 = true;
		}
	}
}
