#define _CRT_SECURE_NO_WARNIGNS
#include <stdio.h>
void problem1();

int main()
{
	problem1();
}

void problem1()
{
	short num1 = 32767;
	for (int count = 15; count >= 0; count--)
	{
		printf("%d", ((num1 >> count) & 1));
	}

	printf("\n\n");

	short num2 = -32768;
	for (int count = 15; count >= 0; count--)
	{
		printf("%d", ((num2 >> count) & 1));
	}

	printf("\n\n");
}