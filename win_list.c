#ifndef _WIN32_WINNT               // ifndef checks whether the given token has been
#define _WIN32_WINNT 0x0600        // defined earlier in the file or in an included file; if not, it includes the code between it and the closing
#endif                             //https://gcc.gnu.org/onlinedocs/gcc-7.5.0/cpp/Include-Syntax.html
#include <stdio.h>                 //C library to perform Input/Output operations http://www.cplusplus.com/reference/cstdio/
#include <winsock2.h>              //windows headers https://docs.microsoft.com/en-us/windows/win32/api/winsock2/
#include <iphlpapi.h>              //windows headers https://docs.microsoft.com/en-us/windows/win32/api/iphlpapi/
#include <ws2tcpip.h>              //windows headers https://docs.microsoft.com/en-us/windows/win32/api/ws2tcpip/
#include <stdlib.h>                //memory allocation http://www.cplusplus.com/reference/cstdlib/
#pragma comment(lib, "ws2_32.lib") // https://www.geeksforgeeks.org/pragma-directive-in-c-c/
// Functions in C - https://www.geeksforgeeks.org/functions-in-c/
int main()
{
    printf("Main function called");
    // WinSock - https://en.wikipedia.org/wiki/Winsock
    // WinSock WSAStartup - https://docs.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsastartup
    WSADATA d;
    //Windef.h - https://stackoverflow.com/questions/24131843/what-is-makeword-used-for
    // Bitwise Operation - https://www.tutorialspoint.com/cprogramming/c_operators.htm
    if (WSAStartup(MAKEWORD(2, 2), &d))
    {
        printf("Failed to initialize.\n");
        return -1;
    }
    // DWord  - https://www.computerhope.com/jargon/d/dword.htm
    ULONG asize = 20000;
    //iptypes.h  - https://docs.microsoft.com/en-us/windows/win32/api/iptypes/ns-iptypes-ip_adapter_addresses_lh
    PIP_ADAPTER_ADDRESSES adapters;
    do
    {

        /* code */
        // Dynamic memory allocation - https://www.programiz.com/c-programming/c-dynamic-memory-allocation
        adapters = (PIP_ADAPTER_ADDRESSES)malloc(asize);

        // system error codes - https://docs.microsoft.com/en-us/windows/win32/debug/system-error-codes--0-499-
        if (!adapters)
        {
            // printf string formating in c - https://alvinalexander.com/programming/printf-format-cheat-sheet
            printf("Couldn't allocate %ld bytes for adapters.\n", asize);
            // Winsock - Wsaclenup = https://docs.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsacleanup
            WSACleanup();
            return -1;
        }

        // iphlpapi.h  -https://docs.microsoft.com/en-us/windows/win32/api/iphlpapi/nf-iphlpapi-getadaptersaddresses
        int r = GetAdaptersAddresses(AF_UNSPEC, GAA_FLAG_INCLUDE_PREFIX, NULL, adapters, &asize);
        if (r == ERROR_BUFFER_OVERFLOW)
        {
            printf("\nGet Adapters Addresses wants %ld bytes.\n", asize);
            // free function in c - https://www.tutorialspoint.com/c_standard_library/c_function_free.htm
            free(adapters);
        }
        else if (r == NO_ERROR)
        {
            PIP_ADAPTER_ADDRESSES adapter = adapters;
            while (adapter)
            {
                // Linked List in C - https://www.geeksforgeeks.org/linked-list-set-1-introduction/
                printf("\nAdapter name: %S\n", adapter->FriendlyName);
                PIP_ADAPTER_UNICAST_ADDRESS address = adapter->FirstUnicastAddress;
                while (address)
                {
                    printf("\t%s", address->Address.lpSockaddr->sa_family == AF_INET ? "IPv4" : "IPv6");
                    // character type in c - https://www.zentut.com/c-tutorial/c-character-type/
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