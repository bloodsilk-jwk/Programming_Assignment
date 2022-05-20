#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

extern int reverse(unsigned int number);

int numberOfDigits(unsigned int number)
{
	int count = 1;

	if (number / 10 == 0)
	{
		return count;
	}
	count = count + 1;
	number = number / 10;

	if (number / 10 == 0)
	{
		return count;
	}
	count = count + 1;
	number = number / 10;

	if (number / 10 == 0)
	{
		return count;
	}
	count = count + 1;
	number = number / 10;

	if (number / 10 == 0)
	{
		return count;
	}
	count = count + 1;
	number = number / 10;

	if (number / 10 == 0)
	{
		return count;
	}
	count = count + 1;
	number = number / 10;

	if (number / 10 == 0)
	{
		return count;
	}
	count = count + 1;
	number = number / 10;

	if (number / 10 == 0)
	{
		return count;
	}
	count = count + 1;
	number = number / 10;

	if (number / 10 == 0)
	{
		return count;
	}
	count = count + 1;
	number = number / 10;

	if (number / 10 == 0)
	{
		return count;
	}
	count = count + 1;
	return count;
}

void problem3(void)
{
	unsigned int number;

	printf("최대 네자리 양의 정수를 입력하세요 (예, 1234) : ");
	(void)scanf("%u", &number);
	unsigned int palindrome = 0;

	// number를 makePalindrome 함수의 입력변수로 넘겨주고 반환값을 palindrome 변수에 저장하도록 코드를 작성하시오.
	palindrome = makePalindrome(number);

	printf("%u 숫자의 palindrome은 다음 정수 %u와 같습니다.\n\n", number, palindrome);

	fseek(stdin, 0, SEEK_END); // 이 코드는 수정하지 마시오.
}

int makePalindrome(unsigned int number)
{
	int temp = 0;
	int digitnumber = numberOfDigits(number);

	if (digitnumber == 4)
	{
		temp += number * 10000;
	}
	else if (digitnumber == 3)
	{
		temp += number * 1000;
	}
	else if (digitnumber == 2)
	{
		temp += number * 100;
	}
	else
	{
		temp += number * 10;
	}
	temp += reverse(number);
}