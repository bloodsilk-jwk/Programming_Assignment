#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void problem6_3();
void problem6_4();
void problem7_2();
void problem7_3();
void problem7_4();
void problem7_5();


int main()
{
	problem6_3();
	problem6_4();
	problem7_2();
	problem7_3();
	problem7_4();
	problem7_5();
}

void problem6_3()
{
	int num1, num2, num3;
	printf("3개의 정수를 입력하시오 : ");
	scanf("%d %d %d", &num1, &num2, &num3);

	int min = num1;
	if (min > num2)
	{
		min = num2;
	}
	if (min > num3)
	{
		min = num3;
	}

	printf("제일 작은 정수는 %d입니다.\n\n", min);
}

void problem6_4()
{
	int ChoiceOfPlayer, ChoiceOfComputer;
	printf("선택하시오 (1 : 가위 / 2 : 바위 / 3 : 보) ");
	scanf("%d", &ChoiceOfPlayer);

	ChoiceOfComputer = (rand() % 3 + 1);

	// 입력값이 1,2,3 중 하나가 아님
	if(ChoiceOfPlayer > 3 || ChoiceOfPlayer < 1)
	{
		printf("잘못된 입력\n\n");
	}
	else
	{
		printf("컴퓨터의 선택 : %d\n", ChoiceOfComputer);

		// 선택이 같을 때
		if (ChoiceOfPlayer == ChoiceOfComputer)
		{
			printf("비겼음\n\n");
		}
		// (바위 vs 가위) (보 vs 바위)
		else if (ChoiceOfPlayer > ChoiceOfComputer)
		{
			printf("사용자가 이겼음\n\n");
		}
		// (가위 vs 보)
		else if ((ChoiceOfPlayer == 1) && (ChoiceOfComputer == 3))
		{
			printf("사용자가 이겼음\n\n");
		}
		// (가위 vs 바위) (바위 vs 보)
		else if (ChoiceOfPlayer < ChoiceOfComputer)
		{
			printf("사용자가 졌음\n\n");
		}
		// (보 vs 가위)
		else if ((ChoiceOfPlayer == 3) && (ChoiceOfComputer == 1))
		{
			printf("사용자가 졌음\n\n");
		}
	}
}

void problem7_2()
{
	int sum = 0;
	for (int num = 1; num <= 100; num++)
	{
		// 3의 배수일 경우
		if (num % 3 == 0)
		{
			sum += num;
		}
	}
	printf("1부터 100 사이의 모든 3의 배수의 합은 %d입니다\n\n", sum);
}

void problem7_3()
{
	int num;
	printf("정수를 입력하시오 : ");
	scanf("%d", &num);

	printf("약수 : ");

	int i = 1;

	while (i <= num)
	{
		if (num % i == 0)
		{
			printf("%d ", i);
		}
		i++;
	}

	printf("\n\n");

}

void problem7_4()
{
	// 세로
	for (int vertical = 1; vertical < 8; vertical++)
	{
		// 가로
		for (int horizontal = 1; horizontal < 8; horizontal++)
		{
			if (horizontal <= (7 - vertical))
			{
				printf(" ");
			}
			else
			{
				printf("*");
			}
		}
		printf("\n");
	}
	printf("\n");
}

void problem7_5()
{
	int num;
	printf("정수를 입력하시오 : ");
	scanf("%d", &num);

	int count = 1;

	while (count <= num)
	{
		for (int horizontal = 1; horizontal <= count; horizontal++)
		{
			printf("%d ", horizontal);
		}
		printf("\n");
		count++;
	}
}