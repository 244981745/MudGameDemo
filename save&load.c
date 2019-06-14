#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "datastruct.h"

#define FILENAMEMAX		20

Items military1[MILIIDMAX]={0};
extern Items military[MILIIDMAX];
int gameSave(TheOne *protagonist, struct PacketLink *L)
{
	int i;
	FILE *pDB,*fp;
	struct PacketLinkNode *p1;
	time_t	seconds =0;
	char enable[2] = {0x00,0x01};
	char filename[FILENAMEMAX];
	char temp[5];
	struct tm	*timeinfo;
	seconds		=	time(NULL);
	timeinfo	=	localtime(&seconds);
//	printf("%d\n",seconds);
//	printf("%d:%d:%d,%d-%d-%d\n",timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_year+1900,timeinfo->tm_mon+1,timeinfo->tm_mday);
	
	itoa((timeinfo->tm_year+1900),filename,10);
	itoa((timeinfo->tm_mon+1),temp,10);
	strcat(filename,temp);	
	itoa((timeinfo->tm_mday),temp,10);
	strcat(filename,temp);
	
	itoa((timeinfo->tm_hour),temp,10);
	strcat(filename,temp);
	itoa((timeinfo->tm_min),temp,10);
	strcat(filename,temp);
	itoa((timeinfo->tm_sec),temp,10);
	strcat(filename,temp);
	
	pDB	=	fopen("game.db","ab+");
	if(pDB == NULL)return -1;
	fwrite((void *)enable,1,2,pDB);
	fwrite((void *)filename,1,FILENAMEMAX,pDB);
	fclose(pDB);
	
//	printf("%s\n",filename);
	strcat(filename,".save");
	printf("%s\n",filename);
	fp = fopen(filename,"wb+");
	if(fp == NULL)return -1;
	fwrite((void *)protagonist,1,sizeof(TheOne),fp);
	for(i = 0; i < MILIIDMAX; i++)
	{
		fwrite((void *)military,1,sizeof(Items),fp);
	}
	p1 = L->head->next;
	for(i = 0; i < L->link_len; i++)
	{
		if(p1 == NULL)break;
		fwrite((void *)p1,1,sizeof(struct PacketLinkNode),fp);
		p1 = p1->next;
	}
	fclose(fp);


	return 0;
}

int gameLoad(TheOne *protagonist, struct PacketLink *L)
{
	FILE *pDB,*fp;
	int r,i;
	struct PacketLinkNode *p;
	struct PacketLinkNode node1;
	pDB	=	fopen("game.db","rb+");
	if(pDB == NULL)return -1;
	char filename[FILENAMEMAX];
	char enable[2];
	while(1)
	{
		fread((void *)enable,1,2,pDB);
		r = fread((void *)filename,1,FILENAMEMAX,pDB);
		if(r > 4)printf("%s\n",filename);
		if(feof(pDB))break;
	}
	fclose(pDB);
	
	strcat(filename,".save");
	printf("%s\n",filename);
	fp = fopen(filename,"rb+");
	if(fp == NULL)return -1;
	fread((void *)protagonist,1,sizeof(TheOne),fp);
	for(i = 0; i < MILIIDMAX; i++)
	{
		r = fread((void *)military,1,sizeof(Items),fp);
	}
	
	while(!feof(fp))
	{
		r = fread((void *)&node1,1,sizeof(struct PacketLinkNode),fp);
		printf("offset:%d\n",ftell(fp));
		if(r == sizeof(struct PacketLinkNode))
		{
			p	=	(struct PacketLinkNode *)malloc(sizeof(struct PacketLinkNode));
			if(p == NULL)break;
			else
			{
				memset((void *)p,'\0',sizeof(struct PacketLinkNode));
				memcpy((void *)p,(void *)&node1,sizeof(struct PacketLinkNode));
				p->next	=	NULL;
				listTailInsert(L,p);
			}
		}
	}
	
	fclose(fp);
		
	return 0;
}




