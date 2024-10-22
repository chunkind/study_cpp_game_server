#pragma once
#include "ResourceBase.h"

class Texture;

struct FlipbookInfo
{
	Texture* texture = nullptr;
	wstring name;
	Vec2Int size = {}; // ũ��
	int32 start = 0; // �����ϴ� ��ġ
	int32 end = 0; // �����ϴ� ��ġ
	int32 line = 0; // ���° �ٿ� �ִ���
	float duration = 1.f; // �󸶸�ŭ �ӵ��� Ʋ���� ������
	bool loop = true; // �ݺ� �� ������
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

