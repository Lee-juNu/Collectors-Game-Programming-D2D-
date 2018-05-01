#pragma once
#include "enemy.h"
class player;
class enemyManager :	public gameNode
{
private:
	ID2D1BitmapRenderTarget* Rt;
private:
	enemy* _enemy;
	enemy* _newEnemy;
	player* _pl;
	tileMap* _tm;
public:
	enemyManager();
	~enemyManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setTileMapAdressLink(tileMap* tm) { _tm = tm; }
	void setPlayerAdressLink(player* pl) { _pl = pl; }

	ID2D1BitmapRenderTarget* getRt() { return Rt; }

};

