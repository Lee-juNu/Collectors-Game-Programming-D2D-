#include "stdafx.h"
#include "player.h"
#include "tileMap.h"
#include "enemyManager.h"




//길어서 유배시켜놨습니다.
void player::focusSetting()
{
	//이건 타일맵이 유저반경으로 그려지도록 정보를 보내기 위한 포커스 포인트
	_player.userFocus.x = _player.x / 32;
	_player.userFocus.y = _player.y / 32;

	_tm->setFocus(_player.userFocus);



	//★여기부터
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
	//★여기까지는  유저의 렉트가 일정 범위를 빠져나가려고 했었을때 그부분에서 제한을 걸어서 유저의 렌더링범위를 구할 포인트
	//★ reLimitFocus는 유저를 중심으로한 에너미와 타일맵들을 그려줄때 유저가 제한 범위 이상으로 나갈때 안나갈때 왼쪽 오른쪽 등등 확인을 위한 포인트
	//★네이밍 센스가 좀 아쉬웠다 바꿀까 고민중 솔직히 이건 limit이라고 하긴 애매한거 같다. reLimit은 진짜 기억이 안났어...ㅠㅜ





	//여긴 위에서 종합한 정보를 토대로
	//키가 눌리면서 X축을 빠져나가려 하는가??? 맞다면 tm과 em의 렌더타겟을 맞게 그려줘라
	if (_reLimitFocus.x != 0 && _reLimitFocus.y == 0 && isKeyDown)
	{
		if (-WINSIZEX / 2 + _player.x - _reLimitFocus.x >= 0 && -WINSIZEX / 2 + _player.x - _reLimitFocus.x <= TILEX * TILESIZE - WINSIZEX)
		{
			_tm->getTileRt()->SetTransform(Matrix3x2F::Translation(WINSIZEX / 2 - _player.x + _reLimitFocus.x, WINSIZEY / 2 - _player.y - (WINSIZEX / 2 - _limitFocus.y)));
			_em->getRt()->SetTransform(Matrix3x2F::Translation(WINSIZEX / 2 - _player.x + _reLimitFocus.x, WINSIZEY / 2 - _player.y - (WINSIZEX / 2 - _limitFocus.y)));

		}
	}//아니다 Y축을 빠져나가려한다 하면 똑같이
	else if (_reLimitFocus.y != 0 && _reLimitFocus.x == 0 && isKeyDown2)
	{
		if (-WINSIZEX / 2 + _player.y - _reLimitFocus.y >= 0 && -WINSIZEY / 2 + _player.y - _reLimitFocus.y <= 2400)
		{
			_tm->getTileRt()->SetTransform(Matrix3x2F::Translation(WINSIZEX / 2 - _player.x - (WINSIZEX / 2 - _limitFocus.x), WINSIZEY / 2 - _player.y + _reLimitFocus.y));
			_em->getRt()->SetTransform(Matrix3x2F::Translation(WINSIZEX / 2 - _player.x - (WINSIZEX / 2 - _limitFocus.x), WINSIZEY / 2 - _player.y + _reLimitFocus.y));

		}
	}//아니다 둘다 걸렸다 대각선부분에 걸린거지 그럴때도 역시 수식에 맞게
	else  if (_reLimitFocus.x != 0 && _reLimitFocus.y != 0)
	{
		_tm->getTileRt()->SetTransform(Matrix3x2F::Translation(WINSIZEX / 2 - _player.x + _reLimitFocus.x, WINSIZEY / 2 - _player.y + _reLimitFocus.y));
		_em->getRt()->SetTransform(Matrix3x2F::Translation(WINSIZEX / 2 - _player.x + _reLimitFocus.x, WINSIZEY / 2 - _player.y + _reLimitFocus.y));
	}

	//플레이어가 실질적으로 있는 렉트
	_player.rc = RectMakeCenter(_player.x, _player.y, 32, 32);
	//플레이어가 그려지는 렉트
	_renderRc = RectMakeCenter(_limitFocus.x, _limitFocus.y, 32, 32);
}