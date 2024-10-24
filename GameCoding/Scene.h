#pragma once

class Actor;
//new
class Creature;

class UI;

class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void Init();
	virtual void Update();
	virtual void Render(HDC hdc);

	void AddActor(Actor* actor);
	void RemoveActor(Actor* actor);

	//new
	Creature* GetCreatureAt(Vec2Int cellPos);

public:
	vector<Actor*> _actors[LAYER_MAXCOUNT];
	vector<UI*> _uis;
};

