#include "pch.h"
#include "HitEffect.h"
//new
#include "ResourceManager.h"
#include "SceneManager.h"
#include "Scene.h"

HitEffect::HitEffect()
{
	//new
	SetLayer(LAYER_EFFECT);
}

HitEffect::~HitEffect()
{
}

void HitEffect::BeginPlay()
{
	Super::BeginPlay();

	//new
	UpdateAnimation();
}

void HitEffect::Tick()
{
	Super::Tick();

	//new
	if (IsAnimationEnded())
	{
		Scene* scene = GET_SINGLE(SceneManager)->GetCurrentScene();
		scene->RemoveActor(this);
	}
}

void HitEffect::Render(HDC hdc)
{
	Super::Render(hdc);
}

//new
void HitEffect::UpdateAnimation()
{
	SetFlipbook(GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_Hit"));
}
