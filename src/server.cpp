#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "../includes/server.h"
#include "../includes/status.h"
int main(int argc, char **argv) {

  Server server;

  server.ServerCreate(8000);

  server.GET("/index", [&](ResponseWritter r) {
    r.HTML(server.peer_fd, HTTP_OK, "index.html");
  });

  /*
  server.GET("/home", [&](ResponseWritter r) {
    r.HTML(server.client->client_fd, HTTP_OK, "home.html");
  });
  */

  return 0;
};
