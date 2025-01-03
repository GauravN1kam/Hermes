#include "../include/hermes.hpp"


#pragma comment(lib, "Ws2_32.lib")
#define DEFAULT_PORT "27015"
#define DEFAULT_BUFLEN 1024

int main()
{
    int iResult;
    std::string port = "27015";
    Server *server = new Server();
    SOCKET ListenSocket = server->Listen(port);
    
    char recvbuf[DEFAULT_BUFLEN];
    int iSendResult;
    int recvbuflen = DEFAULT_BUFLEN;


    while (1) {
        SOCKET ClientSocket;

        ClientSocket = INVALID_SOCKET;

        ClientSocket = accept(ListenSocket, NULL, NULL);
        if(ClientSocket == INVALID_SOCKET){
            printf("accept failed ith error %d\n", WSAGetLastError());
            closesocket(ListenSocket);
            WSACleanup();
            return 1;
        }
        iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
        if(iResult > 0){
            printf("Bytes received %d\n",iResult);
            std::stringstream responce;
            responce << "HTTP/1.1 200 OK\r\n";
            responce << "Content-Type: text/html\r\n\r\n";
            responce << "<h1>Hello world</h1>";


            iSendResult = send(ClientSocket, responce.str().c_str(), responce.str().size(), 0);
            
            if(ClientSocket == SOCKET_ERROR){
                printf("send failed ith error %d\n", WSAGetLastError());
                closesocket(ClientSocket);
                WSACleanup();
                return 1;
            }
            else {
                closesocket(ClientSocket);
            }
            printf("Bytes send: %d\n", iSendResult);

        } else if(iResult == 0){
            printf("Connection Closing...\n");
            closesocket(ClientSocket);
        }
        else{
            printf("recv failed: %d\n", WSAGetLastError());
            WSACleanup();
            return 1;
        }
    }

    WSACleanup();
    return 0;
}

