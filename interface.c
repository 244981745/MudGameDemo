#include "datastruct.h"

extern SpiritAttribute	Monster[];
int showMonsterList(void)
{
	int i;
	printf("================怪物列表================\n");
	for(i = 0; i < 3; i++)
	{
		printf("--------%.8s\t--------\n",Monster[i].Name);
		printf("\t生命值:\t%d\n",Monster[i].HP);
		printf("\t魔力值:\t%d\n",Monster[i].MP);
		printf("\t力量:\t%d\n",Monster[i].ATK);
		printf("\t魔法:\t%d\n",Monster[i].MATK);
		printf("\t物防:\t%d\n",Monster[i].DEF);
		printf("\t魔防:\t%d\n",Monster[i].MDEF);
		printf("------------------------\n");
	}
	printf("========================================\n\n");
}

int showAttritube(TheOne protagonist,int language)
{
	if(language)//中文 
	{
		printf("================人物属性================\n");
		printf("\t名字：\t%s\n",protagonist.Name);
		printf("\t性别：\t%s\n",protagonist.sex?"男":"女");
		printf("\t生命值:\t%d\n",protagonist.HP);
		printf("\t魔力值:\t%d\n",protagonist.MP);
		printf("\t力量:\t%d\n",protagonist.ATK);
		printf("\t魔法:\t%d\n",protagonist.MATK);
		printf("\t物防:\t%d\n",protagonist.DEF);
		printf("\t魔防:\t%d\n",protagonist.MDEF);
		printf("========================================\n\n");
	}
	else	//英文 
	{
		printf("================Attribute================\n");
		printf("\tName：\t%s\n",protagonist.Name);
		printf("\tSex：\t%s\n",protagonist.sex?"man":"female");
		printf("\tHP:\t%d\n",protagonist.HP);
		printf("\tMP:\t%d\n",protagonist.MP);
		printf("\tATK:\t%d\n",protagonist.ATK);
		printf("\tMATK:\t%d\n",protagonist.MATK);
		printf("\tDEF:\t%d\n",protagonist.DEF);
		printf("\tMDEF:\t%d\n",protagonist.MDEF);
		printf("========================================\n\n");
	} 
}

int battleResult(int ret,const char* monstername)
{
	if(ret)	//杀死怪物
	{
		printf("恭喜你杀死了%s！\n",monstername);
	}
	else	//被杀死
	{
		printf("你被%s杀死了！\n",monstername);
	}
	return 0;
}

