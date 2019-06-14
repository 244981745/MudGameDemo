# MudGameDemo

一个mud游戏的demo，为实现cmd版的魔塔做的准备
<br>
filetree
    combat.c    //战斗系统<br>
    config.h    //配置文件，用来包含出主函数外的.c文件<br>
    datastruct.h  //数据结构文件<br>
    game.c      //游戏主体文件<br>
    game.db     //存单索引<br>
    gutscript.c //脚本，用来保存如欢迎界面等文本，但未使用<br>
    interface.c //负责界面的所有函数<br>
    monster.c   //怪物和主角初始化<br>
    monster.xlsx//怪物清单<br>
    packet.c  //包裹系统<br>
    packet.h  //包裹系统的数据结构<br>
    prop.c    //物品系统<br>
    save&load.c //存档和读档<br>
    test.c    //主体测试文件<br>
    testlink.c  //包裹链测试文件<br>
    脑图.xmind  //游戏结构脑图<br>
    道具列表.xlsx //如文件名<br>
    
    如编译器无法对game.c直接编译整个游戏，根据报错信息自行建立工程或makefile，建立工程无需启用config.h，但需要将数据结构的头文件包含到game文件中。
    虽然更多细节没有完善，但up主决定不再对这个demo进行开发。
    9102-6-14
