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
	printf("3���� ������ �Է��Ͻÿ� : ");
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

	printf("���� ���� ������ %d�Դϴ�.\n\n", min);
}

void problem6_4()
{
	int ChoiceOfPlayer, ChoiceOfComputer;
	printf("�����Ͻÿ� (1 : ���� / 2 : ���� / 3 : ��) ");
	scanf("%d", &ChoiceOfPlayer);

	ChoiceOfComputer = (rand() % 3 + 1);

	// �Է°��� 1,2,3 �� �ϳ��� �ƴ�
	if(ChoiceOfPlayer > 3 || ChoiceOfPlayer < 1)
	{
		printf("�߸��� �Է�\n\n");
	}
	else
	{
		printf("��ǻ���� ���� : %d\n", ChoiceOfComputer);

		// ������ ���� ��
		if (ChoiceOfPlayer == ChoiceOfComputer)
		{
			printf("�����\n\n");
		}
		// (���� vs ����) (�� vs ����)
		else if (ChoiceOfPlayer > ChoiceOfComputer)
		{
			printf("����ڰ� �̰���\n\n");
		}
		// (���� vs ��)
		else if ((ChoiceOfPlayer == 1) && (ChoiceOfComputer == 3))
		{
			printf("����ڰ� �̰���\n\n");
		}
		// (���� vs ����) (���� vs ��)
		else if (ChoiceOfPlayer < ChoiceOfComputer)
		{
			printf("����ڰ� ����\n\n");
		}
		// (�� vs ����)
		else if ((ChoiceOfPlayer == 3) && (ChoiceOfComputer == 1))
		{
			printf("����ڰ� ����\n\n");
		}
	}
}

void problem7_2()
{
	int sum = 0;
	for (int num = 1; num <= 100; num++)
	{
		// 3�� ����� ���
		if (num % 3 == 0)
		{
			sum += num;
		}
	}
	printf("1���� 100 ������ ��� 3�� ����� ���� %d�Դϴ�\n\n", sum);
}

void problem7_3()
{
	int num;
	printf("������ �Է��Ͻÿ� : ");
	scanf("%d", &num);

	printf("��� : ");

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
	// ����
	for (int vertical = 1; vertical < 8; vertical++)
	{
		// ����
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
	printf("������ �Է��Ͻÿ� : ");
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