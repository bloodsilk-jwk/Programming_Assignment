#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void PrimeNumber();

int main()
{
	PrimeNumber();
}

void isoscelesTriangle()
{
	int num;
	printf("�Ʒ����� ���̸� ������ �Է��Ͻÿ� : ");
	scnaf("%d", &num);

	for (int vertical = 1; vertical <= num; vertical++)
	{
		int horizontal = 1; 
		horizontal++;
		int temp = (num - horizontal) / 2;
	}
}

void PrimeNumber()
{
	int num;
	printf("������ �Է��Ͻÿ� : ");
	scanf("%d", &num);

	int count = 1;

	while (count <= num)
	{
		int ifPrime = 0;

		int finder = 1;

		while (finder <= count)
		{
			if (count % finder == 0)
			{
				ifPrime++;
			}
			finder++;
		}

		if (ifPrime == 2)
		{
			printf("%d", count);
		}
	}
}