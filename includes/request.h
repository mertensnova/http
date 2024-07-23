#ifndef REQUEST_H
#define REQUEST_H

#include <iostream>
#include <vector>

class Request {

public:
  inline std::vector<std::string> request_parse_url(std::string request);
  // inline std::string request_check_method(std::string request);
};

std::vector<std::string> Request::request_parse_url(std::string request) {
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
