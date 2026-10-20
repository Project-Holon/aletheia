#ifndef GAME_OV095_BTL_PICK_LIST_TYPES_H
#define GAME_OV095_BTL_PICK_LIST_TYPES_H

#include "../types.h"

/* A pick of up to six party slots on one side (see BTL_PICK_InitSlotChoices). */
struct BtlSideSlot;

typedef struct BtlSlotChoices {
    struct BtlSideSlot *sideData;
    u8 pickCount;
    u8 slotState[6];     /* 0 unavailable, 2 selectable */
    u8 mode;
} BtlSlotChoices;

/* The slots picked so far, with the position each one fills. */
typedef struct BtlPickList {
    u8 slots[3];
    u8 positions[3];
    u8 count;
    u8 capacity;
    u8 locked;
} BtlPickList;

#endif
