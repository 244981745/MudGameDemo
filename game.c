#include <stdio.h>
#include "config.h"

int main(int argc,char **argv)
{
	//欢饮界面
	//选择开始游戏，读档和退出界面
	char key;
	int run = 1;
	struct PacketLink gamepack;
	initList(&gamepack);
	
	while(run)//主循环 
	{
		//主菜单
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
			default	:printf("输入有误，请核对\n");	getch();	break;
		}
	}
	;
	
	return 0;
}
