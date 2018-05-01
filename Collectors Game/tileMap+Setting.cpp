#include "stdafx.h"
#include "tileMap.h"
#include "Resource.h"





void tileMap::tileUpdate()
{
	//GIF이미지를 계속 반복시켜주기 위하여 있다.
	_frameCount++;
	for (int i = 0; i < TILEX * TILEY; i++)
	{

		if (_frameCount % ((int)_tiles[i].gifSpeed*10)== 0)
		{
			_tiles[i].gifFrame++;

			if (_tiles[i].gifFrame >= 2)
			{
				_tiles[i].gifFrame = 0;
			}
		}
	}
}