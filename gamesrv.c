#include <stdio.h>
#include <winsock.h>
#include <winsock2.h>

#define MAX_QUEUE		100
#define BUFFER_SIZE		1024

void SendMsg(SOCKET fd)
{
	
}

void RecvMsg(SOCKET fd)
{
	
}

int main(int argc, char **argv)
{
	WSADATA	wsadata;
	if ( WSAStartup( MAKEWORD(2,2), &wsadata ) != 0 )
	{
		printf( "Winsock load faild!\n" );
		return -1;
	}
    
	struct sockaddr_in srvaddr;
 	struct sockaddr_in clientaddr;
    int port		= 9527;
    memset(&srvaddr,	sizeof(&srvaddr),		0);
    memset(&clientaddr,	sizeof(&clientaddr),	0);
    
    srvaddr.sin_family        = AF_INET;
    srvaddr.sin_port          = htons(port);
    srvaddr.sin_addr.s_addr   = htonl(INADDR_ANY);
    
    int slen		= sizeof(clientaddr);               //accept sockaddr *
	SOCKET	srvfd,clientfd = 0;
	srvfd	=	socket(AF_INET, SOCK_STREAM, 0);
    if(srvfd < 0)
    {
            printf("socket error.\n");
            WSACleanup();
            exit;
    }	
	
	
	if(bind(srvfd, (struct sockaddr *)&srvaddr, sizeof(srvaddr)) == -1)
	{
	    printf("socket bind error.\n");
	    closesocket(srvfd);
	    exit(-1);
	}
	else
	{
	    printf("socket bind success.\n");
	}
	
	if( listen(srvfd,MAX_QUEUE) == -1 )
	{
	    printf("socket listen error.\n");
	    closesocket(srvfd);
	    exit(-1);
	}
	else
	{
	    printf("socket listen success.\n");
	}
	
	char recvBuf[1024];
	memset((void *)recvBuf,'\0',1024);
	for(;;)
    {				
            clientfd = accept(srvfd, (struct sockaddr*)&clientaddr, &slen);
            if(clientfd == -1)
            {
                    printf("service accept error.\n");
                    continue;
            }
            else
            {
                    printf("client:%s link in.\n",inet_ntoa(clientaddr.sin_addr));
            }

			send(clientfd,"hello",6,0);
			recv(clientfd,recvBuf,1024,0);
			
			printf("%s\n",recvBuf);
			
	        Sleep(1000);
	        closesocket(clientfd);
	
	}
	
	
	closesocket(srvfd);
	WSACleanup();
	
	return 0;
}
