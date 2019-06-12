//#include "packet.c"
#include "config.h" 

int main()
{
	struct PacketLink gamepack;
	struct PacketLinkNode	*p1;
	 
	initList(&gamepack);
	//printf("%d\n",gamepack.link_len);
	//printf("%p,%p\n",gamepack.head,gamepack.head->next);
	p1	=	creatNode(dropItem[0]);
	//visit((gamepack.head),1);
	listTailInsert(&gamepack,p1);
	listTraverse(&gamepack);
	printf("isempty:%d\n",listEmpty(&gamepack));
	printf("%d\n",listLength(&gamepack));
	
//	clearList(&gamepack);
	listDeleteOneItem(&gamepack,dropItem[0]);
	listTraverse(&gamepack);
	destroyList(&gamepack);
	return 0;
}
