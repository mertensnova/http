#ifndef HASH_H

#include <iostream>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/sha.h>
class Hash {
public:
  void init_openssl();
  void cleanup_openssl();
  std::string sha256(const std::string &str);
  std::string bin2hex(const unsigned char *bin, size_t len);
};

void Hash::init_openssl() {
  // Initialize the OpenSSL library
  ERR_load_crypto_strings();
  OpenSSL_add_all_algorithms();
}

void Hash::cleanup_openssl() {
  // Close the OpenSSL library
  EVP_cleanup();
  ERR_free_strings();
}
// A helper function to convert a binary buffer to a hex string
std::string Hash::bin2hex(const unsigned char *bin, size_t len) {
  std::string hex;
  hex.reserve(2 * len);
  for (size_t i = 0; i < len; i++) {
    hex += "0123456789abcdef"[bin[i] >> 4];
    hex += "0123456789abcdef"[bin[i] & 0x0F];
  }
  return hex;
}
std::string Hash::sha256(const std::string &str) {
  unsigned char hash[SHA256_DIGEST_LENGTH];
  SHA256_CTX sha256;
  if (!SHA256_Init(&sha256)) {
    exit(EXIT_FAILURE);
  }
  if (!SHA256_Update(&sha256, str.c_str(), str.size())) {
    exit(EXIT_FAILURE);
  }
  if (!SHA256_Final(hash, &sha256)) {
    exit(EXIT_FAILURE);
  }
  return bin2hex(hash, SHA256_DIGEST_LENGTH);
}

#endif // !
