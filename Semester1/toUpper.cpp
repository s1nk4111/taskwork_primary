#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char str[100];
	char after[100]{};

	//入力
	(void)scanf("%99s", str);

	//strのnull文字までループ
	int nullPos = 0;
	//小文字から大文字へ変換する
	for (int i = 0; str[i] != '\0'; ++i) {
		after[i] = str[i];
		if (after[i] >= 'a' && after[i] <= 'z') {
			after[i] -= 'a' - 'A';
			//after[i] = str[i] - 32;
		}
		++nullPos;
	}
	after[nullPos] = '\0';
	//表示
	puts(after);

	system("pause");
	return 0;
}