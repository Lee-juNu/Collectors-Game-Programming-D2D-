#include "stdafx.h"
#include "loadingScene.h"


loadingScene::loadingScene()
{
}


loadingScene::~loadingScene()
{

}

HRESULT loadingScene::init()
{
	_loading = new loading;
	_loading->init();

	char image[256];

	//여기에 로딩처리를 하면 된다
	//하지만 지금은 이미지가 한 장이므로, 키 값을 다르게 해서
	//여러장 로딩을 하는 것으로 함!

	for (int i = 0; i < 300; i++)
	{
		ZeroMemory(image, sizeof(image));
		sprintf(image, "오버쿡플레이%d", i);
		_loading->loadImage(image, "오버쿡플레이.bmp", 0, 0, WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	}

	return S_OK;
}

void loadingScene::release()
{
	SAFE_DELETE(_loading);
}

void loadingScene::update()	
{
	_loading->update();

	if (_loading->loadingDone())
	{
		SCENEMANAGER->changeScene("플레이씬");
	}
}

void loadingScene::render()	
{
	_loading->render();
}
