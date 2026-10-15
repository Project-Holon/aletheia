#ifndef BTLV_CLACT_SHARED_TYPES_H
#define BTLV_CLACT_SHARED_TYPES_H

#include "btlv_effvm_types.h"
#include "btlv_camera_shared_types.h"

struct Unit;

struct Actor;

struct PalAnmSlot;

#define BTLV_CLACT_SLOT_COUNT 7

/* Actor setup, same layout as struct ActorInit in arm9/clact.c. */
typedef struct BtlvClactActorInit {
    s16 x;              /* 0x00 */
    s16 y;              /* 0x02 */
    u16 animSeq;        /* 0x04 */
    u8 drawPriority;    /* 0x06 */
    u8 bgPriority;      /* 0x07 */
    s16 originX;        /* 0x08 */
    s16 originY;        /* 0x0A */
    u32 scaleX;         /* 0x0C */
    u32 scaleY;         /* 0x10 */
    u16 rotation;       /* 0x14 */
    u16 affineMode;     /* 0x16 */
} BtlvClactActorInit;

/* One loaded sprite: its actor and the three resources it uses. */
typedef struct BtlvClactSlot {
    struct Actor *actor;    /* 0x00: 0 = slot free */
    s32 charId;             /* 0x04 */
    s32 paletteId;          /* 0x08 */
    s32 cellId;             /* 0x0C */
} BtlvClactSlot;

/* The battle sprite manager (0x84 bytes), made by BTLV_CLACT_Create. */
typedef struct BtlvClact {
    void *owner;                                /* 0x00: task owner */
    struct Unit *unit;                          /* 0x04 */
    BtlvClactSlot slot[BTLV_CLACT_SLOT_COUNT];  /* 0x08 */
    u32 moveMask;       /* 0x78: bit n set while a move task runs on slot n */
    u32 scaleMask;      /* 0x7C: bit n set while a scale task runs on slot n */
    u16 heap;           /* 0x80 */
    u16 pad_82;         /* struct padding */
} BtlvClact;

/* Work of a move or scale task of one slot (0x50 bytes). */
typedef struct BtlvClactMoveTask {
    BtlvClact *clact;   /* 0x00 */
    BtlvVec3 pos;       /* 0x04: current value, written by the mover */
    int slot;           /* 0x10 */
    BtlvMover mover;    /* 0x14 */
} BtlvClactMoveTask;

/* Opaque handles and records that btlv_input.c refers to by tag (lane C094c3 still has no definition for them). */
struct Bank;
struct PtS;
struct Vec2;
struct Obj;
struct Obj_02201DA0;

/* Two ints, used by btlv_input.c (lane C094c3). */
typedef struct BtlvClactPoint {
    int x;
    int y;
} BtlvClactPoint;

#endif
