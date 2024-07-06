#include <arpa/inet.h>
#include <cerrno>
#include <fstream>
#include <iostream>
#include <netdb.h>
#include <sstream>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>

const int BUFFER_SIZE = 30720;

bool check_word(std::string request, std::string word);
std::vector<std::string> parse_url(std::string response);
std::string parse_headers(std::string request);
std::string read_file(std::string filename);
bool check_file(std::string filename);

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

  int connection_backlog = 15;
  if (listen(server_fd, connection_backlog) != 0) {
    return 1;
  }

  struct sockaddr_in client_addr;
  int client_addr_len = sizeof(client_addr);

  std::cout << "Waiting for a client to connect...\n";

  while (true) {
    ssize_t client_fd = accept(server_fd, (struct sockaddr *)&client_addr,
                               (socklen_t *)&client_addr_len);

    std::cout << "Client connected\n";
    char buffer[BUFFER_SIZE] = {0};
    ssize_t bytesReceived = read(client_fd, buffer, BUFFER_SIZE);

    if (bytesReceived < 0) {
      std::cerr << "Error reading from socket: " << hstrerror(errno) << "\n";
    }

    std::string str(buffer);

    // send(client_fd, status_http_OK.c_str(), status_http_OK.size(), 0);
    std::string status_http_error = "HTTP/1.1 404 Not Found\r\n\r\n";
    std::string status_http_OK = "HTTP/1.1 200 OK\r\nContent-Type: "
                                 "application/octet-stream\r\nContent-Length: ";

    auto res = parse_url(str);

    if (res.size() < 2) {
      std::string OK = "HTTP/1.1 200 OK\r\nContent-Type: "
                       "text/plain\r\n\r\n";
      send(client_fd, OK.c_str(), OK.size(), 0);
      close(client_fd);
      continue;
    }

    if (res[0].find("files") != std::string::npos) {
      if (!check_file(res[1])) {
        send(client_fd, status_http_error.c_str(), status_http_error.size(), 0);
        close(client_fd);
        continue;
      } else {
        std::cout << res[1];
        std::string ff = read_file(res[1]);
        std::string siz = std::to_string(ff.size());
        status_http_OK += siz;
        status_http_OK += "\r\n\r\n";
        status_http_OK += ff;
        send(client_fd, status_http_OK.c_str(), status_http_OK.size(), 0);
        close(client_fd);
        continue;
      };
    }

    if (check_word(str, "User-Agent")) {
      auto res = parse_headers(str);
      std::string OK =
          "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nContent-Length: ";
      std::string siz = std::to_string(res.size() - 1);
      OK += siz;
      OK += "\r\n\r\n";
      OK += res;
      send(client_fd, OK.c_str(), OK.size(), 0);
      close(client_fd);
      continue;
    } else {
      if (check_word(str, "/echo")) {
        auto res = parse_url(str);
        std::string OK =
            "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nContent-Length: ";
        std::string siz = std::to_string(res[1].size());
        OK += siz;
        OK += "\r\n\r\n";
        OK += res[1];
        send(client_fd, OK.c_str(), OK.size(), 0);

        close(client_fd);
        continue;
      } else {
        send(client_fd, status_http_error.c_str(), status_http_error.size(), 0);
        close(client_fd);
        continue;
      };
    }
    close(client_fd);
  }
  close(server_fd);

  return 0;
}

bool check_file(std::string filename) {

  std::string dir = "/tmp/data/codecrafters.io/http-server-tester/";
  dir += filename;
  std::ifstream nfp;
  nfp.open(dir);
  if (!nfp.is_open()) {
    return false;
  }
  return true;
};

std::string read_file(std::string filename) {

  std::string dir = "/tmp/data/codecrafters.io/http-server-tester/";
  std::string dirs = "/home/mertens/Desktop/Projects/cc/tmp/files/";
  dir += filename;
  std::ifstream nfp;
  std::string str;

  nfp.open(dir);
  std::ostringstream ss;
  ss << nfp.rdbuf();
  std::string fileContent = ss.str();

  return fileContent;
}

std::vector<std::string> parse_url(std::string response) {
  std::vector<std::string> r;
  for (int i = 0; i < response.size(); ++i) {

    if (response[i] == '\r')
      break;

    if (response[i] == '/') {
      if (response[i + 1] == ' ') {
        break;
      }
      int p = i + 1;
      std::string str = {};
      while (response[p] != '\r' && response[p] != ' ') {
        str.push_back(response[p]);
        p++;
      }
      r.push_back(str);
    }
  }

  return r;
};

bool check_word(std::string request, std::string word) {
  size_t spos = request.find(word);
  if (spos == std::string::npos)
    return false;

  return true;
};

std::string parse_headers(std::string request) {

  std::string user_agent = "";
  size_t spos = request.find("User-Agent");

  if (spos == std::string::npos) {
    std::cerr << "[!]Not Found" << std::endl;
  }

  for (size_t i = spos + 12; i < request.size(); i++) {
    if (request[i] != '\n') {
      user_agent += request[i];
    } else {
      break;
    }
  }

  return user_agent;
};
