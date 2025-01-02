#include "../include/hermes.hpp"


#pragma comment(lib, "Ws2_32.lib")
#define DEFAULT_PORT "27015"
#define DEFAULT_BUFLEN 1024

int main()
{
    WSADATA wsaData;

    int iResult;
    struct addrinfo *result = NULL, *ptr= NULL, hints;

    ZeroMemory(&hints, sizeof(hints));

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;
    
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }
    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if(iResult != 0){
        printf("WSAStartup failed\n", iResult);
        WSACleanup();
        return 1;
    }
    SOCKET ListenSocket = INVALID_SOCKET;

    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);


    if (ListenSocket == INVALID_SOCKET) {
        printf("Error at socket(): %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }
    iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);

    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    freeaddrinfo(result);

    if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR) {
        printf("Listen failed ith error %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    
    char recvbuf[DEFAULT_BUFLEN];
    int iSendResult;
    int recvbuflen = DEFAULT_BUFLEN;


    while (1) { 
        do{

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


                iSendResult = send(ClientSocket, responce.str().c_str(), iResult, 0);

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
            }
            else{
                printf("recv failed: %d\n", WSAGetLastError());
                WSACleanup();
                return 1;
            }
        }while(iResult > 0);
    }

    closesocket(ClientSocket);
    WSACleanup();
    return 0;
}

