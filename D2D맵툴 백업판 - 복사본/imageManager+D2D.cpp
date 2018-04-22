#include "stdafx.h"
#include "imageManager.h"




TagD2DImage* imageManager::D2DAddImage(string strKey, const wchar_t* fileName)
{
	TagD2DImage* image = new TagD2DImage;

	if (FAILED(D2DLoadBitMap(fileName, D2DRt, WICFactory, &image->_bitmap)))
	{
		MessageBox(0, "이미지로드", 0, 0);
		return false;
	}
	image->init(0, 0,
		image->_bitmap->GetSize().width,
		image->_bitmap->GetSize().width);


	_mdImageList.insert(make_pair(strKey, image));
	return image;
}


TagD2DImage* imageManager::D2DAddImage(string strKey, const wchar_t* fileName, int width, int height)
{
	TagD2DImage* image = new TagD2DImage;
	if (FAILED(D2DLoadBitMap(fileName, D2DRt, WICFactory, &image->_bitmap)))
	{
		MessageBox(0, "이미지로드", 0, 0);
		return false;
	}
	image->init(0, 0, width, height);


	_mdImageList.insert(make_pair(strKey, image));
	return image;
}
TagD2DImage* imageManager::D2DAddImage(string strKey, const wchar_t* fileName, float x, float y, int width, int height)
{
	TagD2DImage* image = new TagD2DImage;
	if (FAILED(D2DLoadBitMap(fileName, D2DRt, WICFactory, &image->_bitmap)))
	{
		MessageBox(0, "이미지로드", 0, 0);
		return false;
	}
	image->init(x, y, width, height);
	
	_mdImageList.insert(make_pair(strKey, image));
	return image;
}


TagD2DImage* imageManager::D2DAddGifImage(string strKey, const wchar_t* fileName)
{
	bool isEnd = false;
	int frameIndex = 0;
	vectorD2DFrameList			_vFrameImage;
	while (!isEnd)
	{
	
		TagD2DImage* image = new TagD2DImage;
		if (FAILED(D2DLoadBitMap(fileName, D2DRt, WICFactory, &image->_bitmap, frameIndex,&image->_maxFrame,&isEnd)))
		{
			MessageBox(0, "이미지로드", 0, 0);
			return false;
		}
		image->init(0, 0,
			image->_bitmap->GetSize().width,
			image->_bitmap->GetSize().height);
		
		frameIndex++;
		_vFrameImage.push_back(image);
	}
	_mD2DFrameImageList.insert(make_pair(strKey, _vFrameImage));

	return _mD2DFrameImageList.begin()->second[0];
}


TagD2DImage* imageManager::D2DAddGifFrameImage(string strKey, const wchar_t* fileName, int frameX, int frameY)
{
	bool isEnd = false;
	int frameIndex = 0;
	vectorD2DFrameList			_vFrameImage;
	while (!isEnd)
	{

		TagD2DImage* image = new TagD2DImage;
		if (FAILED(D2DLoadBitMap(fileName, D2DRt, WICFactory, &image->_bitmap, frameIndex, &image->_maxFrame, &isEnd)))
		{
			MessageBox(0, "이미지로드", 0, 0);
			return false;
		}
		image->init(0, 0,
			image->_bitmap->GetSize().width,
			image->_bitmap->GetSize().height,
			frameX,
			frameY);

		frameIndex++;
		_vFrameImage.push_back(image);
	}
	_mD2DFrameImageList.insert(make_pair(strKey, _vFrameImage));

	return _mD2DFrameImageList.begin()->second[0];
}


TagD2DImage* imageManager::D2DAddFrameimage(string strKey, const wchar_t* fileName, int frameX, int frameY)
{
	TagD2DImage* image = new TagD2DImage;
	if (FAILED(D2DLoadBitMap(fileName, D2DRt, WICFactory, &image->_bitmap)))
	{
		MessageBox(0, "이미지로드", 0, 0);
		return false;
	}
	image->init(0, 0,
		image->getBitmap()->GetSize().width,
		image->getBitmap()->GetSize().height,
		frameX, frameY);

	_mdImageList.insert(make_pair(strKey, image));
	return image;
}


TagD2DImage* imageManager::D2DAddFrameimage(string strKey, const wchar_t* fileName, int width, int height, int frameX, int frameY)
{
	TagD2DImage* image = new TagD2DImage;
	if (FAILED(D2DLoadBitMap(fileName, D2DRt, WICFactory, &image->_bitmap)))
	{
		MessageBox(0, "이미지로드", 0, 0);
		return false;
	}
	image->init(0, 0, width, height, frameX, frameY);

	_mdImageList.insert(make_pair(strKey, image));
	return image;
}



TagD2DImage* imageManager::D2DfindImage(string strKey)
{
	mapD2DImageIter	key = _mdImageList.find(strKey);
	//찾았다
	if (key != _mdImageList.end())
	{
		return key->second;
	}

	return NULL;
}

TagD2DImage* imageManager::D2DfindFrameImage(string strKey)
{
	mapFrameD2DImageIter	key = _mD2DFrameImageList.find(strKey);
	//찾았다
	if (key != _mD2DFrameImageList.end())
	{
		return key->second.begin()[0];
	}
	return NULL;
}
TagD2DImage* imageManager::D2DfindFrameImage(string strKey,int currentFrame)
{
	mapFrameD2DImageIter	key = _mD2DFrameImageList.find(strKey);
	//찾았다
	if (key != _mD2DFrameImageList.end())
	{
		return key->second.begin()[currentFrame];
	}
	return NULL;
}

//렌더부분

//그냥 키값을 얻으면 처음에 addImage로 지정된 좌표,크기,뿌려질범위가 렌더링된다

void imageManager::D2DRender(string strKey, ID2D1BitmapRenderTarget* target, float alpha)
{
	TagD2DImage* image = D2DfindImage(strKey);
	ID2D1Bitmap* bitmaps;

	target->DrawBitmap(image->_bitmap, RectF(image->_x, image->_y,
		image->_x + image->_width, 
		image->_y + image->_height),
		alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		RectF(0, 0, image->_width, image->_height));
}


//렌더될 좌표를 얻어서 한다 크기나 범위는 당연히 기본값

							//키값			시작X		시작Y
void imageManager::D2DRender(string strKey, ID2D1BitmapRenderTarget* target, int destX, int destY, float alpha)
{
	TagD2DImage* image = D2DfindImage(strKey);
	target->DrawBitmap(image->_bitmap, RectF(destX, destY,
		destX + image->_width,
		destY + image->_height),
		alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		RectF(0, 0, image->_width, image->_height));
}


//렌더될 좌표, 뿌려질 부분좌표, 뿌려질 부분범위

							//키값			시작X		시작Y	  부분X		 부분Y		부분 범위 가로	부분 범위 세로
void imageManager::D2DRender(string strKey, ID2D1BitmapRenderTarget* target, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, float alpha)
{
	TagD2DImage* image = D2DfindImage(strKey);
	target->DrawBitmap(image->_bitmap, RectF(destX, destY,
		destX + image->_width,
		destY + image->_height),
		alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		RectF(sourX, sourY, sourX + sourWidth, sourY+sourHeight));
}


void imageManager::D2DFrameRender(string strKey, ID2D1BitmapRenderTarget* target, float destX, float destY, float FrameX, float FrameY, float alpha)
{
	TagD2DImage* image = D2DfindImage(strKey);
	target->DrawBitmap(image->_bitmap, RectF(destX, destY,
		destX + image->getFrameWidht(),
		destY + image->getFrameHeight()),
		alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		RectF(FrameX * image->getFrameWidht(), FrameY* image->getFrameHeight(),
		FrameX * image->getFrameWidht() + image->getFrameWidht(),
		FrameY* image->getFrameHeight() + image->getFrameHeight()));
}

void imageManager::D2DFrameRender(string strKey, ID2D1BitmapRenderTarget* target, float destX, float destY, float FrameX, float FrameY, float FrameWidht, float FrameHeight, float alpha)
{
	TagD2DImage* image = D2DfindImage(strKey);
	target->DrawBitmap(image->_bitmap, RectF(destX, destY,
		destX + FrameWidht,
		destY + FrameHeight),
		alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		RectF(FrameX * image->getFrameWidht(), FrameY* image->getFrameHeight(),
		FrameX * image->getFrameWidht() + image->getFrameWidht(),
		FrameY* image->getFrameHeight() + image->getFrameHeight()));
}


void imageManager::D2DGifRender(string strKey, ID2D1BitmapRenderTarget* target, int frame, float alpha)
{
	TagD2DImage* image = D2DfindFrameImage(strKey, frame);
	target->DrawBitmap(image->_bitmap, RectF(image->_x, image->_y,
		image->_x + image->_width,
		image->_y + image->_height),
		alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		RectF(0, 0, image->_width, image->_height));
}
void imageManager::D2DGifRender(string strKey, ID2D1BitmapRenderTarget* target, int destX, int destY, int frame, float alpha)
{
	TagD2DImage* image = D2DfindFrameImage(strKey, frame);
	target->DrawBitmap(image->_bitmap, RectF(destX, destY,
		destX + image->_width,
		destY + image->_height),
		alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		RectF(0, 0, image->_width, image->_height));
}
void imageManager::D2DGifRender(string strKey, ID2D1BitmapRenderTarget* target, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, int frame, float alpha)
{
	TagD2DImage* image = D2DfindFrameImage(strKey, frame);
	target->DrawBitmap(image->_bitmap, RectF(destX, destY,
		destX + image->_width,
		destY + image->_height),
		alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		RectF(sourX, sourY, sourX + sourWidth, sourY + sourHeight));
}

void imageManager::D2DGifFrameRender(string strKey, ID2D1BitmapRenderTarget* target, float destX, float destY, float FrameX, float FrameY,int frame, float alpha)
{

	TagD2DImage* image = D2DfindFrameImage(strKey, frame);
	target->DrawBitmap(image->_bitmap, RectF(destX, destY,
		destX + image->getFrameWidht(),
		destY + image->getFrameHeight()),
		alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		RectF(FrameX* image->getFrameWidht()
			,FrameY * image->getFrameHeight(),
			FrameX* image->getFrameWidht() + image->getFrameWidht(),
			FrameY* image->getFrameHeight() + image->getFrameWidht()));
}
void imageManager::D2DGifFrameRender(string strKey, ID2D1BitmapRenderTarget* target, float destX, float destY, float FrameX, float FrameY, float FrameWidht, float FrameHeight,int frame, float alpha)
{
	TagD2DImage* image = D2DfindFrameImage(strKey, frame);
	target->DrawBitmap(image->_bitmap, RectF(destX, destY,
		destX + FrameWidht,
		destY + FrameHeight),
		alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		RectF(FrameX* image->getFrameWidht()
			, FrameY * image->getFrameHeight(),
			FrameX* image->getFrameWidht() + image->getFrameWidht(),
			FrameY* image->getFrameHeight() + image->getFrameWidht()));
}
