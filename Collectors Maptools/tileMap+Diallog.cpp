#include "stdafx.h"
#include "tileMap.h"




void tileMap::save()
{
	//�밭 ���� ����
	OPENFILENAME ofn;
	char filePathSize[1028] = "";
	ZeroMemory(&ofn, sizeof(OPENFILENAME));

	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = NULL;
	ofn.lpstrFile = filePathSize;
	ofn.nMaxFile = sizeof(filePathSize);
	ofn.nFilterIndex = true;
	ofn.nMaxFileTitle = NULL;
	ofn.lpstrFileTitle = NULL;
	ofn.lpstrInitialDir = NULL;
	ofn.lpstrFilter = ("map������ ��������");
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	//����ó��
	//�������� �������°� ���⿡��!!! ���� �־��
	if (GetSaveFileName(&ofn) == FALSE) return;

	char temp[1208];
	strncpy_s(temp, strlen(ofn.lpstrFile) + 1, ofn.lpstrFile, strlen(ofn.lpstrFile));

	char* context = NULL;
	char* token = strtok_s(temp, "\\", &context);

	//���������� token���� �����̸��� ���Եȴ�
	while (strlen(context))
	{
		token = strtok_s(NULL, "\\", &context);
	}

	HANDLE file;
	DWORD write;

	file = CreateFile(token, GENERIC_WRITE, NULL, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);


	WriteFile(file, _tiles, sizeof(tagTile) * TILEX * TILEY, &write, NULL);
	WriteFile(file, _smTile, sizeof(tagSampleTile) * SAMPLETILEX* SAMPLETILEY, &write, NULL);


	CloseHandle(file);
}



void tileMap::load()
{
	//�밭 ���� ����
	OPENFILENAME ofn;
	char filePathSize[1028] = "";
	ZeroMemory(&ofn, sizeof(OPENFILENAME));

	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = NULL;
	ofn.lpstrFile = filePathSize;
	ofn.nMaxFile = sizeof(filePathSize);
	ofn.nFilterIndex = true;
	ofn.nMaxFileTitle = NULL;
	ofn.lpstrFileTitle = NULL;
	ofn.lpstrInitialDir = NULL;
	ofn.lpstrFilter = ("map������ ��������");
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	//����ó��
	//�������� �޾ƿ��°� ���⿡��!!! ���� �־��
	if (GetOpenFileName(&ofn) == FALSE) return;

	char temp[1208];
	strncpy_s(temp, strlen(ofn.lpstrFile) + 1, ofn.lpstrFile, strlen(ofn.lpstrFile));

	char* context = NULL;
	char* token = strtok_s(temp, "\\", &context);

	while (strlen(context))
	{
		token = strtok_s(NULL, "\\", &context);
	}

	HANDLE file;
	DWORD read;

	file = CreateFile(token, GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, _tiles, sizeof(tagTile) * TILEX * TILEY, &read, NULL);
	ReadFile(file, _smTile, sizeof(tagSampleTile)* SAMPLETILEX* SAMPLETILEY, &read, NULL);

	CloseHandle(file);
}