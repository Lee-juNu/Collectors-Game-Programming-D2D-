#include "stdafx.h"
#include "tileMap.h"




void tileMap::save()
{
	string temps = ".//Map//teilMap.map";


	HANDLE file;
	DWORD write;

	file = CreateFile(temps.c_str(), GENERIC_WRITE, NULL, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);


	WriteFile(file, _tiles, sizeof(tagTile) * TILEX * TILEY, &write, NULL);
	WriteFile(file, _smTile, sizeof(tagSampleTile) * SAMPLETILEX* SAMPLETILEY, &write, NULL);


	CloseHandle(file);
}



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