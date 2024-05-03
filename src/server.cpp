#include <arpa/inet.h>
#include <cctype>
#include <cerrno>
#include <cstring>
#include <execution>
#include <iostream>
#include <netdb.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>

const int BUFFER_SIZE = 30720;

std::vector<std::string> parser(std::string response);
int main(int argc, char **argv) {

  int server_fd = socket(AF_INET, SOCK_STREAM, 0);

  if (server_fd < 0) {
    std::cerr << "Failed to create server socket\n";
    return 1;
  }

  int reuse = 1;
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(reuse)) <
      0) {
    std::cerr << "setsockopt failed\n";
    return 1;
  }

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(4221);

  if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) !=
      0) {
    std::cerr << "Failed to bind to port 4221\n";
    return 1;
  }

  int connection_backlog = 5;
  if (listen(server_fd, connection_backlog) != 0) {
    return 1;
  }

  struct sockaddr_in client_addr;
  int client_addr_len = sizeof(client_addr);

  std::cout << "Waiting for a client to connect...\n";

  ssize_t client_fd = accept(server_fd, (struct sockaddr *)&client_addr,
                             (socklen_t *)&client_addr_len);

  std::cout << "Client connected\n";

  std::string status_http_OK =
      "HTTP/1.1 200 OK\r\n\r\nContent-Type: text/plain\r\n\r\nContent-Length: "
      "3\r\n\r\n\r\n\n";
  std::string status_http_error = "HTTP/1.1 404 Not Found\r\n\r\n";


  char buffer[BUFFER_SIZE] = {0};

  ssize_t bytesReceived = read(client_fd, buffer, BUFFER_SIZE);

  if (bytesReceived < 0) {
    std::cerr << "Error reading from socket: " << hstrerror(errno) << "\n";
  }

  std::string str(buffer);
  auto s = parser(str);

  std::cout << s[0] << std::endl;
  if (std::strcmp(s[0].c_str(), " ")) {
    send(client_fd, status_http_OK.c_str(), status_http_OK.size(), 0);
    return 0;
  }
  if (std::strcmp(s[0].c_str(), "echo") == 0) {
    status_http_OK += s[s.size() - 2];
    send(client_fd, status_http_OK.c_str(), status_http_OK.size(), 0);
    return 0;
  }

  close(server_fd);
  close(client_fd);
  return 0;
}

std::vector<std::string> parser(std::string response) {
  std::vector<std::string> r;
  for (int i = 0; i < response.size(); ++i) {

    if (response[i] == '\r')
      break;

    if (response[i] == '/') {
      int p = i + 1;
      std::string str = {};
      while (response[p] != '/' && response[p] != '\r' && response[p] != ' ') {
        str.push_back(response[p]);
        p++;
      }
      r.push_back(str);
    }
  }

  for (auto x : r) {
      std::cout << x << std::endl;
  }

  return r;
};
