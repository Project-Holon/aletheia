#ifndef GAME_OV187_BR_LAUNCH_TYPES_H
#define GAME_OV187_BR_LAUNCH_TYPES_H

#include "../types.h"

struct GameData;

/* Parameter block the recorder proc (ov187) is started with; the net save screen builds it. */
typedef struct BrLaunchParam {
    u32 kind;
    struct GameData *gameData;
    void *netArg;
    int unknownC;
} BrLaunchParam;

#endif
