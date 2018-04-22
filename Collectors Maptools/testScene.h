#pragma once
#include "enemyManager.h"
#include "player.h"
#include "gameNode.h"
#include "tileMap.h"

static ID2D1Bitmap* pBitmap;

class testScene : public gameNode
{
private:
	tileMap*		_tm;
	enemyManager*	_em;
	player*			_pl;

public:
	testScene();
	~testScene();



	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

