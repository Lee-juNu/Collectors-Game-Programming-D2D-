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