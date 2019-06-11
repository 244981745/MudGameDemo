#include "datastruct.h"


Items dropItem[]	=
{
	{0,"knife",		0,0,10,0,0,0,0x01},		//小刀		0
	{1,"Shield",	0,0,0,0,10,0,0x02},		//护盾		1
};

//通过两层索引来计算和保存掉落物品的概率
//第一层用drop[i][j],i = 0保存所指向物品的索引号
//通过dropItem[drop[0][j]]获取物品属性，i= 1指向掉落的概率

int DroppedLoot(TheOne protagonist,unsigned int monsterkeep)
{
	//百分百掉落
	if(monsterkeep < DROPITEMIDMAX)
		return monsterkeep;
	else
		return -1;
}



