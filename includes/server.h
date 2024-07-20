#ifndef SERVER_H
#define SERVER_H

#include <arpa/inet.h>
#include <cerrno>
#include <functional>
#include <iostream>
#include <netdb.h>
#include <new>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <unordered_map>
// #include <nlohmann/json.hpp>

#include "./request.h"
#include "./response.h"
#include "./status.h"
#include "utils.h"

const int BUFFER_SIZE = 30720;

struct SClient {
  int client_fd;
  std::string buffer;
};

class Server {
public:
  SClient *client = new (std::nothrow) SClient();
  std::unordered_map<std::string, std::string> routes;
  inline int server_create(int port, int connection_backlog);

  inline void server_serve_static(ResponseHeader res, std::string filename);
  inline SClient *server_handle_client(int server_fd);
  inline void GET(std::string url, std::function<void(ResponseHeader)> func);
};

void Server::GET(std::string url, std::function<void(ResponseHeader)> func) {
  func(ResponseHeader());
  return;
};

void Server::server_serve_static(ResponseHeader res, std::string filename) {
  Utils u;
  ResponseWritter response;

  std::string body = u.read_file(filename);
   response.response_send(client->client_fd, HTTP_OK, body);
};

int Server::server_create(int port, int connection_backlog) {

  if (!client) {
    std::perror("Failed to allocate memory");
    std::exit(EXIT_FAILURE);
  };

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

  client = server_handle_client(server_fd);
  server_serve_static("index.html");

  close(client->client_fd);
  return server_fd;
};

SClient *Server::server_handle_client(int server_fd) {

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
  return client_new;
};

#endif
