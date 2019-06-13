/*************************************************
Copyright (C), 2019-2019, DREACYOU
File name:	prop.c
Author:		DREACYOU
Version:	0.0.1.0
Date:		2019.6.11
Description: 道具系统 
Others: 
Function List: 

History: 

*************************************************/
#include "datastruct.h"
#include <math.h>

Items dropItem[]	=
{
	{0,"knife",		0,0,10,0,0,0,0x01},		//小刀		0
	{1,"Shield",	0,0,0,0,10,0,0x02},		//护盾		1
};

//通过两层索引来计算和保存掉落物品的概率
//第一层用drop[i][j],i = 0保存所指向物品的索引号
//通过dropItem[drop[0][j]]获取物品属性，i= 1指向掉落的概率


Items military[MILIIDMAX]={0};


/*************************************************
Function: DroppedLoot
Description: 物品掉落计算
Calls: 
Called By: 

Input: TheOne protagonist,unsigned int monsterkeep
Output: PacketLink *L
Return: 正确返回物品ID，出错返回-1 
Others: 
*************************************************/
int DroppedLoot(TheOne protagonist,unsigned int monsterkeep,struct PacketLink *L)
{
	struct PacketLinkNode	*p;
	//百分百掉落
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
	
	if(from == 1)//包裹->装备 
	{
		if(protagonist->equipment & dropItem[ItemID].location == dropItem[ItemID].location)//更换
		{
			p = creatNode(military[miloffset]);
			if(p == NULL)return -1;
			memcpy((void *)&military[miloffset],(const void*)&dropItem[ItemID],sizeof(Items));
			listTailInsert(L,p);
			listDeleteOneItem(L,dropItem[ItemID]);
		}
		else	//only装备
		{
			memcpy((void *)&military[miloffset],(const void*)&dropItem[ItemID],sizeof(Items));
			listDeleteOneItem(L,dropItem[ItemID]);
			protagonist->equipment |= dropItem[ItemID].location;
		}
	}
	else if(from == 2) //装备->包裹 only卸装
	{
		p = creatNode(military[miloffset]);		
		if(p == NULL)return -1;
		listTailInsert(L,p);
		memset((void*)&military[miloffset],'\0',sizeof(Items));
		protagonist->equipment &= ~dropItem[ItemID].location;
	}
	else	//出错
	{
		return -1;
	}
	
	return 0;
}


