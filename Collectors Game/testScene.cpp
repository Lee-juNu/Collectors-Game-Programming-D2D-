#include "stdafx.h"
#include "testScene.h"


testScene::testScene()
{
}


testScene::~testScene()
{

}



HRESULT testScene::init()
{
	_em = new enemyManager;
	_em->init();

	_tm = new tileMap;
	_tm->init();
	_pl = new player;
	_pl->setLinkAdressTileMap(_tm);
	_pl->init();

	D2DRt->CreateCompatibleRenderTarget(&BRt);


	return S_OK;
}
void testScene::release()
{
	_em->release();
}
void testScene::update()
{
	_em->update();
	_pl->update();
	_tm->update();
}
void testScene::render()
{

	_em->render();
	_tm->render();
	_pl->render();

	TIMEMANAGER->render(getMemDC());



}