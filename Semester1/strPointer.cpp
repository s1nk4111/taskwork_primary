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
//minからmaxの値を返す
float CalcIV(float min, float max)
{
	return min + rand() / (RAND_MAX / (max - min));
}
int main()
{
	srand((unsigned int)time(NULL));

	Monster monstersTable[] =
	{
		{"フシギダネ", 45, 49, 49}, {"ヒトカゲ", 39, 52, 43},
		{"セニカメ", 44, 48, 65}, {"キャタプー", 45, 30, 35}
	};
	int tableNum = sizeof(monstersTable) / sizeof(monstersTable[0]);
	const int slotNum = 30;
	Monster monsterbox[slotNum];
	Monster* partyPointer[slotNum + 1] = {};
	//個体値を生成し、monsterboxへ代入する(slotNum体を生成する)
	for (int i = 0; i < slotNum; i++)
	{   
		monsterbox[i] = monstersTable[rand() % tableNum];
		//簡易的な個体値計算(種族値の0.9~1.1倍で設定)
		monsterbox[i].attack = int(monsterbox[i].attack * CalcIV(0.9f, 1.1f));
		monsterbox[i].defense = int(monsterbox[i].attack * CalcIV(0.9f, 1.1f));
		monsterbox[i].hitpoint = int(monsterbox[i].attack * CalcIV(0.9f, 1.1f));
	}

	//HPの範囲設定
	int min, max;
	printf("選択するHPの範囲を入力:");
	scanf("%d %d", &min, &max);
	//HPがminからmaxの範囲にあるモンスターを検索

	//HPの小さい順でソート、ここではmonstersTableやmonsterboxはソートしないこと

	//モンスターの出力
	for (Monster** ptr = partyPointer; *ptr != nullptr; ++ptr)
	{
		Monster* tmp = *ptr;
		printf("名前:%s HP:%d 攻撃:%d 防御:%d\n",
			tmp->name, tmp->hitpoint, tmp->attack, tmp->defense);
	}

	system("pause");
}