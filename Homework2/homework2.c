#define _CRT_SECURE_NO_WARNIGNS
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
	return 0;
}

void problem1()
{
	float num1, num2, num3, sum;
	printf("실수를 입력하시오: ");
	scanf("%f", &num1);
	printf("실수를 입력하시오: ");
	scanf("%f", &num2);
	printf("실수를 입력하시오: ");
	scanf("%f", &num3);

	sum = num1 + num2 + num3;
	printf("합은 %f이고 평균은 %f입니다.\n\n", sum, sum / 3);
}

void problem2()
{
	float mile;
	printf("마일을 입력하시오: ");
	scanf("%f", &mile);

	printf("%.1f마일은 %f미터입니다.\n\n", mile, (double)mile * 1609);
}

void problem3()
{
	float base, height, area;
	printf("삼각형의 밑변: ");
	scanf("%f", &base);
	printf("삼각형의 높이: ");
	scanf("%f", &height);

	area = (base * height) / 2;
	printf("삼각형의 넓이: %f\n\n", area);
}

void problem4()
{
	float celsius, fahrenheit;
	printf("화씨값을 입력하시오: ");
	scanf("%f", &fahrenheit);

	celsius = (5 * (fahrenheit - 32)) / 9;
	printf("섭씨값은 %f도입니다.\n\n", celsius);
}

void problem5()
{
	float unknown, answer;
	printf("실수를 입력하세요: ");
	scanf("%f", &unknown);

	answer = 3 * (unknown * unknown) + 7 * unknown + 11;
	printf("다항식의 값은 %f\n\n", answer);
}

void problem6()
{
	float weight;
	printf("몸무게를 입력하세요 (단위: kg): ");
	scanf("%f", &weight);

	printf("달에서의 몸무게는 %fkg입니다.", weight * 0.17);
}
