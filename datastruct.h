#ifndef	_DATASTRUCT_H
#define	_DATASTRUCT_H

#define DROPITEMIDMAX		2	//��ƷID������
#define	MONSTERIDMAX		3	//����ID������


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

