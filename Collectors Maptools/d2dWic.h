#pragma once
#include <d2d1.h>
#include <d2d1helper.h>
#include <wincodec.h>
#include<dwrite.h>


#pragma comment(lib,"windowscodecs.lib")
#pragma comment (lib,"d2d1.lib")
#pragma comment(lib,"dwrite.lib")

HRESULT	D2DInit(HWND hWnd, int width, int height,	ID2D1Factory** factory, ID2D1HwndRenderTarget **Rt);
HRESULT WICInit(IWICImagingFactory** factory);
HRESULT DWInit(LPCWSTR fontName, float size, IDWriteFactory **factory, IDWriteTextFormat **format);
HRESULT D2DLoadBitMap(LPCWSTR fileName, ID2D1HwndRenderTarget* target, IWICImagingFactory* factory, ID2D1Bitmap** bitmap);
HRESULT D2DLoadBitMap(LPCWSTR fileName, ID2D1HwndRenderTarget* target, IWICImagingFactory* factory, ID2D1Bitmap** bitmap,
	UINT currentFrame, UINT* maxFrame, bool* isEnd);
HRESULT D2DLoadBitMap(LPCWSTR fileName, ID2D1BitmapRenderTarget* target, IWICImagingFactory* factory, ID2D1Bitmap** bitmap);
HRESULT D2DLoadBitMap(LPCWSTR fileName, ID2D1BitmapRenderTarget* target, IWICImagingFactory* factory, ID2D1Bitmap** bitmap,
	UINT currentFrame, UINT* maxFrame, bool* isEnd);
HRESULT D2DCreateCompatibleRt(ID2D1BitmapRenderTarget* target);

//���̷�Ʈ 2D �Լ�
extern ID2D1Factory*					D2DFactory;
extern ID2D1HwndRenderTarget*			D2DRt;
extern ID2D1DCRenderTarget*				Rts;
extern ID2D1BitmapRenderTarget*			BRt;

extern IWICImagingFactory*				WICFactory;
extern IWICFormatConverter*				ConvertedScrBmp;
extern ID2D1SolidColorBrush*			D2DBrush;

extern IDWriteFactory*		wFactory;
extern IDWriteTextFormat*	textFormat;



void D2DFontChange(LPCWSTR fontName, float size);
void D2DFontChange(LPCWSTR fontName, float size);

/*
//���̷�Ʈ 2D  ���� winMain�� ���������ʽÿ�
ID2D1Factory*					D2DFactory = NULL;
ID2D1HwndRenderTarget*			D2DRt = NULL;
IWICImagingFactory*				WICFactory = NULL;
IWICFormatConverter*			ConvertedScrBmp = NULL;
ID2D1Bitmap*					bitmap = NULL;
ID2D1Bitmap*					bitmap2 = NULL;

*/


/*
/////�ʱ�ȭ �Լ�

if (FAILED(D2DInit(_hWnd, WINSIZEX, WINSIZEY, &D2DFactory, &D2DRt)))
{
MessageBox(_hWnd, TEXT("Direct2D �ʱ�ȭ ����"), TEXT("����"), MB_ICONERROR);
return 0;
}
if (FAILED(WICInit(&WICFactory)))
{
MessageBox(0, "Imaging  Factory", 0, 0);
return false;
}
*/