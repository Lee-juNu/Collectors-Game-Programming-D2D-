#include "stdafx.h"
#include "enemyManager.h"
#include "tileMap.h"
#include "player.h"


enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{

}



HRESULT enemyManager::init()
{
	_enemy = new enemy;
	_enemy->setTileMapAdressLink(_tm);
	_enemy->init(Rt);


	_newEnemy = new enemy;
	_newEnemy->init(Rt);


	D2DRt->CreateCompatibleRenderTarget(&Rt);
	return S_OK;
}
void enemyManager::release()
{
	_enemy->release();
	_newEnemy->release();
	Rt->Release();
}
void enemyManager::update()
{
	//_enemy->getRt()->SetTransform(Matrix3x2F::Translation(_pl->getBgFocus().x, _pl->getBgFocus().y));

	_enemy->update();

	_newEnemy->update();
	_newEnemy->getRt()->SetTransform(Matrix3x2F::Rotation(80, Point2F(150, 150)));

}
void enemyManager::render()
{
	Rt->BeginDraw();
	Rt->Clear(ColorF(ColorF(0, 0, 0, 0)));
	_enemy->render(Rt);

	_newEnemy->render(Rt);
	Rt->EndDraw();
	
	ID2D1Bitmap* bitmap;
	Rt->GetBitmap(&bitmap);

	D2DRt->DrawBitmap(bitmap);

}