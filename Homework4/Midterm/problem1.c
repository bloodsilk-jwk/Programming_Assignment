#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isAlphabet(char ch)
{
	if (ch >= 'a') 
	{
		if (ch <= 'z')
		{
			return 1;
		}
		return 0;
	}
	
	if (ch >= 'A')
	{
		if (ch <= 'Z')
		{
			return 1;
		}
		return 0;
	}
	return 0;
}

int isDigit(char ch)
{
	if (ch >= '0')
	{
		if (ch <= '9')
		{
			return 1;
		}
	}
	return 0;
}

int isAlphabetOrNumeric(char ch);

void problem1(void)
{
	char ch;

	printf("숫자문자를 입력하세요 (예. 3) : ");
	(void) scanf("%c", &ch);

	int result = 0;

	// isAlphabetOrNumeric 함수에 ch를 넘겨주고 그 반환값을 result에 저장하시오.
	result = isAlphabetOrNumeric(ch);

	// result 변수값이 1이면 ch 값이 숫자문자이거나 알파벳문자입니다 라고 화면에 출력하시오.	
	// digit 변수값이 0이면 ch 값이 숫자문자도 알파벳문자가 아닙니다 라고 화면에 출력하시오.
	if (result == 1)
	{
		printf("%c 는 숫자문자이거나 알파벳문자입니다.\n\n", ch);
	}
	else
	{
		printf("%c 는 숫자문자도 알파벳문자도 아닙니다.\n\n", ch);
	}

	fseek(stdin, 0, SEEK_END); // 이 코드는 수정하지 마시오.
}


int isAlphabetOrNumeric(char ch)
{
	if (isDigit(ch) == 1 || isAlphabet(ch) == 1)
	{
		return 1;
	}
	return 0;
}