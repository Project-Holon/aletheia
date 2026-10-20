#ifndef GAME_OV010_MUSICAL_LINK_TYPES_H
#define GAME_OV010_MUSICAL_LINK_TYPES_H

#include "../types.h"

struct MusicalEventWork;
struct GameData;

/* Link work hung on the game data external-work slot (0x38 bytes). */
typedef struct MusicalLink {
    struct MusicalEventWork *owner;       /* 0x00: the show event work */
    void *session;                        /* 0x04: ov132 comm session */
    u32 entryMenu;                        /* 0x08: comm entry menu handle */
    struct GameData *gameData;            /* 0x0C */
    u8 pad10[0x28 - 0x10];
    u32 procMode;                         /* 0x28: 9 or 10 for the ov100 proc */
    u32 procWork;                         /* 0x2C */
    u16 *resultOut;                       /* 0x30: script variable receiving the result */
    u16 memberCount;                      /* 0x34 */
} MusicalLink;

#endif
