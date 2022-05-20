#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

extern int reverse(unsigned int number);

void problem2(void)
{
	unsigned int number;

	printf("최대 네자리 양의 정수를 입력하세요 (예, 1234) : ");
	(void) scanf("%u", &number);
	unsigned int reversed = 0;

	// number를 reverse 함수 입력변수로 넘겨주고 그 결과값을 reversed 변수에 넣도록 코드를 작성하시오.
	reversed = reverse(number);

	printf("%u 숫자를 반대로 만들면 다음과 같은 정수 %u가 됩니다.\n\n", number, reversed);
	
	fseek(stdin, 0, SEEK_END); // 이 코드는 수정하지 마시오.
}

int reverse(unsigned int number)
{
	int temp = 0; // 저장소

	if (number / 1000 > 0) // 4자리 수
	{
		temp += (number % 10) * 1000; // 일의 자리 숫자 >> 천의 자리 숫자
		number = number / 10;

		temp += (number % 10) * 100; // 십의 자리 숫자 >> 백의 자리 숫자
		number = number / 10;

		temp += (number % 10) * 10; // 백의 자리 숫자 >> 십의 자리 숫자
		number = number / 10;

		temp += number; // 천의 자리 숫자 >> 일의 자리 숫자
	}
	else if (number / 100 > 0) // 3자리 수
	{
		temp += (number % 10) * 100; // 일의 자리 숫자 >> 백의 자리 숫자
		number = number / 10;

		temp += (number % 10) * 10; // 십의 자리 숫자 >> 십의 자리 숫자
		number = number / 10;

		temp += number; // 백의 자리 숫자 >> 일의 자리 숫자
	}
	else if (number / 10 > 0) // 2자리 수
	{
		temp += (number % 10) * 10; // 일의 자리 숫자 >> 십의 자리 숫자
		number = number / 10;

		temp += number; // 십의 자리 숫자 >> 일의 자리 숫자
	}
	else // 1자리 수
	{
		temp += number; // 일의 자리 숫자 >> 일의 자리 숫자
	}

	return temp;
}