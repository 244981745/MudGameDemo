#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastruct.h"

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

//原子操作
struct PacketLinkNode*
 creatNode(Items dropitem)
{
	int i;
	struct PacketLinkNode *node;
	node = (struct PacketLinkNode *)malloc(sizeof(struct PacketLinkNode));
	if(node == NULL)return NULL;
	//赋值
	for(i = 0; i < 12; i++)
		node->Name[i]	=	dropitem.Name[i];
	node->ID			=	dropitem.ID;
	node->HP			=	dropitem.HP;
	node->MP			=	dropitem.MP;
	node->ATK			=	dropitem.ATK;
	node->MATK			=	dropitem.MATK;
	node->DEF			=	dropitem.DEF;
	node->MDEF			=	dropitem.MDEF;
	node->location		=	dropitem.location;
	node->num			=	1;
	node->next 			=	NULL;
	return node;
}


void destroyNode(struct PacketLinkNode *node)
{
	free(node);
	node	=	NULL;
}

//
int initList(struct PacketLink *L)			//	构造一个空的线性表
{
	L->head			=	(struct PacketLinkNode *)malloc(sizeof(struct PacketLinkNode));
	if(L->head == NULL)return -1;
	L->link_len		=	0;
	L->head->next	=	NULL;
	
	return 0;
}

int destroyList(struct PacketLink *L)			//线性表存在的前提下,销毁线性表L
{
	struct PacketLinkNode *p1,*p2;
	p1 = L->head->next;
	
	while(p1 != NULL)
	{
		p2 = p1->next;
		destroyNode(p1);
		L->link_len--;
		p1 = p2;
	}
	
	if(L->link_len < 0)return -1;
	free(L->head);
	return 0;
}


int clearList(struct PacketLink *L)			//线性表存在,将L重置为空表
{
	struct PacketLinkNode *p1,*p2;
	p1 = L->head->next;
	
	while(p1 != NULL)
	{
		p2 = p1->next;
		destroyNode(p1);
		L->link_len--;
		p1 = p2;
	}
	
	if(L->link_len != 0)L->link_len = 0;

	return 0;
}

int listEmpty(struct PacketLink *L)			//	线性表存在,L为空表则返回true,否则返回false
{
	if(L->head == NULL)
	{
		L->link_len = 0;
		return true;
	}
	
	return false;
}

int listLength(struct PacketLink *L)		//	线性表存在,返回L中数据元素的个数
{
	return L->link_len;
}


int getElem(struct PacketLink *L, int i, struct PacketLinkNode *e)		//线性表存在,1<< i <<listlength(L),用e返回L中第i个元素的值
{
	int j;
	struct PacketLinkNode *p = L->head;
	if(i > 1 && i < L->link_len)
		for(j = 0; j < L->link_len; j++)
		{
			if(j == i)
				{
					e = p;
					return 0;
				}
			p = p->next;
		}
	e	=	NULL;
	return 1;
}

int listTailInsert(struct PacketLink *L, struct PacketLinkNode *e)			//在L末尾插入新的数据元素e,L的长度+1
{
	if(e ==	NULL)
		return false;
	
	struct PacketLinkNode *p = L->head;
	while(p->next != NULL)
		p = p->next;

	p->next = e;
	L->link_len += 1;
	
	return 0;
}

int listDeleteOneItem(struct PacketLink *L, Items e)
{
	struct PacketLinkNode *pre,*p1 = L->head;
	int i,erro = 0;
	for(i = 0; i < L->link_len; i++)
	{
		pre	=	p1;
		if(p1 == NULL)
		{
			erro = 1;
			break;
		}
		if(p1->ID == e.ID)
		{
			p1->num--;
			if(p1->num == 0)
			{
				pre->next	=	p1->next;
				destroyNode(p1);
				L->link_len--;
			}
			break;
		}
		
		p1 = p1->next;
	}

	if(erro)return -1;
	
	return 0;
}

int visit(struct PacketLinkNode *node,int offset)
{
	printf("PacketItem[%d] ID : %d\n",offset,node->ID);
	return 0;
}

int listTraverse(struct PacketLink *L)		//	依次对L的每个数据元素调用函数vist(),一旦visit失败,则操作失败.
{
	int i;
	struct PacketLinkNode *p = L->head;
	for(i = 0; i < L->link_len; i++)
		visit(p,i);
	return 0;
}

