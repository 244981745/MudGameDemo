#include "datastruct.h"


Items dropItem[]	=
{
	{0,"knife",		0,0,10,0,0,0,0x01},		//С��		0
	{1,"Shield",	0,0,0,0,10,0,0x02},		//����		1
};

//ͨ����������������ͱ��������Ʒ�ĸ���
//��һ����drop[i][j],i = 0������ָ����Ʒ��������
//ͨ��dropItem[drop[0][j]]��ȡ��Ʒ���ԣ�i= 1ָ�����ĸ���

int DroppedLoot(TheOne protagonist,unsigned int monsterkeep)
{
	//�ٷְٵ���
	if(monsterkeep < DROPITEMIDMAX)
		return monsterkeep;
	else
		return -1;
}



