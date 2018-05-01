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
	//���漱���
	tileMap* _tm;
	enemyManager* _em;

private:
	tagPlayer _player;
	ID2D1BitmapRenderTarget* Rt;

	POINT	  _limitFocus;			//���������� �������ִ� ����Ʈ
	POINT	  _reLimitFocus;		//����� ������ �������ִ� ����Ʈ
	POINT	  _bgFocus;				//����� ������ ����ؼ� ������ ������ ���� �����Ѵ�!

	//������ ������ �� Rc�̴�
	RECT	  _renderRc;

private:
	//1�� �����ʰ� ����
	//2�� ���Ʒ��� Ű�� �Է½� true�� �ٲ��� focusSetting�Լ����� ���ȴ�.

	bool isKeyDown = false;
	bool isKeyDown2 = false;

public:
	player();
	~player();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	
	//���ӿ��� ���ȵǰ� �����ڸ���϶�
	//�ڽ��� ����ִ� Ÿ���� ��Ȯ�� Ÿ�� ������ ������ǥ�� Ȯ���ϱ����� ������
	void tempRender();
	

	//������ ���� Ű�Է��� �����ϴ� �Լ�
	void keyInput();
	//������ �������� ������ ����Ÿ���� �׷��� �Լ�
	void focusSetting();






	//�� �ٸ� Ŭ������ �ּҸ� �����ͼ� ���漱���� �Ѵ�.
	void setLinkAdressTileMap(tileMap* tm) { _tm = tm; }
	void setLinkAdressEnemy(enemyManager* em) { _em = em; }
	
	

	//������
	tagPlayer getPlayer() { return _player; }
	POINT getBgFocus() { return _bgFocus; }

	//������


};

