#pragma once
#include "Projectile.h"

class Arrow : public Projectile
{
	using Super = Projectile;

public:
	Arrow();
	virtual ~Arrow() override;

	virtual void BeginPlay() override;
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;

private:
	//old
	/*virtual void TickIdle() override {}
	virtual void TickMove() override {}
	virtual void TickSkill() override {}
	virtual void UpdateAnimation() override {}*/

	//new
	virtual void TickIdle() override;
	virtual void TickMove() override;
	virtual void UpdateAnimation() override;

//new
protected:
	Flipbook* _flipbookMove[4] = {};
};

