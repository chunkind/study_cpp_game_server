#pragma once
#include "Creature.h"

//new
class Player;

class Monster : public Creature
{
	using Super = Creature;

public:
	Monster();
	virtual ~Monster() override;

	virtual void BeginPlay() override;
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;

private:
	virtual void TickIdle() override;
	virtual void TickMove() override;
	virtual void TickSkill() override;
	virtual void UpdateAnimation() override;

protected:
	Flipbook* _flipbookMove[4] = {};
	//new
	float _waitSeconds = 0;

	//new
	Player* _target = nullptr; // TEMP
};

