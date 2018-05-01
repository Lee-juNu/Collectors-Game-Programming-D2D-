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


	_tm = new tileMap;
	_tm->init();



	_pl = new player;
	_pl->setLinkAdressTileMap(_tm);
	_pl->init();


	_em = new enemyManager;
	_em->setTileMapAdressLink(_tm);
	_em->setPlayerAdressLink(_pl);
	_em->init();

	_pl->setLinkAdressEnemy(_em);


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

	_tm->render();
	_pl->render();
	_em->render();

	TIMEMANAGER->render(getMemDC());



}