#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();


int main()
{
	problem1();
	problem2();
	problem3();
	problem4();
	problem5();
	problem6();
	problem7();
	problem8();
}

void problem1()
{
	short num1 = 32767;
	for (int count = 15; count >= 0; count--)
	{
		printf("%d", ((num1 >> count) & 1));
	}

	printf("\n");

	short num2 = -32768;
	for (int count = 15; count >= 0; count--)
	{
		printf("%d", ((num2 >> count) & 1));
	}

	printf("\n\n");
}

void problem2()
{
	short num1 = 32767;
	short num2 = num1 + 1;
	printf("%d\n\n", num2);
}

void problem3()
{
	float num1 = 0.0;
	printf("%f\n\n", num1);
}

void problem4()
{
	printf("overflow란 너무 커서 표현할 수 없을 때 생긴다.\n");
	printf("underflow란 너무 작아서 표현할 수 없을 때 생긴다.\n");
	printf("정수형에는 underflow가 없다.\n\n");
}

void problem5()
{
	float Fahrenheit;
	printf("화씨 온도를 입력하시오 : ");
	scanf("%f", &Fahrenheit);

	float Celsius = (5.0f / 9.0f)*(Fahrenheit - 32);
	printf("섭씨 온도 : %f\n\n", Celsius);
}

void problem6()
{
	int n;
	printf("변수 n의 값을 정수로 입력하시오 : ");
	scanf("%d", &n);

	if (n > 100)
	{
		printf("Large\n\n");
	}
	if (n <= 100)
	{
		printf("Small\n\n");
	}
}

void problem7()
{
	int num1, num2;
	char symbol;

	printf("<단순한 if문 계산기>\n");
	printf("\"숫자 기호 숫자\"순으로 입력하시오(공백 포함)\n");
	scanf("%d %c %d", &num1, &symbol, &num2);

	int result = 0;

	if (symbol == '+')
	{
		result = num1 + num2;
		printf("= %d\n\n", result);
	}
	else if (symbol == '-')
	{
		result = num1 - num2;
		printf("= %d\n\n", result);
	}
	else if (symbol == '*')
	{
		result = num1 * num2;
		printf("= %d\n\n", result);
	}
	else if (symbol == '/')
	{
		result = num1 / num2;
		printf("= %d\n\n", result);
	}
	else if (symbol == '%')
	{
		result = num1 % num2;
		printf("= %d\n\n", result);
	}
	else
	{
		printf("Error\n\n");
	}
}

void problem8()
{
	int num1, num2;
	char symbol;

	printf("<단순한 switch문 계산기>\n");
	printf("\"숫자 기호 숫자\"순으로 입력하시오(공백 포함)\n");
	scanf("%d %c %d", &num1, &symbol, &num2);

	int result = 0;
	switch (symbol) 
	{
		case '+':
			result = num1 + num2;
			printf("= %d\n\n", result);
			break;
		case '-':
			result = num1 - num2;
			printf("= %d\n\n", result);
			break;
		case '*':
			result = num1 * num2;
			printf("= %d\n\n", result);
			break;
		case '/':
			result = num1 / num2;
			printf("= %d\n\n", result);
			break;
		case '%':
			result = num1 % num2;
			printf("= %d\n\n", result);
			break;
		default:
			printf("Error\n\n");
			break;
	}
}