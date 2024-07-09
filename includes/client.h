#ifndef CLIENT_HANDLER_H
#define CLIENT_HANDLER_H

#include <arpa/inet.h>
#include <cerrno>
#include <cstdlib>
#include <iostream>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <string>

const int BUFFER_SIZE = 30720;

struct SClient {
  int client_fd;
  std::string buffer;
};

class ClientHandler {
public:
  inline SClient client_accept(int server_fd);

private:
};

SClient ClientHandler::client_accept(int server_fd) {

  SClient *client_new = new (std::nothrow) SClient();

  struct sockaddr_in client_addr;
  int client_addr_len = sizeof(client_addr);

  std::cout << "Waiting for a client to connect...\n";

  ssize_t client_fd = accept(server_fd, (struct sockaddr *)&client_addr,
                             (socklen_t *)&client_addr_len);

  std::cout << "Client connected\n";
  char buffer[BUFFER_SIZE] = {0};
  ssize_t bytesReceived = read(client_fd, buffer, BUFFER_SIZE);

  if (bytesReceived < 0) {
    std::cerr << "Error reading from socket: " << hstrerror(errno) << "\n";

  };

  std::string str(buffer);

  client_new->client_fd = client_fd;
  client_new->buffer = str;
  return *client_new;
};

#endif
