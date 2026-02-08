#include "../include/hermes.hpp"
#include "../include/server.hpp"
int main() {
  Server *app = new Server();
  int socket_server = app->Listen(8000);
  std::cout << socket_server;
  while (true) {
    char buffer[1024];
    int acceptSocket = accept(socket_server, NULL, NULL);
    if (acceptSocket > 0) {
      std::stringstream responce;
      responce << "HTTP/1.1 200 OK\r\n";
      responce << "Content-Type: text/html\r\n\r\n";
      responce << "<h1>Hello World</h1>\r\n\r\n";
      responce << "<h2>My name is Gaurav</h2>"

          int sendcode =
          send(acceptSocket, responce.str().c_str(), responce.str().size(), 0);
      close(acceptSocket);
    }
  }
  close(socket_server);
  return 0;
}
