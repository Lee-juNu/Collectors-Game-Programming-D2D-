#include "stdafx.h"
#include "mainNodeTestScene.h"


mainNodeTestScene::mainNodeTestScene()
{
}


mainNodeTestScene::~mainNodeTestScene()
{

}

HRESULT mainNodeTestScene::init()
{
	gameNode::init();

	IMAGEMANAGER->addImage("자", "양자.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	_test1 = new nodeTest1;
	_test1->init();

	_test2 = new nodeTest2;
	_test2->init();

	addChild(_test1);
	addChild(_test2);

	return S_OK;
}

void mainNodeTestScene::release()
{

}

void mainNodeTestScene::update() 
{
	gameNode::update();

	if (KEYMANAGER->isOnceKeyDown('Q')) removeChild(_test1);
	if (KEYMANAGER->isOnceKeyDown('W')) removeChild(_test2);
}

void mainNodeTestScene::render() 
{
	IMAGEMANAGER->findImage("자")->render(getMemDC(), 0, 0);

	gameNode::render();
}