#include <arpa/inet.h>
#include <iostream>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "../includes/client.h"
#include "../includes/server.h"
#include "../includes/request.h"
#include "../includes/routes.h"

int main(int argc, char **argv) {

  Server server;
  RoutesHandler route;
  ClientHandler client;
  RequestHandler request;

  int server_fd = server.server_create(8000, 14);
  SClient cc = client.client_accept(server_fd);

  std::cout << cc.buffer << std::endl;

  if (request.request_check_method(cc.buffer,"GET")) {
      auto route = request.request_parse_url(cc.buffer);
  }

  route.GET("/index", "index.html");

  close(cc.client_fd);
  close(server_fd);

  return 0;
};
