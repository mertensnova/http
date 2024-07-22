#ifndef UTILS_H
#define UTILS_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class Utils {
public:
  inline std::string read_file(std::string filename);
  inline std::string set_html(int status, std::string body);
};

std::string Utils::set_html(int status, std::string body) {
  std::string string = "HTTP/1.1";
  string += std::to_string(status);
  string += "\r\nContent-Type: text/html";
  string += "\r\nContent-Length: " + std::to_string(body.size());
  string += "\r\n\r\n" + body;
  return string;
};

std::string Utils::read_file(std::string filename) {
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

#endif
