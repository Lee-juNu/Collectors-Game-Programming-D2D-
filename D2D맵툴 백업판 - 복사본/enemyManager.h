#pragma once
#include "enemy.h"
class enemyManager :	public gameNode
{
private:
	enemy* _enemy;
public:
	enemyManager();
	~enemyManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

