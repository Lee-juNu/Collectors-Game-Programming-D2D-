#pragma once
#include "gameNode.h"
class player :	public gameNode
{
private:

public:
	player();
	~player();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

