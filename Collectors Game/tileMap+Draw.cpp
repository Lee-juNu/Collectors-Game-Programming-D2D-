#include "stdafx.h"
#include "tileMap.h"


void tileMap::allDraw()
{
	this->tilesDraw();
}

void tileMap::tilesDraw()	  
{
	string keyName;
	//타일Rt에 그린다
	_rtTile->BeginDraw();

	//한번 할때마다 투명색비트로 클리어 해준다.
	_rtTile->Clear(ColorF(ColorF(0, 0, 0, 0)));



	//타일 에리어만큼만 반복해준다
	for (int j = 0; j < TILEAREAX * TILEAREAY; j++)
	{
		int i = 0;


		//타일 에리어X보다 반복변수가 높으면 내려가도록 그래야 정사각형 모양으로 그려지니까
		if (j>=TILEAREAX)
		{
			i = j % TILEAREAX + (j/ TILEAREAX)*TILEX;
		}
		else
		{
			//아니면i=j로
			i = j;
		}

		//이제 유저의 좌표를 값으로 바꾼거를 더하여 i에다가 더하여 구해질 좌표를 구한다.
		i += _userFocus;



		//이제부터 진짜 그리기 인데 일단 그 타일의 맵모드를 알아낸다
		switch (_tiles[i].mapMode)
		{

			//그 후 맵모드에 맡게 타일의 이미지 키값을 찾아주고
		case MAP_GRASS:
			keyName = "타일1";
			break;
		case MAP_FULL:
			keyName = "타일2";
			break;
		case MAP_WATER:
			keyName = "타일3";

			//gif는 워터밖에 안해놨으니까 여기서 프레임 렌더링을 땡긴다.
			IMAGEMANAGER->D2DGifFrameRender(
				keyName, _rtTile,
				_tiles[i].rc.left,
				_tiles[i].rc.top,
				_tiles[i].terrainFrameX,
				_tiles[i].terrainFrameY, _tiles[i].gifFrame);

			if (_tiles[i].obj != OBJ_NONE)
			{
				IMAGEMANAGER->D2DGifFrameRender(
					keyName, _rtTile,
					_tiles[i].rc.left,
					_tiles[i].rc.top,
					_tiles[i].objFrameX,
					_tiles[i].objFrameY, _tiles[i].gifFrame);
			}




			break;
		default:
			break;
		}

		//GIF이미지는 위에서 랜더링 했으니까 그냥 넘어가도록!
		if (_tiles[i].mapMode == MAP_WATER) continue;


		IMAGEMANAGER->D2DFrameRender(
			keyName, _rtTile,
			_tiles[i].rc.left,
			_tiles[i].rc.top,
			_tiles[i].terrainFrameX,
			_tiles[i].terrainFrameY);

		if (_tiles[i].obj != OBJ_NONE)
		{
			IMAGEMANAGER->D2DFrameRender(
				keyName, _rtTile,
				_tiles[i].rc.left,
				_tiles[i].rc.top,
				_tiles[i].objFrameX,
				_tiles[i].objFrameY);
		}
	}

	_rtTile->EndDraw();

	ID2D1Bitmap* tempBitmap;
	_rtTile->GetBitmap(&tempBitmap);
	D2DRt->DrawBitmap(tempBitmap);

	
}