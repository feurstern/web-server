#ifndef Server_h
#define Server_h

#include <sys/socket.h>
#include<netinet/in.h>


struct Server
{
    int domain;
    int service;
    int protocol;
    long interface;
    int port;
    int backlog;

    int socket;
    
    struct sockaddr_in address; 
    void(*launch)(void);

};


struct Server server_constructor(int domain, int service, int protocol, long interface, int port, int backlog, void(*launch)(struct Server*server));


#endif