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
class enemyManager;
class tileMap;
class player :	public gameNode
{
private:
	tagPlayer _player;
	tileMap* _tm;
	enemyManager* _em;
	ID2D1BitmapRenderTarget* Rt;

	POINT	  _limitFocus;			//랜더범위를 제한해주는 포인트
	POINT	  _reLimitFocus;		//배경의 범위를 제한해주는 포인트
	POINT	  _bgFocus;				//배경의 범위를 계산해서 밖으로 보내기 위해 존재한다!


	RECT	  _renderRc;

private:
	bool isKeyDown = false;
	bool isKeyDown2 = false;
public:
	player();
	~player();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	void tempRender();

	void keyInput();
	void focusSetting();







	void setLinkAdressTileMap(tileMap* tm) { _tm = tm; }
	void setLinkAdressEnemy(enemyManager* em) { _em = em; }
	
	
	tagPlayer getPlayer() { return _player; }
	POINT getBgFocus() { return _bgFocus; }
};

