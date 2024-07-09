#ifndef SERVER_H
#define SERVER_H

#include <arpa/inet.h>
#include <cerrno>
#include <iostream>
#include <netdb.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

class Server {
public:
  inline int server_create(int port, int connection_backlog);


private:
};

int Server::server_create(int port, int connection_backlog) {

  int server_fd = socket(AF_INET, SOCK_STREAM, 0);

  if (server_fd < 0) {
    std::cerr << "[!]Error: Failed to create server socket\n";
    return -1;
  }

  int reuse = 1;
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(reuse)) <
      0) {
    std::cerr << "[!]Error: setsockopt failed\n";
    return -1;
  }

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(port);

  if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) !=
      0) {
    std::cerr << "[!]Error: Failed to bind to port \n" << port << std::endl;
    return -1;
  }

  if (listen(server_fd, connection_backlog) != 0) {
    return -1;
  }

  return server_fd;
};


#endif
