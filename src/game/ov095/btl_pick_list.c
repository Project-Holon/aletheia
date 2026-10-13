/*
 * file:     btl_pick_list.c
 * unit:     yes
 * function: BTL_PICK_InitSlotChoices, BTL_PICK_MarkSlotsSelectable, BTL_PICK_SetSlotState, BTL_PICK_InitList, BTL_PICK_Push, BTL_PICK_Pop, BTL_PICK_GetLocked, BTL_PICK_GetCount, BTL_PICK_GetLast, BTL_PICK_GetSlot
 * address:  0x0689CA98
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from unit_0689C868.c, unit_0689C888.c by tools/splitfile.py.
 *
 * symbols:
 */
#include "btl_pokeparam_types.h"

/* A pick of up to six party slots on one side (see BTL_PICK_InitSlotChoices). */
typedef struct BtlSlotChoices {
    int sideData;
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

#define BTL_PICK_SLOT_NONE 6

void BTL_PICK_InitSlotChoices(BtlSlotChoices *choices, int sideData, u8 pickCount, u8 mode);

void BTL_PICK_MarkSlotsSelectable(BtlSlotChoices *choices, u8 slotCount);

void BTL_PICK_SetSlotState(BtlSlotChoices *choices, u8 state, int index);

void BTL_PICK_InitList(BtlPickList *list, const BtlSlotChoices *choices);

void BTL_PICK_Push(BtlPickList *list, u8 position, u8 slot);

void BTL_PICK_Pop(BtlPickList *list);

int BTL_PICK_GetLocked(BtlPickList *list);

int BTL_PICK_GetCount(BtlPickList *list);

int BTL_PICK_GetLast(BtlPickList *list);

int BTL_PICK_GetSlot(BtlPickList *list, u8 index);

void BTL_PICK_InitSlotChoices(BtlSlotChoices *choices, int sideData, u8 pickCount, u8 mode)
{
    unsigned i;
    choices->mode = mode;
    choices->pickCount = pickCount;
    choices->sideData = sideData;
    for (i = 0; i < 6; i++)
        choices->slotState[i] = 0;
}

void BTL_PICK_MarkSlotsSelectable(BtlSlotChoices *choices, u8 slotCount)
{
    u8 i;
    for (i = 0; i < slotCount; i++)
        BTL_PICK_SetSlotState(choices, 2, i);
}

void BTL_PICK_SetSlotState(BtlSlotChoices *choices, u8 state, int index)
{
    choices->slotState[index] = state;
}

void BTL_PICK_InitList(BtlPickList *list, const BtlSlotChoices *choices)
{
    list->count = 0;
    list->capacity = choices->pickCount;
}

void BTL_PICK_Push(BtlPickList *list, u8 position, u8 slot)
{
    if (list->count < list->capacity) {
        list->slots[list->count] = slot;
        list->positions[list->count] = position;
        list->count++;
    }
}

void BTL_PICK_Pop(BtlPickList *list)
{
    if (list->count)
        list->count--;
}

int BTL_PICK_GetLocked(BtlPickList *list)
{
    return list->locked;
}

int BTL_PICK_GetCount(BtlPickList *list)
{
    return list->count;
}

int BTL_PICK_GetLast(BtlPickList *list)
{
    u8 count = list->count;
    if (count)
        return list->slots[count - 1];
    return BTL_PICK_SLOT_NONE;
}

int BTL_PICK_GetSlot(BtlPickList *list, u8 index)
{
    if (index < list->count)
        return list->slots[index];
    return BTL_PICK_SLOT_NONE;
}
