#pragma once
#include "GameObject.h"

class Monster : public GameObject
{
	using Super = GameObject;

public:
	Monster();
	virtual ~Monster() override;

	virtual void Update();

};

