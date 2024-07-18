#ifndef SERVER_H
#define SERVER_H

#include <arpa/inet.h>
#include <cerrno>
#include <iostream>
#include <netdb.h>
#include <new>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <unordered_map>

#include "./request.h"
#include "./response.h"
#include "./status.h"

const int BUFFER_SIZE = 30720;

struct SClient {
  int client_fd;
  std::string buffer;
};

class Server {
public:
  std::unordered_map<std::string, std::string> routes;
  inline int server_create(int port, int connection_backlog);
  inline SClient *server_handle_client(int server_fd);
  inline void GET(std::string url, std::string filename);
};

void Server::GET(std::string url, std::string filename) {
  routes[url] = filename;
  return;
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

  SClient *client = new (std::nothrow) SClient();
  RequestHandler request;
  ResponseHandler response;

  if (!client) {
    std::perror("Failed to allocate memory");
    std::exit(EXIT_FAILURE);
  };

  client = server_handle_client(server_fd);

  std::string method = request.request_check_method(client->buffer);
  auto path = request.request_parse_url(client->buffer);
  std::cout << method << std::endl;
  std::cout << path[0] << std::endl;
 

  if (routes["/" + path[0]] == "") {
    std::string ss =
        response.response_handle_header(NOT_FOUND, "text/plain", "Not Found");

    response.response_send(client->client_fd, ss);
    close(client->client_fd);
  } else {

    std::string body = response.response_read_file(path[0]+".html");
    std::string ss = response.response_handle_header(OK, "text/html", body);

    response.response_send(client->client_fd, ss);
  };

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
