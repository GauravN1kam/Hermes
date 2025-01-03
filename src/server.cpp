#include "../include/server.hpp"

int server::Listen(int port)
{
    int socket_server = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_server < 0) {
        std::cerr << "Error creating socket" << std::endl;
        return -1;
    }

    struct sockaddr_in server_address;
    server_address.sin_port = htons(port);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(socket_server, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        std::cerr << "Error binding socket" << std::endl;
        close(socket_server);
        return -1;
    }

    if (listen(socket_server, 5) < 0) {
        std::cerr << "Error listening on socket" << std::endl;
        close(socket_server);
        return -1;
    }

    std::cout << "Server listening on port " << port << std::endl;
    return socket_server;
}
