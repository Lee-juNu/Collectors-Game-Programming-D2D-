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
	d3dParam.SwapEffect = D3DSWAPEFFECT_DISCARD; //�ø��� ����ۿ� ������ ���� �ʴ´�.
	d3dParam.EnableAutoDepthStencil = TRUE; //���� ���ٽ� ���� �ڵ� ����
	d3dParam.AutoDepthStencilFormat = D3DFMT_D16; //���� ����


	d3d = Direct3DCreate9(D3D_SDK_VERSION);


	D3DCAPS9 caps;
	d3d->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps);

	HRESULT hr = d3d->CreateDevice
	(
		D3DADAPTER_DEFAULT, //��� ����� �� ����Ʈ ����͸� ���
		D3DDEVTYPE_HAL, //����Ʈ����� �ϵ���� ���� ������ ���
		handle, //������ �ڵ�
		D3DCREATE_HARDWARE_VERTEXPROCESSING, //���� ������ �ϵ����� ó��
		&d3dParam, &device
	);



	ShowWindow(handle, commandShow); //�� ����� �����ϱ� ������ ���
	//UpdateWindow(handle); //������ ����
	//ShowCursor(isShowCursor); //Ŀ�� ����


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
 