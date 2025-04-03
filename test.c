#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "Server.h"

void launch(struct Server *server)
{
    char buffer[30000]; // buffer to store client's incoming request data
    while (1)
    {
        printf("===== WAITING FOR CONNECTION =====\n");
        // fflush(stdout);

        int address_length = sizeof(server->address); // Get size of address struct

        int new_socket = accept(server->socket, (struct sockaddr *)&server->address, (socklen_t *)&address_length); // accepts a new incoming connection from a client

        read(new_socket, buffer, 30000); // Read the the request from client into buffer

        printf("%s\n", buffer); // print the client's request

        // prepare a basic HTTP response
        char *hello =
            "HTTP/1.1 200 OK\r\n"
            "Date: Mon, 27 Jul 2009 12:28:53 GMT\r\n"
            "Server: Apache/2.2.14 (Win32)\r\n"
            "Last-Modified: Wed, 22 Jul 2009 19:15:56 GMT\r\n"
            "Content-Length: 88\r\n"
            "Content-Type: text/html\r\n"
            "Connection: close\r\n"
            "\r\n"
            "<html><body><h1>Hello, world!</h1></body></html>";

        // Send the response to the client
        write(new_socket, hello, strlen(hello));

        // Close the connection with that client
        close(new_socket);
    }
}

int main()
{
    struct Server server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 3000, 10, launch);
    server.launch(&server);
}