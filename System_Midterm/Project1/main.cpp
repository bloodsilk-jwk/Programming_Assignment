#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <tchar.h>

using namespace std;

struct userInform {
	char id[20];
	char name[20];
	int playTime;
	int score;
};

struct fileInform {
	TCHAR createdTime[100];
	TCHAR accessedTime[100];
	TCHAR writtenTime[100];
};

void fileOut(userInform userinform[], ofstream& fout);
void fillInform(userInform userinform[], int i);
void fileHandler(ofstream& fout);
TCHAR* showFileTime(const FILETIME ft, TCHAR* fileTimeInfo);
void writeFileTime(ofstream& fout, fileInform fileinform);

int main()
{
	printf("%s\n", getenv("COMPUTERNAME"));

	userInform userinform[10];
	
	ofstream fout;

	fileOut(userinform, fout);

	fileHandler(fout);
}

void fileOut(userInform userinform[], ofstream& fout)
{
	// 파일 열기
	try
	{
		fout.open("userinform.dat");
		// 실패 시 에러 메시지 throw
		if (fout.fail())
			throw "File could not be opened";
	}
	catch (string errorMessage)
	{
		// 에러 메시지 출력 후 함수 종료
		cerr << errorMessage << endl;
		return;
	}
	// 10명의 데이터를 받기
	for (int i = 0; i < 10; i++)
	{
		try
		{
			// 데이터 입력
			fillInform(userinform, i);
			// 데이터를 파일에 저장
			fout << userinform[i].id << " " << userinform[i].name << " " << userinform[i].playTime << " " << userinform[i].score << endl;
		}
		// fillInform 함수에서 에러를 받았을 경우
		catch (invalid_argument& e)
		{
			// 에러 메시지 출력 후 종료
			cerr << e.what() << endl;
			return;
		}
	}

	fout.close();
}

void fillInform(userInform userinform[], int i)
{
	try
	{
		// 유저 정보 받기
		cout << i + 1 << "번째 유저의 별명, 플레이시간, 점수 순으로 입력하세요" << endl;
		// 다른 자료형을 입력했다면 throw
		if (!(cin >> userinform[i].name >> userinform[i].playTime >> userinform[i].score))
			throw invalid_argument("Invalid input.");
		// 유저 ID를 컴퓨터 이름으로 바꾸기
		if (getenv("COMPUTERNAME") != NULL)
			strcpy(userinform[i].id, getenv("COMPUTERNAME"));
	}
	// 다른 자료형이 입력되었을 경우
	catch (invalid_argument& e)
	{
		// fileOut 함수에 throw
		throw e;
	}
}

void fileHandler(ofstream& fout)
{
	BY_HANDLE_FILE_INFORMATION fileInfo;
	HANDLE hFile = nullptr;

	try // 파일 열기
	{
		TCHAR fileName[] = _T("userinform.dat");
		hFile = CreateFile(
			fileName, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		// 잘못된 값이면
		if (hFile == INVALID_HANDLE_VALUE)
		{
			// 에러 메시지 던지기
			throw "File open fault! \n";
		}
	}
	catch (string e)
	{
		// 에러 메시지 출력 후 종료
		cerr << e << endl;
		return;
	}

	GetFileInformationByHandle(hFile, &fileInfo);

	fileInform fileinform;
	_tprintf(_T("File created time : "));
	_tprintf(showFileTime(fileInfo.ftCreationTime, fileinform.createdTime));

	_tprintf(_T("\nFile accessed time: "));
	_tprintf(showFileTime(fileInfo.ftLastAccessTime, fileinform.accessedTime));

	_tprintf(_T("\nFile written time : "));
	_tprintf(showFileTime(fileInfo.ftLastWriteTime, fileinform.writtenTime));

	writeFileTime(fout, fileinform);

}

TCHAR* showFileTime(const FILETIME ft, TCHAR* fileTimeInfo)
{
	// 시간 변환
	SYSTEMTIME stUTC, stLocal;
	FileTimeToSystemTime(&ft, &stUTC);
	SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
	
	// fileTimeInfo에 옮겨적기
	_stprintf(
		fileTimeInfo, _T("%02d/%02d/%d  %02d:%02d"),
		stLocal.wMonth, stLocal.wDay, stLocal.wYear,
		stLocal.wHour, stLocal.wMinute
	);

	return fileTimeInfo;
}

void writeFileTime(ofstream& fout, fileInform fileinform)
{
	try
	{
		fout.open("FileMg.tax");
		// 실패 시 에러 메시지 throw
		if (fout.fail())
			throw "File could not be opened";
	}
	catch (string errorMessage)
	{
		// 에러 메시지 출력 후 함수 종료
		cerr << errorMessage << endl;
		return;
	}

	fout << "File created time : " << fileinform.createdTime << endl;
	fout << "File accessed time: " << fileinform.accessedTime << endl;
	fout << "File written time : " << fileinform.writtenTime << endl;

	fout.close();
}