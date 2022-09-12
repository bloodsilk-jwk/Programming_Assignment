#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();

int main()
{
	problem1();
	problem2();
	problem3();
	problem4();
	problem5();
	problem6();
}

void problem1()
{
	printf("Hello World!\n");
	printf("Kim ChulSoo\n\n");
}

void problem2()
{
	int x = 20;
	int y = 10;
	printf("두 수의 합 : %d\n", x + y);
	printf("두 수의 차 : %d\n", x - y);
	printf("두 수의 곱 : %d\n", x * y);
	printf("두 수의 몫 : %d\n\n", x / y);
}

void problem3()
{
	int FirstNumber, SecondNumber;
	printf("첫번째 숫자를 입력하시오 : ");
	scanf("%d", &FirstNumber);
	printf("두번째 숫자를 입력하시오 : ");
	scanf("%d", &SecondNumber);

	printf("두 수의 합 : %d\n\n", FirstNumber + SecondNumber);
}

void problem4()
{
	double radius;
	printf("반지름을 입력하시오 : ");
	scanf("%lf", &radius);

	printf("원의 면적 : %lf\n\n", radius * radius * 3.14);
}

void problem5()
{
	double w, h, area, perimeter;
	w = 10;
	h = 5;
	area = w * h;
	perimeter = 2 * (w + h);
	printf("사각형의 넓이 : %f\n", area);
	printf("사각형의 둘레 : %f\n\n", perimeter);
}

void problem6()
{
	float Fahrenheit, Celsius;
	printf("화씨 온도를 입력하시오 : ");
	scanf("%f", &Fahrenheit);

	Celsius = (5.0f / 9.0f) * (Fahrenheit - 32.0f);
	printf("섭씨 온도 : %f\n\n", Celsius);
}