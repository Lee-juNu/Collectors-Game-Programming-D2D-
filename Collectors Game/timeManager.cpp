#include "stdafx.h"
#include "timeManager.h"


timeManager::timeManager()
	: _timer(NULL)
{
}


timeManager::~timeManager()
{

}

HRESULT timeManager::init(void)		
{
	_timer = new timer;
	_timer->init();

	return S_OK;
}

void timeManager::release(void)		
{
	if (_timer != NULL)
	{
		SAFE_DELETE(_timer);
	}
}

void timeManager::update(float lock)
{
	if (_timer != NULL)
	{
		_timer->tick(lock);
	}
}

void timeManager::render(HDC hdc)
{
	wchar_t str[128] = L"TILE %d";

	//char str[256];
	string frameRate;
	//font 백그라운드 모드는 2개가 있다
	//TRANSPARENT : 투명
	//OPAQUE : 불투명
	//SetBkMode(hdc, TRANSPARENT);


#ifdef _DEBUG
	{
		D2DFontChange(L"명조",12);
		textFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_TRAILING);
		swprintf_s(str, 128, L"framePerSec (FPS) : %d", _timer->getFrameRate());
		D2DWrite(str, D2DRt, 0,0,WINSIZEX,WINSIZEY);

		swprintf_s(str, 128, L"worldTime : %f", _timer->getWorldTime());
		D2DWrite(str, D2DRt, 0,20, WINSIZEX , WINSIZEY);

		swprintf_s(str, 128, L"elapsedTime : %f", _timer->getElapsedTime());
		D2DWrite(str, D2DRt, 0,40, WINSIZEX , WINSIZEY);
		textFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);
	}
#else
	{
		swprintf_s(str, 128, L"framePerSec (FPS) : %d", _timer->getFrameRate());
		D2DWrite(str, D2DRt, WINSIZEX - 200, 0);
		//wsprintf(str, "framePerSec (FPS) : %d", _timer->getFrameRate());
		//TextOut(hdc, 0, 0, str, strlen(str));
	}
#endif
}
