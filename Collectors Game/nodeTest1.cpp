#include "stdafx.h"
#include "nodeTest1.h"


nodeTest1::nodeTest1()
{
}


nodeTest1::~nodeTest1()
{

}

HRESULT nodeTest1::init()
{
	gameNode::init();

	IMAGEMANAGER->addImage("�⽺", "jobs.bmp", 500, 500, true, RGB(255, 0, 255));

	return S_OK;
}

void nodeTest1::release()
{

}

void nodeTest1::update() 
{

}

void nodeTest1::render() 
{
	IMAGEMANAGER->render("�⽺", getMemDC(), 50, 50);
}
