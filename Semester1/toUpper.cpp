#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char str[100];
	char after[100]{};

	//����
	(void)scanf("%99s", str);

	//str��null�����܂Ń��[�v
	int nullPos = 0;
	//����������啶���֕ϊ�����
	for (int i = 0; str[i] != '\0'; ++i) {
		after[i] = str[i];
		if (after[i] >= 'a' && after[i] <= 'z') {
			after[i] -= 'a' - 'A';
			//after[i] = str[i] - 32;
		}
		++nullPos;
	}
	after[nullPos] = '\0';
	//�\��
	puts(after);

	system("pause");
	return 0;
}