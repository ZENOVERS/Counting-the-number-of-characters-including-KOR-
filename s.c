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
	system("title 글자 수 세기");

	printf("문자열을 입력해주세요. 작성이 끝났으면, Tab + Enter키를 동시에 눌러주세요.\n영어 기준 최대 4094자, 한글 기준 2048자 까지 가능합니다.\n\n\n\n");
	scanf("%[^\t]s", s_g);

	Count();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	printf("\n\n\n\n\n\n공백 포함: %d    공백 제외: %d\n\n\n", count_g, count_g - Space_count_g);

	system("pause");

	return 0;
}