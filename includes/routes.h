#ifndef ROUTES_H
#define ROUTES_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class RoutesHandler {
public:
  inline void GET(std::string url, std::string filename);

private:
  std::unordered_map<std::string, std::string> routes;
};

void RoutesHandler::GET(std::string url, std::string filename) {
  routes[url] = filename;
  return;
};

#endif
