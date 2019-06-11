#include "datastruct.h"

extern SpiritAttribute	Monster[];
int showMonsterList(void)
{
	int i;
	printf("================�����б�================\n");
	for(i = 0; i < 3; i++)
	{
		printf("--------%.8s\t--------\n",Monster[i].Name);
		printf("\t����ֵ:\t%d\n",Monster[i].HP);
		printf("\tħ��ֵ:\t%d\n",Monster[i].MP);
		printf("\t����:\t%d\n",Monster[i].ATK);
		printf("\tħ��:\t%d\n",Monster[i].MATK);
		printf("\t���:\t%d\n",Monster[i].DEF);
		printf("\tħ��:\t%d\n",Monster[i].MDEF);
		printf("------------------------\n");
	}
	printf("========================================\n\n");
}

int showAttritube(TheOne protagonist,int language)
{
	if(language)//���� 
	{
		printf("================��������================\n");
		printf("\t���֣�\t%s\n",protagonist.Name);
		printf("\t�Ա�\t%s\n",protagonist.sex?"��":"Ů");
		printf("\t����ֵ:\t%d\n",protagonist.HP);
		printf("\tħ��ֵ:\t%d\n",protagonist.MP);
		printf("\t����:\t%d\n",protagonist.ATK);
		printf("\tħ��:\t%d\n",protagonist.MATK);
		printf("\t���:\t%d\n",protagonist.DEF);
		printf("\tħ��:\t%d\n",protagonist.MDEF);
		printf("\tװ��:\t%.2x\n",protagonist.equipment);
		printf("========================================\n\n");
	}
	else	//Ӣ�� 
	{
		printf("================Attribute================\n");
		printf("\tName��\t%s\n",protagonist.Name);
		printf("\tSex��\t%s\n",protagonist.sex?"man":"female");
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
	if(ret)	//ɱ������
	{
		printf("��ϲ��ɱ����%s��\n",monstername);
	}
	else	//��ɱ��
	{
		printf("�㱻%sɱ���ˣ�\n",monstername);
	}
	return 0;
}

extern Items dropItem[];
int dropResult(int itemid)
{
	printf("��ϲ������%s��\n",dropItem[itemid].Name);
	return 0;
};
