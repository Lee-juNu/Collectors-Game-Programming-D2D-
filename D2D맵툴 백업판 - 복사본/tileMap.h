#pragma once
#include "tileNode.h"
#include <commdlg.h>
#include <commdlg.inl>
#include "gameNode.h"




enum SELECTMODE
{
	SEL_TR,
	SEL_OBJ,
	SEL_SMTR,
	SEL_SMOBJ,
	SEL_SMSPEED,
	SEL_FILL,
	SEL_SAVE,
	SEL_LOAD
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
	ID2D1BitmapRenderTarget* _rtTile;	//타일 랜더타겟
	ID2D1BitmapRenderTarget* _rtUI;		//UI랜더타겟
	ID2D1BitmapRenderTarget* _rtBG;		//UI랜더타겟
	int angle = 30;

//타일관련 선언부
private:
	tagSampleTile	_smTile[SAMPLETILEX * SAMPLETILEY];
	tagTile			_tiles[TILEX * TILEY];


//간단하게 사용할 변수들 선언
private:
	//샘플타일들은 아직 틀이 없어서 유동적인 움직임을 위해만들어둘 변수
	int			_smStartX;
	int			_smStartY;

	//이제 샘플타일들의 갯수가 변해서 매크로가 아닌 변수로 선언해주자
	int			_smTileX;
	int			_smTileY;


	//현재 클릭한 타일의 현재 프레임
	int			_currentFrameX;
	int			_currentFrameY;

	//현재 속도
	float		_currentSpeed;


	//현재 상태들
	int			_currentSelect;			//현재 타일맵 모드 타일인가??? 오브젝트인가?? 속도조절중인가??
	TERRAIN		_currentSmTrSel;		//현재 마우스가 가지고있는 샘플타일의 속성
	OBJECT		_currentSmObjSel;		//현재 마우스가 가지고 있는 오브젝트
	MapMode		_currentMapMode;		//현재 3개의 맵중에 무슨 맵인가??

	//20*20짜리 맵에서 100*100은 못보니까 포커스를 맞춰준다.
	POINT		_userFocusPoint;					//타일 갯수는 100개인데 보이는건 20개이니까 나머지들도 볼 수 있도록 시작 좌표를 정해준다.
	int			_userFocus;							//그 좌표를 받아 곱해서 총 좌표를 구해준다.
	int			_prevUserFocus;						//이게 뭐였지 ㅋㅋㅋㅋㅋㅋㅋ 전에 있던 포커스는 왜 만들어놨을까 ㅋㅋ	대답해줘 새벽4시의 나!!!

	
	//프레임 속도 조절용 변수인대 폭포랑 바다의 프레임이 좀 달랐으면 좋겠어서 삭제 예정
	int			_frameCount;		//gif프레임의 카운트 (속도조절)
	int			_gifFrame;			//gif프레임을 직접적으로 입력할것  다같이 바껴야 볼맛나니까?


	//테스트용 게임이 시작안됬으면 가만히 있되 만약 시작키가 들어오면 타일등의 재설정을 위하여
	bool		_isGameStart;
public:
	tileMap();
	~tileMap();


	virtual HRESULT init();
	virtual	void release();
	virtual void update();
	virtual void render();



	//이니셜 라이즈			START
	void allInit();			//초기화 관련은 전부 담겨있다.
	void variableInit();	//변수 초기화
	void imageInit();		//이미지 초기화
	void tileInit();		//그려질 타일 이미지 초기화
	void RtInit();			//랜더타겟 초기화
	//이니셜 라이즈			END



	//tileMap + draw에 보관 위에서 순서대로
	//Render관련 함수 모집	START
	void allDraw();			//모든 그림 집합
	void tilesDraw();		//타일관련 그림 집합 그릴타일,샘플타일
	void renderTest();
	//Render관련 함수 모집	END



	//tileMap+diallog에 보관
	//세이브 로드			START
	void save();//저장 
	void load();//불러오기
	//세이브 로드			END
	


	//tileMap + Setting에 보관
	//선택  START

	void tileUpdate();		//타일을 보는 중점 좌표가 바뀌면 그 좌표에 맞게 새로 좌표를 잡아주는 함수
	//선택  END




	




	void setFocus(POINT userFocusPoint) { _userFocusPoint = userFocusPoint; }
	tagTile* getTile() { return _tiles; }
	ID2D1BitmapRenderTarget* getTileRt() { return  _rtTile; }


};

