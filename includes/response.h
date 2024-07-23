#ifndef RESPONSE_H
#define RESPONSE_H

#include "./utils.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <variant>
#include <vector>

struct ResponseHeader {
  int status;
  std::string content_type;
  int content_length;
  std::string message;
  std::string body;
  ResponseHeader()
      : status(200), message("OK"), content_type("text/html"),
        content_length(0) {}
};

class ResponseWritter {
public:
  // inline std::string ResponseWrite(int status, std::string body);
  // inline void ResponseSend(ResponseHeader *res, int client_fd);
  inline void HTML(int client_fd, int status, std::string body);
  inline void String(int client_fd, int status, std::string string);
};

void ResponseWritter::HTML(int client_fd, int status, std::string body) {
  Utils u;

  if (body.find(".html") != std::string::npos) {
    std::string response = u.set_html(status, u.read_file(body));
    send(client_fd, response.c_str(), response.size(), 0);
    close(client_fd);
    return;
  };

  std::string response = u.set_html(status, body);
  send(client_fd, response.c_str(), response.size(), 0);
  close(client_fd);
  return;
};

/*
void ResponseWritter::ResponseSend(ResponseHeader *res, int client_fd) {
  std::string response = "HTTP/1.1";
  response += std::to_string(res->status);
  response += "\r\nContent-Type: " + res->content_type;
  response += "\r\nContent-Length: " + std::to_string(res->content_length);
  response += "\r\n\r\n" + res->body;
  send(client_fd, response.c_str(), response.size(), 0);
  close(client_fd);
  return;
};

std::string ResponseWritter::ResponseWrite(int status, std::string message) {
  ResponseHeader *http = new (std::nothrow) ResponseHeader;
  http->status = status;
  http->content_type = "text/html";
  http->message = message;
  http->content_length = message.size();

  return "";
};
*/

#endif
