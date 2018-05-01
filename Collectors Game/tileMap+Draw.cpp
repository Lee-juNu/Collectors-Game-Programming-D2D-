#include "stdafx.h"
#include "tileMap.h"


void tileMap::allDraw()
{
	this->tilesDraw();
}

void tileMap::tilesDraw()	  
{
	string keyName;
	//Ÿ��Rt�� �׸���
	_rtTile->BeginDraw();

	//�ѹ� �Ҷ����� �������Ʈ�� Ŭ���� ���ش�.
	_rtTile->Clear(ColorF(ColorF(0, 0, 0, 0)));



	//Ÿ�� �����ŭ�� �ݺ����ش�
	for (int j = 0; j < TILEAREAX * TILEAREAY; j++)
	{
		int i = 0;


		//Ÿ�� ������X���� �ݺ������� ������ ���������� �׷��� ���簢�� ������� �׷����ϱ�
		if (j>=TILEAREAX)
		{
			i = j % TILEAREAX + (j/ TILEAREAX)*TILEX;
		}
		else
		{
			//�ƴϸ�i=j��
			i = j;
		}

		//���� ������ ��ǥ�� ������ �ٲ۰Ÿ� ���Ͽ� i���ٰ� ���Ͽ� ������ ��ǥ�� ���Ѵ�.
		i += _userFocus;



		//�������� ��¥ �׸��� �ε� �ϴ� �� Ÿ���� �ʸ�带 �˾Ƴ���
		switch (_tiles[i].mapMode)
		{

			//�� �� �ʸ�忡 �ð� Ÿ���� �̹��� Ű���� ã���ְ�
		case MAP_GRASS:
			keyName = "Ÿ��1";
			break;
		case MAP_FULL:
			keyName = "Ÿ��2";
			break;
		case MAP_WATER:
			keyName = "Ÿ��3";

			//gif�� ���͹ۿ� ���س����ϱ� ���⼭ ������ �������� �����.
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

		//GIF�̹����� ������ ������ �����ϱ� �׳� �Ѿ����!
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