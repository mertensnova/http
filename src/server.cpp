#include "../includes/server.h"
#include "../includes/request.h"
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {

  Server server;

  Request request;

  server.GET("/index", "index.html",
             [&]() { server.server_serve_static("index.html"); });

  // server.GET("/home", "home.html");
  // server.GET("/about", "about.html");

  close(server.server_create(8000, 14));
  return 0;
};
