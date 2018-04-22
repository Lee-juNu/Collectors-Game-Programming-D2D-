#pragma once
#include "gameNode.h"

class nodeTest1 : public gameNode
{
public:
	HRESULT init();
	void release();
	void update();
	void render();


	nodeTest1();
	~nodeTest1();
};

