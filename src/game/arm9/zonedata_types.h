#ifndef GAME_ARM9_ZONEDATA_TYPES_H
#define GAME_ARM9_ZONEDATA_TYPES_H

#include "../types.h"
#include "../sdk_fx.h"

/* Rail position, the second form of Location.pos. */
typedef struct RailLocation {
    u16 railIndex;  /* 0x00 */
    u8  type;       /* 0x02, 2 marks a stored location as not set yet */
    u8  key;        /* 0x03, rail move key */
    s16 widthGrid;  /* 0x04 */
    u16 lineGrid;   /* 0x06 */
} RailLocation;

/* A warp destination (0x1c bytes). */
typedef struct Location {
    u32 type;           /* 0x00: 0 exit, 1 direct */
    u16 zoneId;         /* 0x04 */
    s16 exitId;         /* 0x06 */
    s16 dir;            /* 0x08, read signed by ov020 event_mapchange */
    u16 exitOffset;     /* 0x0a */
    u32 posType;        /* 0x0c: 0 vector, 1 rail */
    union {
        VecFx32 vec;
        RailLocation rail;
    } pos;              /* 0x10 */
} Location;

#endif
