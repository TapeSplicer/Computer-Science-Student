#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>

#pragma comment (lib, "Ws2_32.lib")
#define DEFAULT_BUFLEN 512

#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
    string ipAddress = "127.0.0.1"; // Server IP Address
    int port = 54000;   // Server port number

    // Initialize winsock
    WSADATA wsaData;
    WORD ver = MAKEWORD(2, 2);
    int iResult = WSAStartup(ver, &wsaData);
    if (argc != 3) 
    {
        printf("usage: %s server-name port#\n", argv[0]);
        return 1;
    }

    if (iResult != 0) 
    {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    //Fill in the hint structure
    struct addrinfo *ptr = NULL, hints;
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Create socket
    SOCKET ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);

    if (ConnectSocket == INVALID_SOCKET) 
    {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    iResult = getaddrinfo(argv[1], argv[2], &hints, &ptr);
    if (iResult != 0) 
    {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    // Connect to server
    iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
    if (iResult == SOCKET_ERROR) 
    {
        freeaddrinfo(ptr);
        closesocket(ConnectSocket);
        ConnectSocket = INVALID_SOCKET;
        printf("Unable to connect to server!\n");
        WSACleanup();
        return 1;
    }

    // Do-while loop to send and receive data
    const char* testbuf = "this is a test";
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;
    string userInput;

    do
    {
        cout << "> ";
        getline(cin, userInput);

        iResult = send(ConnectSocket, testbuf, (int)strlen(testbuf), 0);
        iResult = send(ConnectSocket, userInput.c_str(), userInput.size() + 1, 0);
        if (iResult == SOCKET_ERROR) 
        {
            printf("send failed with error: %d\n", WSAGetLastError());
            closesocket(ConnectSocket);
            WSACleanup();
            return 1;
        }
        printf("Bytes Sent: %ld\n", iResult);
        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);           
        if (iResult == 0)
            printf("Connection closed\n");
        else if (iResult == SOCKET_ERROR)
            printf("recv failed with error: %d\n", WSAGetLastError());
        else
        {
            printf("Bytes received: %d\n", iResult);
            printf("%s\n", recvbuf);
        } 
    } while (userInput.size() > 0);

    // Close down everything
    iResult = shutdown(ConnectSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) 
    {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }
    closesocket(ConnectSocket);
    WSACleanup();
    return 0;
}