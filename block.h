#if !defined(BLOCK_H)
#define BLOCK_H

#include <cstring>
#include <ctime>
#include <iostream>

#include "hash.h"

class Block {
public:
  Hash h;
  std::string prev_hash;
  std::string date;
  std::string hash;

  void hash_set();
};

void Block::hash_set() {

  unsigned char hash[999];
  unsigned char t;
  time_t now = time(0);
  char *dt = ctime(&now);
  tm *gmtm = gmtime(&now);
  dt = asctime(gmtm);

  unsigned char test[999] = "Text";
  h.init_openssl();

  std::cout << h.sha256(dt) << std::endl;
}
#endif
