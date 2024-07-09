#ifndef RESPONSE_H
#define RESPONSE_H

#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>

class ResponseHandler {

public:
  inline void response_send(int client_fd, int status, std::string message);
};

void ResponseHandler::response_send(int client_fd, int status,
                                    std::string message) {
  send(client_fd, message.c_str(), message.size(), 0);
  close(client_fd);
  return;
};

#endif
