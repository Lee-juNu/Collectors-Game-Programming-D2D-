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
	//전방선언용
	tileMap* _tm;
	enemyManager* _em;

private:
	tagPlayer _player;
	ID2D1BitmapRenderTarget* Rt;

	POINT	  _limitFocus;			//랜더범위를 제한해주는 포인트
	POINT	  _reLimitFocus;		//배경의 범위를 제한해주는 포인트
	POINT	  _bgFocus;				//배경의 범위를 계산해서 밖으로 보내기 위해 존재한다!

	//실제로 렌더링 될 Rc이다
	RECT	  _renderRc;

private:
	//1은 오른쪽과 왼쪽
	//2는 위아래의 키를 입력시 true로 바껴서 focusSetting함수에서 사용된다.

	bool isKeyDown = false;
	bool isKeyDown2 = false;

public:
	player();
	~player();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	
	//게임에선 사용안되고 관리자모드일때
	//자신이 밞고있는 타일이 정확히 타일 위인지 절대좌표를 확인하기위한 렌더링
	void tempRender();
	

	//유저에 대한 키입력을 관리하는 함수
	void keyInput();
	//유저를 중점으로 나머지 랜더타겟을 그려줄 함수
	void focusSetting();






	//각 다른 클래스의 주소를 가져와서 전방선언을 한다.
	void setLinkAdressTileMap(tileMap* tm) { _tm = tm; }
	void setLinkAdressEnemy(enemyManager* em) { _em = em; }
	
	

	//접근자
	tagPlayer getPlayer() { return _player; }
	POINT getBgFocus() { return _bgFocus; }

	//수정자


};

