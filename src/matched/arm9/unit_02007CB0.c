/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x02007CB0
 * packet:   pkt_02007B54
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: MYITEM_SAVEDATA_GetSize, MYITEM_SAVEDATA_Init, MYITEM_SAVEDATA_CopyPocket, MYITEM_SAVEDATA_GetPocket,
 *           MYITEM_SAVEDATA_GetPocketOfItem, MYITEM_SAVEDATA_FindAddSlot, MYITEM_SAVEDATA_FindAddSlotForItem, MYITEM_SAVEDATA_CanAddItem,
 *           MYITEM_SAVEDATA_AddItem, MYITEM_SAVEDATA_FindRemoveSlot, MYITEM_SAVEDATA_FindItemSlot, MYITEM_SAVEDATA_RemoveItem,
 *           MYITEM_SAVEDATA_HasItem, MYITEM_SAVEDATA_CountUsedSlots, MYITEM_SAVEDATA_CountUsedSlotsInPocket, MYITEM_SAVEDATA_GetItemQuantity,
 *           MYITEM_SAVEDATA_SwapSlots, MYITEM_SAVEDATA_MoveLastUsedToFront, MYITEM_SAVEDATA_ClearEmptyQuantities, MYITEM_SAVEDATA_CompactPocket,
 *           MYITEM_SAVEDATA_SortPocketById, MYITEM_SAVEDATA_SortPocketByItemOrder, MYITEM_SAVEDATA_CompactAllPockets, MYITEM_SAVEDATA_GetSlot,
 *           MYITEM_SAVEDATA_GetMaxStack
 *
 * symbols:
 *   MI_CpuCopy8    0x02082D44  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   FILE_UTIL_GetItemParam  0x02020FE4  thumb
 *   FILE_UTIL_IsMachineItem  0x02021288  thumb
 *   FILE_UTIL_GetId  0x0202130C  thumb
 *
 * The item bag: a 0x9C0 byte block holding five arrays of `{u16 id; u16
 * qty;}` entries, and the add, take, count and sort routines over them.  The
 * file boundary at the low end is the block file opening idiom: MYITEM_SAVEDATA_GetSize
 * returns 0x9C0 and MYITEM_SAVEDATA_Init fills exactly 0x9C0 bytes with zero, and the
 * function before it belongs to "perapvoice.c".
 *
 * The five arrays are named by the two switches, MYITEM_SAVEDATA_GetPocket and the
 * unlabelled MYITEM_SAVEDATA_GetSlot, which agree entry for entry:
 *
 *   id 0   offset 0x000   0x136 entries
 *   id 4   offset 0x4D8   0x053 entries
 *   id 2   offset 0x624   0x06D entries
 *   id 1   offset 0x7D8   0x030 entries
 *   id 3   offset 0x898   0x040 entries
 *
 * and 0x898 + 0x40 * 4 is 0x998, which is the whole block bar 0x28 trailing
 * bytes.  The case bodies of both switches are emitted in the order 4, 0, 3,
 * 1, 2, and per docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md
 * that order is the order the source wrote the case labels in, so it is kept
 * here.  Neither switch has a `default:` that sets the count, and
 * MYITEM_SAVEDATA_GetSlot reads an uninitialised count on an unknown id: the dispatch
 * chain branches past the merged tail rather than into it, which is the
 * reading in docs/idioms/switch-arms-tail-merge.md.
 *
 * Eleven of the twenty-five functions carry no label, all of them because
 * they save no lr.  MYITEM_SAVEDATA_GetSlot is the largest of them, 96 bytes of switch
 * plus table plus pool sitting between two literal pools in the listing.
 *
 * What the range teaches:
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
 *    docs/idioms/cmp-operand-order-names-the-temporary.md records; here the
 *    spill is forced by the second call rather than by a named local, so the
 *    two calls can be written inline inside the `||`.
 *  - MYITEM_SAVEDATA_FindRemoveSlot returns `&arr[i]` from a second `return` statement rather
 *    than through a merged local.  MYITEM_SAVEDATA_FindAddSlot, ten functions earlier, does
 *    use the merged form, and the difference is visible: the merged form
 *    reaches the shared epilogue with an extra `adds r0, rN, #0`.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define NULL ((void *)0)

struct Item {
    u16 id;
    u16 qty;
};

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void MI_CpuFill8(void *dest, u8 value, u32 size);

extern u32 FILE_UTIL_GetItemParam(void *a, u32 sel, u32 id);
extern u32 FILE_UTIL_IsMachineItem(u32 a);
extern u32 FILE_UTIL_GetId(u32 id);

u32 MYITEM_SAVEDATA_GetPocket(u8 *base, u32 id, void **pp, u32 *pn);
u32 MYITEM_SAVEDATA_GetPocketOfItem(u8 *base, u32 a, void **pp, u32 *pn, u16 d);
struct Item *MYITEM_SAVEDATA_FindAddSlot(struct Item *arr, u32 n, u16 id, u16 qty, u16 max);
struct Item *MYITEM_SAVEDATA_FindAddSlotForItem(u8 *base, u16 id, u16 qty, u16 d);
struct Item *MYITEM_SAVEDATA_FindRemoveSlot(struct Item *arr, u32 n, u16 id, u16 qty);
struct Item *MYITEM_SAVEDATA_FindItemSlot(u8 *base, u16 id, u16 qty, u16 d);
u32 MYITEM_SAVEDATA_CountUsedSlots(const struct Item *arr, u32 n);
void MYITEM_SAVEDATA_SwapSlots(struct Item *a, struct Item *b);
void MYITEM_SAVEDATA_MoveLastUsedToFront(struct Item *arr, u32 n);
void MYITEM_SAVEDATA_ClearEmptyQuantities(struct Item *arr, u32 n);
void MYITEM_SAVEDATA_CompactPocket(struct Item *arr, u32 n);
void MYITEM_SAVEDATA_SortPocketById(struct Item *arr, u32 n);
void MYITEM_SAVEDATA_SortPocketByItemOrder(struct Item *arr, u32 n);

u32 MYITEM_SAVEDATA_GetSize(void)
{
    return 0x9C0;
}

void MYITEM_SAVEDATA_Init(void *p)
{
    MI_CpuFill8(p, 0, 0x9C0);
}

void MYITEM_SAVEDATA_CopyPocket(u8 *base, void *buf, u32 id, int save)
{
    void *p;
    u32 n;

    MYITEM_SAVEDATA_GetPocket(base, id, &p, &n);
    if (save) {
        MI_CpuCopy8(p, buf, n * 4);
    } else {
        MI_CpuCopy8(buf, p, n * 4);
    }
}

u32 MYITEM_SAVEDATA_GetPocket(u8 *base, u32 id, void **pp, u32 *pn)
{
    switch (id) {
    case 4:
        *pp = base + 0x4D8;
        *pn = 0x53;
        break;
    case 0:
        *pp = base;
        *pn = 0x136;
        break;
    case 3:
        *pp = base + 0x898;
        *pn = 0x40;
        break;
    case 1:
        *pp = base + 0x7D8;
        *pn = 0x30;
        break;
    case 2:
        *pp = base + 0x624;
        *pn = 0x6D;
        break;
    default:
        *pp = NULL;
        break;
    }
    return id;
}

u32 MYITEM_SAVEDATA_GetPocketOfItem(u8 *base, u32 a, void **pp, u32 *pn, u16 d)
{
    u32 id = FILE_UTIL_GetItemParam((void *)a, 5, d);

    MYITEM_SAVEDATA_GetPocket(base, id, pp, pn);
    return id;
}

struct Item *MYITEM_SAVEDATA_FindAddSlot(struct Item *arr, u32 n, u16 id, u16 qty, u16 max)
{
    u32 i;
    u32 free = -1;

    for (i = 0; i < n; i++) {
        if (id == arr[i].id) {
            struct Item *e = &arr[i];

            if (qty + e->qty > max) {
                e = NULL;
            }
            return e;
        }
        if (free == -1 && arr[i].id == 0 && arr[i].qty == 0) {
            free = i;
        }
    }
    if (free == -1) {
        return NULL;
    }
    return &arr[free];
}

struct Item *MYITEM_SAVEDATA_FindAddSlotForItem(u8 *base, u16 id, u16 qty, u16 d)
{
    void *p;
    u32 n;

    if (MYITEM_SAVEDATA_GetPocketOfItem(base, id, &p, &n, d) == 2) {
        return MYITEM_SAVEDATA_FindAddSlot(p, n, id, qty, 1);
    }
    return MYITEM_SAVEDATA_FindAddSlot(p, n, id, qty, 999);
}

u32 MYITEM_SAVEDATA_CanAddItem(u8 *base, u16 id, u16 qty, u16 d)
{
    if (MYITEM_SAVEDATA_FindAddSlotForItem(base, id, qty, d) != NULL) {
        return 1;
    }
    return 0;
}

u32 MYITEM_SAVEDATA_AddItem(u8 *base, u16 id, u16 qty, u16 d)
{
    void *p;
    u32 n;
    void *q;
    u32 m;
    u16 old;
    u32 kind;

    p = MYITEM_SAVEDATA_FindAddSlotForItem(base, id, qty, d);
    if (p == NULL) {
        return 0;
    }
    old = ((struct Item *)p)->qty;
    ((struct Item *)p)->id = id;
    ((struct Item *)p)->qty = (u16)(((struct Item *)p)->qty + qty);
    kind = MYITEM_SAVEDATA_GetPocketOfItem(base, id, &p, &n, d);
    if (kind == 3) {
        MYITEM_SAVEDATA_SortPocketById(p, n);
    } else if (kind == 2) {
        MYITEM_SAVEDATA_SortPocketByItemOrder(p, n);
    } else if (old == 0) {
        MYITEM_SAVEDATA_GetPocket(base, kind, &q, &m);
        m = MYITEM_SAVEDATA_CountUsedSlots(q, m);
        MYITEM_SAVEDATA_MoveLastUsedToFront(q, m);
    }
    return 1;
}

struct Item *MYITEM_SAVEDATA_FindRemoveSlot(struct Item *arr, u32 n, u16 id, u16 qty)
{
    u32 i;

    for (i = 0; i < n; i++) {
        if (id == arr[i].id) {
            if (arr[i].qty < qty) {
                return NULL;
            }
            return &arr[i];
        }
    }
    return NULL;
}

struct Item *MYITEM_SAVEDATA_FindItemSlot(u8 *base, u16 id, u16 qty, u16 d)
{
    void *p;
    u32 n;

    MYITEM_SAVEDATA_GetPocketOfItem(base, id, &p, &n, d);
    return MYITEM_SAVEDATA_FindRemoveSlot(p, n, id, qty);
}

u32 MYITEM_SAVEDATA_RemoveItem(u8 *base, u16 id, u16 qty, u16 d)
{
    void *p;
    u32 n;

    p = MYITEM_SAVEDATA_FindItemSlot(base, id, qty, d);
    if (p == NULL) {
        return 0;
    }
    ((struct Item *)p)->qty = (u16)(((struct Item *)p)->qty - qty);
    if (((struct Item *)p)->qty == 0) {
        ((struct Item *)p)->id = 0;
    }
    MYITEM_SAVEDATA_GetPocketOfItem(base, id, &p, &n, d);
    MYITEM_SAVEDATA_CompactPocket(p, n);
    return 1;
}

u32 MYITEM_SAVEDATA_HasItem(u8 *base, u16 id, u16 qty, u16 d)
{
    if (MYITEM_SAVEDATA_FindItemSlot(base, id, qty, d) != NULL) {
        return 1;
    }
    return 0;
}

u32 MYITEM_SAVEDATA_CountUsedSlots(const struct Item *arr, u32 n)
{
    u32 c = 0;
    u32 i;

    if (arr != NULL) {
        for (i = 0; i < n; i++) {
            if (arr[i].id != 0) {
                c++;
            }
        }
    }
    return c;
}

u32 MYITEM_SAVEDATA_CountUsedSlotsInPocket(u8 *base, u32 id)
{
    void *p;
    u32 n;

    MYITEM_SAVEDATA_GetPocket(base, id, &p, &n);
    return MYITEM_SAVEDATA_CountUsedSlots(p, n);
}

u32 MYITEM_SAVEDATA_GetItemQuantity(u8 *base, u16 id, u16 d)
{
    struct Item *e = MYITEM_SAVEDATA_FindItemSlot(base, id, 1, d);

    if (e == NULL) {
        return 0;
    }
    return e->qty;
}

void MYITEM_SAVEDATA_SwapSlots(struct Item *a, struct Item *b)
{
    struct Item t;

    t = *a;
    *a = *b;
    *b = t;
}

void MYITEM_SAVEDATA_MoveLastUsedToFront(struct Item *arr, u32 n)
{
    struct Item t;
    int i;

    t.id = 0;
    if (n <= 1) {
        return;
    }
    for (i = (int)n - 1; i >= 0; i--) {
        if (t.id == 0) {
            MI_CpuCopy8(&arr[i], &t, sizeof(struct Item));
        } else {
            MI_CpuCopy8(&arr[i], &arr[i + 1], sizeof(struct Item));
        }
    }
    MI_CpuCopy8(&t, arr, sizeof(struct Item));
}

void MYITEM_SAVEDATA_ClearEmptyQuantities(struct Item *arr, u32 n)
{
    u32 i;

    for (i = 0; i < n; i++) {
        if (arr[i].id == 0) {
            arr[i].qty = 0;
        }
    }
}

void MYITEM_SAVEDATA_CompactPocket(struct Item *arr, u32 n)
{
    u32 lim;
    u32 i;
    u32 j;

    MYITEM_SAVEDATA_ClearEmptyQuantities(arr, n);
    for (i = 0, lim = n - 1; i < lim; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i].qty == 0) {
                MYITEM_SAVEDATA_SwapSlots(&arr[i], &arr[j]);
            }
        }
    }
}

void MYITEM_SAVEDATA_SortPocketById(struct Item *arr, u32 n)
{
    u32 lim;
    u32 i;
    u32 j;

    MYITEM_SAVEDATA_ClearEmptyQuantities(arr, n);
    for (i = 0, lim = n - 1; i < lim; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i].qty == 0 ||
                (arr[j].qty != 0 && arr[i].id > arr[j].id)) {
                MYITEM_SAVEDATA_SwapSlots(&arr[i], &arr[j]);
            }
        }
    }
}

void MYITEM_SAVEDATA_SortPocketByItemOrder(struct Item *arr, u32 n)
{
    u32 lim;
    u32 i;
    u32 j;

    MYITEM_SAVEDATA_ClearEmptyQuantities(arr, n);
    for (i = 0, lim = n - 1; i < lim; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i].qty == 0 ||
                (arr[j].qty != 0 &&
                 FILE_UTIL_GetId(arr[i].id) > FILE_UTIL_GetId(arr[j].id))) {
                MYITEM_SAVEDATA_SwapSlots(&arr[i], &arr[j]);
            }
        }
    }
}

void MYITEM_SAVEDATA_CompactAllPockets(u8 *base)
{
    void *p;
    u32 n;

    MYITEM_SAVEDATA_GetPocket(base, 4, &p, &n);
    MYITEM_SAVEDATA_CompactPocket(p, n);
    MYITEM_SAVEDATA_GetPocket(base, 0, &p, &n);
    MYITEM_SAVEDATA_CompactPocket(p, n);
    MYITEM_SAVEDATA_GetPocket(base, 3, &p, &n);
    MYITEM_SAVEDATA_CompactPocket(p, n);
    MYITEM_SAVEDATA_GetPocket(base, 1, &p, &n);
    MYITEM_SAVEDATA_CompactPocket(p, n);
    MYITEM_SAVEDATA_GetPocket(base, 2, &p, &n);
    MYITEM_SAVEDATA_CompactPocket(p, n);
}

struct Item *MYITEM_SAVEDATA_GetSlot(u8 *base, u32 id, u32 index)
{
    u32 n;

    switch (id) {
    case 4:
        base += 0x4D8;
        n = 0x53;
        break;
    case 0:
        n = 0x136;
        break;
    case 3:
        base += 0x898;
        n = 0x40;
        break;
    case 1:
        base += 0x7D8;
        n = 0x30;
        break;
    case 2:
        base += 0x624;
        n = 0x6D;
        break;
    }
    if (index >= n) {
        return NULL;
    }
    return (struct Item *)(base + index * 4);
}

u32 MYITEM_SAVEDATA_GetMaxStack(u32 a)
{
    if (FILE_UTIL_IsMachineItem(a) == 1) {
        return 1;
    }
    return 999;
}
