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
	printf("overflow�� �ʹ� Ŀ�� ǥ���� �� ���� �� �����.\n");
	printf("underflow�� �ʹ� �۾Ƽ� ǥ���� �� ���� �� �����.\n");
	printf("���������� underflow�� ����.\n\n");
}

void problem5()
{
	float Fahrenheit;
	printf("ȭ�� �µ��� �Է��Ͻÿ� : ");
	scanf("%f", &Fahrenheit);

	float Celsius = (5.0f / 9.0f)*(Fahrenheit - 32);
	printf("���� �µ� : %f\n\n", Celsius);
}

void problem6()
{
	int n;
	printf("���� n�� ���� ������ �Է��Ͻÿ� : ");
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

	printf("<�ܼ��� if�� ����>\n");
	printf("\"���� ��ȣ ����\"������ �Է��Ͻÿ�(���� ����)\n");
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

	printf("<�ܼ��� switch�� ����>\n");
	printf("\"���� ��ȣ ����\"������ �Է��Ͻÿ�(���� ����)\n");
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