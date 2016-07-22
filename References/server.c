#include "server.h"
#include <sys/socket.h>
#include <netinet/in.h>

void Server()
{
  int sockfd, newsockfd, clilen;
  //char buffer[256];
  struct sockaddr_in serv_addr, cli_addr;
  UpdateStatus("Making socket");
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0)
     error("ERROR opening socket");
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(PORT);
  if (bind(sockfd, (struct sockaddr *) &serv_addr,
           sizeof(serv_addr)) < 0)
           error("ERROR on binding");
  UpdateStatus("Listening");
  listen(sockfd,5);
  clilen = sizeof(cli_addr);
  newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
  UpdateStatus("Connected");
  if (newsockfd < 0)
       error("ERROR on accept");
  //bzero(buffer,256);
  //n = read(newsockfd,buffer,255);
  write(newsockfd,"Hello",18);
}
