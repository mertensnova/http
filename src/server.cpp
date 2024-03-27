#include <arpa/inet.h>
#include <cctype>
#include <cerrno>
#include <iostream>
#include <netdb.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

const int BUFFER_SIZE = 30720;

int parser(std::string response);
int main(int argc, char **argv) {

  // Create a socket for communication for TCP protocol ("SOCK_STREAM")
  // AF_INET indicates the domain will use IPv4 address
  // SOCK_STREM type of communcation sturcyture that socket will allow realible
  // full duplex byte streams the last paramter is protocl There is one protocol
  // that supoots SOCK_STREAM
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);

  if (server_fd < 0) {
    std::cerr << "Failed to create server socket\n";
    return 1;
  }

  // This code sets the socket option SO_REUSEPORT to allow multiple sockets to
  // bind to the same port.
  //  If unsuccessful, it prints an error message and returns 1.

  int reuse = 1;
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(reuse)) <
      0) {
    std::cerr << "setsockopt failed\n";
    return 1;
  }

  /*
    ******************************************
       NAMING A SOCKET
   sin_family is the socket family which is AF_INET
   sin_port the port used in the server. htons() ensures the port is sotored in
   network byte order sin_addr the ip address of the server
    ************************************
*/

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(4221);

  // bind() is used to tie socketaddress to given socket
  if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) !=
      0) {
    std::cerr << "Failed to bind to port 4221\n";
    return 1;
  }

  // listen() system call to collect icoming connectisos on a wueeue
  // the first  argument is socket
  // the second is max num of connectrion theresh we want to be able to hold at
  // once
  int connection_backlog = 5;
  if (listen(server_fd, connection_backlog) != 0) {
    return 1;
  }

  struct sockaddr_in client_addr;
  int client_addr_len = sizeof(client_addr);

  std::cout << "Waiting for a client to connect...\n";
  // acpept() system call is used to process each conneftion htread in the queue
  // created by listen()

  // firts arg is server socket
  // second pointer to a socket addrr
  // thried is the lenght of th addr
  ssize_t client_fd = accept(server_fd, (struct sockaddr *)&client_addr,
                             (socklen_t *)&client_addr_len);

  std::cout << "Client connected\n";

  std::string status_http_OK = "HTTP/1.1 200 OK\r\n\r\n";
  std::string status_http_error = "HTTP/1.1 404 Not Found\r\n\r\n";
  send(client_fd, status_http_OK.c_str(), status_http_OK.size(), 0);

  std::cout << "Sent correclty" << std::endl;

  char buffer[BUFFER_SIZE] = {0};

  ssize_t bytesReceived = read(client_fd, buffer, BUFFER_SIZE);

  if (bytesReceived < 0) {
    std::cerr << "Error reading from socket: " << hstrerror(errno) << "\n";
  }

  std::string str(buffer);

  if (parser(str) == 0) {
    send(client_fd, status_http_OK.c_str(), status_http_OK.size(), 0);
  } else {
    send(client_fd, status_http_error.c_str(), status_http_error.size(), 0);
  }

  std::cout << "\n";
  std::cout << "\n";

  close(server_fd);
  close(client_fd);
  return 0;
}

int parser(std::string response) {
  //std::cout << response << std::endl;
  for (int i = 0; i < response.size(); ++i) {

    if (response[i] == '/') {

        std::cout << response[i+1] << "\n";
      //if (std::isalpha(response[i + 1]) == 0) {
      return 0;
      //}
    }
  }
  return -1;
};
