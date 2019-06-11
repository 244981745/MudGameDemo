/*************************************************
Copyright (C), 2019-2019, DREACYOU
File name:	combat.c
Author:		DREACYOU
Version:	0.0.1.0
Date:		2019.6.11
Description: 战斗系统 
Others: 
Function List: 

History: 

*************************************************/
#include "datastruct.h"


/*************************************************
Function: battle
Description: 打怪 
Calls: 
Called By: 

Input: TheOne *protagonist,SpiritAttribute Monster
Output: 
Return: 胜利返回1，被杀死返回-1 
Others: 
*************************************************/
int battle(TheOne *protagonist,SpiritAttribute Monster)
{
	while(1)
	{
		//主动攻击
		Monster.HP		-=	protagonist->ATK-Monster.DEF;
		printf("你攻击了%s，%s受到%d点伤害\n",Monster.Name,Monster.Name,protagonist->ATK-Monster.DEF);
		if(Monster.HP < 1 )			break;
		
		//被攻击
		protagonist->HP	-=	Monster.ATK-protagonist->DEF;
		printf("%s攻击了你，你受到%d点伤害\n",Monster.Name,Monster.ATK-protagonist->DEF);
		if(protagonist->HP < 1 )	break;
	}
	
	if(protagonist->HP > 0) return 1;	//杀死怪物 
	return -1;		//被杀死 
}

