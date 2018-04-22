#include "stdafx.h"
#include "graphics.h"


graphics::graphics(HINSTANCE hInstance,int cmdShow)
{
	commandShow = cmdShow;
	instance = hInstance;
}


graphics::~graphics()
{
}


void graphics::init(HWND handle)
{
	D3DPRESENT_PARAMETERS d3dParam;
	ZeroMemory(&d3dParam, sizeof(d3dParam));

	d3dParam.Windowed = isWindow;
	d3dParam.SwapEffect = D3DSWAPEFFECT_DISCARD; //플립시 백버퍼에 영향을 주지 않는다.
	d3dParam.EnableAutoDepthStencil = TRUE; //깊이 스텐실 버퍼 자동 생성
	d3dParam.AutoDepthStencilFormat = D3DFMT_D16; //버퍼 포맷


	d3d = Direct3DCreate9(D3D_SDK_VERSION);


	D3DCAPS9 caps;
	d3d->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps);

	HRESULT hr = d3d->CreateDevice
	(
		D3DADAPTER_DEFAULT, //듀얼 모니터 중 디폴트 모니터를 대상
		D3DDEVTYPE_HAL, //소프트웨어와 하드웨어 동시 렌더링 사용
		handle, //윈도우 핸들
		D3DCREATE_HARDWARE_VERTEXPROCESSING, //정점 정보를 하드웨어로 처리
		&d3dParam, &device
	);



	ShowWindow(handle, commandShow); //다 만들어 졌으니까 윈도우 출력
	//UpdateWindow(handle); //윈도우 갱신
	//ShowCursor(isShowCursor); //커서 설정


}


void graphics::render()
{
	device->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0xFFFFFFFF, 1.0f, 0);
	device->BeginScene();
	{


	}
	device->EndScene();
	device->Present(0, 0, 0, 0);
}
 