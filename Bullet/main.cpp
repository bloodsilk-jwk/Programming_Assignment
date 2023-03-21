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
		for (int j = 0; j < 60; j++) // intialize background ��� �ʱ�ȭ
		{
			Background[j] = ' ';
		}
		Background[60] = '\0'; // put 'null' at the end of background �迭 ���� �� ����

		// Overwrite Bullet, Player, Enemy on the background �����
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

		// print, and move cursor to start Ŀ�� �� ������ ������
		printf("%s\r", Background);

		if (BulletPos == 10) // before bullet is moving, �Ѿ��� �����̱� ����
		{
			Sleep(3000); // stop 3 seconds 3�� ������Ű��
		}
		else // After 3 seconds ���� �� �����̸�
		{
			Sleep(100); // repeat it every 0.1 seconds 0.1�ʸ��� �ݺ�
		}

		if (BulletPos < 48)
		{
			BulletPos++;
		}
		else // when bullet collides �� �����ؼ� �浹�ϸ�
		{
			for (int n = 0; n < strlen(Bullet); n++)
			{
				Bullet[n] = ' '; // remove bullet �Ѿ� ����
			}
		}
	}
}