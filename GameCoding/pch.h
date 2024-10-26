#pragma once

//new
#include "CorePch.h"

#include "Types.h"
#include "Defines.h"
#include "Enums.h"
#include "Utils.h"
#include "Values.h"

//new
#include "Protocol.pb.h"
#include "Enum.pb.h"
#include "Struct.pb.h"

//old
/*#include <windows.h>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

#include <string>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;*/
#include <assert.h>
//new
#include "ClientPacketHandler.h"

// C++20
#include <format>
#include <filesystem>
namespace fs = std::filesystem;

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#pragma comment(lib, "msimg32.lib")

// »ç¿îµå
#include <MMSystem.h>
#include <dsound.h>
#pragma comment (lib, "winmm.lib")
#pragma comment (lib, "dsound.lib")

//new
#ifdef _DEBUG
#pragma comment(lib, "ServerCore\\Debug\\ServerCore.lib")
#pragma comment(lib, "Protobuf\\Debug\\libprotobufd.lib")
#else
#pragma comment(lib, "ServerCore\\Release\\ServerCore.lib")
#pragma comment(lib, "Protobuf\\Release\\libprotobuf.lib")
#endif