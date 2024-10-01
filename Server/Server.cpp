#include "pch.h"
#include <iostream>
#include <thread>
#include <vector>
using namespace std;
#include <atomic>
#include <mutex>
#include <windows.h>
//#include "TestMain.h"
#include "ThreadManager.h"


// 서버
// 1) 새로운 소켓 생성 (socket)
// 2) 소켓에 주소/포트 번호 설정 (bind)
// --------------------
// 3) 클라와 통신

int main()
{
	SocketUtils::Init();

	// 블로킹 소켓
	// accept -> 접속한 클라가 있을 때
	// connect -> 서버 접속 성공했을 때
	// send -> 요청한 데이터를 송신 버퍼에 복사했을 때
	// recv -> 수신 버퍼에 도착한 데이터가 있고, 이를 유저레벨 버퍼에 복사했을 때

	SOCKET listenSocket = ::socket(AF_INET, SOCK_STREAM, 0);
	if (listenSocket == INVALID_SOCKET)
		return 0;
	/*
	//소켓 옵션
	// - 1) level (SOL_SOCKET, IPPROTO_IP, IPPROTO_TCP)
	// - 2) optname
	// - 3) optval

	// SO_KEEPALIVE
	bool enable = true;
	::setsockopt(listenSocket, SOL_SOCKET, SO_KEEPALIVE, (char*)&enable, sizeof(enable));

	// SO_LINGER = 지연하다.
	// SO_SNDBUF
	// SO_RCVBUF

	int32 sendBufferSize;
	int32 optionLen = sizeof(sendBufferSize);
	::getsockopt(listenSocket, SOL_SOCKET, SO_SNDBUF, (char*)&sendBufferSize, &optionLen);
	cout << "송신 버퍼 크기" << sendBufferSize << endl; //64KB

	// SO_REUSEADDR
	{
		bool enable = true;
		::setsockopt(listenSocket, SOL_SOCKET, SO_REUSEADDR, (char*)&enable, sizeof(enable));
	}

	// IPPROTO_TCP
	// TCP_NODELAY = Nagle 알고리즘 작동 여부
	// 1byte << [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ] 패킷을 뭉처보낸다.
	*/

	// https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-ioctlsocket
	// 논블로킹 소켓으로
	u_long on = 1;
	if (::ioctlsocket(listenSocket, FIONBIO, &on) == INVALID_SOCKET)
		return 0;

	SocketUtils::SetReuseAddress(listenSocket, true);

	if (SocketUtils::BindAnyAddress(listenSocket, 7777) == false)
		return 0;

	if (SocketUtils::Listen(listenSocket, SOMAXCONN) == false)
		return 0;

	SOCKADDR_IN clientAddr;
	int32 addrLen = sizeof(clientAddr);

	// Accept
	while (true)
	{
		SOCKET clientSocket = ::accept(listenSocket, (SOCKADDR*)&clientAddr, &addrLen);
		if (clientSocket == INVALID_SOCKET)
		{
			// 원래 블로킹했어야 했는데... 너가 논블로킹으로 하라며?
			if (::WSAGetLastError() == WSAEWOULDBLOCK)
				continue;
		}

		cout << "Client Connected!" << endl;

		// Recv
		while (true)
		{
			char recvBuffer[1000];
			int32 recvLen = ::recv(clientSocket, recvBuffer, sizeof(recvBuffer), 0);
			if (recvLen == SOCKET_ERROR)
			{
				// 원래 블로킹했어야 했는데... 너가 논블로킹으로 하라며?
				if (::WSAGetLastError() == WSAEWOULDBLOCK)
					continue;

				// TODO
				break;
			}

			cout << "Recv Data = " << recvBuffer << endl;
			cout << "Recv Data len = " << recvLen << endl;
		}
	}

	SocketUtils::Close(listenSocket);
}