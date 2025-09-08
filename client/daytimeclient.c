#include <netinet/in.h>
#include <strings.h>
#include <arpa/inet.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	
	
	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(13);
	int n = inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
	printf("%d\n", n);
	return 0;		
}	
