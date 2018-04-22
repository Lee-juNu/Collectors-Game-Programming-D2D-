#include "stdafx.h"
#include "tileMap.h"


void tileMap::allDraw()
{
	this->backGroundDraw();
	this->tilesDraw();
	this->btnDraw();
}


void tileMap::backGroundDraw()
{
	ID2D1Bitmap* tempBitmap;
	_rtBG->BeginDraw();
	_rtBG->Clear(ColorF(ColorF(0, 0, 0, 0)));
	IMAGEMANAGER->D2DRender("배경", _rtBG);
	IMAGEMANAGER->D2DRender("타일맵틀", _rtBG); //0,0
	_rtBG->EndDraw();
	_rtBG->GetBitmap(&tempBitmap);

	

	D2DRt->DrawBitmap(tempBitmap);

}


void tileMap::tilesDraw()	  
{
	string keyName;
	
	_rtTile->BeginDraw();
	_rtTile->Clear(ColorF(ColorF(0, 0, 0, 0)));

	for (int j = 0; j < TILEAREAX * TILEAREAY; j++)
	{
		int i = 0;
		if (j>=TILEAREAX)
		{
			i = j % TILEAREAX + (j/ TILEAREAX)*TILEX;
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


	int tileX;
	int tileY;
	switch (_currentMapMode)
	{
	case MAP_GRASS:
		keyName = "타일1";
		break;
	case MAP_FULL:
		keyName = "타일2";
		break;
	case MAP_WATER:
		keyName = "타일3";
		break;
	}
	if (_currentMapMode == MAP_WATER)
	{
		tileX = IMAGEMANAGER->D2DfindFrameImage(keyName)->getFrameX();
		tileY = IMAGEMANAGER->D2DfindFrameImage(keyName)->getFrameY();
	}
	else
	{
		tileX = IMAGEMANAGER->D2DfindImage(keyName)->getFrameX();
		tileY = IMAGEMANAGER->D2DfindImage(keyName)->getFrameY();
	}


	bool isGif = false;
	if (_currentMapMode == MAP_WATER) isGif = true;
	//샘플타일들의 지형 속성을 정해줄때 자신이 맞으면 알파값 1 아니면 0.5로 구분짓기 위해서 만약 SMTR모드가 아니면 그냥 비춰주기
	if (_currentSelect == SEL_SMTR || _currentSelect  == SEL_SMOBJ)
	{
		for (int i = 0; i < tileX * tileY; i++)
		{
			if ((_smTile[i].terrain == _currentSmTrSel && _currentSelect == SEL_SMTR) ||
				(_smTile[i].obj == _currentSmObjSel	  && _currentSelect == SEL_SMOBJ))
			{
				if (isGif)
				{
					IMAGEMANAGER->D2DGifFrameRender(keyName, _rtTile,
						_smTile[i].rcTile.left,
						_smTile[i].rcTile.top,
						i%tileX, i / tileX, 0);
					continue;
				}
				IMAGEMANAGER->D2DFrameRender(keyName, _rtTile,
					_smTile[i].rcTile.left, 
					_smTile[i].rcTile.top,
					i%tileX, i / tileX);
			}
			else
			{
				if (isGif)
				{
					IMAGEMANAGER->D2DGifFrameRender(keyName, _rtTile,
						_smTile[i].rcTile.left,
						_smTile[i].rcTile.top,
						i%tileX, i / tileX, 0,0.5);
					continue;
				}
				IMAGEMANAGER->D2DFrameRender(keyName, _rtTile,
					_smTile[i].rcTile.left,
					_smTile[i].rcTile.top,
					i%tileX, i / tileX,0.5);
			}
		}
	}
	else
	{ 
			for (int i = 0; i < tileX * tileY; i++)
			{

				if (isGif)
				{
					IMAGEMANAGER->D2DGifFrameRender(keyName, _rtTile,
						_smTile[i].rcTile.left,
						_smTile[i].rcTile.top,
						i%tileX, 
						i / tileX,
						0);
					wchar_t str[128];
					textFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
					swprintf_s(str, 128, L"%0.0d", _smTile[i].gifSpeed);
					D2DWrite(str, _rtTile, _smTile[i].rcTile);
					textFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);
				}
				else
				{
					IMAGEMANAGER->D2DFrameRender(keyName, _rtTile,
						_smTile[i].rcTile.left,
						_smTile[i].rcTile.top,
						i%tileX,
						i / tileX);
				}

			}
	}
	_rtTile->EndDraw();

	ID2D1Bitmap* tempBitmap;
	_rtTile->GetBitmap(&tempBitmap);
	D2DRt->DrawBitmap(tempBitmap);

	
}


void tileMap::btnDraw()		  
{
	_rtUI->BeginDraw();
	_rtUI->Clear(ColorF(ColorF(0, 0, 0, 0)));

	IMAGEMANAGER->D2DRender("세이브", _rtUI,_saveBtn.rc.left, _saveBtn.rc.top);
	IMAGEMANAGER->D2DRender("로드", _rtUI, _loadBtn.rc.left, _loadBtn.rc.top);
	IMAGEMANAGER->D2DRender("샘플셀렉트", _rtUI, _selSmSetBtn.rc.left, _selSmSetBtn.rc.top);
	IMAGEMANAGER->D2DRender("타일셀렉트", _rtUI, _selTileSetBtn.rc.left, _selTileSetBtn.rc.top);
	IMAGEMANAGER->D2DRender("OBJ_SEL", _rtUI, _selOBJSetBtn.rc.left, _selOBJSetBtn.rc.top);

	if (_currentSelect == SEL_SMTR)
	{
		IMAGEMANAGER->D2DRender("TR_GRASS",_rtUI, _selSmTileGRASS.rc.left, _selSmTileGRASS.rc.top);
		IMAGEMANAGER->D2DRender("TR_WATER",_rtUI, _selSmTileWATER.rc.left, _selSmTileWATER.rc.top);
	
	}
	if (_currentSelect == SEL_SMOBJ)
	{
		IMAGEMANAGER->D2DRender("OBJ_NONE", _rtUI, _selSmObjNONE.rc.left, _selSmObjNONE.rc.top);
		IMAGEMANAGER->D2DRender("OBJ_BLOCK", _rtUI, _selSmObjBLOCK.rc.left, _selSmObjBLOCK.rc.top);
		IMAGEMANAGER->D2DRender("리스폰", _rtUI, _responeBtn.rc.left, _responeBtn.rc.top);
	}

	for (int i = 0; i < 3; i++)
	{
		IMAGEMANAGER->D2DRender("BUTTONBK", _rtUI, _selTileMap[i].rc.left, _selTileMap[i].rc.top);
		wchar_t str[128] = L"TILE %d";
		swprintf_s(str,128, L"TILE %d", i);


		D2DFontChange(L"명조",20);
		textFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
		D2DBrush->SetColor(D2D1::ColorF(ColorF(255, 255, 255)));
		D2DWrite(str, _rtUI, _selTileMap[i].rc);
	}


	IMAGEMANAGER->D2DRender("BUTTONBK", _rtUI, _selSmTileFrameSpeed.rc.left, _selSmTileFrameSpeed.rc.top);
	wchar_t str[128] = L"TILESPEED";
	D2DWrite(str, _rtUI, _selSmTileFrameSpeed.rc);


	textFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_TRAILING);
	swprintf_s(str, 128, L"현재 타일 속도는: %0.1f 입니다.", _currentSpeed);
	D2DBrush->SetColor(D2D1::ColorF(ColorF(120, 120, 0)));
	D2DWrite(str, _rtUI, 0, 60, WINSIZEX, WINSIZEY);
	D2DBrush->SetColor(D2D1::ColorF(ColorF(255, 255, 255)));
	textFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);
	_rtUI->EndDraw();

	ID2D1Bitmap* tempBitmap;
	_rtUI->GetBitmap(&tempBitmap);


	D2DRt->DrawBitmap(tempBitmap);
}
