#pragma once
#include "gameNode.h"
class enemy : public gameNode
{
protected:
	INT64 _HP;
	INT64 _MP;


	UINT _currentFrame;
	UINT _maxFrame;

	RECT _rc;
	float _x;
	float _y;
	float _centerX;
	float _centerY;
	float _width;
	float _height;

	float _zX; //Z����
	float _zY; //Z����

public:
	enemy();
	~enemy();

	virtual HRESULT	init();
	virtual void	release();
	virtual void	update();
	virtual void	render();


	void create(string strkey, float _centerX, float _centerY);
	void setup();



	INT64 getHP() { return _HP; }
	INT64 getMP() { return _MP; }

	float getX() { return _x; }
	float getY() { return _y; }
	float getCenterX() { return _centerX; }
	float getCenterY() { return _centerY; }


	float getWidth() { return _width; }
	float getHeight() { return _height; }

	float getZX() { return _zX; }
	float getZY() { return _zY; }

};
