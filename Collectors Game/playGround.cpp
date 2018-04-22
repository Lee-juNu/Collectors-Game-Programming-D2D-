#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{

}

HRESULT playGround::init()
{
	gameNode::init(true);

	SCENEMANAGER->addScene("�׽�Ʈ��", new testScene);
	SCENEMANAGER->changeScene("�׽�Ʈ��");


	return S_OK;
}

//�޸� ���� ����
void playGround::release(void)
{
	gameNode::release();
	

}

//����
void playGround::update(void)
{
	gameNode::update();
	SCENEMANAGER->update();
	
}

//�׸��°�.......
void playGround::render(void)
{
	D2D1_POINT_2F scale;
	scale.x = WINSIZEX/2;
	scale.y = WINSIZEY/2;
	D2DRt->Clear(D2D1::ColorF(RGB(255, 255, 255)));
	
	SCENEMANAGER->render();
	D2DRt->SetTransform(Matrix3x2F::Scale(1, 1, scale));
}