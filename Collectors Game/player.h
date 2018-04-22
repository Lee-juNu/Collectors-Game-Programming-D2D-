#pragma once
#include "gameNode.h"

struct tagPlayer
{
	RECT rc;			//�÷��̾� ��Ʈ �̰� ������ �浹�ǰ�~~ ���̶� �ο� ��Ʈ�ô�
	POINT limitFocus;		//�÷��̾� ������ ��Ʈ �� ���ڴ� �׷��� �� �� ���� ���� ���̷���. ���� ��� ���� �̻��� ���Ѿ��.
	POINT userFocus;	//�̰� ������ ����ִ��� ����Ʈ�� ��Ƽ� Ÿ�Ϸ� ���� �ֺ��� ������ �ϱ� ���ؼ� ������־���
	
	float x;			// �� ���� ��Ʈ�� �׸���~~ ����RC�� �׸���~~ ������Ŀ���� ���� �⺻ xy�̽ô�.
	float y;
};
class tileMap;
class player :	public gameNode
{
private:
	tagPlayer _player;
	tileMap* _tm;

	ID2D1BitmapRenderTarget* Rt;

	POINT	  _limitFocus;
	POINT	  _reLimitFocus;
	RECT	  _renderRc;
	bool test;
public:
	player();
	~player();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	void setLinkAdressTileMap(tileMap* tm) { _tm = tm; }
	tagPlayer getPlayer() { return _player; }
};

