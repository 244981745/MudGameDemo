#include <stdio.h>
#include <winsock.h>
#include <winsock2.h>
#include "gameclient.h"

int main(int argc, char **argv)
{
	WSADATA	wsadata;
	if( WSAStartup( MAKEWORD(2,2), &wsadata ) != 0 )
	{
		printf("Winsock load faild!\n");
		return -1;
	}
	
	int port		= 9527;
	const char *srvip = "127.0.0.1";
	struct sockaddr_in srvaddr;
    memset(&srvaddr,	sizeof(&srvaddr),	0);
	srvaddr.sin_family = AF_INET;
    srvaddr.sin_addr.S_un.S_addr = inet_addr(srvip);
    srvaddr.sin_port = htons( port );
    
	SOCKET srvfd = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
    if(srvfd < 0)
    {
            printf("socket error.\n");
            WSACleanup();
            exit;
    }
    
    //  连接服务器
    if ( connect(srvfd, &srvaddr, sizeof(srvaddr)) == SOCKET_ERROR )
	{
        printf( "connect faild!\n" );
        closesocket(srvfd);
        WSACleanup();
        return -1;
    }
    
    char recvBuf[1024];
	memset((void *)recvBuf, '\0', 1024); 
	
	recv(srvfd,recvBuf,1024,0);
	printf("recv msg:%s\n",recvBuf);
	send(srvfd,"hello srv",10,0);
	
	
	closesocket(srvfd);
	WSACleanup();
	
	return 0;
}

int userLog(SOCKET srvfd, const char *userName, const char *userPwd)
{
	int flag=0,token = 0;
	unsigned char len;
	unsigned char sendBuf[1024];
	unsigned char recvBuf[1024];
	unsigned char region1[256];
	unsigned char region2[256];
	memset((void *)sendBuf, '\0', 1024);
	memset((void *)recvBuf, '\0', 1024);
	memset((void*)region1, '\0', 256);
	memset((void*)region2, '\0', 256);	
	
	sendBuf[0]	=	0x1;	// logflag
	sendBuf[1]	=	0x2;	//section

	len	=	strlen(userName);
	sendBuf[strlen(sendBuf)]	=	len;
	strcat(sendBuf,userName);
	
	len	=	strlen(userPwd);
	sendBuf[strlen(sendBuf)]	=	len;
	strcat(sendBuf,userPwd);

	send(srvfd,sendBuf,strlen(sendBuf),0);
	
	recv(srvfd,recvBuf,1024,0);
	
	buffDecoder(recvBuf,region1,region2,&flag);

	
	int i;
	for(i = 0; i < 10; i++)
		printf("%x ",recvBuf[i]);
	printf("\n");
	if(flag == 0x80) return -1;
	else
	{
		token	=	region1[0]&&0xff;
		token<<8;
		token	|=	region1[1]&&0xff;
		token<<8;
		token	|=	region1[2]&&0xff;
		token<<8;
		token	|=	region1[3]&&0xff;
	}
	printf("token :%d\n",token);

	return 0;
}

int userLogIn(SOCKET srvfd, const char *userName, const char *userPwd)
{
	unsigned char len;
	unsigned char sendBuf[1024];
	memset((void *)sendBuf, '\0', 1024);

	sendBuf[0]	=	0x2;	// loginflag
	sendBuf[1]	=	0x2;	//section

	len	=	strlen(userName);
	sendBuf[strlen(sendBuf)]	=	len;
	strcat(sendBuf,userName);
	
	len	=	strlen(userPwd);
	sendBuf[strlen(sendBuf)]	=	len;
	strcat(sendBuf,userPwd);

	send(srvfd,sendBuf,strlen(sendBuf),0);
	
	return 0;
}
