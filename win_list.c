#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif
#include <stdio.h>
#include <winsock2.h>
#include <iphlpapi.h>              //windows headers https://docs.microsoft.com/en-us/windows/win32/api/iphlpapi/
#include <ws2tcpip.h>              //windows headers https://docs.microsoft.com/en-us/windows/win32/api/ws2tcpip/
#include <stdlib.h>                //memory allocation http://www.cplusplus.com/reference/cstdlib/
#pragma comment(lib, "ws2_32.lib") // https://www.geeksforgeeks.org/pragma-directive-in-c-c/
// Functions in C - https://www.geeksforgeeks.org/functions-in-c/
int main()
{

    WSADATA d;
    if (WSAStartup(MAKEWORD(2, 2), &d))
    {
        printf("Failed to initialize.\n");
        return -1;
    }

    ULONG asize = 20000;
    PIP_ADAPTER_ADDRESSES adapters;
    do
    {
        adapters = (PIP_ADAPTER_ADDRESSES)malloc(asize);

        if (!adapters)
        {
            printf("Couldn't allocate %ld bytes for adapters.\n", asize);
            WSACleanup();
            return -1;
        }

        int r = GetAdaptersAddresses(AF_UNSPEC, GAA_FLAG_INCLUDE_PREFIX, NULL, adapters, &asize);
        if (r == ERROR_BUFFER_OVERFLOW)
        {
            printf("\nGet Adapters Addresses wants %ld bytes.\n", asize);
            free(adapters);
        }
        else if (r == NO_ERROR)
        {
            PIP_ADAPTER_ADDRESSES adapter = adapters;
            while (adapter)
            {
                printf("\nAdapter name: %S\n", adapter->FriendlyName);
                PIP_ADAPTER_UNICAST_ADDRESS address = adapter->FirstUnicastAddress;
                while (address)
                {
                    printf("\t%s", address->Address.lpSockaddr->sa_family == AF_INET ? "IPv4" : "IPv6");
                    char ap[100];
                    getnameinfo(address->Address.lpSockaddr, address->Address.iSockaddrLength, ap, sizeof(ap), 0, 0, NI_NUMERICHOST);
                    printf("\t%s\n", ap);
                    address = address->Next;
                }
                adapter = adapter->Next;
            }
            free(adapters);
            WSACleanup();
            return 0;
        }
        else
        {
            printf("\nError from  GetAdaptersAddresses: %d. \n", r);
            free(adapters);
            WSACleanup();
            return -1;
        }
    } while (!adapters);

    WSACleanup();
    printf("Ok.\n");
    return 0;
}