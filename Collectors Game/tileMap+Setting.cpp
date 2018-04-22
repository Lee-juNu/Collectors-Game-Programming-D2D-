#include "stdafx.h"
#include "tileMap.h"
#include "Resource.h"





void tileMap::tileUpdate()
{
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