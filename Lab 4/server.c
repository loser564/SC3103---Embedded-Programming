#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
void error(char *m)
{
    perror(m);
}
int main(int argc, char *argv[])
{ 
    int sockfd, newsockfd, port, clilen, n;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    if (argc < 2)
    error("ERROR, no port provided\n");
    port = atoi(argv[1]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    error("ERROR opening socket");
    memset(((char *) &serv_addr), 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port); //host to network
    if (bind(sockfd, (struct sockaddr *)&serv_addr,
    sizeof(serv_addr)) < 0)
    error("ERROR binding to socket");

    listen(sockfd,2);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd,(structsockaddr *)
    &cli_addr, &clilen);
    if (newsockfd < 0) error("ERROR on accept");
    n = read(newsockfd,buffer,255);
    if (n < 0) error("ERROR reading from socket");
    printf("Message received: %s\n",buffer);
    n = write(newsockfd,"Message acknowledged",21);
    if (n < 0)
    error("ERROR writing back to socket");
    return 0;
    }