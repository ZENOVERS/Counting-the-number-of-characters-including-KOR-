#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#pragma warning(disable : 4996)


char s_g[4095] = { NULL, };
int count_g, Space_count_g;


void Count()
{
	for (int i = 0; s_g[i] != NULL; i++)
	{
		if (s_g[i] & 0x80)
		{
			count_g += 1;
			i++;
			continue;
		}

		count_g += 1;
		if (s_g[i] == ' ')
			Space_count_g += 1;
	}
}

int main()
{
	system("title ���� �� ����");

	printf("���ڿ��� �Է����ּ���. �ۼ��� ��������, Tab + EnterŰ�� ���ÿ� �����ּ���.\n���� ���� �ִ� 4094��, �ѱ� ���� 2048�� ���� �����մϴ�.\n\n\n\n");
	scanf("%[^\t]s", s_g);

	Count();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	printf("\n\n\n\n\n\n���� ����: %d    ���� ����: %d\n\n\n", count_g, count_g - Space_count_g);

	system("pause");

	return 0;
}