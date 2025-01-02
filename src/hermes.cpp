#include "../include/hermes.hpp"

int main()
{
  int socket_server = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server_address;
  server_address.sin_port = htons(8000);
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;

  bind(socket_server, (struct sockaddr *)&server_address, sizeof(server_address));

  listen(socket_server, 5);
  printf("server listning on port 8000\n");

  while (true) {
    char buffer[1024];
    int acceptSocket = accept(socket_server, NULL, NULL);
    if(acceptSocket > 0)
    {
      std::stringstream responce;
      responce << "HTTP/1.1 200 OK\r\n";
      responce << "Content-Type: text/html\r\n\r\n";
      responce << "<h1>Hello World</h1>\r\n\r\n";

      int sendcode = send(acceptSocket, responce.str().c_str(), responce.str().size(), 0);
      close(acceptSocket);
    }
  }
  close(socket_server);
  return 0;
}
