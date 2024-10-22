#pragma once
#include "ResourceBase.h"

class Texture;

struct FlipbookInfo
{
	Texture* texture = nullptr;
	wstring name;
	Vec2Int size = {}; // 크기
	int32 start = 0; // 시작하는 위치
	int32 end = 0; // 종료하는 위치
	int32 line = 0; // 몇번째 줄에 있느냐
	float duration = 1.f; // 얼마만큼 속도로 틀어줄 것인지
	bool loop = true; // 반복 할 것인지
};

class Flipbook : public ResourceBase
{
public:
	Flipbook();
	virtual ~Flipbook();

	void SetInfo(const FlipbookInfo& info) { _info = info; }
	const FlipbookInfo& GetInfo() { return _info; }

private:
	FlipbookInfo _info;
};

