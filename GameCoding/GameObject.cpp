#include "pch.h"
#include "GameObject.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "ResourceManager.h"
#include "Flipbook.h"
#include "CameraComponent.h"
#include "BoxCollider.h"
#include "SceneManager.h"
#include "DevScene.h"

GameObject::GameObject()
{
	
}

GameObject::~GameObject()
{

}

void GameObject::BeginPlay()
{
	Super::BeginPlay();

	SetState(MOVE);
	SetState(IDLE);
}

void GameObject::Tick()
{
	Super::Tick();

	switch (info.state())
	{
	case IDLE:
		TickIdle();
		break;
	case MOVE:
		TickMove();
		break;
	case SKILL:
		TickSkill();
		break;
	}
}

void GameObject::Render(HDC hdc)
{
	Super::Render(hdc);
}

void GameObject::SetState(ObjectState state)
{
	//old
	//if (_state == state)
	//new
	if (info.state() == state)
		return;

	//old
	//_state = state;
	info.set_state(state);
	UpdateAnimation();
}

void GameObject::SetDir(Dir dir)
{
	//old
	//info.dir() = dir;
	//new
	info.set_dir(dir);
	UpdateAnimation();
}

bool GameObject::HasReachedDest()
{
	Vec2 dir = (_destPos - _pos);
	return (dir.Length() < 10.f);
}

bool GameObject::CanGo(Vec2Int cellPos)
{
	DevScene* scene = dynamic_cast<DevScene*>(GET_SINGLE(SceneManager)->GetCurrentScene());
	if (scene == nullptr)
		return false;

	return scene->CanGo(cellPos);
}

Dir GameObject::GetLookAtDir(Vec2Int cellPos)
{
	Vec2Int dir = cellPos - GetCellPos();
	if (dir.x > 0)
		return DIR_RIGHT;
	else if (dir.x < 0)
		return DIR_LEFT;
	else if (dir.y > 0)
		return DIR_DOWN;
	else
		return DIR_UP;
}

void GameObject::SetCellPos(Vec2Int cellPos, bool teleport)
{
	//old
	//GetCellPos() = cellPos;
	//new
	info.set_posx(cellPos.x);
	info.set_posy(cellPos.y);

	DevScene* scene = dynamic_cast<DevScene*>(GET_SINGLE(SceneManager)->GetCurrentScene());
	if (scene == nullptr)
		return;

	_destPos = scene->ConvertPos(cellPos);

	if (teleport)
		_pos = _destPos;
}

//new
Vec2Int GameObject::GetCellPos()
{
	return Vec2Int{ info.posx(), info.posy() };
}

//old
/*Vec2Int GameObject::GetFrontCellPos()
{
	switch (info.dir())
	{
	case DIR_DOWN:
		return GetCellPos() + Vec2Int{ 0, 1 };
	case DIR_LEFT:
		return GetCellPos() + Vec2Int{ -1, 0 };
	case DIR_RIGHT:
		return GetCellPos() + Vec2Int{ 1, 0 };
	case DIR_UP:
		return GetCellPos() + Vec2Int{ 0, -1 };
	}

	return GetCellPos();
}*/
//new
Vec2Int GameObject::GetFrontCellPos()
{
	switch (info.dir())
	{
	case DIR_DOWN:
		return GetCellPos() + Vec2Int{ 0, 1 };
	case DIR_LEFT:
		return GetCellPos() + Vec2Int{ -1, 0 };
	case DIR_RIGHT:
		return GetCellPos() + Vec2Int{ 1, 0 };
	case DIR_UP:
		return GetCellPos() + Vec2Int{ 0, -1 };
	}

	return GetCellPos();
}
