/*************************************************
Copyright (C), 2019-2019, DREACYOU
File name:	prop.c
Author:		DREACYOU
Version:	0.0.1.0
Date:		2019.6.11
Description: ����ϵͳ 
Others: 
Function List: 

History: 

*************************************************/
#include "datastruct.h"
#include <math.h>

Items dropItem[]	=
{
	{0,"knife",		0,0,10,0,0,0,0x01},		//С��		0
	{1,"Shield",	0,0,0,0,10,0,0x02},		//����		1
};

//ͨ����������������ͱ��������Ʒ�ĸ���
//��һ����drop[i][j],i = 0������ָ����Ʒ��������
//ͨ��dropItem[drop[0][j]]��ȡ��Ʒ���ԣ�i= 1ָ�����ĸ���


Items military[MILIIDMAX]={0};


/*************************************************
Function: DroppedLoot
Description: ��Ʒ�������
Calls: 
Called By: 

Input: TheOne protagonist,unsigned int monsterkeep
Output: PacketLink *L
Return: ��ȷ������ƷID��������-1 
Others: 
*************************************************/
int DroppedLoot(TheOne protagonist,unsigned int monsterkeep,struct PacketLink *L)
{
	struct PacketLinkNode	*p;
	//�ٷְٵ���
	if(monsterkeep < DROPITEMIDMAX)
	{
		p	=	creatNode(dropItem[monsterkeep]);
		listTailInsert(L,p);
		return monsterkeep;
	}
	else
		return -1;
}

int changeMilitary(TheOne *protagonist,struct PacketLink *L,int ItemID,int from)
{
	int miloffset=0,temp = dropItem[ItemID].location;
	struct PacketLinkNode *p;
	while(temp > 1)
	{
		temp >>= 1;
		miloffset++;
	}
	
	if(from == 1)//����->װ�� 
	{
		if(protagonist->equipment & dropItem[ItemID].location == dropItem[ItemID].location)//����
		{
			p = creatNode(military[miloffset]);
			if(p == NULL)return -1;
			memcpy((void *)&military[miloffset],(const void*)&dropItem[ItemID],sizeof(Items));
			listTailInsert(L,p);
			listDeleteOneItem(L,dropItem[ItemID]);
		}
		else	//onlyװ��
		{
			memcpy((void *)&military[miloffset],(const void*)&dropItem[ItemID],sizeof(Items));
			listDeleteOneItem(L,dropItem[ItemID]);
			protagonist->equipment |= dropItem[ItemID].location;
		}
	}
	else if(from == 2) //װ��->���� onlyжװ
	{
		p = creatNode(military[miloffset]);		
		if(p == NULL)return -1;
		listTailInsert(L,p);
		memset((void*)&military[miloffset],'\0',sizeof(Items));
		protagonist->equipment &= ~dropItem[ItemID].location;
	}
	else	//����
	{
		return -1;
	}
	
	return 0;
}


