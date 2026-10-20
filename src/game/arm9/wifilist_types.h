#ifndef GAME_ARM9_WIFILIST_TYPES_H
#define GAME_ARM9_WIFILIST_TYPES_H

#include "../types.h"

/* One friend entry of the DWC friend list (12 bytes, opaque to the game). */
typedef struct DWCFriendData {
    u32 w[3];
} DWCFriendData;

#endif
