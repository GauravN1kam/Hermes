#pragma once
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <fcntl.h>
#include <iostream>
#include <sstream>
#include <string>

class Server {
public:
  Server();
  int Listen(int port); 
};  
