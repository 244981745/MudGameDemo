#include <stdio.h>
#include <winsock.h>
#include <winsock2.h>

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


