#pragma once
#include "gameNode.h"

class tileMap;
class enemy : public gameNode
{
private:
	tileMap* _tm;
	ID2D1BitmapRenderTarget* _Rt;
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

	float _zX; //Z오더
	float _zY; //Z오더

public:
	enemy();
	~enemy();

	virtual HRESULT	init(ID2D1BitmapRenderTarget* Rt);
	virtual void	release();
	virtual void	update();
	virtual void	render(ID2D1BitmapRenderTarget* Rt);


	


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

	void setTileMapAdressLink(tileMap* tm) { _tm = tm; }

	ID2D1BitmapRenderTarget* getRt() { return _Rt; }
};

