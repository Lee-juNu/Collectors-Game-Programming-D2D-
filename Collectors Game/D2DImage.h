#pragma once



class TagD2DImage
{
public:
	ID2D1Bitmap* _bitmap;
	RECT _rc;
	float _x, _y;
	float _centerX, _centerY;
	float _width, _height;
	int _frameX, _frameY;
	float _frameWidht, _frameHeight;
	UINT _maxFrame;


public:
	TagD2DImage();
	~TagD2DImage();


	inline void setX(float x) { _x = x; }
	inline void setY(float y) { _y = y; }
	inline void setWidth(float width) { _width = width; }
	inline void setHeight(float height) { _height = height; }


	inline int getFrameX() { return _frameX;  }
	inline int getFrameY() { return _frameY;  }



	inline float getX() { return _x; }
	inline float getY() { return _y; }
	inline float getWidth() { return _width; }
	inline float getHeight() { return _height; }
	inline UINT	 getMaxFrame() { return _maxFrame; }
	inline float getFrameWidht() { return  _frameWidht; }
	inline float getFrameHeight() { return _frameHeight; }

	inline ID2D1Bitmap* getBitmap() { return _bitmap; }

	HRESULT init(float x, float y, float width, float height);
	HRESULT init(float x, float y, float width, float height, int frameX, int frameY);
};

