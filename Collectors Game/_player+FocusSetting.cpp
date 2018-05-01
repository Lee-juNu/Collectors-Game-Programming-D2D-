#include "stdafx.h"
#include "player.h"
#include "tileMap.h"
#include "enemyManager.h"




//�� ������ѳ����ϴ�.
void player::focusSetting()
{
	//�̰� Ÿ�ϸ��� �����ݰ����� �׷������� ������ ������ ���� ��Ŀ�� ����Ʈ
	_player.userFocus.x = _player.x / 32;
	_player.userFocus.y = _player.y / 32;

	_tm->setFocus(_player.userFocus);



	//�ڿ������
	if (_limitFocus.x <= 200 && -WINSIZEX / 2 + _player.x + 200 >= 0)
	{
		_limitFocus.x = 200;
		_reLimitFocus.x = -200;
	}
	else if (_limitFocus.x >= WINSIZEX - 200 && -WINSIZEX / 2 + _player.x - 200 <= TILEX * TILESIZE - WINSIZEX)
	{
		_limitFocus.x = WINSIZEX - 200;
		_reLimitFocus.x = 200;
	}
	else
	{
		_reLimitFocus.x = 0;
	}


	if (_limitFocus.y <= 200 && -WINSIZEY / 2 + _player.y + 200 >= 0)
	{
		_limitFocus.y = 200;
		_reLimitFocus.y = -200;
	}
	else if (_limitFocus.y >= WINSIZEX - 200 && -WINSIZEY / 2 + _player.y - 200 <= TILEX * TILESIZE - WINSIZEY)
	{
		_limitFocus.y = WINSIZEY - 200;
		_reLimitFocus.y = 200;
	}
	else
	{
		_reLimitFocus.y = 0;
	}
	//�ڿ��������  ������ ��Ʈ�� ���� ������ ������������ �߾����� �׺κп��� ������ �ɾ ������ ������������ ���� ����Ʈ
	//�� reLimitFocus�� ������ �߽������� ���ʹ̿� Ÿ�ϸʵ��� �׷��ٶ� ������ ���� ���� �̻����� ������ �ȳ����� ���� ������ ��� Ȯ���� ���� ����Ʈ
	//�ڳ��̹� ������ �� �ƽ����� �ٲܱ� ����� ������ �̰� limit�̶�� �ϱ� �ָ��Ѱ� ����. reLimit�� ��¥ ����� �ȳ���...�Ф�





	//���� ������ ������ ������ ����
	//Ű�� �����鼭 X���� ���������� �ϴ°�??? �´ٸ� tm�� em�� ����Ÿ���� �°� �׷����
	if (_reLimitFocus.x != 0 && _reLimitFocus.y == 0 && isKeyDown)
	{
		if (-WINSIZEX / 2 + _player.x - _reLimitFocus.x >= 0 && -WINSIZEX / 2 + _player.x - _reLimitFocus.x <= TILEX * TILESIZE - WINSIZEX)
		{
			_tm->getTileRt()->SetTransform(Matrix3x2F::Translation(WINSIZEX / 2 - _player.x + _reLimitFocus.x, WINSIZEY / 2 - _player.y - (WINSIZEX / 2 - _limitFocus.y)));
			_em->getRt()->SetTransform(Matrix3x2F::Translation(WINSIZEX / 2 - _player.x + _reLimitFocus.x, WINSIZEY / 2 - _player.y - (WINSIZEX / 2 - _limitFocus.y)));

		}
	}//�ƴϴ� Y���� �����������Ѵ� �ϸ� �Ȱ���
	else if (_reLimitFocus.y != 0 && _reLimitFocus.x == 0 && isKeyDown2)
	{
		if (-WINSIZEX / 2 + _player.y - _reLimitFocus.y >= 0 && -WINSIZEY / 2 + _player.y - _reLimitFocus.y <= 2400)
		{
			_tm->getTileRt()->SetTransform(Matrix3x2F::Translation(WINSIZEX / 2 - _player.x - (WINSIZEX / 2 - _limitFocus.x), WINSIZEY / 2 - _player.y + _reLimitFocus.y));
			_em->getRt()->SetTransform(Matrix3x2F::Translation(WINSIZEX / 2 - _player.x - (WINSIZEX / 2 - _limitFocus.x), WINSIZEY / 2 - _player.y + _reLimitFocus.y));

		}
	}//�ƴϴ� �Ѵ� �ɷȴ� �밢���κп� �ɸ����� �׷����� ���� ���Ŀ� �°�
	else  if (_reLimitFocus.x != 0 && _reLimitFocus.y != 0)
	{
		_tm->getTileRt()->SetTransform(Matrix3x2F::Translation(WINSIZEX / 2 - _player.x + _reLimitFocus.x, WINSIZEY / 2 - _player.y + _reLimitFocus.y));
		_em->getRt()->SetTransform(Matrix3x2F::Translation(WINSIZEX / 2 - _player.x + _reLimitFocus.x, WINSIZEY / 2 - _player.y + _reLimitFocus.y));
	}

	//�÷��̾ ���������� �ִ� ��Ʈ
	_player.rc = RectMakeCenter(_player.x, _player.y, 32, 32);
	//�÷��̾ �׷����� ��Ʈ
	_renderRc = RectMakeCenter(_limitFocus.x, _limitFocus.y, 32, 32);
}