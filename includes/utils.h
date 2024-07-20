#ifndef UTILS_H
#define UTILS_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class Utils {
public:
  inline std::string read_file(std::string filename);
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
