#pragma once
#include <windows.h>
#include <string>
using namespace std;

class Utils
{
public:
	static void DrawText(HDC hdc, Pos pos, const wstring& str);

	static void DrawRect(HDC hdc, Pos pos, float w, float h);

	static void DrawCircle(HDC hdc, Pos pos, float radius);

	static void DrawLine(HDC hdc, Pos from, Pos to);
};