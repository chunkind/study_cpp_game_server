#pragma once

enum class SceneType
{
	None,
	DevScene,
	EditScene
};

enum LAYER_TYPE
{
	LAYER_BACKGROUND,
	LAYER_OBJECT,
	LAYER_EFFECT,

	LAYER_UI,

	LAYER_MAXCOUNT
};

enum class ColliderType
{
	Box,
	Sphere,
};

enum COLLISION_LAYER_TYPE : uint8
{
	CLT_OBJECT,
	CLT_GROUND,
	CLT_WALL,
};

//old
/*enum Dir
{
	DIR_UP,
	DIR_DOWN,
	DIR_LEFT,
	DIR_RIGHT,
};

enum class ObjectState
{
	Idle,
	Move,
	Skill
};*/
//new
#include "Enum.pb.h"
using Dir = Protocol::DIR_TYPE;

//new
#define DIR_DOWN	Protocol::DIR_TYPE_DOWN
#define DIR_UP		Protocol::DIR_TYPE_UP
#define DIR_LEFT	Protocol::DIR_TYPE_LEFT
#define DIR_RIGHT	Protocol::DIR_TYPE_RIGHT

//new
#define IDLE	Protocol::OBJECT_STATE_TYPE_IDLE
#define MOVE	Protocol::OBJECT_STATE_TYPE_MOVE
#define SKILL	Protocol::OBJECT_STATE_TYPE_SKILL

//new
using ObjectState = Protocol::OBJECT_STATE_TYPE;

enum class WeaponType
{
	Sword,
	Bow,
	Staff
};