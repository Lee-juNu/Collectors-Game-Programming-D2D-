#include "stdafx.h"
#include "tileMap.h"


void tileMap::allInit()
{
	this->variableInit();
	this->imageInit();//�̹������� �߰����ش�.
	this->smTileInit();// ����Ÿ�ϵ��� �ʱ�ȭ
	this->tileInit();//�� Ÿ�ϵ��� �ʱ�ȭ
	this->btnInit();//��ư���� �ʱ�ȭ
	this->RtInit();
}

void tileMap::variableInit()
{
	_currentSelect = SEL_TR;
	_currentSmTrSel = TR_GRASS;
	_currentMapMode = MAP_GRASS;
	_currentFrameX = 0;
	_currentFrameY = 0;


	//�����ӽ��ǵ���������!!
	_currentSpeed = 2;

	//����Ÿ�� ��������
	_smStartX = 25;
	_smStartY = 34;




	_userFocusPoint.x = 0;
	_userFocusPoint.y = 0;
	_userFocus = (_userFocusPoint.x %TILEAREAX)  + _userFocusPoint.y*TILEX;

	_frameCount		= 0;
	_gifFrame		= 0;


	_isGameStart = false; //���� �ȵ�
}

void tileMap::imageInit()
{
	//����� ������ �ɽ��ϴϱ�
	IMAGEMANAGER->D2DAddImage("���", L".//Image//backGround.BMP", WINSIZEX, WINSIZEY);

	//�̹����� �̻ڰ� �ϱ����� Ʋ
	IMAGEMANAGER->D2DAddImage("Ÿ�ϸ�Ʋ", L".//Image//tileMapFrame.bmp", 690, 690);
	IMAGEMANAGER->D2DAddImage("����Ʋ", L".//Image//smTileMapFrame.BMP", 478, 313);

	//���� Ÿ�ϰ� �׷��� Ÿ���� ���� ��¥��� �̹���
	IMAGEMANAGER->D2DAddFrameimage("Ÿ��1", L".//Image//tileMap.bmp",  13, 8);
	IMAGEMANAGER->D2DAddFrameimage("Ÿ��2", L".//Image//tileMap2.png", 23, 14);
	IMAGEMANAGER->D2DAddGifFrameImage("Ÿ��3",   L".//Image//tileMap3.gif",9,13);

	//����� �ƿ���gif	������ �̹����� �����ִ°ɷ� �Ǵ�.
	IMAGEMANAGER->D2DAddGifImage("�ƿ���", L".//�ƿ���.gif");

	//���̺� �ε� ��ư ���۳���
	IMAGEMANAGER->D2DAddImage("���̺�",		L".//Image//save.BMP", 84, 34);
	IMAGEMANAGER->D2DAddImage("�ε�",		L".//Image//Load.BMP", 84, 34);
	IMAGEMANAGER->D2DAddImage("������",		L".//Image//Respone.BMP", 84, 34);
	IMAGEMANAGER->D2DAddImage("Ÿ�ϼ���Ʈ", L".//Image//tileSet.BMP", 84, 34);
	IMAGEMANAGER->D2DAddImage("���ü���Ʈ", L".//Image//smSelect.BMP", 84, 34);

	IMAGEMANAGER->D2DAddImage("TR_GRASS", L".//Image//GRASS.BMP", 84, 34);
	IMAGEMANAGER->D2DAddImage("TR_WATER", L".//Image//WATER.BMP", 84, 34);


	IMAGEMANAGER->D2DAddImage("OBJ_SEL", L".//Image//Object.bmp", 84, 34);
	IMAGEMANAGER->D2DAddImage("OBJ_NONE", L".//Image//Button//OBJ_NONE.bmp", 84, 34);
	IMAGEMANAGER->D2DAddImage("OBJ_BLOCK", L".//Image//Button//OBJ_BLOCK.bmp", 84, 34);
	IMAGEMANAGER->D2DAddImage("BUTTONBK", L".//Image//Button//ButtonBk.bmp", 84, 34);
}



void tileMap::tileInit()
{
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		_tiles[i].rc = RectMake
		(
			25 + (TILESIZE * (i%TILEX)),
			25 + (TILESIZE * (i / TILEX)),
			TILESIZE, TILESIZE
		);
		_tiles[i].mapMode = MAP_GRASS;

		_tiles[i].terrain = TR_GRASS;
		_tiles[i].terrainFrameX = 0;
		_tiles[i].terrainFrameY = 0;

		_tiles[i].obj = OBJ_NONE;
		_tiles[i].objFrameX = 0;
		_tiles[i].objFrameY = 0;

		_tiles[i].gifFrame = 0;
		_tiles[i].gifCount = 0;
		_tiles[i].gifSpeed = _currentSpeed;

	}

}
void tileMap::smTileInit()
{
	for (int ii = 0; ii < 3; ii++)
	{
		switch (ii)
		{
		case MAP_GRASS:
			_smTileX = IMAGEMANAGER->D2DfindImage("Ÿ��1")->getFrameX();
			_smTileY = IMAGEMANAGER->D2DfindImage("Ÿ��1")->getFrameY();
			break;
		case MAP_FULL:
			_smTileX = IMAGEMANAGER->D2DfindImage("Ÿ��2")->getFrameX();
			_smTileY = IMAGEMANAGER->D2DfindImage("Ÿ��2")->getFrameY();
			break;
		case MAP_WATER:
			_smTileX = IMAGEMANAGER->D2DfindFrameImage("Ÿ��3")->getFrameX();
			_smTileY = IMAGEMANAGER->D2DfindFrameImage("Ÿ��3")->getFrameY();
			break;
		default:
			break;
		}

		for (int i = 0; i < _smTileX * _smTileY; i++)
		{
			_smTile[i].rcTile = RectMake
			(690 +
				(TILESIZE * (i%_smTileX)
					+ i % _smTileX) + _smStartX
				,
				TILESIZE*(i / _smTileX) + i / _smTileX + _smStartY,
				TILESIZE, TILESIZE);

			_smTile[i].terrain = TR_GRASS;
			_smTile[i].obj = OBJ_NONE;
			_smTile[i].terrainFrameX = i % _smTileX;
			_smTile[i].terrainFrameY = i / _smTileX;
			_smTile[i].gifSpeed = _currentSpeed;
		}
	}
}




void tileMap::btnInit()
{
	_saveBtn.bitmap = IMAGEMANAGER->D2DfindImage("���̺�");
	_saveBtn.rc = RectMake(WINSIZEX - 84 * 2, 690 - 34, _saveBtn.bitmap->getWidth(), _saveBtn.bitmap->getHeight());


	_loadBtn.bitmap = IMAGEMANAGER->D2DfindImage("�ε�");
	_loadBtn.rc = RectMake(WINSIZEX - 84, 690 - 34, _loadBtn.bitmap->getWidth(), _loadBtn.bitmap->getHeight());


	_selSmSetBtn.bitmap = IMAGEMANAGER->D2DfindImage("���ü���Ʈ");
	_selSmSetBtn.rc = RectMake(690, 690 - 34, _selSmSetBtn.bitmap->getWidth(), _selSmSetBtn.bitmap->getHeight());

	_selTileSetBtn.bitmap = IMAGEMANAGER->D2DfindImage("Ÿ�ϼ���Ʈ");
	_selTileSetBtn.rc = RectMake(690 + 84, 690 - 34, _selTileSetBtn.bitmap->getWidth(), _selTileSetBtn.bitmap->getHeight());

	_selSmTileGRASS.bitmap = IMAGEMANAGER->D2DfindImage("TR_GRASS");
	_selSmTileGRASS.rc = RectMake(WINSIZEX - 84, 0, _selSmTileGRASS.bitmap->getWidth(), _selSmTileGRASS.bitmap->getHeight());
	
	_selSmTileWATER.bitmap = IMAGEMANAGER->D2DfindImage("TR_WATER");
	_selSmTileWATER.rc = RectMake(WINSIZEX - 84, 34, _selSmTileWATER.bitmap->getWidth(), _selSmTileWATER.bitmap->getHeight());

	
	_selOBJSetBtn.bitmap = IMAGEMANAGER->D2DfindImage("OBJ_SEL");
	_selOBJSetBtn.rc = RectMake(690 + 84 * 2, 690 - 34, _selOBJSetBtn.bitmap->getWidth(), _selOBJSetBtn.bitmap->getHeight());


		
	_selSmObjNONE.bitmap = IMAGEMANAGER->D2DfindImage("OBJ_NONE");
	_selSmObjNONE.rc = RectMake(WINSIZEX - 84, 0, _selSmObjNONE.bitmap->getWidth(), _selSmObjNONE.bitmap->getHeight());

	_selSmObjBLOCK.bitmap = IMAGEMANAGER->D2DfindImage("OBJ_BLOCK");
	_selSmObjBLOCK.rc = RectMake(WINSIZEX - 84, 34, _selSmObjBLOCK.bitmap->getWidth(), _selSmObjBLOCK.bitmap->getHeight());

	_responeBtn.bitmap = IMAGEMANAGER->D2DfindImage("������");
	_responeBtn.rc = RectMake(WINSIZEX - 84, 68, _responeBtn.bitmap->getWidth(), _responeBtn.bitmap->getHeight());


	for (int i = 0; i < 3; i++)
	{
		_selTileMap[i].bitmap = IMAGEMANAGER->D2DfindImage("BUTTONBK");

		_selTileMap[i].rc = RectMake(690+i*84+25, 0, _selSmObjBLOCK.bitmap->getWidth(), _selSmObjBLOCK.bitmap->getHeight());
	}


	_selSmTileFrameSpeed.bitmap = IMAGEMANAGER->D2DfindImage("BUTTONBK");
	_selSmTileFrameSpeed.rc = RectMake(690 + 84 * 3, 690 - 34, _selSmTileFrameSpeed.bitmap->getWidth(), _selSmTileFrameSpeed.bitmap->getHeight());
}



void tileMap::RtInit()
{
	D2DRt->CreateCompatibleRenderTarget(&_rtTile);
	D2DRt->CreateCompatibleRenderTarget(&_rtUI);
	D2DRt->CreateCompatibleRenderTarget(&_rtBG);


}