#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int numOfBits(unsigned int positive);
void printThreeNumbersInAscendingOrder(int num1, int num2, int num3);
int isPrime(int number);
void minusTime(int earlyHour, int earlyMinute, int earlySecond, int lateHour, int lateMinute, int lateSecond);
int compareTime(int hour1, int minute1, int second1, int hour2, int minute2, int second2);

int main()
{
	// problem1
	unsigned int positive;
	printf("양의 정수 입력 : ");
	scanf("%d", &positive);
	
	int result = numOfBits(positive);
	printf("%d\n\n", result);

	// problem2
/*	int num1, num2, num3;
	printf("3개의 정수 입력 : ");
	scanf("%d %d %d", &num1, &num2, &num3);

	printThreeNumbersInAscendingOrder(num1, num2, num3);
*/
	// Test Case
	printf("Test Case\n\n"); 
	printThreeNumbersInAscendingOrder(3, 5, 10);
	printThreeNumbersInAscendingOrder(6, 22, 9);
	printThreeNumbersInAscendingOrder(4, 3, 3);
	printThreeNumbersInAscendingOrder(4, 3, 4);

	// problem3
	int num;
	printf("2 ~ 10까지의 정수 1개 입력 : ");
	scanf("%d", &num);

	if (isPrime(num) == 1)
	{
		printf("%d는 소수입니다.\n\n", num);
	}
	else
	{
		printf("%d는 소수가 아닙니다.\n\n", num);
	}

	// problem4
	int hour1, minute1, second1;
	printf("첫 번째 시간을 입력합니다. : ");
	scanf("%d %d %d", &hour1, &minute1, &second1);

	int hour2, minute2, second2;
	printf("두 번째 시간을 입력합니다. : ");
	scanf("%d %d %d", &hour2, &minute2, &second2);

	int compared = compareTime(hour1, minute1, second1, hour2, minute2, second2);

	if (compared == 1)
	{
		minusTime(hour2, minute2, second2, hour1, minute1, second1);
	}
	else
	{
		minusTime(hour1, minute1, second1, hour2, minute2, second2);
	}

}

int numOfBits(unsigned int positive)
{
	unsigned int temp = positive;
	int bit1Number = 0;

	// int형은 4byte (= 32bit)
	for (int count = 31; count >= 0; count--)
	{
		// count만큼 우측으로 시프트
		temp >>= count;
		
		// 0000 0001과 AND 연산
		// 맨 오른쪽 자리만 0 아니면 1로 연산됨
		if ((temp & 1) == 1) 
		{
			// 연산 결과가 1이라면 bit1 개수 +1
			bit1Number++;
		}

		// temp 리셋
		temp = positive; 
	}

	return bit1Number;
}

void printThreeNumbersInAscendingOrder(int num1, int num2, int num3)
{
	if (num1 >= num2)
	{
		if (num1 >= num3)
		{
			if (num2 >= num3)
			{
				printf("%d %d %d\n\n", num1, num2, num3);
			}
			else // num2 < num3
			{
				printf("%d %d %d\n\n", num1, num3, num2);
			}
		}
		else // num1 < num3
		{
			printf("%d %d %d\n\n", num3, num1, num2);
		}
	}
	else // num1 < num2
	{
		if (num2 >= num3)
		{
			if (num1 >= num3)
			{
				printf("%d %d %d\n\n", num2, num1, num3);
			}
			else // num1 < num3
			{
				printf("%d %d %d\n\n", num2, num3, num1);
			}
		}
		else // num2 < num3
		{
			printf("%d %d %d\n\n", num3, num2, num1);
		}
	}
}

int isPrime(int number)
{
	// 2에서 (입력값 - 1)까지
	for (int quotient = 2; quotient < number; quotient++)
	{
		// 나누어 떨어진다면 0 반환
		if ((number % quotient) == 0)
		{
			return 0;
		}
	}
	// 나누어 떨어지는 값이 없음
	return 1;
}

void minusTime(int earlyHour, int earlyMinute, int earlySecond, int lateHour, int lateMinute, int lateSecond)
{
	int resultHour, resultMinute, resultSecond;

	if (lateSecond < earlySecond)
	{
		lateSecond += 60;
		lateMinute -= 1;
	}
	resultSecond = lateSecond - earlySecond;

	if (lateMinute < earlyMinute)
	{
		lateMinute += 60;
		lateHour -= 1;
	}
	resultMinute = lateMinute - earlyMinute;

	resultHour= lateHour - earlyHour;

	printf("두 시간의 시간차는 %d시간 %d분 %d초 입니다.\n\n", resultHour, resultMinute, resultSecond);
}

int compareTime(int hour1, int minute1, int second1, int hour2, int minute2, int second2)
{
	if (hour1 > hour2)
	{
		return 1;
	}
	if (hour1 < hour2)
	{
		return 0;
	}
	// 시간이 같음. 분 계산
	if (minute1 > minute2)
	{
		return 1;
	}
	if (minute1 < minute2)
	{
		return 0;
	}
	// 분도 같음. 초 계산
	if (second1 > second2)
	{
		return 1;
	}
	// 초가 같거나 2번째가 클 경우
	return 0;
}