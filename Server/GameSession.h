#pragma once
#include "Session.h"

//old
//class GameSession : public Session
//new
class GameSession : public PacketSession

{
public:
	~GameSession()
	{
		cout << "~GameSession" << endl;
	}

	virtual void OnConnected() override;
	virtual void OnDisconnected() override;
	//old
	//virtual int32 OnRecv(BYTE* buffer, int32 len) override;
	//new
	virtual void OnRecvPacket(BYTE* buffer, int32 len) override;

	virtual void OnSend(int32 len) override;
};