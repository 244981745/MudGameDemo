#include <stdio.h>
#include <winsock.h>
#include <winsock2.h>

#define MAX_QUEUE		100
#define BUFFER_SIZE		1024


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
	
	unsigned char recvBuf[1024];
	unsigned char region1[256],region2[256];
	int flag = 0;
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

			//send(clientfd,"hello",6,0);
			recv(clientfd,recvBuf,1024,0);
			
			memset((void*)region1,'\0',256);
			memset((void*)region2,'\0',256);
			buffDecoder(recvBuf, region1, region2, &flag);
			
			
			printf("%s\n%s\n",region1, region2);
			
	        Sleep(1000);
	        closesocket(clientfd);
	
	}
	
	
	closesocket(srvfd);
	WSACleanup();
	
	return 0;
}

int buffDecoder(const unsigned char *buffer, unsigned char *Region1, unsigned char *Region2, int *flag)
{
	int offset = 2;
	int len	=	0;
	int i,j;
	*flag	=	(int)buffer[0];
	i	=	(int)buffer[1];
	
	if( i < 0 )	return -1;
	if( i > 3 )	return -1;
	
	if( i > 0)
	{
		len	=	(int)buffer[offset++];
		for( j = 0; j < len; j++)
			Region1[j]	=	buffer[offset++];
		Region1[j]	=	'\0';
	}
	
	if( i > 1)
	{
		len	=	(int)buffer[offset++];
		for( j = 0; j < len; j++)
			Region2[j]	=	buffer[offset++];
		Region2[j]	=	'\0';
	}
	
	return 0;
}