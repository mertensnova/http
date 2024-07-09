#include <arpa/inet.h>
#include <iostream>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "../includes/client.h"
#include "../includes/server.h"
#include "../includes/request.h"

int main(int argc, char **argv) {

  Server server;
  ClientHandler client;
  RequestHandler request;

  int server_fd = server.server_create(8000, 14);
  SClient cc = client.client_accept(server_fd);

  std::cout << cc.buffer << std::endl;

  server.GET("/index", "index.html");
  server.GET("/home", "home.html");
  server.GET("/about", "about.html");

  close(cc.client_fd);
  close(server_fd);

  return 0;
};
