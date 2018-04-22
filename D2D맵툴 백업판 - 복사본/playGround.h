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
	virtual HRESULT init(void);		//초기화 함수
	virtual void release(void);		//메모리 관련 해제
	virtual void update(void);		//업데이트(연산)
	virtual void render(void);		//그려주는 함수


	playGround();
	~playGround();
};

