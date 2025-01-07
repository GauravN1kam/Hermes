#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
class Server{
    public:
        SOCKET __cdecl Listen(std::string port);
        int __cdecl get() const;
        int  __cdecl post() const;
        int  __cdecl del() const;
};

