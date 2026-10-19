/*
 * file:     myitem_savedata.c
 * unit:     yes
 * function: MYITEM_SAVEDATA_GetSize, MYITEM_SAVEDATA_Init, MYITEM_SAVEDATA_CopyPocket, MYITEM_SAVEDATA_GetPocket, MYITEM_SAVEDATA_GetPocketOfItem, MYITEM_SAVEDATA_FindAddSlot, MYITEM_SAVEDATA_FindAddSlotForItem, MYITEM_SAVEDATA_CanAddItem, MYITEM_SAVEDATA_AddItem, MYITEM_SAVEDATA_FindRemoveSlot, MYITEM_SAVEDATA_FindItemSlot, MYITEM_SAVEDATA_RemoveItem, MYITEM_SAVEDATA_HasItem, MYITEM_SAVEDATA_CountUsedSlots, MYITEM_SAVEDATA_CountUsedSlotsInPocket, MYITEM_SAVEDATA_GetItemQuantity, MYITEM_SAVEDATA_SwapSlots, MYITEM_SAVEDATA_MoveLastUsedToFront, MYITEM_SAVEDATA_ClearEmptyQuantities, MYITEM_SAVEDATA_CompactPocket, MYITEM_SAVEDATA_SortPocketById, MYITEM_SAVEDATA_SortPocketByItemOrder, MYITEM_SAVEDATA_CompactAllPockets, MYITEM_SAVEDATA_GetSlot, MYITEM_SAVEDATA_GetMaxStack, MYITEM_SAVEDATA_CreateBagCursor, MYITEM_SAVEDATA_GetFieldPocketCursor, MYITEM_SAVEDATA_GetLastFieldPocket, MYITEM_SAVEDATA_SetFieldPocketCursor, MYITEM_SAVEDATA_SetLastFieldPocket, MYITEM_SAVEDATA_GetBattlePocketCursor, MYITEM_SAVEDATA_GetLastBattleItem, MYITEM_SAVEDATA_GetLastBattleItemPocket, MYITEM_SAVEDATA_SetBattlePocketCursors, MYITEM_SAVEDATA_SetLastBattleItem
 * address:  0x02007CB0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from save_control.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   FILE_UTIL_GetItemParam  0x02020FE4  thumb
 *   FILE_UTIL_IsMachineItem  0x02021288  thumb
 *   FILE_UTIL_GetId  0x0202130C  thumb
 *   _MyItemSavedataFileName  0x020A708C  data
 */

#include "../types.h"

#define NULL ((void *)0)

/* Bag. */
struct BagSlot {
    u16 itemId;
    u16 quantity;
};

#define BAG_POCKET_ITEMS 0

#define BAG_POCKET_MEDICINE 1

#define BAG_POCKET_TMHM 2

#define BAG_POCKET_BERRIES 3

#define BAG_POCKET_KEY_ITEMS 4

#define BAG_ITEMS_COUNT 0x136

#define BAG_KEY_ITEMS_COUNT 0x53

#define BAG_TMHM_COUNT 0x6D

#define BAG_MEDICINE_COUNT 0x30

#define BAG_BERRIES_COUNT 0x40

#define BAG_STACK_MAX 999

/* Remembered bag cursor, 0x2C bytes. */
struct BagCursor {
    s16 fieldPocketPosition[5]; /* 00 */
    s16 fieldPocketScroll[5];   /* 0A */
    u16 lastFieldPocket;      /* 14 */
    u16 pad16;                /* 16: not accessed */
    s16 battlePocketPosition[4]; /* 18 */
    s16 battlePocketScroll[4];   /* 20 */
    u16 lastBattleItem;       /* 28 */
    u16 lastBattleItemPocket; /* 2A */
};

/* The bag block as the pocket arrays lay out in it (0x9C0 bytes). */
struct MyItem {
    struct BagSlot items[BAG_ITEMS_COUNT];         /* 000 */
    struct BagSlot keyItems[BAG_KEY_ITEMS_COUNT];  /* 4D8 */
    struct BagSlot tmhm[BAG_TMHM_COUNT];           /* 624 */
    struct BagSlot medicine[BAG_MEDICINE_COUNT];   /* 7D8 */
    struct BagSlot berries[BAG_BERRIES_COUNT];     /* 898 */
    u8 reserved[0x28];                             /* 998 */
};

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *file, u16 line);

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

extern void MI_CpuFill8(void *dest, u8 value, u32 size);

extern u32 FILE_UTIL_GetItemParam(u32 itemId, u32 param, u32 heapId);

extern u32 FILE_UTIL_IsMachineItem(u32 itemId);

extern u32 FILE_UTIL_GetId(u32 itemId);

extern const char _MyItemSavedataFileName[];

u32 MYITEM_SAVEDATA_GetPocket(struct MyItem *bag, u32 pocket, struct BagSlot **slots, u32 *count);

u32 MYITEM_SAVEDATA_GetPocketOfItem(struct MyItem *bag, u32 itemId, struct BagSlot **slots, u32 *count, u16 heapId);

struct BagSlot *MYITEM_SAVEDATA_FindAddSlot(struct BagSlot *slots, u32 count, u16 itemId, u16 quantity, u16 maxQuantity);

struct BagSlot *MYITEM_SAVEDATA_FindAddSlotForItem(struct MyItem *bag, u16 itemId, u16 quantity, u16 heapId);

struct BagSlot *MYITEM_SAVEDATA_FindRemoveSlot(struct BagSlot *slots, u32 count, u16 itemId, u16 quantity);

struct BagSlot *MYITEM_SAVEDATA_FindItemSlot(struct MyItem *bag, u16 itemId, u16 quantity, u16 heapId);

u32 MYITEM_SAVEDATA_CountUsedSlots(const struct BagSlot *slots, u32 count);

void MYITEM_SAVEDATA_SwapSlots(struct BagSlot *a, struct BagSlot *b);

void MYITEM_SAVEDATA_MoveLastUsedToFront(struct BagSlot *slots, u32 count);

void MYITEM_SAVEDATA_ClearEmptyQuantities(struct BagSlot *slots, u32 count);

void MYITEM_SAVEDATA_CompactPocket(struct BagSlot *slots, u32 count);

void MYITEM_SAVEDATA_SortPocketById(struct BagSlot *slots, u32 count);

void MYITEM_SAVEDATA_SortPocketByItemOrder(struct BagSlot *slots, u32 count);

/*
 * "myitem_savedata.c" starts here: the bag, a 0x9C0 byte block holding five
 * pockets of `{u16 itemId; u16 quantity;}` slots, and the add, take, count
 * and sort routines over them.  The file boundary at the low end is the block
 * file opening idiom: MYITEM_SAVEDATA_GetSize returns 0x9C0 and MYITEM_SAVEDATA_Init fills
 * exactly 0x9C0 bytes with zero, and the function before it belongs to
 * "perapvoice.c".  (The bag cursor allocated by MYITEM_SAVEDATA_CreateBagCursor passes
 * 0x020A708C, "myitem_savedata.c", so the cursor code is in this file too.)
 *
 * The pockets are named by the two switches, MYITEM_SAVEDATA_GetPocket and MYITEM_SAVEDATA_GetSlot,
 * which agree entry for entry:
 *
 *   pocket 0 items      offset 0x000   0x136 slots
 *   pocket 4 key items  offset 0x4D8   0x053 slots
 *   pocket 2 TM/HM      offset 0x624   0x06D slots (stack of 1)
 *   pocket 1 medicine   offset 0x7D8   0x030 slots
 *   pocket 3 berries    offset 0x898   0x040 slots
 *
 * and 0x898 + 0x40 * 4 is 0x998, which is the whole block bar 0x28 trailing
 * bytes.  The case bodies of both switches are emitted in the order 4, 0, 3,
 * 1, 2, and per docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md
 * that order is the order the source wrote the case labels in, so it is kept
 * here.  Neither switch has a `default:` that sets the count, and
 * MYITEM_SAVEDATA_GetSlot reads an uninitialised count on an unknown pocket: the
 * dispatch chain branches past the merged tail rather than into it, which is
 * the reading in docs/idioms/switch-arms-tail-merge.md.
 *
 *  - MYITEM_SAVEDATA_FindAddSlotForItem, MYITEM_SAVEDATA_AddItem and MYITEM_SAVEDATA_RemoveItem pass the address of a local
 *    pointer to MYITEM_SAVEDATA_GetPocketOfItem after having already used that pointer for
 *    something else, and the compiler gives both uses the same stack slot.
 *    Writing them as two variables produces two slots and moves every offset
 *    in the frame, so the source really does reuse the one variable.
 *  - the loop bound in MYITEM_SAVEDATA_CompactPocket and its two siblings is assigned after
 *    the induction variable, not before: `for (i = 0, lim = n - 1; ...)`.
 *    Written the other way round the compiler has no zero in hand at the
 *    point it needs one and materialises it from a literal pool, which costs
 *    four bytes of pool the original does not have.
 *  - MYITEM_SAVEDATA_SortPocketByItemOrder compares two calls to FILE_UTIL_GetId.  The first result is
 *    spilled across the second call and the comparison comes out `cmp r1, r0`
 *    with the spilled operand first, which is the same tell
 *    docs/idioms/cmp-operand-order-names-the-temporary.md records.
 *  - MYITEM_SAVEDATA_FindRemoveSlot returns `&slots[i]` from a second `return` statement rather
 *    than through a merged local.  MYITEM_SAVEDATA_FindAddSlot does use the merged form, and
 *    the difference is visible: the merged form reaches the shared epilogue
 *    with an extra `adds r0, rN, #0`.
 */
u32 MYITEM_SAVEDATA_GetSize(void)
{
    return sizeof(struct MyItem);
}

void MYITEM_SAVEDATA_Init(struct MyItem *bag)
{
    MI_CpuFill8(bag, 0, sizeof(struct MyItem));
}

/* Copy a pocket to (toBuffer) or from the buffer. */
void MYITEM_SAVEDATA_CopyPocket(struct MyItem *bag, void *buffer, u32 pocket, int toBuffer)
{
    struct BagSlot *slots;
    u32 count;

    MYITEM_SAVEDATA_GetPocket(bag, pocket, &slots, &count);
    if (toBuffer) {
        MI_CpuCopy8(slots, buffer, count * sizeof(struct BagSlot));
    } else {
        MI_CpuCopy8(buffer, slots, count * sizeof(struct BagSlot));
    }
}

/* Array and size of a pocket. */
u32 MYITEM_SAVEDATA_GetPocket(struct MyItem *bag, u32 pocket, struct BagSlot **slots, u32 *count)
{
    switch (pocket) {
    case BAG_POCKET_KEY_ITEMS:
        *slots = bag->keyItems;
        *count = BAG_KEY_ITEMS_COUNT;
        break;
    case BAG_POCKET_ITEMS:
        *slots = bag->items;
        *count = BAG_ITEMS_COUNT;
        break;
    case BAG_POCKET_BERRIES:
        *slots = bag->berries;
        *count = BAG_BERRIES_COUNT;
        break;
    case BAG_POCKET_MEDICINE:
        *slots = bag->medicine;
        *count = BAG_MEDICINE_COUNT;
        break;
    case BAG_POCKET_TMHM:
        *slots = bag->tmhm;
        *count = BAG_TMHM_COUNT;
        break;
    default:
        *slots = NULL;
        break;
    }
    return pocket;
}

/* Pocket of an item (item parameter 5), with its array and size; returns the pocket. */
u32 MYITEM_SAVEDATA_GetPocketOfItem(struct MyItem *bag, u32 itemId, struct BagSlot **slots, u32 *count, u16 heapId)
{
    u32 pocket = FILE_UTIL_GetItemParam(itemId, 5, heapId);

    MYITEM_SAVEDATA_GetPocket(bag, pocket, slots, count);
    return pocket;
}

/* Slot to add `quantity` of an item to: its own slot if the total stays within the limit, else the first empty one. */
struct BagSlot *MYITEM_SAVEDATA_FindAddSlot(struct BagSlot *slots, u32 count, u16 itemId, u16 quantity, u16 maxQuantity)
{
    u32 index;
    u32 freeIndex = -1;

    for (index = 0; index < count; index++) {
        if (itemId == slots[index].itemId) {
            struct BagSlot *slot = &slots[index];

            if (quantity + slot->quantity > maxQuantity) {
                slot = NULL;
            }
            return slot;
        }
        if (freeIndex == -1 && slots[index].itemId == 0 && slots[index].quantity == 0) {
            freeIndex = index;
        }
    }
    if (freeIndex == -1) {
        return NULL;
    }
    return &slots[freeIndex];
}

/* Slot that can take the item; TM/HM stack to 1, the other pockets to 999. */
struct BagSlot *MYITEM_SAVEDATA_FindAddSlotForItem(struct MyItem *bag, u16 itemId, u16 quantity, u16 heapId)
{
    struct BagSlot *slots;
    u32 count;

    if (MYITEM_SAVEDATA_GetPocketOfItem(bag, itemId, &slots, &count, heapId) == BAG_POCKET_TMHM) {
        return MYITEM_SAVEDATA_FindAddSlot(slots, count, itemId, quantity, 1);
    }
    return MYITEM_SAVEDATA_FindAddSlot(slots, count, itemId, quantity, BAG_STACK_MAX);
}

u32 MYITEM_SAVEDATA_CanAddItem(struct MyItem *bag, u16 itemId, u16 quantity, u16 heapId)
{
    if (MYITEM_SAVEDATA_FindAddSlotForItem(bag, itemId, quantity, heapId) != NULL) {
        return 1;
    }
    return 0;
}

/* Add items; the pocket is then re-sorted (berries by id, TM/HM by item order) or the new item moved to the front. */
u32 MYITEM_SAVEDATA_AddItem(struct MyItem *bag, u16 itemId, u16 quantity, u16 heapId)
{
    struct BagSlot *slot; /* reused as the pocket array below: one stack slot in the original */
    u32 count;
    struct BagSlot *usedSlots;
    u32 usedCount;
    u16 oldQuantity;
    u32 pocket;

    slot = MYITEM_SAVEDATA_FindAddSlotForItem(bag, itemId, quantity, heapId);
    if (slot == NULL) {
        return 0;
    }
    oldQuantity = slot->quantity;
    slot->itemId = itemId;
    slot->quantity = (u16)(slot->quantity + quantity);
    pocket = MYITEM_SAVEDATA_GetPocketOfItem(bag, itemId, &slot, &count, heapId);
    if (pocket == BAG_POCKET_BERRIES) {
        MYITEM_SAVEDATA_SortPocketById(slot, count);
    } else if (pocket == BAG_POCKET_TMHM) {
        MYITEM_SAVEDATA_SortPocketByItemOrder(slot, count);
    } else if (oldQuantity == 0) {
        MYITEM_SAVEDATA_GetPocket(bag, pocket, &usedSlots, &usedCount);
        usedCount = MYITEM_SAVEDATA_CountUsedSlots(usedSlots, usedCount);
        MYITEM_SAVEDATA_MoveLastUsedToFront(usedSlots, usedCount);
    }
    return 1;
}

/* Slot of an item holding at least `quantity`, else NULL. */
struct BagSlot *MYITEM_SAVEDATA_FindRemoveSlot(struct BagSlot *slots, u32 count, u16 itemId, u16 quantity)
{
    u32 index;

    for (index = 0; index < count; index++) {
        if (itemId == slots[index].itemId) {
            if (slots[index].quantity < quantity) {
                return NULL;
            }
            return &slots[index];
        }
    }
    return NULL;
}

struct BagSlot *MYITEM_SAVEDATA_FindItemSlot(struct MyItem *bag, u16 itemId, u16 quantity, u16 heapId)
{
    struct BagSlot *slots;
    u32 count;

    MYITEM_SAVEDATA_GetPocketOfItem(bag, itemId, &slots, &count, heapId);
    return MYITEM_SAVEDATA_FindRemoveSlot(slots, count, itemId, quantity);
}

/* Remove items and compact the pocket. */
u32 MYITEM_SAVEDATA_RemoveItem(struct MyItem *bag, u16 itemId, u16 quantity, u16 heapId)
{
    struct BagSlot *slot; /* reused as the pocket array below */
    u32 count;

    slot = MYITEM_SAVEDATA_FindItemSlot(bag, itemId, quantity, heapId);
    if (slot == NULL) {
        return 0;
    }
    slot->quantity = (u16)(slot->quantity - quantity);
    if (slot->quantity == 0) {
        slot->itemId = 0;
    }
    MYITEM_SAVEDATA_GetPocketOfItem(bag, itemId, &slot, &count, heapId);
    MYITEM_SAVEDATA_CompactPocket(slot, count);
    return 1;
}

u32 MYITEM_SAVEDATA_HasItem(struct MyItem *bag, u16 itemId, u16 quantity, u16 heapId)
{
    if (MYITEM_SAVEDATA_FindItemSlot(bag, itemId, quantity, heapId) != NULL) {
        return 1;
    }
    return 0;
}

/* Number of slots in use. */
u32 MYITEM_SAVEDATA_CountUsedSlots(const struct BagSlot *slots, u32 count)
{
    u32 used = 0;
    u32 index;

    if (slots != NULL) {
        for (index = 0; index < count; index++) {
            if (slots[index].itemId != 0) {
                used++;
            }
        }
    }
    return used;
}

u32 MYITEM_SAVEDATA_CountUsedSlotsInPocket(struct MyItem *bag, u32 pocket)
{
    struct BagSlot *slots;
    u32 count;

    MYITEM_SAVEDATA_GetPocket(bag, pocket, &slots, &count);
    return MYITEM_SAVEDATA_CountUsedSlots(slots, count);
}

/* Quantity of an item held. */
u32 MYITEM_SAVEDATA_GetItemQuantity(struct MyItem *bag, u16 itemId, u16 heapId)
{
    struct BagSlot *slot = MYITEM_SAVEDATA_FindItemSlot(bag, itemId, 1, heapId);

    if (slot == NULL) {
        return 0;
    }
    return slot->quantity;
}

void MYITEM_SAVEDATA_SwapSlots(struct BagSlot *a, struct BagSlot *b)
{
    struct BagSlot temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

/* Move the last used slot to the front, shifting the slots before it up by one. */
void MYITEM_SAVEDATA_MoveLastUsedToFront(struct BagSlot *slots, u32 count)
{
    struct BagSlot temp;
    int index;

    temp.itemId = 0;
    if (count <= 1) {
        return;
    }
    for (index = (int)count - 1; index >= 0; index--) {
        if (temp.itemId == 0) {
            MI_CpuCopy8(&slots[index], &temp, sizeof(struct BagSlot));
        } else {
            MI_CpuCopy8(&slots[index], &slots[index + 1], sizeof(struct BagSlot));
        }
    }
    MI_CpuCopy8(&temp, slots, sizeof(struct BagSlot));
}

/* Zero the quantity of every empty slot. */
void MYITEM_SAVEDATA_ClearEmptyQuantities(struct BagSlot *slots, u32 count)
{
    u32 index;

    for (index = 0; index < count; index++) {
        if (slots[index].itemId == 0) {
            slots[index].quantity = 0;
        }
    }
}

/* Move empty slots to the end, keeping the order of the others. */
void MYITEM_SAVEDATA_CompactPocket(struct BagSlot *slots, u32 count)
{
    u32 lastIndex;
    u32 i;
    u32 j;

    MYITEM_SAVEDATA_ClearEmptyQuantities(slots, count);
    for (i = 0, lastIndex = count - 1; i < lastIndex; i++) {
        for (j = i + 1; j < count; j++) {
            if (slots[i].quantity == 0) {
                MYITEM_SAVEDATA_SwapSlots(&slots[i], &slots[j]);
            }
        }
    }
}

/* Sort a pocket by item id, empty slots last. */
void MYITEM_SAVEDATA_SortPocketById(struct BagSlot *slots, u32 count)
{
    u32 lastIndex;
    u32 i;
    u32 j;

    MYITEM_SAVEDATA_ClearEmptyQuantities(slots, count);
    for (i = 0, lastIndex = count - 1; i < lastIndex; i++) {
        for (j = i + 1; j < count; j++) {
            if (slots[i].quantity == 0 ||
                (slots[j].quantity != 0 && slots[i].itemId > slots[j].itemId)) {
                MYITEM_SAVEDATA_SwapSlots(&slots[i], &slots[j]);
            }
        }
    }
}

/* Sort a pocket by the item sort key (FILE_UTIL_GetId), empty slots last. */
void MYITEM_SAVEDATA_SortPocketByItemOrder(struct BagSlot *slots, u32 count)
{
    u32 lastIndex;
    u32 i;
    u32 j;

    MYITEM_SAVEDATA_ClearEmptyQuantities(slots, count);
    for (i = 0, lastIndex = count - 1; i < lastIndex; i++) {
        for (j = i + 1; j < count; j++) {
            if (slots[i].quantity == 0 ||
                (slots[j].quantity != 0 &&
                 FILE_UTIL_GetId(slots[i].itemId) > FILE_UTIL_GetId(slots[j].itemId))) {
                MYITEM_SAVEDATA_SwapSlots(&slots[i], &slots[j]);
            }
        }
    }
}

/* Compact every pocket. */
void MYITEM_SAVEDATA_CompactAllPockets(struct MyItem *bag)
{
    struct BagSlot *slots;
    u32 count;

    MYITEM_SAVEDATA_GetPocket(bag, BAG_POCKET_KEY_ITEMS, &slots, &count);
    MYITEM_SAVEDATA_CompactPocket(slots, count);
    MYITEM_SAVEDATA_GetPocket(bag, BAG_POCKET_ITEMS, &slots, &count);
    MYITEM_SAVEDATA_CompactPocket(slots, count);
    MYITEM_SAVEDATA_GetPocket(bag, BAG_POCKET_BERRIES, &slots, &count);
    MYITEM_SAVEDATA_CompactPocket(slots, count);
    MYITEM_SAVEDATA_GetPocket(bag, BAG_POCKET_MEDICINE, &slots, &count);
    MYITEM_SAVEDATA_CompactPocket(slots, count);
    MYITEM_SAVEDATA_GetPocket(bag, BAG_POCKET_TMHM, &slots, &count);
    MYITEM_SAVEDATA_CompactPocket(slots, count);
}

/* Slot `index` of a pocket, NULL past its end. */
struct BagSlot *MYITEM_SAVEDATA_GetSlot(struct MyItem *bag, u32 pocket, u32 index)
{
    u32 count;
    struct BagSlot *slots;

    switch (pocket) {
    case BAG_POCKET_KEY_ITEMS:
        slots = bag->keyItems;
        count = BAG_KEY_ITEMS_COUNT;
        break;
    case BAG_POCKET_ITEMS:
        slots = bag->items;
        count = BAG_ITEMS_COUNT;
        break;
    case BAG_POCKET_BERRIES:
        slots = bag->berries;
        count = BAG_BERRIES_COUNT;
        break;
    case BAG_POCKET_MEDICINE:
        slots = bag->medicine;
        count = BAG_MEDICINE_COUNT;
        break;
    case BAG_POCKET_TMHM:
        slots = bag->tmhm;
        count = BAG_TMHM_COUNT;
        break;
    }
    if (index >= count) {
        return NULL;
    }
    return &slots[index];
}

/* Largest stack of an item: 1 for items that FILE_UTIL_IsMachineItem flags, else 999. */
u32 MYITEM_SAVEDATA_GetMaxStack(u32 itemId)
{
    if (FILE_UTIL_IsMachineItem(itemId) == 1) {
        return 1;
    }
    return BAG_STACK_MAX;
}

/*
 * The bag cursor (0x2C bytes, line 0x342 of "myitem_savedata.c"): the last
 * position and scroll of each field bag pocket and each of the four battle
 * bag pockets, plus the last pocket and the last item used in battle.  Nine
 * of the ten functions carry no label, because only the constructor saves lr.
 *
 * Every one of the four array reads is an `ldrsh` with a register offset,
 * which per docs/idioms/ldrsh-register-offset-is-signedness.md is the only
 * evidence that those elements are signed; the writers use plain `strh` and
 * say nothing.
 *
 * The range stops short of 0x020082DC, a six byte tail call whose pool words
 * are both unattestable (no other branch or pool word in the image names
 * either address); it closes the day anything else names them.
 */
struct BagCursor *MYITEM_SAVEDATA_CreateBagCursor(u32 heapId)
{
    return GFL_HEAP_Alloc(heapId, sizeof(struct BagCursor), 1, _MyItemSavedataFileName, 0x342);
}

void MYITEM_SAVEDATA_GetFieldPocketCursor(struct BagCursor *cursor, int pocket, s16 *scroll, s16 *position)
{
    *scroll = cursor->fieldPocketScroll[pocket];
    *position = cursor->fieldPocketPosition[pocket];
}

u16 MYITEM_SAVEDATA_GetLastFieldPocket(const struct BagCursor *cursor)
{
    return cursor->lastFieldPocket;
}

void MYITEM_SAVEDATA_SetFieldPocketCursor(struct BagCursor *cursor, int pocket, s16 scroll, s16 position)
{
    cursor->fieldPocketScroll[pocket] = scroll;
    cursor->fieldPocketPosition[pocket] = position;
}

void MYITEM_SAVEDATA_SetLastFieldPocket(struct BagCursor *cursor, u16 lastFieldPocket)
{
    cursor->lastFieldPocket = lastFieldPocket;
}

void MYITEM_SAVEDATA_GetBattlePocketCursor(const struct BagCursor *cursor, int pocket, s16 *scroll, s16 *position)
{
    *scroll = cursor->battlePocketScroll[pocket];
    *position = cursor->battlePocketPosition[pocket];
}

u16 MYITEM_SAVEDATA_GetLastBattleItem(const struct BagCursor *cursor)
{
    return cursor->lastBattleItem;
}

u16 MYITEM_SAVEDATA_GetLastBattleItemPocket(const struct BagCursor *cursor)
{
    return cursor->lastBattleItemPocket;
}

void MYITEM_SAVEDATA_SetBattlePocketCursors(struct BagCursor *cursor, const s16 *scrolls, const s16 *positions)
{
    u32 pocket;

    for (pocket = 0; pocket < 4; pocket++) {
        cursor->battlePocketScroll[pocket] = scrolls[pocket];
        cursor->battlePocketPosition[pocket] = positions[pocket];
    }
}

void MYITEM_SAVEDATA_SetLastBattleItem(struct BagCursor *cursor, u16 lastBattleItem, u16 lastBattleItemPocket)
{
    cursor->lastBattleItem = lastBattleItem;
    cursor->lastBattleItemPocket = lastBattleItemPocket;
}
