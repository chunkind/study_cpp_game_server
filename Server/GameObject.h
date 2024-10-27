#pragma once

class Player;
class Monster;

class GameObject
{
public:
	GameObject() {}
	virtual ~GameObject() {}

	//new
	virtual void Update();

	static PlayerRef CreatePlayer();
	static MonsterRef CreateMonster();

	//new
	void SetState(ObjectState state, bool broadcast = false);
	void SetDir(Dir dir, bool broadcast = false);

	//new
	//bool HasReachedDest();
	bool CanGo(Vec2Int cellPos);
	Dir GetLookAtDir(Vec2Int cellPos);

	//new
	void SetCellPos(Vec2Int cellPos, bool broadcast = false);
	Vec2Int GetCellPos() { return Vec2Int{ info.posx(), info.posy() }; }
	Vec2Int GetFrontCellPos();

	//new
	int64 GetObjectID() { return info.objectid(); }
	void SetObjectID(int64 id) { info.set_objectid(id); }

	//new
	void BroadcastMove();

public:
	Protocol::ObjectInfo info;
	GameRoomRef room;

private:
	static atomic<uint64> s_idGenerator;
};

