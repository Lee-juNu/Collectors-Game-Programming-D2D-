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
class enemyManager;
class tileMap;
class player :	public gameNode
{
private:
	tagPlayer _player;
	tileMap* _tm;
	enemyManager* _em;
	ID2D1BitmapRenderTarget* Rt;

	POINT	  _limitFocus;			//���������� �������ִ� ����Ʈ
	POINT	  _reLimitFocus;		//����� ������ �������ִ� ����Ʈ
	POINT	  _bgFocus;				//����� ������ ����ؼ� ������ ������ ���� �����Ѵ�!


	RECT	  _renderRc;

private:
	bool isKeyDown = false;
	bool isKeyDown2 = false;
public:
	player();
	~player();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	void tempRender();

	void keyInput();
	void focusSetting();







	void setLinkAdressTileMap(tileMap* tm) { _tm = tm; }
	void setLinkAdressEnemy(enemyManager* em) { _em = em; }
	
	
	tagPlayer getPlayer() { return _player; }
	POINT getBgFocus() { return _bgFocus; }
};

