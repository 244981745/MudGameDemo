#include <stdio.h>
#include "config.h"

int main(int argc, char **argv)
{
	struct PacketLink gamepack;
	initList(&gamepack);
	
//	printf("%s\n",Monster[0].Name);
//	showMonsterList();
//	showAttritube(Neo,1);
//	battle(&Neo,Monster[0]);
//	showAttritube(Neo,1);
//	battle(&Neo,Monster[0]);
//	showAttritube(Neo,1);

	
//	battleResult(battle(&Neo,Monster[0]),Monster[0].Name);
	DroppedLoot(Neo,0,&gamepack);
	DroppedLoot(Neo,1,&gamepack);
	//listTraverse(&gamepack);
	showPacket(&gamepack);	
	showAttritube(Neo,1);	
	showMilitary();
	
//	gameSave(&Neo,&gamepack);	//´æµµ 
	
	changeMilitary(&Neo,&gamepack,0,1);
	showAttritube(Neo,1);
	showMilitary();
	showPacket(&gamepack);
	TheOne make;

//	gameLoad(&Neo,&gamepack);	//¶Áµµ 
	showPacket(&gamepack);
	destroyList(&gamepack);
	
	return 0;
}
