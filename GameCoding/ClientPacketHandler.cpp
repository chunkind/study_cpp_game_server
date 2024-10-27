#include "pch.h"
#include "ClientPacketHandler.h"
#include "BufferReader.h"

//old
//void ClientPacketHandler::HandlePacket(BYTE* buffer, int32 len)
//new
void ClientPacketHandler::HandlePacket(ServerSessionRef session, BYTE* buffer, int32 len)

{
	BufferReader br(buffer, len);

	PacketHeader header;
	br >> header;

	switch (header.id)
	{
	case S_TEST:
		//old
		//Handle_S_TEST(buffer, len);
		//new
		Handle_S_TEST(session, buffer, len);
		break;
	case S_EnterGame:
		//old
		//Handle_S_EnterGame(buffer, len);
		//new
		Handle_S_EnterGame(session, buffer, len);
		break;
	}
}

//old
//void ClientPacketHandler::Handle_S_TEST(BYTE* buffer, int32 len)
//new
void ClientPacketHandler::Handle_S_TEST(ServerSessionRef session, BYTE* buffer, int32 len)
{
	PacketHeader* header = (PacketHeader*)buffer;
	//uint16 id = header->id;
	uint16 size = header->size;

	Protocol::S_TEST pkt;
	pkt.ParseFromArray(&header[1], size - sizeof(PacketHeader));

	uint64 id = pkt.id();
	uint32 hp = pkt.hp();
	uint16 attack = pkt.attack();

	//cout << "ID: " << id << " HP : " << hp << " ATT : " << attack << endl;

	for (int32 i = 0; i < pkt.buffs_size(); i++)
	{
		const Protocol::BuffData& data = pkt.buffs(i);
		//cout << "BuffInfo : " << data.buffid() << " " << data.remaintime() << endl;
	}
}

//old
//void ClientPacketHandler::Handle_S_EnterGame(BYTE* buffer, int32 len)
//new
void ClientPacketHandler::Handle_S_EnterGame(ServerSessionRef session, BYTE* buffer, int32 len)
{
	PacketHeader* header = (PacketHeader*)buffer;
	//uint16 id = header->id;
	uint16 size = header->size;

	Protocol::S_EnterGame pkt;
	pkt.ParseFromArray(&header[1], size - sizeof(PacketHeader));

	bool success = pkt.success();
	uint64 accountId = pkt.accountid();

	// TODO

}