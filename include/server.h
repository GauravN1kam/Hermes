#include <string>
#include <sstream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
class Server{
    public:
        SOCKET Listen(std::string port);
        int get();
        int post();
        int del();
};

