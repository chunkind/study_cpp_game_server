#include "pch.h"
#include "GameSession.h"
#include "GameSessionManager.h"

void GameSession::OnConnected()
{
	GSessionManager.Add(static_pointer_cast<GameSession>(shared_from_this()));
}

void GameSession::OnDisconnected()
{
	GSessionManager.Remove(static_pointer_cast<GameSession>(shared_from_this()));
}

//old
//int32 GameSession::OnRecv(BYTE* buffer, int32 len)
//new
void GameSession::OnRecvPacket(BYTE* buffer, int32 len)
{
	//old
	/*// Echo
	cout << "OnRecv Len = " << len << endl;

	SendBufferRef sendBuffer = make_shared<SendBuffer>(4096);
	sendBuffer->CopyData(buffer, len);

	GSessionManager.Broadcast(sendBuffer);

	return len;*/

	//new
	PacketHeader header = *((PacketHeader*)buffer);
	cout << "Packet ID : " << header.id << "Size : " << header.size << endl;
}

void GameSession::OnSend(int32 len)
{
	//old
	//cout << "OnSend Len = " << len << endl;
}