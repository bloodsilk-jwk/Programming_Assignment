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
	// ���� ����
	try
	{
		fout.open("userinform.dat");
		// ���� �� ���� �޽��� throw
		if (fout.fail())
			throw "File could not be opened";
	}
	catch (string errorMessage)
	{
		// ���� �޽��� ��� �� �Լ� ����
		cerr << errorMessage << endl;
		return;
	}
	// 10���� �����͸� �ޱ�
	for (int i = 0; i < 10; i++)
	{
		try
		{
			// ������ �Է�
			fillInform(userinform, i);
			// �����͸� ���Ͽ� ����
			fout << userinform[i].id << " " << userinform[i].name << " " << userinform[i].playTime << " " << userinform[i].score << endl;
		}
		// fillInform �Լ����� ������ �޾��� ���
		catch (invalid_argument& e)
		{
			// ���� �޽��� ��� �� ����
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
		// ���� ���� �ޱ�
		cout << i + 1 << "��° ������ ����, �÷��̽ð�, ���� ������ �Է��ϼ���" << endl;
		// �ٸ� �ڷ����� �Է��ߴٸ� throw
		if (!(cin >> userinform[i].name >> userinform[i].playTime >> userinform[i].score))
			throw invalid_argument("Invalid input.");
		// ���� ID�� ��ǻ�� �̸����� �ٲٱ�
		if (getenv("COMPUTERNAME") != NULL)
			strcpy(userinform[i].id, getenv("COMPUTERNAME"));
	}
	// �ٸ� �ڷ����� �ԷµǾ��� ���
	catch (invalid_argument& e)
	{
		// fileOut �Լ��� throw
		throw e;
	}
}

void fileHandler(ofstream& fout)
{
	BY_HANDLE_FILE_INFORMATION fileInfo;
	HANDLE hFile = nullptr;

	try // ���� ����
	{
		TCHAR fileName[] = _T("userinform.dat");
		hFile = CreateFile(
			fileName, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		// �߸��� ���̸�
		if (hFile == INVALID_HANDLE_VALUE)
		{
			// ���� �޽��� ������
			throw "File open fault! \n";
		}
	}
	catch (string e)
	{
		// ���� �޽��� ��� �� ����
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
	// �ð� ��ȯ
	SYSTEMTIME stUTC, stLocal;
	FileTimeToSystemTime(&ft, &stUTC);
	SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
	
	// fileTimeInfo�� �Ű�����
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
		// ���� �� ���� �޽��� throw
		if (fout.fail())
			throw "File could not be opened";
	}
	catch (string errorMessage)
	{
		// ���� �޽��� ��� �� �Լ� ����
		cerr << errorMessage << endl;
		return;
	}

	fout << "File created time : " << fileinform.createdTime << endl;
	fout << "File accessed time: " << fileinform.accessedTime << endl;
	fout << "File written time : " << fileinform.writtenTime << endl;

	fout.close();
}