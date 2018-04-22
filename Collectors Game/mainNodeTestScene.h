#pragma once
#include "gameNode.h"
#include "nodeTest1.h"
#include "nodeTest2.h"


class mainNodeTestScene : public gameNode
{
private:
	nodeTest1* _test1;
	nodeTest2* _test2;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	mainNodeTestScene();
	~mainNodeTestScene();
};

