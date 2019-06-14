# MudGameDemo

一个mud游戏的demo，为实现cmd版的魔塔做的准备

filetree
    combat.c    //战斗系统
    config.h    //配置文件，用来包含出主函数外的.c文件
    datastruct.h  //数据结构文件
    game.c      //游戏主体文件
    game.db     //存单索引
    gutscript.c //脚本，用来保存如欢迎界面等文本，但未使用
    interface.c //负责界面的所有函数
    monster.c   //怪物和主角初始化
    monster.xlsx//怪物清单
    packet.c  //包裹系统
    packet.h  //包裹系统的数据结构
    prop.c    //物品系统
    save&load.c //存档和读档
    test.c    //主体测试文件
    testlink.c  //包裹链测试文件
    脑图.xmind  //游戏结构脑图
    道具列表.xlsx //如文件名
    
    如编译器无法对game.c直接编译整个游戏，根据报错信息自行建立工程或makefile，建立工程无需启用config.h，但需要将数据结构的头文件包含到game文件中。
    虽然更多细节没有完善，但up主决定不再对这个demo进行开发。
    9102-6-14
