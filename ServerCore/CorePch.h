#pragma once

#include "Types.h"
#include "CoreMacro.h"
#include "CoreTLS.h"
#include "CoreGlobal.h"

#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <iostream>
#include <winsock2.h>
#include <mswsock.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <windows.h>
using namespace std;

#include <assert.h>
#include "SocketUtils.h"
#include "SendBuffer.h"
#include "Session.h"

// Need to link with Ws2_32.lib
#pragma comment(lib, "ws2_32.lib")
