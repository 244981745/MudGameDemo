#ifndef	_DATASTRUCT_H
#define	_DATASTRUCT_H


//精灵属性 
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

//人物属性 
typedef struct theone
{
	unsigned char	Name[12];
	signed	 int	HP;
	unsigned int	MP;
	unsigned int	ATK;
	unsigned int	MATK;
	unsigned int	DEF;
	unsigned int	MDEF;
	
	unsigned char	sex;	//性别 

}TheOne;

#endif

