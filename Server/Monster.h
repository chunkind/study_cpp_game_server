#pragma once
#include "GameObject.h"

class Monster : public GameObject
{
	using Super = GameObject;

public:
	Monster();
	virtual ~Monster() override;

	virtual void Update();

//new
private:
	virtual void UpdateIdle();
	virtual void UpdateMove();
	virtual void UpdateSkill();

//new
private:
	uint64 _waitUntil = 0;
	weak_ptr<Player> _target;
};

