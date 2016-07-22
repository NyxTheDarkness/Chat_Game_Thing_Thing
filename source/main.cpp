//#include "server.h"
#include "logging.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include <unistd.h>


#define PORT 1337

struct sockaddr_in serv_addr, cli_addr;


void Server(int sock)
{
  int newsock;
  socklen_t cliLen;

  listen(sock,5);
  UpdateStatus("Listening");

  cliLen = sizeof(cli_addr);
  newsock = accept(sock, (struct sockaddr *) &cli_addr, &cliLen);
  if (newsock < 0)
  {
      UpdateStatus("ERROR on accept");
  }
  else
  {
    UpdateStatus("Connected");
  }

  char buffer[256];
  bzero(buffer,256);
  read(newsock,buffer,255);
  write(newsock,"hi\n",18);
  UpdateStatus(buffer);
}

int SetupSockets()
{
  int sock, newsock;
  int optval;
  int optlen;
  char *optval2;
  socklen_t clilen;
  int n;
  sock = socket(AF_INET, SOCK_STREAM, 0);
  setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval);
  if (sock < 0)
     UpdateStatus("ERROR opening socket");
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(PORT);
  if (bind(sock, (struct sockaddr *) &serv_addr,
           sizeof(serv_addr)) < 0)
           UpdateStatus("ERROR on binding, is port 1337 being used?");
  return sock;
}

int main()
{
  ShowTitleScreen();
  int sock = SetupSockets();
  Server(sock);
  return 0;
}
