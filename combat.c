/*************************************************
Copyright (C), 2019-2019, DREACYOU
File name:	combat.c
Author:		DREACYOU
Version:	0.0.1.0
Date:		2019.6.11
Description: ս��ϵͳ 
Others: 
Function List: 

History: 

*************************************************/
#include "datastruct.h"


/*************************************************
Function: battle
Description: ��� 
Calls: 
Called By: 

Input: TheOne *protagonist,SpiritAttribute Monster
Output: 
Return: ʤ������1����ɱ������-1 
Others: 
*************************************************/
int battle(TheOne *protagonist,SpiritAttribute Monster)
{
	while(1)
	{
		//��������
		Monster.HP		-=	protagonist->ATK-Monster.DEF;
		printf("�㹥����%s��%s�ܵ�%d���˺�\n",Monster.Name,Monster.Name,protagonist->ATK-Monster.DEF);
		if(Monster.HP < 1 )			break;
		
		//������
		protagonist->HP	-=	Monster.ATK-protagonist->DEF;
		printf("%s�������㣬���ܵ�%d���˺�\n",Monster.Name,Monster.ATK-protagonist->DEF);
		if(protagonist->HP < 1 )	break;
	}
	
	if(protagonist->HP > 0) return 1;	//ɱ������ 
	return -1;		//��ɱ�� 
}

