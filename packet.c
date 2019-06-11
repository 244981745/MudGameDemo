/*************************************************
Copyright (C), 2019-2019, DREACYOU
File name:	packet.c
Author:		DREACYOU
Version:	0.0.1.0
Date:		2019.6.11
Description: 包裹系统 
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

//原子操作

/*************************************************
Function: creatNode
Description: 创建链表节点，并赋值 
Calls: 
Called By: 

Input: Items dropitem
Output: struct PacketLinkNode*
Return: 正确返回所创建的节点指针，出错返回NULL 
Others: 
*************************************************/
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


/*************************************************
Function: destroyNode
Description: 销毁节点 
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
Description: 构造一个空链表 (创建头节点) 
Calls: 
Called By: 

Input: struct PacketLink *L
Output: 
Return: 出错返回-1，正确返回0 
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
Description: 销毁一个链表
Calls: 
Called By: 

Input: struct PacketLink *L
Output: 
Return: 出错返回-1，正确返回0 
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
Description: 清空一个链表
Calls: 
Called By: 

Input: struct PacketLink *L
Output: 
Return: 返回0
Others: 
*************************************************/
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

/*************************************************
Function: listEmpty
Description: 查询链表是否为空 
Calls: 
Called By: 

Input: struct PacketLink *L
Output: 
Return: 空链表返回true，非空链表返回false 
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
Description: 查询链表长度
Calls: 
Called By: 

Input: struct PacketLink *L
Output: 
Return: 返回链表长度 
Others: 
*************************************************/
int listLength(struct PacketLink *L)
{
	return L->link_len;
}

/*************************************************
Function: getElem
Description: 获取链表第i个节点 
Calls: 
Called By: 

Input: struct PacketLink *L, int i,
Output: struct PacketLinkNode *e
Return: 找到节点i返回0，未找到返回-1 
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
Description: 在链表末尾插入节点e 
Calls: 
Called By: 

Input: struct PacketLink *L, struct PacketLinkNode *e
Output: 
Return: 出错返回false 正确返回0 
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
Description: 在链表中消耗1个单位的物品e 
Calls: 
Called By: 

Input: struct PacketLink *L, Items e
Output: 
Return: 出错返回-1； 正确返回0 
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
Description: 访问节点信息并输出 
Calls: 
Called By: 

Input: struct PacketLinkNode *node,int offset
Output: 
Return: 返回0 
Others: 
*************************************************/
int visit(struct PacketLinkNode *node,int offset)
{
	printf("PacketItem[%d] ID : %d\n",offset,node->ID);
	return 0;
}

/*************************************************
Function: listTraverse
Description: 遍历链表 
Calls: 
Called By: 

Input: struct PacketLink *L
Output: 
Return: 返回0 
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

