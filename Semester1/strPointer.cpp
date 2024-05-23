#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
using namespace std;


struct Monster
{
	char name[16];
	int hitpoint;
	int attack;
	int defense;
};
//min����max�̒l��Ԃ�
float CalcIV(float min, float max)
{
	return min + rand() / (RAND_MAX / (max - min));
}
int main()
{
	srand((unsigned int)time(NULL));

	Monster monstersTable[] =
	{
		{"�t�V�M�_�l", 45, 49, 49}, {"�q�g�J�Q", 39, 52, 43},
		{"�Z�j�J��", 44, 48, 65}, {"�L���^�v�[", 45, 30, 35}
	};
	int tableNum = sizeof(monstersTable) / sizeof(monstersTable[0]);
	const int slotNum = 30;
	Monster monsterbox[slotNum];
	Monster* partyPointer[slotNum + 1] = {};
	//�̒l�𐶐����Amonsterbox�֑������(slotNum�̂𐶐�����)
	for (int i = 0; i < slotNum; i++)
	{   
		monsterbox[i] = monstersTable[rand() % tableNum];
		//�ȈՓI�Ȍ̒l�v�Z(�푰�l��0.9~1.1�{�Őݒ�)
		monsterbox[i].attack = int(monsterbox[i].attack * CalcIV(0.9f, 1.1f));
		monsterbox[i].defense = int(monsterbox[i].attack * CalcIV(0.9f, 1.1f));
		monsterbox[i].hitpoint = int(monsterbox[i].attack * CalcIV(0.9f, 1.1f));
	}

	//HP�͈̔͐ݒ�
	int min, max;
	printf("�I������HP�͈̔͂����:");
	scanf("%d %d", &min, &max);
	//HP��min����max�͈̔͂ɂ��郂���X�^�[������

	//HP�̏��������Ń\�[�g�A�����ł�monstersTable��monsterbox�̓\�[�g���Ȃ�����

	//�����X�^�[�̏o��
	for (Monster** ptr = partyPointer; *ptr != nullptr; ++ptr)
	{
		Monster* tmp = *ptr;
		printf("���O:%s HP:%d �U��:%d �h��:%d\n",
			tmp->name, tmp->hitpoint, tmp->attack, tmp->defense);
	}

	system("pause");
}