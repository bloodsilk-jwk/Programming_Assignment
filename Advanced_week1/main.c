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
	printf("�� ���� �� : %d\n", x + y);
	printf("�� ���� �� : %d\n", x - y);
	printf("�� ���� �� : %d\n", x * y);
	printf("�� ���� �� : %d\n\n", x / y);
}

void problem3()
{
	int FirstNumber, SecondNumber;
	printf("ù��° ���ڸ� �Է��Ͻÿ� : ");
	scanf("%d", &FirstNumber);
	printf("�ι�° ���ڸ� �Է��Ͻÿ� : ");
	scanf("%d", &SecondNumber);

	printf("�� ���� �� : %d\n\n", FirstNumber + SecondNumber);
}

void problem4()
{
	double radius;
	printf("�������� �Է��Ͻÿ� : ");
	scanf("%lf", &radius);

	printf("���� ���� : %lf\n\n", radius * radius * 3.14);
}

void problem5()
{
	double w, h, area, perimeter;
	w = 10;
	h = 5;
	area = w * h;
	perimeter = 2 * (w + h);
	printf("�簢���� ���� : %f\n", area);
	printf("�簢���� �ѷ� : %f\n\n", perimeter);
}

void problem6()
{
	float Fahrenheit, Celsius;
	printf("ȭ�� �µ��� �Է��Ͻÿ� : ");
	scanf("%f", &Fahrenheit);

	Celsius = (5.0f / 9.0f) * (Fahrenheit - 32.0f);
	printf("���� �µ� : %f\n\n", Celsius);
}