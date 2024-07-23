#ifndef SERVER_H
#define SERVER_H

#include <arpa/inet.h>
#include <functional>
#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "./request.h"
#include "./response.h"

#define LISTEN_BACKLOG 10
#define BUFFER_SIZE 3000

class Server {
public:
  size_t peer_fd;
  inline int ServerCreate(int port);
  inline void GET(std::string url, std::function<void(ResponseWritter)> func);
  inline void PeerHandler();

private:
  struct sockaddr_in socket_addr, peer_addr;
  int sock_fd; // Socket file descriptor
  char buffer[BUFFER_SIZE] = {0};
  inline void set(int port);
};

void Server::set(int port) {
  socket_addr.sin_family = AF_INET;
  socket_addr.sin_port = htons(port);
  socket_addr.sin_addr.s_addr = INADDR_ANY;
};

void Server::GET(std::string url, std::function<void(ResponseWritter)> func) {
  Request r;
  std::string sbuff(buffer);
  auto vec = r.request_parse_url(sbuff);

  if ("/" + vec[0] == url) {
    func(ResponseWritter());
  };
  return;
};

int Server::ServerCreate(int port) {

  set(port);
  sock_fd = socket(AF_INET, SOCK_STREAM, 0);

  if (bind(sock_fd, (struct sockaddr *)&socket_addr, sizeof(socket_addr)) ==
      -1) {
    perror("[!] bind()");
    return -1;
  };

  int reuse = 1;
  if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) <
      0) {
    perror("[!] setsockopt()");
    return -1;
  };
  if (listen(sock_fd, LISTEN_BACKLOG) == -1) {
    perror("[!] listen()");
    return -1;
  };

  PeerHandler();
  return 0;
};

void Server::PeerHandler() {
  while (true) {

    socklen_t peer_addr_size = sizeof(peer_addr);

    if ((peer_fd = accept(sock_fd, (struct sockaddr *)&peer_addr,
                          &peer_addr_size)) == -1) {
      perror("[!] accept()");
      return;
    };

    if (read(peer_fd, &buffer, BUFFER_SIZE) == -1)
      perror("[!] read()");

    std::string sbuffer(buffer);
    // std::cout << sbuffer << std::endl;
    close(peer_fd);
  };
};

#endif
