#pragma once
#include "gameNode.h"

struct tagPlayer
{
	RECT rc;			//플레이어 렉트 이건 실제로 충돌되고~~ 적이랑 싸울 렉트시다
	POINT limitFocus;		//플레이어 랜더링 렉트 이 상자는 그려질 뿐 즉 착각 현상 쯤이려나. 절대 어느 범위 이상은 못넘어간다.
	POINT userFocus;	//이건 유저가 어디있는지 포인트로 잡아서 타일로 보내 주변을 랜더링 하기 위해서 만들어주었다
	
	float x;			// 이 둘은 렉트를 그리고~~ 랜더RC를 그리고~~ 유저포커스를 보낼 기본 xy이시다.
	float y;
};
class tileMap;
class player :	public gameNode
{
private:
	tagPlayer _player;
	tileMap* _tm;

	ID2D1BitmapRenderTarget* Rt;

	POINT	  _limitFocus;
	POINT	  _reLimitFocus;
	RECT	  _renderRc;
	bool test;
public:
	player();
	~player();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	void setLinkAdressTileMap(tileMap* tm) { _tm = tm; }
	tagPlayer getPlayer() { return _player; }
};

