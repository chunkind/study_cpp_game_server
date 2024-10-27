#pragma once

class Scene;
//new
class MyPlayer;

class SceneManager
{
	DECLARE_SINGLE(SceneManager)

public:
	void Init();
	void Update();
	void Render(HDC hdc);

	void Clear();

public:
	void ChangeScene(SceneType sceneType);
	Scene* GetCurrentScene() { return _scene; }
	//new
	class DevScene* GetDevScene();

	//new
	MyPlayer* GetMyPlayer() { return _myPlayer; }
	uint64 GetMyPlayerId();
	void SetMyPlayer(MyPlayer* myPlayer) { _myPlayer = myPlayer; }

private:
	Scene* _scene;
	SceneType _sceneType = SceneType::None;

	//new
	MyPlayer* _myPlayer = nullptr;

public:
	Vec2 GetCameraPos() { return _cameraPos; }
	void SetCameraPos(Vec2 pos) { _cameraPos = pos; }

private:
	Vec2 _cameraPos = { 400, 300 };
};

