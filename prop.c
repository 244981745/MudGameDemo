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
Output: 
Return: ��ȷ������ƷID��������-1 
Others: 
*************************************************/
int DroppedLoot(TheOne protagonist,unsigned int monsterkeep)
{
	//�ٷְٵ���
	if(monsterkeep < DROPITEMIDMAX)
		return monsterkeep;
	else
		return -1;
}




