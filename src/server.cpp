#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "../includes/server.h"
#include "../includes/request.h"

int main(int argc, char **argv) {

  Server server;

  RequestHandler request;
  int server_fd = server.server_create(8000, 14);
 
    server.GET("/index", "index.html");
  server.GET("/home", "home.html");
  server.GET("/about", "about.html");


  close(server_fd);

  return 0;
};
