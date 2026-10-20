#ifndef GAME_ARM9_MYITEM_SAVEDATA_H
#define GAME_ARM9_MYITEM_SAVEDATA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of myitem_savedata.c, prototypes copied from their definitions. */

struct MyItem;
struct BagSlot;
struct BagCursor;

#include "../types.h"

u32 MYITEM_SAVEDATA_GetSize(void);
void MYITEM_SAVEDATA_Init(struct MyItem *bag);
void MYITEM_SAVEDATA_CopyPocket(struct MyItem *bag, void *buffer, u32 pocket, int toBuffer);
u32 MYITEM_SAVEDATA_GetPocket(struct MyItem *bag, u32 pocket, struct BagSlot **slots, u32 *count);
u32 MYITEM_SAVEDATA_GetPocketOfItem(struct MyItem *bag, u32 itemId, struct BagSlot **slots, u32 *count, u16 heapId);
struct BagSlot *MYITEM_SAVEDATA_FindAddSlot(struct BagSlot *slots, u32 count, u16 itemId, u16 quantity, u16 maxQuantity);
struct BagSlot *MYITEM_SAVEDATA_FindAddSlotForItem(struct MyItem *bag, u16 itemId, u16 quantity, u16 heapId);
u32 MYITEM_SAVEDATA_CanAddItem(struct MyItem *bag, u16 itemId, u16 quantity, u16 heapId);
u32 MYITEM_SAVEDATA_AddItem(struct MyItem *bag, u16 itemId, u16 quantity, u16 heapId);
struct BagSlot *MYITEM_SAVEDATA_FindRemoveSlot(struct BagSlot *slots, u32 count, u16 itemId, u16 quantity);
struct BagSlot *MYITEM_SAVEDATA_FindItemSlot(struct MyItem *bag, u16 itemId, u16 quantity, u16 heapId);
u32 MYITEM_SAVEDATA_RemoveItem(struct MyItem *bag, u16 itemId, u16 quantity, u16 heapId);
u32 MYITEM_SAVEDATA_HasItem(struct MyItem *bag, u16 itemId, u16 quantity, u16 heapId);
u32 MYITEM_SAVEDATA_CountUsedSlots(const struct BagSlot *slots, u32 count);
u32 MYITEM_SAVEDATA_CountUsedSlotsInPocket(struct MyItem *bag, u32 pocket);
u32 MYITEM_SAVEDATA_GetItemQuantity(struct MyItem *bag, u16 itemId, u16 heapId);
void MYITEM_SAVEDATA_SwapSlots(struct BagSlot *a, struct BagSlot *b);
void MYITEM_SAVEDATA_MoveLastUsedToFront(struct BagSlot *slots, u32 count);
void MYITEM_SAVEDATA_ClearEmptyQuantities(struct BagSlot *slots, u32 count);
void MYITEM_SAVEDATA_CompactPocket(struct BagSlot *slots, u32 count);
void MYITEM_SAVEDATA_SortPocketById(struct BagSlot *slots, u32 count);
void MYITEM_SAVEDATA_SortPocketByItemOrder(struct BagSlot *slots, u32 count);
void MYITEM_SAVEDATA_CompactAllPockets(struct MyItem *bag);
struct BagSlot *MYITEM_SAVEDATA_GetSlot(struct MyItem *bag, u32 pocket, u32 index);
u32 MYITEM_SAVEDATA_GetMaxStack(u32 itemId);
struct BagCursor *MYITEM_SAVEDATA_CreateBagCursor(u32 heapId);
void MYITEM_SAVEDATA_GetFieldPocketCursor(struct BagCursor *cursor, int pocket, s16 *scroll, s16 *position);
u16 MYITEM_SAVEDATA_GetLastFieldPocket(const struct BagCursor *cursor);
void MYITEM_SAVEDATA_SetFieldPocketCursor(struct BagCursor *cursor, int pocket, s16 scroll, s16 position);
void MYITEM_SAVEDATA_SetLastFieldPocket(struct BagCursor *cursor, u16 lastFieldPocket);
void MYITEM_SAVEDATA_GetBattlePocketCursor(const struct BagCursor *cursor, int pocket, s16 *scroll, s16 *position);
u16 MYITEM_SAVEDATA_GetLastBattleItem(const struct BagCursor *cursor);
u16 MYITEM_SAVEDATA_GetLastBattleItemPocket(const struct BagCursor *cursor);
void MYITEM_SAVEDATA_SetBattlePocketCursors(struct BagCursor *cursor, const s16 *scrolls, const s16 *positions);
void MYITEM_SAVEDATA_SetLastBattleItem(struct BagCursor *cursor, u16 lastBattleItem, u16 lastBattleItemPocket);
/* END mkheaders: generated region */

#endif
