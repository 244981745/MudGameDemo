#include <stdio.h>
#include "config.h"

int main(int argc,char **argv)
{
	//��������
	//ѡ��ʼ��Ϸ���������˳�����
	char key;
	int run = 1;
	struct PacketLink gamepack;
	initList(&gamepack);
	
	while(run)//��ѭ�� 
	{
		//���˵�
		system("cls");
		showMainMenu();
		key = getch();
		switch(key)
		{
			case	'1':	showAttritube(Neo,1);	getch();	break;
			case	'2':	showMonsterList();		getch();	break;
			case	'3':	showMilitary();			getch();	break;
			case	'4':	showPacket(&gamepack);	getch();	break;
			case	'5':							getch();	break;
			//case	'6':	showSaveAndLoad();		getch();	break;
			case	'7':	showEixt();run = 0;		getch();	break;
			default	:printf("����������˶�\n");	getch();	break;
		}
	}
	;
	
	return 0;
}
