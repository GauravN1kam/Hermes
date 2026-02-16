#pragma once
#include <fcntl.h>
#include <iostream>
#include <netinet/in.h>
#include <sstream>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

enum Family { v4 = AF_INET, v6 = AF_INET6 };

class Server {
public:
  Server();
  int Listen(int port);
  int Listen(int port, Family family);
};
