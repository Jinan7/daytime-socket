#include <netinet/in.h>
#include <strings.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
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
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	
	//convert server socket to listening socket
	listen(listenfd, 5);
	
	//accept connection from clients
	int connfd;
	char buff[50];
	socklen_t len;
	for (;;)
	{
		len = sizeof(cliaddr);
		
		connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &len);
		const char *fi = inet_ntop(AF_INET, &cliaddr.sin_addr, buff, sizeof(buff));
		
		printf("client\nIP Address: %s\nPort: %d\n", fi, ntohs(cliaddr.sin_port));
		close(connfd);
	}
	return 0;
}
