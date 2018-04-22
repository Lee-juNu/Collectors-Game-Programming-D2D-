#pragma once
#include "gameNode.h"

class nodeTest2 : public gameNode
{
public:
	HRESULT init();
	void release();
	void update();
	void render();

	nodeTest2();
	~nodeTest2();
};

