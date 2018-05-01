#include "stdafx.h"
#include "d2dWic.h"


IDWriteFactory*		wFactory = 0;
IDWriteTextFormat* textFormat = 0;
ID2D1SolidColorBrush*		D2DBrush;

LPCWSTR _fontName = L"¸íÁ¶";
float	_size = 0;

HRESULT	D2DInit(HWND hWnd, int width, int height,
	ID2D1Factory** factory, ID2D1HwndRenderTarget **Rt)
{

	HRESULT hr;
	hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, factory);
	
	if (FAILED(hr))
		return hr;
	
	DWInit(L"±Ã¼­", 40.0f, &wFactory, &textFormat);
	
	D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties(
		D2D1_RENDER_TARGET_TYPE_DEFAULT,
		D2D1::PixelFormat(
			DXGI_FORMAT_B8G8R8A8_UNORM,
			D2D1_ALPHA_MODE_IGNORE),
		0, 0,
		D2D1_RENDER_TARGET_USAGE_NONE,
		D2D1_FEATURE_LEVEL_DEFAULT
	);



	return (*factory)->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(hWnd,D2D1::SizeU(width, height)), Rt);
}

HRESULT WICInit(IWICImagingFactory** factory)
{
	CoInitialize(0);

	return CoCreateInstance(
		CLSID_WICImagingFactory,
		0, CLSCTX_INPROC_SERVER,
		IID_PPV_ARGS(factory)
	);
}

HRESULT DWInit(LPCWSTR fontName, float size, IDWriteFactory **factory, IDWriteTextFormat **format)
{
	HRESULT hr;
	
	hr = DWriteCreateFactory(
		DWRITE_FACTORY_TYPE_SHARED,
		__uuidof(*factory),
		(IUnknown**)factory
	);
	if (FAILED(hr))
		return hr;

	hr = (*factory)->CreateTextFormat
	(
		fontName,
		0,
		DWRITE_FONT_WEIGHT_REGULAR,
		DWRITE_FONT_STYLE_NORMAL,
		DWRITE_FONT_STRETCH_NORMAL,
		size,
		L"ko",
		format
	);
	
	return hr;
}


HRESULT D2DLoadBitMap(LPCWSTR fileName, ID2D1HwndRenderTarget* target,
	IWICImagingFactory* factory, ID2D1Bitmap** bitmap)
{
	HRESULT hr;

	IWICBitmapDecoder *decoder = 0;
	hr = factory->CreateDecoderFromFilename(fileName,
		0, GENERIC_READ,
		WICDecodeMetadataCacheOnDemand,
		&decoder);
	if (FAILED(hr))
		return hr;

	IWICBitmapFrameDecode* frameDecode = 0;

	hr = decoder->GetFrame(0, &frameDecode);
	UINT x;
	decoder->GetFrameCount(&x);
	if (FAILED(hr))
	{
		decoder->Release();
		return hr;
	}

	IWICFormatConverter* converter = 0;
	hr = factory->CreateFormatConverter(&converter);
	if (FAILED(hr))
	{
		decoder->Release();
		return hr;
	}

	hr = converter->Initialize(
		frameDecode,
		GUID_WICPixelFormat32bppPBGRA,
		WICBitmapDitherTypeNone,
		0, 0.0, WICBitmapPaletteTypeCustom);
	if (FAILED(hr))
	{
		decoder->Release();
		frameDecode->Release();
		converter->Release();
		return hr;
	}

	hr = target->CreateBitmapFromWicBitmap(converter, bitmap);
	
	decoder->Release();
	frameDecode->Release();
	converter->Release();

	return hr;
}



HRESULT D2DLoadBitMap(LPCWSTR fileName, ID2D1HwndRenderTarget* target,
	IWICImagingFactory* factory, ID2D1Bitmap** bitmap, UINT currentFrame, UINT* maxFrames, bool* isEnd)
{
	HRESULT hr;

	IWICBitmapDecoder *decoder = 0;
	hr = factory->CreateDecoderFromFilename(fileName,
		0, GENERIC_READ,
		WICDecodeMetadataCacheOnDemand,
		&decoder);
	if (FAILED(hr))
		return hr;

	IWICBitmapFrameDecode* frameDecode = 0;
	UINT maxFrame;

	decoder->GetFrameCount(&maxFrame);
	*maxFrames = maxFrame;
	if(currentFrame+1 >= maxFrame)
	{
		*isEnd = true;
	}

	hr = decoder->GetFrame(currentFrame, &frameDecode);
	
	
	if (FAILED(hr))
	{
		decoder->Release();
		return hr;
	}

	IWICFormatConverter* converter = 0;
	hr = factory->CreateFormatConverter(&converter);
	if (FAILED(hr))
	{
		decoder->Release();
		return hr;
	}
	
	hr = converter->Initialize(
		frameDecode,
		GUID_WICPixelFormat32bppPBGRA,
		WICBitmapDitherTypeNone,
		0, 0.0, WICBitmapPaletteTypeCustom);
	if (FAILED(hr))
	{
		decoder->Release();
		frameDecode->Release();
		converter->Release();
		return hr;
	}
	

	


	hr = target->CreateBitmapFromWicBitmap(converter, bitmap);
	

	decoder->Release();
	frameDecode->Release();
	converter->Release();

	return hr;
}

HRESULT D2DLoadBitMap(LPCWSTR fileName, ID2D1BitmapRenderTarget* target,
	IWICImagingFactory* factory, ID2D1Bitmap** bitmap)
{
	HRESULT hr;

	IWICBitmapDecoder *decoder = 0;
	hr = factory->CreateDecoderFromFilename(fileName,
		0, GENERIC_READ,
		WICDecodeMetadataCacheOnDemand,
		&decoder);
	if (FAILED(hr))
		return hr;

	IWICBitmapFrameDecode* frameDecode = 0;

	hr = decoder->GetFrame(0, &frameDecode);
	UINT x;
	decoder->GetFrameCount(&x);
	if (FAILED(hr))
	{
		decoder->Release();
		return hr;
	}

	IWICFormatConverter* converter = 0;
	hr = factory->CreateFormatConverter(&converter);
	if (FAILED(hr))
	{
		decoder->Release();
		return hr;
	}

	hr = converter->Initialize(
		frameDecode,
		GUID_WICPixelFormat32bppPBGRA,
		WICBitmapDitherTypeNone,
		0, 0.0, WICBitmapPaletteTypeCustom);
	if (FAILED(hr))
	{
		decoder->Release();
		frameDecode->Release();
		converter->Release();
		return hr;
	}

	hr = target->CreateBitmapFromWicBitmap(converter, bitmap);

	decoder->Release();
	frameDecode->Release();
	converter->Release();

	return hr;
}



HRESULT D2DLoadBitMap(LPCWSTR fileName, ID2D1BitmapRenderTarget* target,
	IWICImagingFactory* factory, ID2D1Bitmap** bitmap, UINT currentFrame, UINT* maxFrames, bool* isEnd)
{
	HRESULT hr;

	IWICBitmapDecoder *decoder = 0;
	hr = factory->CreateDecoderFromFilename(fileName,
		0, GENERIC_READ,
		WICDecodeMetadataCacheOnDemand,
		&decoder);
	if (FAILED(hr))
		return hr;

	IWICBitmapFrameDecode* frameDecode = 0;
	UINT maxFrame;

	decoder->GetFrameCount(&maxFrame);
	*maxFrames = maxFrame;
	if (currentFrame + 1 >= maxFrame)
	{
		*isEnd = true;
	}

	hr = decoder->GetFrame(currentFrame, &frameDecode);


	if (FAILED(hr))
	{
		decoder->Release();
		return hr;
	}

	IWICFormatConverter* converter = 0;
	hr = factory->CreateFormatConverter(&converter);
	if (FAILED(hr))
	{
		decoder->Release();
		return hr;
	}

	hr = converter->Initialize(
		frameDecode,
		GUID_WICPixelFormat32bppPBGRA,
		WICBitmapDitherTypeNone,
		0, 0.0, WICBitmapPaletteTypeCustom);
	if (FAILED(hr))
	{
		decoder->Release();
		frameDecode->Release();
		converter->Release();
		return hr;
	}





	hr = target->CreateBitmapFromWicBitmap(converter, bitmap);


	decoder->Release();
	frameDecode->Release();
	converter->Release();

	return hr;
}

HRESULT D2DCreateCompatibleRt(ID2D1BitmapRenderTarget* target)
{
	HRESULT hr;
	hr = D2DRt->CreateCompatibleRenderTarget(
		SizeF(WINSIZEX, WINSIZEY),
		SizeU(WINSIZEX, WINSIZEY),
		&target);
	if (FAILED(hr))
		return hr;
}



void D2DFontChange(LPCWSTR fontName)
{
	_fontName = fontName;
	wFactory->CreateTextFormat
	(
		_fontName,
		0,
		DWRITE_FONT_WEIGHT_REGULAR,
		DWRITE_FONT_STYLE_NORMAL,
		DWRITE_FONT_STRETCH_NORMAL,
		_size,
		L"ko",
		&textFormat
	);
}
void D2DFontChange(float size)
{
	_size = size;
	wFactory->CreateTextFormat
	(
		_fontName,
		0,
		DWRITE_FONT_WEIGHT_REGULAR,
		DWRITE_FONT_STYLE_NORMAL,
		DWRITE_FONT_STRETCH_NORMAL,
		_size,
		L"ko",
		&textFormat
	);
}

void D2DFontChange(LPCWSTR fontName, float size)
{
	_fontName = fontName;
	_size = size;
	wFactory->CreateTextFormat
	(
		_fontName,
		0,
		DWRITE_FONT_WEIGHT_REGULAR,
		DWRITE_FONT_STYLE_NORMAL,
		DWRITE_FONT_STRETCH_NORMAL,
		_size,
		L"ko",
		&textFormat
	);
}