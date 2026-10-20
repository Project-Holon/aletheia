#ifndef BTLV_CLACT_SHARED_TYPES_H
#define BTLV_CLACT_SHARED_TYPES_H

#include "../ov094/btlv_effvm_types.h"
#include "../arm9/clact.h"
#include "../ov094/btlv_camera_shared_types.h"

struct Unit;

struct ClactActor;


#define BTLV_CLACT_SLOT_COUNT 7

/* One loaded sprite: its actor and the three resources it uses. */
typedef struct BtlvClactSlot {
    struct ClactActor *actor;    /* 0x00: 0 = slot free */
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
    VecFx32 pos;       /* 0x04: current value, written by the mover */
    int slot;           /* 0x10 */
    BtlvMover mover;    /* 0x14 */
} BtlvClactMoveTask;

/* Opaque handles and records that btlv_input.c refers to by tag (lane C094c3 still has no definition for them). */
struct Unit;
struct PtS;
struct ClactVec2;
struct ClactActor;

/* Two ints, used by btlv_input.c (lane C094c3). */
typedef struct BtlvClactPoint {
    int x;
    int y;
} BtlvClactPoint;

#endif
