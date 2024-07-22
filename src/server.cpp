#include "../includes/server.h"
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {

  Server server;

  int a = server.server_create(8000, 14);
  while (1) {

    server.GET("/index","index.html", [&](ResponseWritter r) {
      r.HTML(server.client->client_fd, HTTP_OK, "index.html");
      return;
    });

    server.GET("/home","home.html", [&](ResponseWritter r) {
      r.HTML(server.client->client_fd, HTTP_OK, "home.html");
    });
  };

  close(a);
  return 0;
};
