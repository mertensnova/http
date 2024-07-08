#include "../includes/server.h"
#include "../includes/client.h"
#include <arpa/inet.h>
#include <iostream>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {

  Server server;
  ClientHandler client;

  int server_fd = server.server_create(8000, 14);
  SClient cc = client.client_accept(server_fd);

  
  std::cout << cc.buffer << std::endl;

  close(cc.client_fd);
  close(server_fd);

  return 0;
}

;
