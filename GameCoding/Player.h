#pragma once
#include "FlipbookActor.h"
//new
#include "Creature.h"

class Flipbook;
//old
//class Collider;
//class BoxCollider;

//old
/*enum class ObjectState
{
	Idle,
	Move,
	Skill
};*/

//old
//class Player : public FlipbookActor
//new
class Player : public Creature
{
	//old
	//using Super = FlipbookActor;
	//new
	using Super = Creature;

public:
	Player();
	virtual ~Player() override;

	virtual void BeginPlay() override;
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;

private:
	//old
	/*virtual void TickIdle();
	virtual void TickMove();
	virtual void TickSkill();*/
	//new
	virtual void TickIdle() override;
	virtual void TickMove() override;
	virtual void TickSkill() override;

	//old
	//void SetState(PlayerState state);
	//void SetDir(Dir dir);

	//old
	//void UpdateAnimation();
	//new
	virtual void UpdateAnimation() override;

	//old
	/*bool HasReachedDest();
	bool CanGo(Vec2Int cellPos);
	void SetCellPos(Vec2Int cellPos, bool teleport = false);*/

private:
	Flipbook* _flipbookIdle[4] = {};
	Flipbook* _flipbookMove[4] = {};
	Flipbook* _flipbookAttack[4] = {};

	//old
/*private:
	Vec2Int _cellPos = {};
	Vec2 _speed = {};
	Dir _dir = DIR_DOWN;
	PlayerState _state = PlayerState::Idle;*/

	bool _keyPressed = false;
};

