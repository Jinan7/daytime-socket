#include <netinet/in.h>
#include <strings.h>
#include <stdio.h>
#include <arpa/inet.h>

int main()
{
	//create socket address struct for server and client
	struct sockaddr_in servaddr, cliaddr;
	
	//initialize server socket address struct
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(13);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	//create server socket and bind to address
	int listenfd;
	listenfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	
	//convert server socket to listening socket
	listen(listenfd, 5);
	
	//accept connection from clients
	int connfd;
	socklen_t len;
	for (;;)
	{
		len = sizeof(cliaddr);
		
		connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &len);	
	}
	return 0;
}
