#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Error Function
void error(const char *msg)
{
	perror(msg);
	exit(1);
}

// Main Function

int main(int argc,char *argv[])
{
	// argc = total parameters passing to program
	// argv contains file name and portnumber

	// Check if Required 2 Parameters are Provided
	if(argc<2)
	{
		fprintf(stderr,"Port Number Not Provided.Closing the Program\n");
		exit(1);	
	}

	int sockfd,newsockfd,portno,n;
	// buffer to send our message
	char buffer[255];

	// Required Variables
	struct sockaddr_in serv_addr , cli_addr;
	socklen_t clilen;

	// Implementing the Socket
	sockfd= socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
		error("Error Opening The Socket");
	}
	// Clears anything in the Server
	bzero((char *)&serv_addr,sizeof(serv_addr));
	// Get the Port number from the arguments and convert its type
	portno=atoi(argv[1]);

	serv_addr.sin_family= AF_INET;
	serv_addr.sin_addr.s_addr=INADDR_ANY;
	// host to network shot
	serv_addr.sin_port=htons(portno);

	// Binding
	if(bind(sockfd ,(struct sockaddr *)&serv_addr , sizeof(serv_addr)) < 0 )
	{
		error("Binding Failed");
	}
	// Listen     5 represent nu,ber of clients server can handle
	listen(sockfd,5);
	clilen=sizeof(cli_addr);

	// Accept
	newsockfd=accept(sockfd,(struct sockaddr *)&cli_addr,&clilen);
	if(newsockfd<0)
	{
		error("Error on Accepting");
	}
	// Loop Untill Chat Ends
	while(1)
	{
		bzero(buffer,255);
		n=read(newsockfd,buffer,255);
		if(n<0)
		{
			error("Error On Reading From Client");
		}
		else 
		{
			printf("client :%s\n" , buffer);
		}

		// clears the buffers
		bzero(buffer,255);
		// get reply from server and sends to client
		fgets(buffer,255,stdin);

		n=write(newsockfd,buffer,strlen(buffer));
		if(n<0)
		{
			error("Error On writting");
		}
		// To Get out of the loop
		int i=strncmp("bye",buffer,3);
		if(i==0)
			break;
	}
	close (newsockfd);
	close(sockfd);
	return 0;
}