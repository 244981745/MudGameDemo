/*************************************************
Copyright (C), 2019-2019, DREACYOU
File name:	datastruct.h 
Author:		DREACYOU
Version:	0.0.1.0
Date:		2019.6.12
Description: 包裹链数据结构和函数声明 
Others: 
Function List: 

History: 

*************************************************/
#ifndef	_PACKET_H
#define	_PACKET_H

#define	false	-1
#define	true	0
#define NULL	((void *)0)


struct PacketLinkNode{
	unsigned int	ID;
	unsigned char	Name[12];
	unsigned int	HP;
	unsigned int	MP;
	unsigned int	ATK;
	unsigned int	MATK;
	unsigned int	DEF;
	unsigned int	MDEF;
	
	unsigned int	location;
	unsigned int	num;
	
	struct PacketLinkNode *next;

};

struct PacketLink{
	struct PacketLinkNode *head;
	int link_len;
};

//fun
struct PacketLinkNode *creatNode(Items dropitem);
void destroyNode(struct PacketLinkNode *node);
int initList(struct PacketLink *L);
int destroyList(struct PacketLink *L);
int clearList(struct PacketLink *L);
int listEmpty(struct PacketLink *L);
int listLength(struct PacketLink *L);
int getElem(struct PacketLink *L, int i, struct PacketLinkNode *e);
int listTailInsert(struct PacketLink *L, struct PacketLinkNode *e);
int listDeleteOneItem(struct PacketLink *L, Items e);
int visit(struct PacketLinkNode *node,int offset);
int listTraverse(struct PacketLink *L);


#endif
