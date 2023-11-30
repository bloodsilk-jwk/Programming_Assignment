#include <iostream>
#include <Windows.h>
#include <process.h>
#include <tchar.h>

#define NUM_OF_THREADS 3
#define NUM_OF_INPUT 12

CRITICAL_SECTION hCriticalSection;

DWORD total = 0;

struct ThreadData {
	DWORD start;
	DWORD end;
};

// Things that Thread should do
DWORD WINAPI ThreadProc(LPVOID IpParam)
{
	ThreadData* data = (ThreadData*)IpParam;

	for (DWORD i = data->start; i < data->end; i++)
	{
		EnterCriticalSection(&hCriticalSection);
		total += i;
		LeaveCriticalSection(&hCriticalSection);
	}

	return 0;
}

int _tmain(int argc, TCHAR* argv[])
{
	// Save input

	float input[NUM_OF_INPUT];

	printf("%d개의 숫자를 입력하세요\n", NUM_OF_INPUT);
	
	for (int i = 0; i < NUM_OF_INPUT; i++)
	{
		std::cin >> input[i];
	}

	DWORD dwThreadID[NUM_OF_THREADS];
	HANDLE hThread[NUM_OF_THREADS];

	InitializeCriticalSection(&hCriticalSection);

	ThreadData threadData[NUM_OF_THREADS];

	for (int i = 0; i < NUM_OF_THREADS; i++)
	{
		threadData[i].start = i * (NUM_OF_INPUT / NUM_OF_THREADS);

		if (i == NUM_OF_THREADS - 1)
			threadData[i].end = 12;
		else
			threadData[i].end = (i + 1) * (NUM_OF_INPUT / NUM_OF_THREADS);

		// Create Thread
		hThread[i] = (HANDLE)
			CreateThread(
				NULL,
				0,
				ThreadProc,
				&threadData[i],
				CREATE_SUSPENDED,
				&dwThreadID[i]
			); 

		if (hThread[i] == NULL)
		{
			_tprintf(_T("Thread creation fault!\n"));
			return -1;
		}
	}

	for (DWORD i = 0; i < NUM_OF_THREADS; i++)
	{
		ResumeThread(hThread[i]);
	}

	WaitForMultipleObjects(NUM_OF_THREADS, hThread, TRUE, INFINITE);

	_tprintf(_T("total : %d\n"), total);

	for (DWORD i = 0; i < NUM_OF_THREADS; i++)
	{
		CloseHandle(hThread[i]);
	}

	DeleteCriticalSection(&hCriticalSection);

	return 0;
}