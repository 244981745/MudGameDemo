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


Items dropItem[]	=
{
	{0,"knife",		0,0,10,0,0,0,0x01},		//小刀		0
	{1,"Shield",	0,0,0,0,10,0,0x02},		//护盾		1
};

//通过两层索引来计算和保存掉落物品的概率
//第一层用drop[i][j],i = 0保存所指向物品的索引号
//通过dropItem[drop[0][j]]获取物品属性，i= 1指向掉落的概率

/*************************************************
Function: DroppedLoot
Description: 物品掉落计算 
Calls: 
Called By: 

Input: TheOne protagonist,unsigned int monsterkeep
Output: 
Return: 正确返回物品ID，出错返回-1 
Others: 
*************************************************/
int DroppedLoot(TheOne protagonist,unsigned int monsterkeep)
{
	//百分百掉落
	if(monsterkeep < DROPITEMIDMAX)
		return monsterkeep;
	else
		return -1;
}



