#include "stdafx.h"
#include "tileMap.h"


void tileMap::gameStart()
{
	gameTileInit();
}
void tileMap::gameTileInit()
{
	for (int i = 0; i < TILEX* TILEY; i++)
	{
		_tiles[i].rc.left -= 25;
		_tiles[i].rc.right -= 25;
		_tiles[i].rc.bottom -= 25;
		_tiles[i].rc.top -= 25;
	}
}
void tileMap::gameRender()
{
	string keyName;

	_rtTile->BeginDraw();
	_rtTile->Clear(ColorF(ColorF(0, 0, 0, 0)));

	for (int j = 0; j < TILEAREAX * TILEAREAY; j++)
	{
		int i = 0;
		if (j >= TILEAREAX)
		{
			i = j % TILEAREAX + (j / TILEAREAX)*TILEX;
		}
		else
		{
			i = j;
		}
		i += _userFocus;
		switch (_tiles[i].mapMode)
		{
		case MAP_GRASS:
			keyName = "타일1";
			break;
		case MAP_FULL:
			keyName = "타일2";
			break;
		case MAP_WATER:
			keyName = "타일3";

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


			wchar_t str[128];
			textFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
			swprintf_s(str, 128, L"%0.0f", _tiles[i].gifSpeed);
			D2DWrite(str, _rtTile, _tiles[i].rc);
			textFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);

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
