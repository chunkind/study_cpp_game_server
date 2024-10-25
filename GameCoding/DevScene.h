#pragma once
#include "Scene.h"

class Actor;
class GameObject;
class UI;

class DevScene : public Scene
{
	using Super = Scene;

public:
	DevScene();
	virtual ~DevScene() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	//new
	virtual void AddActor(Actor* actor) override;
	virtual void RemoveActor(Actor* actor) override;

	void LoadMap();
	void LoadPlayer();
	void LoadMonster();
	void LoadProjectiles();
	void LoadEffect();
	void LoadTilemap();

	template<typename T>
	T* SpawnObject(Vec2Int pos)
	{
		// Type-Trait
		auto isGameObject = std::is_convertible_v<T*, GameObject*>;
		assert(isGameObject);

		T* ret = new T();
		ret->SetCellPos(pos, true);
		AddActor(ret);

		ret->BeginPlay();

		return ret;
	}

	//new
	template<typename T>
	T* SpawnObjectAtRandomPos()
	{
		Vec2Int randPos = GetRandomEmptyCellPos();
		return SpawnObject<T>(randPos);
	}

	bool CanGo(Vec2Int cellPos);
	Vec2 ConvertPos(Vec2Int cellPos);
	//new
	Vec2Int GetRandomEmptyCellPos();

//new
private:
	void TickMonsterSpawn();

//new
private:
	const int32 DESIRED_MONSTER_COUNT = 20;
	int32 _monsterCount = 0;

	class TilemapActor* _tilemapActor = nullptr;
};

