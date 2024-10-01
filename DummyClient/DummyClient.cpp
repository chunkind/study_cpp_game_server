﻿#include "pch.h"
#include <iostream>

// 클라
// 1) 새로운 소켓 생성
// 2) 서버와 통신
int main()
{
	WSAData wsaData;
	if (::WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		return 0;

	this_thread::sleep_for(1s);

	// ad : Address Family (AF_INET = IPv4, AF_INET6 = IPv6)
	// type : TCP(SOCK_STREAM) vs UDP(SOCK_DGRAM)
	// protocol : 0
	// return : descriptor
	SOCKET clientSocket = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (clientSocket == INVALID_SOCKET)
		return 0;

	SOCKADDR_IN serverAddr; // IPv4
	::memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	//serverAddr.sin_addr.s_addr = ::inet_addr("127.0.0.1"); << deprecated
	::inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);
	serverAddr.sin_port = ::htons(7777); // 80 : HTTP

	while (true)
	{
		char sendBuffer[100] = "Hello! I am Client";
		int32 sendLen = ::sendto(clientSocket, sendBuffer, sizeof(sendBuffer), 0, (SOCKADDR*)&serverAddr, sizeof(serverAddr));

		this_thread::sleep_for(0.01s);
	}

	// --------------------------

	::closesocket(clientSocket);
	::WSACleanup();
}