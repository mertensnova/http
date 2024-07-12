#ifndef RESPONSE_H
#define RESPONSE_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>

struct HTTPHeader {
  int status;
  std::string content_type;
  int content_length;
  std::string user_agent;
  std::string body;
};

class ResponseHandler {
public:
  inline void response_send(int client_fd, std::string message);
  inline std::string response_read_file(std::string filename);
  inline std::string response_handle_header(int status,
                                            std::string content_type,
                                            std::string body);

  inline std::string response_make_message(HTTPHeader response);
};

void ResponseHandler::response_send(int client_fd, std::string message) {
  send(client_fd, message.c_str(), message.size(), 0);
  close(client_fd);
  return;
};
std::string ResponseHandler::response_handle_header(int status,
                                                    std::string content_type,
                                                    std::string body) {

  HTTPHeader *http = new (std::nothrow) HTTPHeader;
  http->status = status;
  http->content_type = content_type;
  http->content_length = body.size();
  http->body = body;
  return response_make_message(*http);
};

std::string ResponseHandler::response_make_message(HTTPHeader response) {
  std::string message = "HTTP/1.1";
  message += std::to_string(response.status);
  message += "\r\nContent-Type: " + response.content_type;
  message += "\r\nContent-Length: " + std::to_string(response.content_length);
  message += "\r\n\r\n" + response.body;
  return message;
};
std::string ResponseHandler::response_read_file(std::string filename) {

  std::string dir = "/home/mertens/Desktop/Projects/http/static";
  dir += filename;
  std::ifstream nfp;
  std::string str;

  nfp.open(dir);
  std::ostringstream ss;
  ss << nfp.rdbuf();
  std::string fileContent = ss.str();

  return fileContent;
};

#endif
