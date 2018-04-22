#include "stdafx.h"
#include "nodeTest2.h"


nodeTest2::nodeTest2()
{
}


nodeTest2::~nodeTest2()
{

}

HRESULT nodeTest2::init()
{
	gameNode::init();

	IMAGEMANAGER->addImage("ºô", "bill.bmp", 500, 500, true, RGB(255, 0, 255));

	return S_OK;
}

void nodeTest2::release()
{

}

void nodeTest2::update() 
{

}

void nodeTest2::render() 
{
	IMAGEMANAGER->render("ºô", getMemDC(), 600, 50);
}
