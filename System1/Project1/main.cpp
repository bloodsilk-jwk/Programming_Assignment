#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <tchar.h>

using namespace std;

#define STRING_LEN		100

void ShowAttributes(DWORD attrib);
void ShowFileTime(FILETIME t);

struct userInform {
	char id[20];
	char name[30];
	int playTime;
	int score;
};

int main()
{
	printf("%s\n", getenv("COMPUTERNAME"));

	userInform userinform[10];

	ofstream fout;

	fout.open("userinform.dat");

	for (int i = 0; i < 10; i++)
	{
		cin >> userinform[i].id >> userinform[i].name >> userinform[i].playTime >> userinform[i].score;

		if (getenv("COMPUTERNAME") != NULL)
		{
			strcpy(userinform[i].name, getenv("COMPUTERNAME"));
		}

		fout << userinform[i].id << " " << userinform[i].name << " " << userinform[i].playTime << " " << userinform[i].score << endl;
	}

	fout.close();

	TCHAR fileName[] = _T("userinform.dat");
	BY_HANDLE_FILE_INFORMATION fileInfo;

	HANDLE hFile = CreateFile(
		fileName, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("File open fault! \n"));
		return -1;
	}

	GetFileInformationByHandle(hFile, &fileInfo);

	ShowAttributes(fileInfo.dwFileAttributes);

	_tprintf(_T("File size: %u \n"), fileInfo.nFileSizeLow);

	_tprintf(_T("File created time : "));
	ShowFileTime(fileInfo.ftCreationTime);

	_tprintf(_T("File accessed time: "));
	ShowFileTime(fileInfo.ftLastAccessTime);

	_tprintf(_T("File written time : "));
	ShowFileTime(fileInfo.ftLastWriteTime);

	return 0;
	
}

void ShowAttributes(DWORD attrib)
{
	if (attrib & FILE_ATTRIBUTE_NORMAL)
	{
		_tprintf(_T("Normal \n"));
	}
	else
	{
		if (attrib & FILE_ATTRIBUTE_READONLY)
			_tprintf(_T("Read Only \n"));

		if (attrib & FILE_ATTRIBUTE_HIDDEN)
			_tprintf(_T("Hidden \n"));
	}

	_tprintf(_T("\n"));
}

void ShowFileTime(FILETIME t)
{
	TCHAR fileTimeInfo[STRING_LEN];

	FILETIME ft = t;
	SYSTEMTIME stUTC, stLocal;

	FileTimeToSystemTime(&ft, &stUTC);
	SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);

	_stprintf(
		fileTimeInfo, _T("%02d/%02d/%d  %02d:%02d"),
		stLocal.wMonth, stLocal.wDay, stLocal.wYear,
		stLocal.wHour, stLocal.wMinute
	);

	_tprintf(_T("[%s] \n"), fileTimeInfo);
}