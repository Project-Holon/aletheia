/*
 * file:     recent_id_list_savedata.c
 * unit:     yes
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * address:  0x0200C3F4
 * packet:   pkt_0200C0E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: RECENT_ID_LIST_SAVEDATA_GetBlock, RECENT_ID_LIST_SAVEDATA_GetBlockFromSys,
 *           RECENT_ID_LIST_SAVEDATA_GetBlockSize, RECENT_ID_LIST_SAVEDATA_InitBlock,
 *           RECENT_ID_LIST_SAVEDATA_SetId, RECENT_ID_LIST_SAVEDATA_ContainsId,
 *           RECENT_ID_LIST_SAVEDATA_GetIdAt, RECENT_ID_LIST_SAVEDATA_CountIds,
 *           RECENT_ID_LIST_SAVEDATA_InsertId, RECENT_ID_LIST_SAVEDATA_CompactIds,
 *           RECENT_ID_LIST_SAVEDATA_GetSaveAreaSize, RECENT_ID_LIST_SAVEDATA_InitArea
 *
 * 300 bytes, 0x0200C3F4..0x0200C520, 12 functions, six of which carry no
 * label in the generated listing.
 *
 * The object is the save block with id 0x36 and it is 26 bytes of nothing but
 * a list: 25 slots holding small ids, with 25 itself as the empty marker, and
 * one slot past the end that RECENT_ID_LIST_SAVEDATA_SetId writes into when
 * the list is full.  The size getter, the constructor's MI_CpuFill8(list, 25,
 * 26) and the three loop bounds all agree, which is what pins the length.
 *
 * RECENT_ID_LIST_SAVEDATA_InsertId is a most-recently-used insert: it removes
 * the id if it is already listed, then either takes the first free slot (when
 * the caller passes 0xFF) or shifts the tail down by one and drops the id in
 * at the requested position.  Three things in it are worth recording.
 *
 *  - the index of the first loop is `s16` and the index of the second is
 *    `u8`, which is not a guess: one increments through `lsls #0x10 / asrs
 *    #0x10` and the other through `lsls #0x18 / lsrs #0x18`, and the widths
 *    are the types.
 *  - the store `ids[position] = id` and the `return position` exist once
 *    between them all, reached by a branch from each arm.  Writing the early
 *    exit as `ids[position] = id; goto out;` inside the loop is what produces
 *    that: the compiler cross-jumps the two identical blocks and leaves the
 *    loop with `bne` over a `b` to the shared copy.  Written as `return
 *    position;` the block is emitted twice and the function is four bytes
 *    long; written as a bare `goto store;` to a label in front of the store
 *    it is two bytes short, because a single conditional branch then reaches
 *    the target.
 *  - RECENT_ID_LIST_SAVEDATA_CompactIds clamps `i + 1` into 1..24 before
 *    using it as the swap partner, so slot 0 and slot 24 are both their own
 *    neighbour at the ends.  The clamp is two compares against hoisted
 *    constants, which is what an `if`/`else if` pair gives and a `min`/`max`
 *    pair does not.
 *
 * symbols:
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 */

#include "../types.h"

extern void  MI_CpuFill8(void *dest, u8 value, u32 size);
struct SaveControl;
extern void *SAVE_CONTROL_GetBlock(struct SaveControl *saveControl, u32 id);

/*
 * The save block with id 0x36.  ids[0..24] hold small ids and the value 25
 * marks an empty slot; ids[25] is the extra slot the full-list case writes.
 */
struct RecentIdList {
    u8 ids[26];
};

void RECENT_ID_LIST_SAVEDATA_CompactIds(u8 *ids);

u32 RECENT_ID_LIST_SAVEDATA_GetBlockSize(void)
{
    return sizeof(struct RecentIdList);
}

void RECENT_ID_LIST_SAVEDATA_InitBlock(struct RecentIdList *list)
{
    MI_CpuFill8(list, 25, sizeof(struct RecentIdList));
}

void *RECENT_ID_LIST_SAVEDATA_GetBlock(void *sys);

void *RECENT_ID_LIST_SAVEDATA_GetBlockFromSys(void *sys)
{
    return RECENT_ID_LIST_SAVEDATA_GetBlock(sys);
}

void *RECENT_ID_LIST_SAVEDATA_GetBlock(void *sys)
{
    return SAVE_CONTROL_GetBlock(sys, 0x36);
}

void RECENT_ID_LIST_SAVEDATA_SetId(u8 *ids, u32 id, u32 enabled)
{
    s32 i;

    if (enabled) {
        for (i = 0; i < 25; i++) {
            if (id == ids[i]) {
                return;
            }
            if (ids[i] == 25) {
                break;
            }
        }
        ids[i] = id;
    } else {
        for (i = 0; i < 25; i++) {
            if (id == ids[i]) {
                ids[i] = 25;
            }
        }
    }
    RECENT_ID_LIST_SAVEDATA_CompactIds(ids);
}

u32 RECENT_ID_LIST_SAVEDATA_ContainsId(const u8 *ids, u8 id)
{
    s32 i;

    for (i = 0; i < 25; i++) {
        if (id == ids[i]) {
            return 1;
        }
    }
    return 0;
}

u8 RECENT_ID_LIST_SAVEDATA_GetIdAt(const u8 *ids, u32 index)
{
    return ids[index];
}

u16 RECENT_ID_LIST_SAVEDATA_CountIds(const u8 *ids)
{
    s32 i;
    s32 count = 0;

    for (i = 0; i < 25; i++) {
        if (ids[i] != 25) {
            count++;
        }
    }
    return count;
}

u8 RECENT_ID_LIST_SAVEDATA_InsertId(u8 *ids, int id, u8 position)
{
    s16 previousPos;
    s16 i;

    for (previousPos = 0; previousPos < 25; previousPos++) {
        if (id == ids[previousPos]) {
            break;
        }
    }
    RECENT_ID_LIST_SAVEDATA_SetId(ids, id, 0);
    if (position == 0xFF) {
        for (position = 0; position < 25; position++) {
            if (ids[position] == 25) {
                ids[position] = id;
                goto out;
            }
        }
        goto out;
    }
    if (previousPos < position) {
        position--;
    }
    for (i = 24; i >= position; i--) {
        ids[i] = ids[i - 1];
    }
    ids[position] = id;
out:
    return position;
}

void RECENT_ID_LIST_SAVEDATA_CompactIds(u8 *ids)
{
    u16 i;
    u16 neighbor;
    s32 neighborIndex;
    u8 value;

    for (i = 0; i < 25; i++) {
        neighborIndex = i + 1;
        if (neighborIndex > 24) {
            neighborIndex = 24;
        } else if (neighborIndex < 1) {
            neighborIndex = 1;
        }
        neighbor = neighborIndex;
        value = ids[i];
        if (value == 25) {
            ids[i] = ids[neighbor];
            ids[neighbor] = value;
        }
    }
}

int RECENT_ID_LIST_SAVEDATA_GetSaveAreaSize(void);

int RECENT_ID_LIST_SAVEDATA_GetSaveAreaSize(void)
{
    return 0x1FC00;
}

void RECENT_ID_LIST_SAVEDATA_InitArea(void);

void RECENT_ID_LIST_SAVEDATA_InitArea(void)
{
}
