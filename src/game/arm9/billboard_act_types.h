#ifndef GAME_ARM9_BILLBOARD_ACT_TYPES_H
#define GAME_ARM9_BILLBOARD_ACT_TYPES_H

#include "../arm9/billboard_types.h"

/*
 * Request records of the billboard_act system (particle.c). The effect files
 * fill them on the stack and pass them to the slot and entry creation calls.
 */

struct BbActSys;

typedef struct BbActRec BbActRec;
typedef struct BbActDesc BbActDesc;

typedef void (*BbActEntryHook)(struct BbActSys *sys, int entryIndex, void *arg);

/* Request record for one image slot (creation of slots). */
struct BbActRec {
    uptr resource;
    u8  format;
    u8  sizeS;
    u8  sizeT;
    u8  paletteId;
    u32 kind;                /* 0: board image, 1: board image plus commit, 2: external payload */
};

/* Creation record for one entry (0x24 bytes). */
struct BbActDesc {
    u16 slot;                /* 0x00: slot index, relative to the base slot */
    s16 width;               /* 0x02 */
    s16 height;              /* 0x04 */
    u8  layer;               /* 0x06 */
    u8  pad07;
    u32 flags;               /* 0x08 */
    u32 color;               /* 0x0C */
    VecFx32 pos;             /* 0x10 */
    BbActEntryHook hook;     /* 0x1C */
    void *hookArg;           /* 0x20 */
};

#endif
