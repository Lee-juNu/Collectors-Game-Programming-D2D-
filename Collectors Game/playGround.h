#pragma once
#include "gameNode.h"
#include "testScene.h"
class playGround : public gameNode
{
private:
	ID2D1Bitmap* testBitmap;

	RECT rc;
	HRESULT hr;


	int _aobaFrame;
	int _cahrgeFrame;

	int _aobaCount;
	int _cahrgeCount;

public:
	virtual HRESULT init(void);		//�ʱ�ȭ �Լ�
	virtual void release(void);		//�޸� ���� ����
	virtual void update(void);		//������Ʈ(����)
	virtual void render(void);		//�׷��ִ� �Լ�


	playGround();
	~playGround();
};

