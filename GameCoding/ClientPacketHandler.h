#pragma once

enum
{
	S_TEST = 1,
	//new
	S_EnterGame = 2,
};

class ClientPacketHandler
{
public:
	static void HandlePacket(BYTE* buffer, int32 len);

	//�ޱ�
	static void Handle_S_TEST(BYTE* buffer, int32 len);
	//new
	static void Handle_S_EnterGame(BYTE* buffer, int32 len);

	// ������
	template<typename T>
	static SendBufferRef MakeSendBuffer(T& pkt, uint16 pktId)
	{
		const uint16 dataSize = static_cast<uint16>(pkt.ByteSizeLong());
		const uint16 packetSize = dataSize + sizeof(PacketHeader);

		SendBufferRef sendBuffer = make_shared<SendBuffer>(packetSize);
		PacketHeader* header = reinterpret_cast<PacketHeader*>(sendBuffer->Buffer());
		header->size = packetSize;
		header->id = pktId;
		assert(pkt.SerializeToArray(&header[1], dataSize));
		sendBuffer->Close(packetSize);

		return sendBuffer;
	}
};
