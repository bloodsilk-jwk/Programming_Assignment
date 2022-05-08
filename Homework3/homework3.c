#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void problem2();
void problem4();
void problem6();
void problem8();
void problem10();

int main()
{
	problem2();
	problem4();
	problem6();
	problem8();
	problem10();

	return 0;
}

void problem2()
{
	int hexadecimal;
	printf("16진수 정수를 입력하시오: ");
	scanf("%x", &hexadecimal);

	printf("8진수로는 %#o입니다\n", hexadecimal);
	printf("10진수로는 %d입니다\n", hexadecimal);
	printf("16진수로는 %#x입니다\n\n", hexadecimal);
}

void problem4()
{
	double width, length, height;
	printf("상자의 가로 세로 높이를 한번에 입력: ");
	scanf("%lf %lf %lf", &width, &length, &height);

	printf("상자의 부피는 %lf입니다.\n\n", width * length * height);
}

void problem6()
{
	double num1 = 3.32e-3;
	double num2 = 9.76e-8;
	printf("%lf\n\n", num1 + num2);
}

void problem8()
{
	int	num;
	printf("아스키 코드값을 입력하시오: ");
	scanf("%d", &num);
	char ascii = (char)num;
	printf("문자: %c입니다.\n\n", ascii);
}

void problem10()
{
	printf("\a");
	printf("화재가 발생하였습니다.");
	printf("\a");
}