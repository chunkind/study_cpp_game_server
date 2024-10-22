#include "pch.h"
#include "CameraComponent.h"
#include "Actor.h"
#include "SceneManager.h"

CameraComponent::CameraComponent()
{

}

CameraComponent::~CameraComponent()
{
}

void CameraComponent::BeginPlay()
{

}

void CameraComponent::TickComponent()
{
	if (_owner == nullptr)
		return;

	Vec2 pos = _owner->GetPos();

	// TEMP
	pos.x = ::clamp(pos.x, 400.f, 3024.f - 400.f); // x 범위를 400.f ~ 3024.f - 400.f 사이로 
	pos.y = ::clamp(pos.y, 300.f, 2064.f - 300.f); // y 범위를 300.f ~ 2064.f - 300.f 사이로 

	GET_SINGLE(SceneManager)->SetCameraPos(pos);
}

void CameraComponent::Render(HDC hdc)
{

}
