#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Error Function
void error(const char *msg)
{
	perror(msg);
	exit(1);
}

// Main Function

int main(int argc,char *argv[])
{
	// Required Variables
	int sockfd,portno,n;
	struct sockaddr_in serv_addr;
	struct hostnet *server;
	// buffer to send our message
	char buffer[255];

	// argc = total parameters passing to program
	// argv contains file name and portnumber

	// Check if Required 3 Parameters are Provided
	if(argc<3)
	{
		fprintf(stderr,"Usage %s Hostname Port\n",argv[0]);
		exit(0);	
	}
	// Get the Port number from the arguments and convert its type
	portno=atoi(argv[1]);

	// Implementing the Socket
	sockfd= socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
		error("Error Opening the Socket");
	}

	server=gethostbyname(argv[1]);

	if(server==NULL)
	{
		fprintf(stderr,"No Such Host Exist\n");
	}
	//clears buffers
	bzero((char *)&serv_addr,sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	bcopy((char *) server->_addr ,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
	serv_addr.sin_port=htons(portno);

	if(connect(sockfd,(struct sock_addr)&serv_addr,sizeof(serv_addr))<0)
	{
		error("Connection Failed !");
	}

	while(1)
	{
		bzero(buffer,255);
		fgets(buffer,255,stdin);
		n=write(sockfd,buffer,strlen(buffer));
		if(n<0)
		{
			error("Failed to Write\n");
		}
		bzero(buffer,255);
		n=read(sockfd,buffer,255);
		if(n<0)
		{
			error("Error at Reading from Server\n");
		}
		printf("Server: %s",buffer);
		int i=strncmp("bye",buffer,3);
		if(i==0)
		{
			break;
		}
	}
	close(sockfd);
	return 0;
}