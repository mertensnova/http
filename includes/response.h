#ifndef RESPONSE_H
#define RESPONSE_H

#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>

struct HTTPHeader {
  int status;
  std::string content_type;
  std::string content_length;
  std::string user_agent;
  std::string body;
};

class ResponseHandler {
public:
  inline void response_send(int client_fd, HTTPHeader response);
};

void ResponseHandler::response_send(int client_fd, HTTPHeader response) {
  // send(client_fd, message.c_str(), message.size(), 0);
  // close(client_fd);
  return;
};

#endif
