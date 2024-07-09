#ifndef REQUEST_H
#define REQUEST_H

#include <iostream>
#include <vector>

class RequestHandler {

public:
  inline std::vector<std::string> request_parse_url(std::string request);
  inline bool request_check_method(std::string request, std::string method);
};

bool RequestHandler::request_check_method(std::string request,
                                          std::string method) {
  std::string m = "";
  for (size_t i = 0; i < request.size(); i++) {
    if (request[i] == ' ')
      continue;
    if (request[i] != '/')
      method += request[i];
    else
      break;
  };

  return m == method;
};

std::vector<std::string>
RequestHandler::request_parse_url(std::string request) {
  std::vector<std::string> r;
  for (int i = 0; i < request.size(); ++i) {
    if (request[i] == '\r')
      break;
    if (request[i] == '/') {
      if (request[i + 1] == ' ') {
        break;
      }
      int p = i + 1;
      std::string str = {};
      while (request[p] != '\r' && request[p] != ' ') {
        str.push_back(request[p]);
        p++;
      }
      r.push_back(str);
    }
  }
  return r;
}

#endif
