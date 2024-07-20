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
};

void ResponseWritter::response_send(int client_fd, int status,
                                    std::string message) {
  std::string response = "HTTP/1.1";
  response += std::to_string(status);
  response += "\r\nContent-Type: text/html";
  response += "\r\nContent-Length: " + std::to_string(message.size());
  response += "\r\n\r\n" + message;
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
