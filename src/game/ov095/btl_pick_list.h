#ifndef GAME_OV095_BTL_PICK_LIST_H
#define GAME_OV095_BTL_PICK_LIST_H




/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btl_pick_list.c, prototypes copied from their definitions. */

struct BtlSideSlot;

#include "../ov095/btl_pick_list_types.h"
#include "../types.h"

void BTL_PICK_InitSlotChoices(BtlSlotChoices *choices, struct BtlSideSlot *sideData, u8 pickCount, u8 mode);
void BTL_PICK_MarkSlotsSelectable(BtlSlotChoices *choices, u8 slotCount);
void BTL_PICK_SetSlotState(BtlSlotChoices *choices, u8 state, int index);
void BTL_PICK_InitList(BtlPickList *list, const BtlSlotChoices *choices);
void BTL_PICK_Push(BtlPickList *list, u8 position, u8 slot);
void BTL_PICK_Pop(BtlPickList *list);
int BTL_PICK_GetLocked(BtlPickList *list);
int BTL_PICK_GetCount(BtlPickList *list);
int BTL_PICK_GetLast(BtlPickList *list);
int BTL_PICK_GetSlot(BtlPickList *list, u8 index);
/* END mkheaders: generated region */

#endif
