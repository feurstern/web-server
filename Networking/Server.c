#include "Server.h"
#include <stdio.h>
#include <stdlib.h>

struct Server server_constructor(int domain, int service, int protocol, __u_long interface, int port, int backlog, void (*launch)(void))
{
    struct Server server;
    {
        server.domain = domain;
        server.service = service;
        server.protocol = protocol;
        server.interface = interface;
        server.port = port;
        server.backlog = backlog;

        server.address.sin_family = domain;
        server.address.sin_port = htons(port);
        server.address.sin_addr.s_addr = htons(interface);

        // socket connection
        server.socket = socket(domain, service, protocol);
        if (server.socket == 0)
        {
            perror("failed to connect ... !\n");
            exit(1);
        }

        if (bind(server.socket, (struct sockaddr *)&server.address, sizeof(server.address)) < 0)
        {
            perror("failled to connect to bind socker");
            exit(1);
        }

        if (listen(server.socket, server.backlog))
        {
            perror("Erorr during start listening ...");
            exit(1);
        }

        server.launch = launch;

        return server;
    };
};
