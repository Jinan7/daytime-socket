#include <netinet/in.h>
#include <strings.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <sys/socket.h>
int main(int argc, char **argv)
{
	
	//create server socket address
	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(13);
	int n = inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
	
	//debug
	printf("%d\n", n);
	
	
	//create socket
	int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	//debug
	printf("%d\n", sockfd);
	
	//connect socket to server 
	int status = connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	
	//debug
	printf("%d\n", status);
	return 0;		
}	
