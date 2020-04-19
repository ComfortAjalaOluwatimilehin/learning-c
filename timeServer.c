#if defined(_WIN32)
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#endif
#if defined(_WIN32)
#define ISVALIDSOCKET(s) ((s) >= 0)
#define CLOSESOCKET(s) close(s)
#define SOCKET int
#define GETSOCKETERRNO() (errno)
#endif

#include <stdio.h>
#include <time.h>
#include <string.h>

int main()
{
#if defined(_WIN32)
    WSADATA d;
    if (WSAStartup(MAKEWORD(2, 2), &d))
    {
        fprintf(stderr, "Failed to Initialize.\n");
        return 1;
    }
#endif
    printf("Configuring local address info.\n");
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;                     // IPv4
    hints.ai_socktype = SOCK_STREAM;               // TCP
    hints.ai_flags = AI_PASSIVE;                   // bind to wildcard address
    struct addrinfo *bind_address;                 // holds return information of future getaddrino call
    getaddrinfo(0, "8080", &hints, &bind_address); // generates an address for the bind()
    printf("Creating socket...\n");
    SOCKET socket_listen;
    socket_listen = socket(bind_address->ai_family, bind_address->ai_socktype, bind_address->ai_protocol);
    if (!ISVALIDSOCKET(socket_listen))
    {
        fprintf(stderr, "socket failed.. (%d)\n", GETSOCKETERRNO());
        return 1;
    }
    printf("Binding socket to local address...\n");
    if (bind(socket_listen, bind_address->ai_addr, bind_address->ai_addrlen))
    {
        fprintf(stderr, "bind() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }
    freeaddrinfo(bind_address); // releases address memory

    printf("Listening...\n");
    if (listen(socket_listen, 10) < 0)
    {
        fprintf(stderr, "listen() failed. (%d).\n", GETSOCKETERRNO());
        return 1;
    }

    printf("Waiting for connections ....\n");
    struct sockaddr_storage client_address;
    socklen_t client_length = sizeof(client_address);
    SOCKET socket_client = accept(socket_listen, (struct sockaddr *)&client_address, &client_length);
    if (!ISVALIDSOCKET(socket_client))
    {
        fprintf(stderr, "accept() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }


    
}