#ifndef GAME_ARM9_BATTLE_BOX_TYPES_H
#define GAME_ARM9_BATTLE_BOX_TYPES_H

#include "../types.h"

/* Save block 0x31: the Battle Box, six boxed Pokemon and the box name.
 * BATTLE_BOX_GetMon indexes the group array with a 0x330 stride. */
struct BoxMonGroup {
    struct BoxMon mon[6];
};

struct BattleBoxSave {
    struct BoxMonGroup group;
    u16 boxName[10];
    u8  unusedData[0x14];
    u16 lockFlags;
    u16 padding;
};

#endif
