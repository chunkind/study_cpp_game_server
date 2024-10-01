#include "pch.h"
#include "CoreTLS.h"


// 코드 X
// 스택 X
// 힙 O
// 데이터 O
// TLS X  -> 동일한 쓰레드 영역에서는 공유할수 있음.

thread_local uint32 LThreadId = 0;
