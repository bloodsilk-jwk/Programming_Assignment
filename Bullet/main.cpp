#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>

int main()
{
	char Background[60 + 1];

	char Player[] = "(^_^)7";
	int PlayerPos = 10;

	char Enemy[] = "{#o#}";
	int EnemyPos = 50;

	char Bullet[] = "=>";
	int BulletPos = 10;
	
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 60; j++) // intialize background 배경 초기화
		{
			Background[j] = ' ';
		}
		Background[60] = '\0'; // put 'null' at the end of background 배열 끝에 널 문자

		// Overwrite Bullet, Player, Enemy on the background 덮어쓰기
		for (int k = 0; k < strlen(Bullet); k++)
		{
			Background[BulletPos + k] = Bullet[k];
		}

		for (int l = 0; l < strlen(Player); l++)
		{
			Background[PlayerPos + l] = Player[l];
		}

		for (int m = 0; m < strlen(Enemy); m++)
		{
			Background[EnemyPos + m] = Enemy[m];
		}

		// print, and move cursor to start 커서 맨 앞으로 보내기
		printf("%s\r", Background);

		if (BulletPos == 10) // before bullet is moving, 총알이 움직이기 전에
		{
			Sleep(3000); // stop 3 seconds 3초 지연시키기
		}
		else // After 3 seconds 지연 후 움직이면
		{
			Sleep(100); // repeat it every 0.1 seconds 0.1초마다 반복
		}

		if (BulletPos < 48)
		{
			BulletPos++;
		}
		else // when bullet collides 다 도착해서 충돌하면
		{
			for (int n = 0; n < strlen(Bullet); n++)
			{
				Bullet[n] = ' '; // remove bullet 총알 삭제
			}
		}
	}
}