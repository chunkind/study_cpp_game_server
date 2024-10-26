#include "pch.h"
#include "GameSession.h"
#include "GameSessionManager.h"
//new
#include "ServerPacketHandler.h"

void GameSession::OnConnected()
{
	GSessionManager.Add(static_pointer_cast<GameSession>(shared_from_this()));

	//new
	Send(ServerPacketHandler::Make_S_EnterGame());

	//new
	// 게임 입장
	//GRoom->EnterRoom(GetSessionRef());
}

void GameSession::OnDisconnected()
{
	GSessionManager.Remove(static_pointer_cast<GameSession>(shared_from_this()));
}

void GameSession::OnRecvPacket(BYTE* buffer, int32 len)
{
	PacketHeader header = *((PacketHeader*)buffer);
	cout << "Packet ID : " << header.id << "Size : " << header.size << endl;
}

void GameSession::OnSend(int32 len)
{

}