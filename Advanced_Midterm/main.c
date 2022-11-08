#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void II9();
void IV2();
void IV3();
int max(int A[], int size);

int main()
{
	II9();
	printf("\n\n");

	IV2();
	printf("\n\n");

	IV3();
}

void II9()
{
	float c_temp, f_temp = 122.0;
	c_temp = 5 / 9 * (f_temp - 32); // (int)5/(int)9 = 0
	printf("섭씨온도는 %f입니다", c_temp);
}

void IV2()
{
	int A[10] = { 5,64,14,80,81,59,42,66,62,83 };
	int temp;
	int max = A[0];
	for (int i = 0; i < 9; i++)
	{
		// 중간 저장물을 잊어버림
/*		if (A[i] > A[i + 1])
		{
			max = A[i];
		}
		else
		{
			max = A[i + 1];
		}
		*/
		if (max < A[i + 1])
		{
			max = A[i + 1];
		}
	}
	printf("%d", max);
}

void IV3()
{
	int A[10] = { 5,64,14,80,81,59,42,66,62,83 };
	printf("%d", max(A[10], 10));
}

int max(int A[], int size)
{
	int temp;
	for (int i = 0; i < size - 1; i++)
	{
		if (A[i] > A[i + 1])
		{
			temp = A[i];
		}
		else
		{
			temp = A[i + 1];
		}
	}

	return temp;
}