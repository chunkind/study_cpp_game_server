#pragma once
#include "FlipbookActor.h"

class GameObject : public FlipbookActor
{
	using Super = FlipbookActor;

public:
	GameObject();
	virtual ~GameObject() override;

	virtual void BeginPlay() override;
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;

protected:
	virtual void TickIdle() {}
	virtual void TickMove() {}
	virtual void TickSkill() {}
	virtual void UpdateAnimation() {}

public:
	void SetState(ObjectState state);
	void SetDir(Dir dir);

	bool HasReachedDest();
	bool CanGo(Vec2Int cellPos);
	Dir GetLookAtDir(Vec2Int cellPos);

	void SetCellPos(Vec2Int cellPos, bool teleport = false);
	//old
	//Vec2Int GetCellPos() { return GetCellPos(); }
	//new
	Vec2Int GetCellPos();

	Vec2Int GetFrontCellPos();

	//new
	int64 GetObjectID() { return info.objectid(); }
	void SetObjectID(int64 id) { info.set_objectid(id); }

//old
/*protected:
	Vec2Int GetCellPos() = {};
	Vec2 _speed = {};
	Dir info.dir() = DIR_DOWN;
	ObjectState _state = ObjectState::Idle;*/

//new
public:
	Protocol::ObjectInfo info;
};
