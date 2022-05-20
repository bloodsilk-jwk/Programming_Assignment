#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int verifyStudentNumber(unsigned int studentNumber);

void problem4(void)
{
	unsigned int studentNumber;

	printf("학번을 입력하세요 : ");
	(void)scanf("%x", &studentNumber);

	int correct = 0;

	// studentNumber를 verifyStudentNumber의 함수 입력으로 넘겨주고 그 결과를 correct에 저장하도록 구현하시오.
	correct = verifyStudentNumber(studentNumber);
	// correct가 1이면 정상적으로 입력되었다는 메세지를
	// correct가 0이면 정상적인 학번이 아니다는 메세지를 출력하도록 하시오.
	if (correct == 1)
	{
		printf("학번 %x은(는) 정상적으로 입력된 값입니다.\n\n", studentNumber);
	}
	else
	{
		printf("학번 %x은(는) 정상적인 학번이 아닙니다.\n\n", studentNumber);
	}

	fseek(stdin, 0, SEEK_END); // 이 코드는 수정하지 마시오.
}

int verifyStudentNumber(unsigned int studentNumber)
{
	// A, B, C는 각각 10진수로 10, 11, 12
	int temp = studentNumber;
	int abc = 0; // 첫자리 ABC 체크용

	if (temp % 0x10 >= 0x00 && temp % 0x10 <= 0x09) // 뒤에서 1번째
	{
		temp = temp / 0x10;
	}
	if (temp % 0x10 >= 0x00 && temp % 0x10 <= 0x09) // 뒤에서 2번째
	{
		temp = temp / 0x10;
	}
	if (temp % 0x10 >= 0x00 && temp % 0x10 <= 0x09) // 뒤에서 3번째
	{
		temp = temp / 0x10;
	}
	if (temp % 0x10 >= 0x00 && temp % 0x10 <= 0x09) // 뒤에서 4번째
	{
		temp = temp / 0x10;
	}
	if (temp % 0x10 >= 0x00 && temp % 0x10 <= 0x09) // 뒤에서 5번째
	{
		temp = temp / 0x10;
	}
	if (temp % 0x10 >= 0x00 && temp % 0x10 <= 0x09) // 뒤에서 6번째
	{
		temp = temp / 0x10;
	}
	if (temp % 0x10 >= 0x0a && temp % 0x10 <= 0x0c) // 뒤에서 7번째, ABC
	{
		abc++;
		temp = temp / 0x10;
	}
	
	if (temp == 0x00 && abc == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}