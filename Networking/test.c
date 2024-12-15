#include "Server.h"
#include <stdio.h>
#include<string.h>

void launch(struct Server *server)
{
    char buffer[30000];
    int addressLength = sizeof(server->address);
    int newSocket = accept(server->socket, (struct sockaddr *)&server->address, (socklen_t *)&addressLength);
    read(newSocket, buffer, 30000);
    printf("%s\n", buffer);
    
    char hello = "Welcome to the web server xixixi";

    write(newSocket, hello, strlen(hello));

    close(newSocket);
}

int main()
{
    struct Server server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 80, 10, launch);
    
    server.launch(&server);
}