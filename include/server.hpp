#pragma once
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <fcntl.h>
#include <iostream>
#include <sstream>
#include <string>


enum Family{
  v4 = AF_INET,
  v6 = AF_INET6
};

class Server {
public:
  Server();
  int Listen(int port); 
  int Listen(int port, Family family);

};  
