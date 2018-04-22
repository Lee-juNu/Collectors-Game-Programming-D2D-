#include "stdafx.h"
#include "d2dWic.h"

inline POINT PointMake(int x, int y)
{
	POINT pt = { x, y };

	return pt;
}

//선 그려주는 매크로            시작점 X, Y     끝점 X, Y
inline void LineMake(HDC hdc, int x1, int y1, int x2, int y2)
{
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
}

//RECT
inline RECT RectMake(int x, int y, int width, int height)
{
	RECT rc = { x, y, x + width, y + height };

	return rc;
}

inline RECT RectMakeCenter(int x, int y, int width, int height)
{
	RECT rc = { x - (width / 2), y - (height / 2), x + (width / 2), y + (height / 2) };

	return rc;
}

//사각형 그려주는 매크로

//									시작점 X, Y    가로크기,   세로크기
inline void RectangleMake(HDC hdc, int x, int y, int width, int height)
{
	Rectangle(hdc, x, y, x + width, y + height);
}

//										 중점 X  Y         가로크기   세로크기
inline void RectangleMakeCenter(HDC hdc, int x, int y, int width, int height)
{
	Rectangle(hdc, x - (width / 2), y - (height / 2), x + (width / 2), y + (height / 2));
}

//원 그려주는 매크로

//                               시작좌표 X, Y    가로크기   세로크기
inline void EllipseMake(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x, y, x + width, y + height);
}

inline void EllipseMakeCenter(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x - (width / 2), y - (height / 2), x + (width / 2), y + (height / 2));
}


inline void D2DRectDraw(ID2D1BitmapRenderTarget* target, RECT rc)
{
	ID2D1SolidColorBrush* Brush;
	D2D1_RECT_F tempRc;


	D2DRt->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF(255, 0, 0)), &Brush);

	tempRc.left = rc.left;
	tempRc.top = rc.top;
	tempRc.right = rc.right;
	tempRc.bottom = rc.bottom;
	target->DrawRectangle(tempRc, Brush);
}
inline void D2DRectDraw(ID2D1BitmapRenderTarget* target, float left,float top ,float right, float bottom)
{
	ID2D1SolidColorBrush* Brush;
	D2D1_RECT_F tempRc;

	D2DRt->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF(255,0,0)),&Brush);

	tempRc.left = left;
	tempRc.top = top;
	tempRc.right = right;
	tempRc.bottom = bottom;
	target->DrawRectangle(tempRc, Brush);
}
inline void D2DWrite(wchar_t* str, ID2D1BitmapRenderTarget* target, RECT rc)
{
	D2D1_RECT_F rcf;
	rcf.left = rc.left;
	rcf.right = rc.right;
	rcf.bottom = rc.bottom;
	rcf.top = rc.top;

	target->DrawTextA(str, wcslen(str), textFormat, rcf, D2DBrush);
}

inline void D2DWrite(wchar_t* str, ID2D1BitmapRenderTarget* target, float x, float y, float width=1000, float height=1000)
{
	target->DrawTextA(str, wcslen(str), textFormat, D2D1::RectF(x,y,x+width,y+height),D2DBrush);
}




inline void D2DRectDraw(ID2D1HwndRenderTarget* target, RECT rc)
{
	ID2D1SolidColorBrush* Brush;
	D2D1_RECT_F tempRc;


	D2DRt->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF(255, 0, 0)), &Brush);

	tempRc.left = rc.left;
	tempRc.top = rc.top;
	tempRc.right = rc.right;
	tempRc.bottom = rc.bottom;
	target->DrawRectangle(tempRc, Brush);
}
inline void D2DRectDraw(ID2D1HwndRenderTarget* target, float left, float top, float right, float bottom)
{
	ID2D1SolidColorBrush* Brush;
	D2D1_RECT_F tempRc;

	D2DRt->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF(255, 0, 0)), &Brush);

	tempRc.left = left;
	tempRc.top = top;
	tempRc.right = right;
	tempRc.bottom = bottom;
	target->DrawRectangle(tempRc, Brush);
}
inline void D2DWrite(wchar_t* str, ID2D1HwndRenderTarget* target, RECT rc)
{
	D2D1_RECT_F rcf;
	rcf.left = rc.left;
	rcf.right = rc.right;
	rcf.bottom = rc.bottom;
	rcf.top = rc.top;

	target->DrawTextA(str, wcslen(str), textFormat, rcf, D2DBrush);
}

inline void D2DWrite(wchar_t* str, ID2D1HwndRenderTarget* target, float x, float y, float width = 1000, float height = 1000)
{
	target->DrawTextA(str, wcslen(str), textFormat, D2D1::RectF(x, y, x + width, y + height), D2DBrush);
}

