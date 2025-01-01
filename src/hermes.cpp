#include "../include/hermes.hpp"

int main()
{
    int socket_server = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in server_address;
    server_address.sin_port = htons(8000);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

    listen(server_socket, 5);
    printf("server listning on port 8000\n");
}
