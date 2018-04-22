#pragma once
#include "singletonBase.h"
#include "d2dWic.h"
#include "D2DImage.h"
#include "image.h"
#include <map>
#include <vector>
//D2D Gif를 한번 만들어보자!!

class imageManager : public singletonBase<imageManager>
{
private:
	//typedef map<string, image*> 이것을 mapImageList라 칭한다
	typedef map<string, image*>				mapImageList;
	typedef map<string, image*>::iterator	mapImageIter;
	

	// D2D를 사용하기 위하여 맵으로 만들어 키값으로 찾아온다.
	typedef map<string, TagD2DImage*>				mapD2DImageList;
	typedef map<string, TagD2DImage*>::iterator		mapD2DImageIter;


	typedef		vector<TagD2DImage*>				vectorD2DFrameList;
	typedef		vector<TagD2DImage*>::iterator		vectorD2DFrameIter;



	//D2D Gif를 vector에 수순으로 저장한 다음 키값으로 그 벡터를 찾아서 사용하자
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

	//프레임 렌더
	void frameRender(string strKey, HDC hdc, int destX, int destY);
	void frameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	//루프렌더

	//알파렌더
	void alphaRender(string strKey, HDC hdc, BYTE alpha);
	void alphaRender(string strKey, HDC hdc, int destX, int destY, BYTE alpha);




	//D2D
	TagD2DImage* D2DAddImage(string strKey, const wchar_t* fileName);
	TagD2DImage* D2DAddImage(string strKey, const wchar_t* fileName, int width, int height);
	TagD2DImage* D2DAddImage(string strKey, const wchar_t* fileName, float x, float y, int width, int height);
	
	
	TagD2DImage* D2DAddGifImage(string strKey, const wchar_t* fileName);
									//키값			경로					넓이		높이	가로몇개?	세로몇개?	
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

