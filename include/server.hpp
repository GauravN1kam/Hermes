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

enum HermesFlags {
    Passive = 0x01,
    Canonname = 0x02,
    NumericHost = 0x04,
    All = 0x0100,
    AddrConfig = 0x0400,
    v4Mapped = 0x0800,
    FileServer = 0x00040000,
};

enum Protocol{
    v4 = 2,
    v6 = 23,
};

class Server{

    public:
        SOCKET __cdecl Listen(std::string port); 
        SOCKET __cdecl Listen(std::string port, HermesFlags flag);
        SOCKET __cdecl Listen(std::string port, HermesFlags flag, Protocol protocol);
        int __cdecl get() const;
        int  __cdecl post() const;
        int  __cdecl del() const;
};

