#pragma once
#include <d3d9.h>
#include <d3dx9.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "winmm.lib")

class graphics
{
private:

	HINSTANCE instance;
	LPWSTR className;
	LPSTR commandLine;
	int commandShow;

	HWND handle;

	POINT winSize = { WINSIZEX, WINSIZEY };
	DWORD winStyle = WS_OVERLAPPEDWINDOW | WS_VISIBLE;

	BOOL isWindow = TRUE;
	BOOL isShowCursor = TRUE;

	LPDIRECT3D9	d3d = NULL;
	LPDIRECT3DDEVICE9 device = NULL;
public:
	graphics();
	graphics(HINSTANCE hInstance, int cmdShow);
	
	~graphics();


	void init(HWND handle);
	void render();
};

