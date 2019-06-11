#include <stdio.h>
#include "config.h"

int main(int argc, char **argv)
{
//	printf("%s\n",Monster[0].Name);
//	showMonsterList();
//	showAttritube(Neo,1);
//	battle(&Neo,Monster[0]);
//	showAttritube(Neo,1);
//	battle(&Neo,Monster[0]);
//	showAttritube(Neo,1);

	battleResult(battle(&Neo,Monster[0]),Monster[0].Name);
	
	return 0;
}
