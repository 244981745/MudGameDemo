/*************************************************
Copyright (C), 2019-2019, DREACYOU
File name:	interface.c
Author:		DREACYOU
Version:	0.0.1.0
Date:		2019.6.11
Description: ������� 
Others: 
Function List: 

History: 

*************************************************/
#include "datastruct.h"
#include "packet.h"


/*************************************************
Function: showMonsterList
Description: list�����б� 
Calls: 
Called By: 

Input: void
Output: 
Return: ����0
Others: 
*************************************************/
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
	return 0; 
}

/*************************************************
Function: showAttritube
Description: list�������� 
Calls: 
Called By: 

Input: TheOne protagonist,int language
Output: 
Return: ����0
Others: 
*************************************************/
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
	return 0; 
}

/*************************************************
Function: battleResult
Description: ��ʾս����� 
Calls: 
Called By: 

Input: int ret,const char* monstername
Output: 
Return: ����0
Others: 
*************************************************/
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

/*************************************************
Function: dropResult
Description: ��ʾ������Ʒ 
Calls: 
Called By: 

Input: int itemid
Output: 
Return: ����0
Others: 
*************************************************/
extern Items dropItem[];
int dropResult(int itemid)
{
	printf("��ϲ������%s��\n",dropItem[itemid].Name);
	return 0;
};

/*************************************************
Function: showPacket
Description: ��ʾ������Ʒ��Ϣ 
Calls: 
Called By: 

Input: struct PacketLink *L
Output: 
Return: ����0
Others: 
*************************************************/
int showPacket(struct PacketLink *L)
{
	int i;
	struct PacketLinkNode *p = L->head->next;
	printf("================������Ϣ================\n");
	if(listEmpty(L) == true)printf("packet is empty.\n");
	else
	{
		for(i = 0; i < L->link_len; i++)
		{
			//printf("%p\n",p);
			printf("PacketItem[%d] Name:%s\t",i,p->Name);
			printf("Have:%d\n",p->num);
			p=p->next;
		}
	}
	printf("========================================\n\n");

	return 0;
}

char miloffsetname[8][8]={
	{"����"},
	{"����"},
	{"����"},
	{"��ָ"},
	{"��ָ"},
	{"����"},
	{"����"},
	{"����"},
}; 
extern Items military[MILIIDMAX];
int showMilitary(void)
{
	int i;
	printf("================װ����Ϣ================\n");
	
	for(i = 0; i < MILIIDMAX; i++)
	{
		//if(military[i].Name[0] != 0)
			printf("\t%s:\t%s\n",miloffsetname[i],military[i].Name);
	}
	printf("========================================\n\n");
	return 0;
}

int showMainMenu(void)
{
	printf("================���˵�==================\n");
	printf("\t1.�鿴��������\n");
	printf("\t2.�鿴�����б�\n");
	printf("\t3.�鿴װ���嵥\n");
	printf("\t4.�鿴�����嵥\n");
	printf("\t5.ȥ���\n");
	printf("\t6.�浵�Ͷ���\n");
	printf("\t7.�˳���Ϸ\n");
	printf("========================================\n\n");		
} 

int  showEixt(void)
{
	
	
	return 0;
}
