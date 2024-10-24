#pragma once
#include "FlipbookActor.h"
#include "Creature.h"

class Flipbook;

class Player : public Creature
{
	using Super = Creature;

public:
	Player();
	virtual ~Player() override;

	virtual void BeginPlay() override;
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;

private:
	virtual void TickIdle() override;
	virtual void TickMove() override;
	virtual void TickSkill() override;
	virtual void UpdateAnimation() override;

	//new
	void SetWeaponType(WeaponType weaponType) { _weaponType = weaponType; }
	WeaponType GetWeaponType() { return _weaponType; }

private:
	Flipbook* _flipbookIdle[4] = {};
	Flipbook* _flipbookMove[4] = {};
	Flipbook* _flipbookAttack[4] = {};
	//new
	Flipbook* _flipbookBow[4] = {};
	Flipbook* _flipbookStaff[4] = {};

	bool _keyPressed = false;
	//new
	WeaponType _weaponType = WeaponType::Sword;
};

