/*************************************************
Copyright (C), 2019-2019, DREACYOU
File name: monster.c
Author:		DREACYOU
Version:	0.0.1.0
Date:		2019.6.11
Description: 怪物列表初始化，人物初始化 
Others: 
Function List: 

History: 

*************************************************/
#include "datastruct.h"

//怪物列表 
SpiritAttribute	Monster[]	=
{
	{"Slime",	35,0,18,0,1,1},
	{" Bat ",	35,0,38,0,3,3},
	{"Keeper",	50,0,48,0,22,20},
};

//主角初始属性 
TheOne Neo	=
{
	"Neo", 100,100,20,10,10,10,1,0x0	//主角初始属性
};

