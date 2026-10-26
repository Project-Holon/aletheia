#ifndef GAME_OV014_WIH_TYPES_H
#define GAME_OV014_WIH_TYPES_H

#include "../types.h"

/* Callback types of the WH work block (what the SDK calls back into). */
typedef int (*WihJudgeAcceptFunc)(void *startParentCb, void *userArg);

typedef int (*WihRecvCallback)(u32 aid, u32 data, u32 length);

typedef void (*WihSlotCallback)(u16 aid);

typedef void (*WihBeaconFoundCallback)(void *bssDesc, void *userArg, u16 linkLevel);

typedef int (*WihJudgeScanFunc)(void *bssDesc);

typedef void (*WihResultCallback)(int ok);

/* Callback of WIH_End: runs when WM has shut down; its result is not read. */
typedef int (*WihEndCallback)(int ok);

#endif
