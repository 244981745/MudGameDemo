/*************************************************
Copyright (C), 2019-2019, DREACYOU
File name:	packet.c
Author:		DREACYOU
Version:	0.0.1.0
Date:		2019.6.11
Description: ����ϵͳ 
Others: 
Function List: 

History: 

*************************************************/
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

//ԭ�Ӳ���

/*************************************************
Function: creatNode
Description: ��������ڵ㣬����ֵ 
Calls: 
Called By: 

Input: Items dropitem
Output: struct PacketLinkNode*
Return: ��ȷ�����������Ľڵ�ָ�룬������NULL 
Others: 
*************************************************/
struct PacketLinkNode*
 creatNode(Items dropitem)
{
	int i;
	struct PacketLinkNode *node;
	node = (struct PacketLinkNode *)malloc(sizeof(struct PacketLinkNode));
	if(node == NULL)return NULL;
	//��ֵ
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


/*************************************************
Function: destroyNode
Description: ���ٽڵ� 
Calls: 
Called By: 

Input: struct PacketLinkNode *node
Output: 
Return: void 
Others: 
*************************************************/
void destroyNode(struct PacketLinkNode *node)
{
	free(node);
	node	=	NULL;
}


/*************************************************
Function: initList
Description: ����һ�������� (����ͷ�ڵ�) 
Calls: 
Called By: 

Input: struct PacketLink *L
Output: 
Return: ������-1����ȷ����0 
Others: 
*************************************************/
int initList(struct PacketLink *L)
{
	L->head			=	(struct PacketLinkNode *)malloc(sizeof(struct PacketLinkNode));
	if(L->head == NULL)return -1;
	L->link_len		=	0;
	L->head->next	=	NULL;
	
	return 0;
}

/*************************************************
Function: destroyList
Description: ����һ������
Calls: 
Called By: 

Input: struct PacketLink *L
Output: 
Return: ������-1����ȷ����0 
Others: 
*************************************************/
int destroyList(struct PacketLink *L)
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

/*************************************************
Function: clearList
Description: ���һ������
Calls: 
Called By: 

Input: struct PacketLink *L
Output: 
Return: ����0
Others: 
*************************************************/
int clearList(struct PacketLink *L)			//���Ա����,��L����Ϊ�ձ�
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

/*************************************************
Function: listEmpty
Description: ��ѯ�����Ƿ�Ϊ�� 
Calls: 
Called By: 

Input: struct PacketLink *L
Output: 
Return: ��������true���ǿ�������false 
Others: 
*************************************************/
int listEmpty(struct PacketLink *L)
{
	if(L->head == NULL)
	{
		L->link_len = 0;
		return true;
	}
	
	return false;
}

/*************************************************
Function: listLength
Description: ��ѯ������
Calls: 
Called By: 

Input: struct PacketLink *L
Output: 
Return: ���������� 
Others: 
*************************************************/
int listLength(struct PacketLink *L)
{
	return L->link_len;
}

/*************************************************
Function: getElem
Description: ��ȡ�����i���ڵ� 
Calls: 
Called By: 

Input: struct PacketLink *L, int i,
Output: struct PacketLinkNode *e
Return: �ҵ��ڵ�i����0��δ�ҵ�����-1 
Others: 
*************************************************/
int getElem(struct PacketLink *L, int i, struct PacketLinkNode *e)
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
	return -1;
}

/*************************************************
Function: listTailInsert
Description: ������ĩβ����ڵ�e 
Calls: 
Called By: 

Input: struct PacketLink *L, struct PacketLinkNode *e
Output: 
Return: ������false ��ȷ����0 
Others: 
*************************************************/
int listTailInsert(struct PacketLink *L, struct PacketLinkNode *e)
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

/*************************************************
Function: listDeleteOneItem
Description: ������������1����λ����Ʒe 
Calls: 
Called By: 

Input: struct PacketLink *L, Items e
Output: 
Return: ������-1�� ��ȷ����0 
Others: 
*************************************************/
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

/*************************************************
Function: visit
Description: ���ʽڵ���Ϣ����� 
Calls: 
Called By: 

Input: struct PacketLinkNode *node,int offset
Output: 
Return: ����0 
Others: 
*************************************************/
int visit(struct PacketLinkNode *node,int offset)
{
	printf("PacketItem[%d] ID : %d\n",offset,node->ID);
	return 0;
}

/*************************************************
Function: listTraverse
Description: �������� 
Calls: 
Called By: 

Input: struct PacketLink *L
Output: 
Return: ����0 
Others: 
*************************************************/
int listTraverse(struct PacketLink *L)
{
	int i;
	struct PacketLinkNode *p = L->head;
	for(i = 0; i < L->link_len; i++)
		visit(p,i);
	return 0;
}

