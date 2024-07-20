#ifndef RESPONSE_H
#define RESPONSE_H

#include "./utils.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>

struct ResponseHeader {
  int status;
  std::string content_type;
  int content_length;
  std::string message;
  std::string body;
  // Default constructor (if needed)
  ResponseHeader()
      : status(200), message("OK"), content_type("text/html"),
        content_length(0) {}
};

class ResponseWritter {
public:
  inline void handle_file_ext(std::string filename);
  inline void response_send(int client_fd, int status, std::string message);
  inline std::string response_write(int status, std::string body);
  inline void response_send(ResponseHeader *res, int client_fd);
};

void ResponseWritter::response_send(ResponseHeader *res, int client_fd) {
  std::string response = "HTTP/1.1";
  response += std::to_string(res->status);
  response += "\r\nContent-Type: " + res->content_type;
  response += "\r\nContent-Length: " + std::to_string(res->content_length);
  response += "\r\n\r\n" + res->body;
  send(client_fd, response.c_str(), response.size(), 0);
  close(client_fd);
  return;
};

std::string ResponseWritter::response_write(int status, std::string message) {
  ResponseHeader *http = new (std::nothrow) ResponseHeader;
  http->status = status;
  http->content_type = "text/html";
  http->message = message;
  http->content_length = message.size();

  return "";
};

#endif
