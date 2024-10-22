#include "pch.h"
#include "TimeManager.h"

void TimeManager::Init()
{
	::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&_frequency));
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&_prevCount));
}

void TimeManager::Update()
{
	// 현재값 받아오기
	uint64 currentCount;
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount));

	// 경과된 시간
	_deltaTime = (currentCount - _prevCount) / static_cast<float>(_frequency);
	// 현재상태 이전상태에 저장
	_prevCount = currentCount;

	_frameCount++; // 몇번 호출됐는지 저장
	_frameTime += _deltaTime; // 경과된 시간도 저장

	if (_frameTime > 1.f)
	{
		_fps = static_cast<uint32>(_frameCount / _frameTime);

		_frameTime = 0.f;
		_frameCount = 0;
	}
}