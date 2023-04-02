#undef UNICODE
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

#pragma comment (lib, "Ws2_32.lib")
#define DEFAULT_BUFLEN 512

#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
	// Initialize winsock
	WSADATA	wsaData;
	WORD ver = MAKEWORD(2, 2);

	if (argc != 2)
	{
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	int WSOK = WSAStartup(ver, &wsaData);
	if (WSOK != 0)
		printf("WSAStartup() error!");

	// Create a socket
	SOCKET hServSock, hClntSock;	// hServSock = listening
	hServSock = socket(AF_INET, SOCK_STREAM, 0);
	if (hServSock == INVALID_SOCKET)
		printf("socket() error");

	// Bind the IP address and port to a socket
	SOCKADDR_IN servAddr, clntAddr;
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(54000);
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	int binder = bind(hServSock, (SOCKADDR*)&servAddr, sizeof(servAddr));
	if (binder == SOCKET_ERROR)
		printf("bind() error");

	// Tell winsock the socket is ready for listening
	if (listen(hServSock, SOMAXCONN) == SOCKET_ERROR)
		printf("listen() error");

	// Wait for a connection
	int szClntAddr = sizeof(clntAddr);
	hClntSock = accept(hServSock, (SOCKADDR*)&clntAddr, &szClntAddr);
	if (hClntSock == INVALID_SOCKET)
		printf("accept() error");

	char host[NI_MAXHOST];	// Client's remote name
	char service[NI_MAXSERV];	// Service the client is connected on
	ZeroMemory(host, NI_MAXHOST);
	ZeroMemory(service, NI_MAXSERV);
	
	int GNI = getnameinfo((SOCKADDR*)&clntAddr, szClntAddr, host, NI_MAXHOST, service, NI_MAXSERV, 0);
	if (GNI == 0)
		cout << host << " connected on port " << service << endl;
	else
	{
		inet_ntop(AF_INET, &clntAddr.sin_addr, host, NI_MAXHOST);
		cout << host << " connected on port " << ntohs(clntAddr.sin_port) << endl;
	}

	// While loop: accept and echo message back to client
	char testMessage[] = "Hello World!";
	char recvbuf[DEFAULT_BUFLEN];
	int recvbuflen = DEFAULT_BUFLEN;
	while(true)
	{
		int iResult = recv(hClntSock, recvbuf, recvbuflen, 0);

		if (iResult == 0)
		{
			printf("Connection closed\n");
			break;
		}
		else if (iResult == SOCKET_ERROR)
		{
			printf("recv failed with error: %d\n", WSAGetLastError());
			break;
		}
		else
		{
			printf("Bytes received: %d\n", iResult);
			printf("%s\n", recvbuf);
		}
		send(hClntSock, testMessage, sizeof(testMessage) + 1, 0);
		send(hClntSock, recvbuf, sizeof(recvbuflen) + 1, 0);
	}

	// Close the sockets
	closesocket(hClntSock);
	closesocket(hServSock);

	// Clean up winsock
	WSACleanup();
	return 0;
}