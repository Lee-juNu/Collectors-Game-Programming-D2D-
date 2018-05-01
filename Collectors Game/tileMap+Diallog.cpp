#include "stdafx.h"
#include "tileMap.h"




void tileMap::load()
{
	HANDLE file;
	DWORD read;

	file = CreateFile(".//Map//testMap", GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, _tiles, sizeof(tagTile) * TILEX * TILEY, &read, NULL);

	CloseHandle(file);


	for (int i = 0; i<TILEX * TILEY; i++)
	{
		_tiles[i].rc = RectMake
		(
			(TILESIZE * (i%TILEX)),
			(TILESIZE * (i / TILEX)),
			TILESIZE, TILESIZE
		);
	}
}