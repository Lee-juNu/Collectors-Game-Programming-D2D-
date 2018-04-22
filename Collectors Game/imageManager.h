#pragma once
#include "singletonBase.h"
#include "d2dWic.h"
#include "D2DImage.h"
#include "image.h"
#include <map>
#include <vector>
//D2D Gif�� �ѹ� ������!!

class imageManager : public singletonBase<imageManager>
{
private:
	//typedef map<string, image*> �̰��� mapImageList�� Ī�Ѵ�
	typedef map<string, image*>				mapImageList;
	typedef map<string, image*>::iterator	mapImageIter;
	

	// D2D�� ����ϱ� ���Ͽ� ������ ����� Ű������ ã�ƿ´�.
	typedef map<string, TagD2DImage*>				mapD2DImageList;
	typedef map<string, TagD2DImage*>::iterator		mapD2DImageIter;


	typedef		vector<TagD2DImage*>				vectorD2DFrameList;
	typedef		vector<TagD2DImage*>::iterator		vectorD2DFrameIter;



	//D2D Gif�� vector�� �������� ������ ���� Ű������ �� ���͸� ã�Ƽ� �������
	typedef map< string, vector<TagD2DImage*>>				mapFrameD2DImageList;
	typedef map< string, vector<TagD2DImage*>>::iterator	mapFrameD2DImageIter;





private:
	mapImageList				_mImageList;
	mapD2DImageList				_mdImageList;
	mapFrameD2DImageList		_mD2DFrameImageList;


public:
	HRESULT init(void);
	void release(void);

	image* addImage(string strKey, int width, int height);
	image* addImage(string strKey, const char* fileName, int width, int height, bool trans, COLORREF transColor);
	image* addImage(string strKey, const char* fileName, float x, float y, int width, int height, bool trans, COLORREF transColor);
	

	image* addFrameImage(string strKey, const char* fileName, float x, float y, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor);
	image* addFrameImage(string strKey, const char* fileName, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor);

	image* findImage(string strKey);

	BOOL deleteImage(string strKey);

	BOOL deleteAll(void);

	void render(string strKey, HDC hdc);
	void render(string strKey, HDC hdc, int destX, int destY);
	void render(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	//������ ����
	void frameRender(string strKey, HDC hdc, int destX, int destY);
	void frameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	//��������

	//���ķ���
	void alphaRender(string strKey, HDC hdc, BYTE alpha);
	void alphaRender(string strKey, HDC hdc, int destX, int destY, BYTE alpha);




	//D2D
	TagD2DImage* D2DAddImage(string strKey, const wchar_t* fileName);
	TagD2DImage* D2DAddImage(string strKey, const wchar_t* fileName, int width, int height);
	TagD2DImage* D2DAddImage(string strKey, const wchar_t* fileName, float x, float y, int width, int height);
	
	
	TagD2DImage* D2DAddGifImage(string strKey, const wchar_t* fileName);
									//Ű��			���					����		����	���θ?	���θ?	
	TagD2DImage* D2DAddFrameimage(string strkey, const wchar_t* fileName, int width, int height, int x, int y);

	TagD2DImage* D2DAddFrameimage(string strKey, const wchar_t* fileName, int frameX, int frameY);

	
	TagD2DImage* D2DAddGifFrameImage(string strKey, const wchar_t* fileName, int x, int y);
	
	
	TagD2DImage* D2DfindImage(string strKey);
	TagD2DImage* D2DfindFrameImage(string strKey);
	TagD2DImage* D2DfindFrameImage(string strKey, int currentFrame);




	void D2DRender(string strKey, ID2D1BitmapRenderTarget* target, float alpha = 1);
	void D2DRender(string strKey, ID2D1BitmapRenderTarget* target, int destX, int destY, float alpha = 1);
	void D2DRender(string strKey, ID2D1BitmapRenderTarget* target, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, float alpha = 1);


	void D2DGifRender(string strKey, ID2D1BitmapRenderTarget* target, int frame, float alpha = 1);
	void D2DGifRender(string strKey, ID2D1BitmapRenderTarget* target, int destX, int destY, int frame, float alpha = 1);
	void D2DGifRender(string strKey, ID2D1BitmapRenderTarget* target, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, int frame, float alpha = 1);

	void D2DFrameRender(string strKey, ID2D1BitmapRenderTarget* target, float destX, float destY, float FrameX, float FrameY, float alpha = 1);
	void D2DFrameRender(string strKey, ID2D1BitmapRenderTarget* target, float destX, float destY, float FrameX, float FrameY, float FrameWidht, float FrameHeight, float alpha = 1);


	void D2DGifFrameRender(string strKey, ID2D1BitmapRenderTarget* target, float destX, float destY, float FrameX, float FrameY, int frame, float alpha = 1);
	void D2DGifFrameRender(string strKey, ID2D1BitmapRenderTarget* target, float destX, float destY, float FrameX, float FrameY, float FrameWidht, float FrameHeight, int frame, float alpha = 1);


	imageManager();
	~imageManager();
};

