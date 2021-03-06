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
	ID2D1BitmapRenderTarget* _rtTile;	//展析 沓希展為
	ID2D1BitmapRenderTarget* _rtUI;		//UI沓希展為
	ID2D1BitmapRenderTarget* _rtBG;		//UI沓希展為
	int angle = 30;

//展析淫恵 識情採
private:
	tagSampleTile	_smTile[SAMPLETILEX * SAMPLETILEY];
	tagTile			_tiles[TILEX * TILEY];


//娃舘馬惟 紫遂拝 痕呪級 識情
private:
	//児巴展析級精 焼送 堂戚 蒸嬢辞 政疑旋昔 崇送績聖 是背幻級嬢却 痕呪
	int			_smStartX;
	int			_smStartY;

	//戚薦 児巴展析級税 姐呪亜 痕背辞 古滴稽亜 焼観 痕呪稽 識情背爽切
	int			_smTileX;
	int			_smTileY;


	//薄仙 適遣廃 展析税 薄仙 覗傾績
	int			_currentFrameX;
	int			_currentFrameY;

	//薄仙 紗亀
	float		_currentSpeed;


	//薄仙 雌殿級
	int			_currentSelect;			//薄仙 展析己 乞球 展析昔亜??? 神崎詮闘昔亜?? 紗亀繕箭掻昔亜??
	TERRAIN		_currentSmTrSel;		//薄仙 原酔什亜 亜走壱赤澗 児巴展析税 紗失
	OBJECT		_currentSmObjSel;		//薄仙 原酔什亜 亜走壱 赤澗 神崎詮闘
	MapMode		_currentMapMode;		//薄仙 3鯵税 己掻拭 巷充 己昔亜??

	//20*20促軒 己拭辞 100*100精 公左艦猿 匂朕什研 限仲層陥.
	POINT		_userFocusPoint;					//展析 姐呪澗 100鯵昔汽 左戚澗闇 20鯵戚艦猿 蟹袴走級亀 瑳 呪 赤亀系 獣拙 疎妊研 舛背層陥.
	int			_userFocus;							//益 疎妊研 閤焼 咽背辞 恥 疎妊研 姥背層陥.
	int			_prevUserFocus;						//戚惟 更心走 せせせせせせせ 穿拭 赤揮 匂朕什澗 訊 幻級嬢鎌聖猿 せせ	企岩背操 歯混4獣税 蟹!!!

	
	//覗傾績 紗亀 繕箭遂 痕呪昔企 賑匂櫛 郊陥税 覗傾績戚 岨 含串生檎 疏畏嬢辞 肢薦 森舛
	int			_frameCount;		//gif覗傾績税 朝錘闘 (紗亀繕箭)
	int			_gifFrame;			//gif覗傾績聖 送羨旋生稽 脊径拝依  陥旭戚 郊恩醤 瑳言蟹艦猿?


	//砺什闘遂 惟績戚 獣拙照�臉幻� 亜幻備 赤鞠 幻鉦 獣拙徹亜 級嬢神檎 展析去税 仙竺舛聖 是馬食
	bool		_isGameStart;
public:
	tileMap();
	~tileMap();


	virtual HRESULT init();
	virtual	void release();
	virtual void update();
	virtual void render();



	//戚艦屡 虞戚綜			START
	void allInit();			//段奄鉢 淫恵精 穿採 眼移赤陥.
	void variableInit();	//痕呪 段奄鉢
	void imageInit();		//戚耕走 段奄鉢
	void tileInit();		//益形霜 展析 戚耕走 段奄鉢
	void RtInit();			//沓希展為 段奄鉢
	//戚艦屡 虞戚綜			END



	//tileMap + draw拭 左淫 是拭辞 授辞企稽
	//Render淫恵 敗呪 乞増	START
	void allDraw();			//乞窮 益顕 増杯
	void tilesDraw();		//展析淫恵 益顕 増杯 益険展析,児巴展析
	void renderTest();
	//Render淫恵 敗呪 乞増	END



	//tileMap+diallog拭 左淫
	//室戚崎 稽球			START
	void save();//煽舌 
	void load();//災君神奄
	//室戚崎 稽球			END
	


	//tileMap + Setting拭 左淫
	//識澱  START

	void tileUpdate();		//展析聖 左澗 掻繊 疎妊亜 郊餓檎 益 疎妊拭 限惟 歯稽 疎妊研 説焼爽澗 敗呪
	//識澱  END




	




	void setFocus(POINT userFocusPoint) { _userFocusPoint = userFocusPoint; }
	tagTile* getTile() { return _tiles; }
	ID2D1BitmapRenderTarget* getTileRt() { return  _rtTile; }


};

