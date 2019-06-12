/*************************************************
Copyright (C), 2019-2019, DREACYOU
File name:	datastruct.h 
Author:		DREACYOU
Version:	0.0.1.0
Date:		2019.6.11
Description: ���ݽṹ 
Others: 
Function List: 

History: 

*************************************************/
#ifndef	_DATASTRUCT_H
#define	_DATASTRUCT_H

#define DROPITEMIDMAX		2	//��ƷID������
#define	MONSTERIDMAX		3	//����ID������
#define	MILIIDMAX			8	//װ��ID������


//�������� 
typedef struct spiritattribute
{
	unsigned char	Name[12];
	signed	 int	HP;
	unsigned int	MP;
	unsigned int	ATK;
	unsigned int	MATK;
	unsigned int	DEF;		
	unsigned int	MDEF;
}SpiritAttribute;

//�������� 
typedef struct theone
{
	unsigned char	Name[12];
	signed	 int	HP;
	unsigned int	MP;
	unsigned int	ATK;
	unsigned int	MATK;
	unsigned int	DEF;
	unsigned int	MDEF;
	
	unsigned char	sex;		//�Ա�
	unsigned int	equipment;	//װ��λ״̬

}TheOne;

//��Ʒ����
typedef struct item
{
	unsigned int	ID;
	unsigned char	Name[12];
	unsigned int	HP;
	unsigned int	MP;
	unsigned int	ATK;
	unsigned int	MATK;
	unsigned int	DEF;
	unsigned int	MDEF;
	
	unsigned int	location;
}Items;

#endif

