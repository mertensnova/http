#ifndef RESPONSE_H
#define RESPONSE_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>

struct ResponseHeader{
  int status;
  std::string content_type;
  int content_length;
  std::string message;
};

class ResponseWritter {
public:
  inline void handle_file_ext(std::string filename);
  inline void response_send(int client_fd, std::string message);
  inline std::string response_read_file(std::string filename);
  inline std::string response_write(int status, std::string body);

 // inline std::string response_make_message(HTTPHeader response);
};

void ResponseWritter::response_send(int client_fd, std::string message) {
  send(client_fd, message.c_str(), message.size(), 0);
  close(client_fd);
  return;
};
std::string ResponseWritter::response_write(int status, std::string message) {
  ResponseHeader *http = new (std::nothrow) ResponseHeader;
  http->status = status;
  http->message = message;

 // return response_make_message(*http);
 return "";
};
/*
std::string ResponseWritter::response_make_message(HTTPHeader response) {
  std::string message = "HTTP/1.1";
  message += std::to_string(response.status);
  message += "\r\nContent-Type: " + response.content_type;
  message += "\r\nContent-Length: " + std::to_string(response.content_length);
  message += "\r\n\r\n" + response.body;
  return message;
};
*/
std::string ResponseWritter::response_read_file(std::string filename) {

  std::string dir = "/home/mertens/Desktop/Projects/http/statics/";
  dir += filename;
  std::ifstream nfp;
  std::string str;

  nfp.open(dir);
  std::ostringstream ss;
  ss << nfp.rdbuf();
  std::string fileContent = ss.str();

  return fileContent;
};

void ResponseWritter::handle_file_ext(std::string filename){};

#endif
