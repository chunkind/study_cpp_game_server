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

//old
//private:
//new
protected:
	virtual void TickIdle() {}
	virtual void TickMove() {}
	virtual void TickSkill() {}
	virtual void UpdateAnimation() {}

//new
public:
	//old
	//void SetState(PlayerState state);
	//new
	void SetState(ObjectState state);
	void SetDir(Dir dir);

	bool HasReachedDest();
	bool CanGo(Vec2Int cellPos);
	void SetCellPos(Vec2Int cellPos, bool teleport = false);

//old
//private:
//new
protected:

	Vec2Int _cellPos = {};
	Vec2 _speed = {};
	Dir _dir = DIR_DOWN;
	//old
	//PlayerState _state = PlayerState::Idle;
	//new
	ObjectState _state = ObjectState::Idle;
};
