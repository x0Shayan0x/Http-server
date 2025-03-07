#ifndef Server_h
#define Server_h

#include <sys/socket.h>
#include <netinet/in.h>

struct Server
{
    int domain;              // Specifies the communication domain (address family e.g. IPv4)
    int service;             // Defines the socket type e.g. SOCK_STREAM (TCP)
    int protocol;            // Specifies the protocol used
    unsigned long interface; // Defines the IP address/interface the server listens on.
    int port;                // The port number the server listens on
    int backlog;             //  Specifies the maximum number of queued connections before rejecting new ones

    struct sockaddr_in address; // Stores the server's address details

    int socket;

    void (*launch)(void);
};

struct Server server_constructor(int domain, int service, int protocol, unsigned long interface, int port, int backlog, void (*launch)(void)); // function prototype for initialising a server object

#endif