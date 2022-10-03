#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void problem7_7();
void problem7_9();
void problem7_12();
void problem7_14();
void problem8_2();
void problem8_4();
void is_leap(int year);
void problem8_6();
int even(int num);
int absolute(int num);
int sign(int num);



int main()
{
	problem7_7();
	problem7_9();
	problem7_12();
	problem7_14();
	problem8_2();
	problem8_4();
	problem8_6();
}

void problem7_7()
{
	int num = 100;

	int PrimeNumber = 0;

	int count = 1;
	int divisor = 1;
	
	while (count <= 100)
	{
		while (divisor <= count)
		{
			if (count % divisor == 0)
			{
				PrimeNumber++;
			}
			divisor++;
		}
		

		if (PrimeNumber == 2)
		{
			printf("%d ", count);
		}
		
		divisor = 1;

		PrimeNumber = 0;

		count++;
	}

	printf("\n\n");
}

void problem7_9()
{
	int count = 1;

	int sum = 0;

	while (sum < 10000)
	{
		sum += count;
		count++;
	}
	sum -= count;
	count -= 2;

	printf("1부터 %d까지의 합이 %d입니다.\n\n", count, sum);
}

void problem7_12()
{
	int num1 = 0, num2 = 1, num3;
	int count;

	printf("몇 번째 항까지 구할까요? : ");
	scanf("%d", &count);

	for (int i = 0; i < count; i++)
	{
		printf("%d ", num2);
		num3 = num1 + num2;
		num1 = num2;
		num2 = num3;
	}

	printf("\n\n");
}

void problem7_14()
{
	int num;
	printf("정수를 입력하시오 : ");
	scanf("%d", &num);

	int temp = num;
	int result = 0;

	do
	{
		result += temp % 10;
		temp /= 10;
		result *= 10;
	} 
	while (temp > 0);

	printf("%d\n\n", result / 10);
}

void problem8_2()
{
	char character;
	scanf("%c", &character);

	printf("문자를 입력하시오 : ");
	scanf("%c", &character);

	if (character >= 'A' && character <= 'z')
	{
		if (character <= 'Z' || character >= 'a')
		{
			printf("%c는 알파벳 문자입니다.\n\n", character);
		}

	}
	else
	{
		printf("%c는 알파벳 문자가 아닙니다.\n\n", character);
	}
}

void problem8_4()
{
	int year;
	printf("연도를 입력하시오 : ");
	scanf("%d", &year);

	is_leap(year);
}

void is_leap(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 != 0)
		{
			printf("%d는 윤년입니다.\n\n", year);
		}
		else if (year % 400 == 0)
		{
			printf("%d는 윤년입니다.\n\n", year);
		}
		else
		{
			printf("%d는 윤년이 아닙니다.\n\n", year);
		}
	}
	else
	{
		printf("%d는 윤년이 아닙니다.\n\n", year);
	}
}

void problem8_6()
{
	int num;
	printf("정수를 입력하시오 : ");
	scanf("%d", &num);
	
	if (even(num) == 1)
	{
		printf("even()의 결과 : 짝수\n");
	}
	else
	{
		printf("even()의 결과 : 홀수\n");
	}

	printf("absolute()의 결과 : %d\n", absolute(num));
	
	if (sign(num) == -1)
	{
		printf("sign()의 결과 : 음수\n");
	}
	else if (sign(num) == 1)
	{
		printf("sign()의 결과 : 양수\n");
	}
	else
	{
		printf("sign()의 결과 : 0\n");
	}
}

int even(int num)
{
	if (num % 2 == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int absolute(int num)
{
	int temp = num;
	if (num < 0)
	{
		temp *= -1;
	}
	return temp;
}

int sign(int num)
{
	if (num < 0)
	{
		return -1;
	}
	if (num > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}