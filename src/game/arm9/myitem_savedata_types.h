#ifndef GAME_ARM9_MYITEM_SAVEDATA_TYPES_H
#define GAME_ARM9_MYITEM_SAVEDATA_TYPES_H

#include "../types.h"

/* One bag slot: item id and stack size (4 bytes). */
typedef struct BagSlot {
    u16 itemId;
    u16 quantity;
} BagSlot;

#endif
