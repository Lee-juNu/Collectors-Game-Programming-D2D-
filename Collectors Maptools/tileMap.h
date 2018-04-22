#pragma once
#include "tileNode.h"
#include <commdlg.h>
#include <commdlg.inl>
#include "gameNode.h"




enum SELECTMODE
{
	SEL_TR,
	SEL_OBJ,
	SEL_SMTR,		//����Ÿ�� ����
	SEL_SMOBJ,		//���ÿ�����Ʈ ����
	SEL_DELOBJ,		//������Ʈ ����
	SEL_SMSPEED,	//Ÿ����   gif�� ��� �ִϸ��̼� �ӵ�����
	SEL_FILL,		//Ÿ��     ä���
	SEL_SAVE,		//Ÿ��     ����
	SEL_LOAD		//Ÿ��     �ҷ�����
};



struct tagButton
{
	TagD2DImage *bitmap;
	image* image;
	RECT rc;
};

class tileMap : public gameNode
{

private:
	ID2D1BitmapRenderTarget* _rtTile;	//Ÿ�� ����Ÿ��
	ID2D1BitmapRenderTarget* _rtUI;		//UI����Ÿ��
	ID2D1BitmapRenderTarget* _rtBG;		//UI����Ÿ��
	int angle = 30;

//Ÿ�ϰ��� �����
private:
	tagSampleTile	_smTile[SAMPLETILEX * SAMPLETILEY];
	tagTile			_tiles[TILEX * TILEY];

//��ư���� �����
private:
	tagButton		_saveBtn;			//saveButton
	tagButton		_loadBtn;			//loadButton
	tagButton		_responeBtn;		//������ ������ư


	tagButton		_selSmSetBtn;		//���� ��ư�� ���� ���� ������ ���Ͽ�
	tagButton		_selTileSetBtn;		//Ÿ�� �׸���� ��ư
	tagButton		_selOBJSetBtn;		//������Ʈ �׸���� ��ư

	
	tagButton		_selSmTileGRASS;		//���� ��ư�� ���� ���� ������ ���Ͽ�
	tagButton		_selSmTileWATER;		//Ÿ�� �׸���� ��ư
	tagButton		_selSmTileEND;			//������Ʈ �׸���� ��ư
	tagButton		_selSmTileFrameSpeed;	//����Ÿ���� ������ �ӵ�������




	tagButton		_selSmObjNONE;			//���� Ÿ�Ͽ��� ������Ʈ ������ ���Ͽ�		��
	tagButton		_selSmObjBLOCK;			//���� Ÿ�Ͽ��� ������Ʈ�� �����ϱ� ���Ͽ� ���

	tagButton		_selTileMap[3];			//Ÿ�� 3������ �����ϱ� ���Ͽ�


//�����ϰ� ����� ������ ����
private:
	//����Ÿ�ϵ��� ���� Ʋ�� ��� �������� �������� ���ظ����� ����
	int			_smStartX;
	int			_smStartY;

	//���� ����Ÿ�ϵ��� ������ ���ؼ� ��ũ�ΰ� �ƴ� ������ ����������
	int			_smTileX;
	int			_smTileY;


	//���� Ŭ���� Ÿ���� ���� ������
	int			_currentFrameX;
	int			_currentFrameY;

	//���� �ӵ�
	float		_currentSpeed;


	//���� ���µ�
	int			_currentSelect;			//���� Ÿ�ϸ� ��� Ÿ���ΰ�??? ������Ʈ�ΰ�?? �ӵ��������ΰ�??
	TERRAIN		_currentSmTrSel;		//���� ���콺�� �������ִ� ����Ÿ���� �Ӽ�
	OBJECT		_currentSmObjSel;		//���� ���콺�� ������ �ִ� ������Ʈ
	MapMode		_currentMapMode;		//���� 3���� ���߿� ���� ���ΰ�??

	//20*20¥�� �ʿ��� 100*100�� �����ϱ� ��Ŀ���� �����ش�.
	POINT		_userFocusPoint;					//Ÿ�� ������ 100���ε� ���̴°� 20���̴ϱ� �������鵵 �� �� �ֵ��� ���� ��ǥ�� �����ش�.
	int			_userFocus;							//�� ��ǥ�� �޾� ���ؼ� �� ��ǥ�� �����ش�.
	int			_prevUserFocus;						//�̰� ������ �������������� ���� �ִ� ��Ŀ���� �� ���������� ����	������� ����4���� ��!!!

	
	//������ �ӵ� ������ �����δ� ������ �ٴ��� �������� �� �޶����� ���ھ ���� ����
	int			_frameCount;		//gif�������� ī��Ʈ (�ӵ�����)
	int			_gifFrame;			//gif�������� ���������� �Է��Ұ�  �ٰ��� �ٲ��� �������ϱ�?


	//�׽�Ʈ�� ������ ���۾ȉ����� ������ �ֵ� ���� ����Ű�� ������ Ÿ�ϵ��� �缳���� ���Ͽ�
	bool		_isGameStart;
public:
	tileMap();
	~tileMap();


	virtual HRESULT init();
	virtual	void release();
	virtual void update();
	virtual void render();



	//�̴ϼ� ������			START
	void allInit();			//�ʱ�ȭ ������ ���� ����ִ�.
	void variableInit();	//���� �ʱ�ȭ
	void imageInit();		//�̹��� �ʱ�ȭ
	void tileInit();		//�׷��� Ÿ�� �̹��� �ʱ�ȭ
	void smTileInit();		//������ Ÿ�� ���� �̹��� �ʱ�ȭ
	void btnInit();			//���̺� �ε� �� ��ư �ʱ�ȭ
	void RtInit();			//����Ÿ�� �ʱ�ȭ
	//�̴ϼ� ������			END



	//tileMap + draw�� ���� ������ �������
	//Render���� �Լ� ����	START
	void allDraw();			//��� �׸� ����
	void backGroundDraw();	//��� �׸� ���� Ʋ�� ����
	void tilesDraw();		//Ÿ�ϰ��� �׸� ���� �׸�Ÿ��,����Ÿ��
	void btnDraw();			//��ư �׸� ����
	//Render���� �Լ� ����	END



	//tileMap+diallog�� ����
	//���̺� �ε�			START
	void save();//���� 
	void load();//�ҷ�����
	//���̺� �ε�			END
	


	//tileMap + Setting�� ����
	//����  START
	void tileSetting();
	void tileSelect();		//����Ÿ�Ϸκ��� ������ �����ͼ� Ÿ�Ͽ� ĥ�ϴ� ��
	void smTileSelect();	//����Ÿ���� �������� �����ִ� �Լ�
	void smTerrainSet();	//����Ÿ���� Ÿ�� �Ӽ��� �����ִ� �Լ�
	void smObjSet();
	void smTileChange();
	void smSpeedSet();

	void tileUpdate();		//Ÿ���� ���� ���� ��ǥ�� �ٲ�� �� ��ǥ�� �°� ���� ��ǥ�� ����ִ� �Լ�

	//����  END



	//tileMap + description�� ����
	//Ÿ�ϸ� ���
	void fillMap();			//ä���
	//Ÿ�ϸ� ���
	

	void gameStart();
	void gameTileInit();
	void gameRender();



};

