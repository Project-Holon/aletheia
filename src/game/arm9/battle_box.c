/*
 * file:     battle_box.c
 * unit:     yes
 * function: BATTLE_BOX_GetSize, BATTLE_BOX_Init, BATTLE_BOX_GetFromSave, BATTLE_BOX_SetMon, BATTLE_BOX_CreateParty, BATTLE_BOX_StoreParty, BATTLE_BOX_HasMon, BATTLE_BOX_SetLockFlags, BATTLE_BOX_ClearLockFlags, BATTLE_BOX_GetMon, BATTLE_BOX_IsLocked
 * address:  0x0200BA78
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from battle_rec.c by tools/splitfile.py.
 *
 * symbols:
 *   POKEPARTY_GetCount   0x0201AA18  thumb
 *   POKEPARTY_GetMember   0x0201AB28  thumb
 *   func_020307B0   0x020307B0  arm
 *   MI_CpuFill8          0x02082BCC  arm
 *   func_02045B38  0x02045B38  arm
 *   MSGDATA_ReadUnits  0x02045F5C  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   POKE_TOOL_ClearBoxParam  0x02017550  thumb
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb
 *   POKE_TOOL_CreateFromBoxParam  0x0201747C  thumb
 *   POKEPARTY_Create  0x0201A920  thumb
 *   POKEPARTY_InitEx  0x0201A954  thumb
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb
 */
#include "battle_rec_types.h"
typedef unsigned char u8;

typedef unsigned int u32;

typedef signed int s32;
typedef unsigned short u16;

typedef unsigned long long u64;
struct MsgData;

/* A party Pokemon (0xDC bytes) and a boxed Pokemon (0x88 bytes).  Both are
 * declared as words: the copies of them are eight-byte stepped ldm/stm loops. */
struct PokeParam {
    u32 data[0x37];
};

struct BoxMon {
    u32 data[0x22];
};

/* Save block 0x31: the Battle Box, six boxed Pokemon and the box name.
 * BATTLE_BOX_GetMon indexes the group array with a 0x330 stride. */
struct BoxMonGroup {
    struct BoxMon mon[6];
};

struct BattleBoxSave {
    struct BoxMonGroup group;
    u16 boxName[10];
    u8  unusedData[0x14];
    u16 lockFlags;
    u16 padding;
};

extern u32 POKEPARTY_GetCount(struct Party *party);

extern struct PokeParam *POKEPARTY_GetMember(struct Party *party, u32 index);

extern u32 POKE_TOOL_GetBoxValue(struct BoxMon *mon, u32 param, u32 arg);

extern void MI_CpuFill8(void *dest, u8 value, u32 size);

extern void *func_020071CC(struct SaveControl *save, u32 blockId);

extern u32 func_020307B0(void *mem);

extern struct MsgData *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern void MSGDATA_ReadUnits(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);

extern u32 MSGDATA_Delete(struct MsgData *msg);

extern void POKE_TOOL_ClearBoxParam(struct BoxMon *mon);

extern struct Party *POKEPARTY_Create(u32 heap);

extern void POKEPARTY_InitEx(struct Party *party, s32 capacity);

extern u32 POKEPARTY_Add(struct Party *party, const struct PokeParam *mon);

extern struct BoxMon *POKE_TOOL_GetBoxParam(struct PokeParam *mon);

extern struct PokeParam *POKE_TOOL_CreateFromBoxParam(struct BoxMon *mon, u32 heap);

u32 BATTLE_BOX_GetSize(void);

void BATTLE_BOX_Init(struct BattleBoxSave *box);

struct BattleBoxSave *BATTLE_BOX_GetFromSave(struct SaveControl *save);

void BATTLE_BOX_SetMon(struct BoxMonGroup *groups, u32 group, u32 index, const struct BoxMon *src);

struct Party *BATTLE_BOX_CreateParty(struct BoxMonGroup *box, int heap);

void BATTLE_BOX_StoreParty(struct BoxMonGroup *box, struct Party *party);

u32 BATTLE_BOX_HasMon(struct BoxMonGroup *box);

void BATTLE_BOX_SetLockFlags(struct BattleBoxSave *box, u32 flags);

void BATTLE_BOX_ClearLockFlags(struct BattleBoxSave *box, int flags);

struct BoxMon *BATTLE_BOX_GetMon(struct BoxMonGroup *groups, u32 group, u32 index);

u32 BATTLE_BOX_IsLocked(struct BattleBoxSave *box, u32 flags);

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 80 bytes, 0x0200BA78..0x0200BAC8, 2 functions, one of which carries a
 * label in the generated listing.
 *
 * The size getter and the constructor of a 0x35C-byte record: six 0x88-byte
 * entries, then 0x14 bytes at +0x330 that a resource read fills.  The two
 * agree, which is what pins the entry size: 6 * 0x88 is 0x330.
 *
 * The entry is declared as an array of words rather than of bytes, because
 * BATTLE_BOX_SetMon in src/matched/unit_0200BAD4.c copies one with an eight-byte
 * stepped `ldm`/`stm` loop; a one-aligned declaration gives a byte loop
 * instead.  See docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md.
 *
 * The range stops at 0x0200BAC8 because of BATTLE_BOX_GetFromSave, an eight-byte tail
 * call whose pool word names 0x020271CC and which nothing else in the image
 * branches to or holds a pointer to, so the `label` and `literal` classes are
 * both empty and no cut helps.  It is now matched on its own, as are the
 * other two: src/matched/arm9/BATTLE_BOX_GetFromSave.c, BATTLE_REC_LoadToolOverlay.c and
 * BATTLE_REC_UnloadToolOverlay.c. *
 */
u32 BATTLE_BOX_GetSize(void)
{
    return sizeof(struct BattleBoxSave);
}

void BATTLE_BOX_Init(struct BattleBoxSave *box)
{
    u32 i;
    struct MsgData *msg;

    MI_CpuFill8(box, 0, sizeof(struct BattleBoxSave));
    for (i = 0; i < 6; i++) {
        POKE_TOOL_ClearBoxParam(&box->group.mon[i]);
    }
    msg = func_02045B38(0, 2, 9, 1);
    if (msg != 0) {
        MSGDATA_ReadUnits(msg, 6, box->boxName, sizeof(box->boxName));
        MSGDATA_Delete(msg);
    }
}

/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 */
struct BattleBoxSave *BATTLE_BOX_GetFromSave(struct SaveControl *save)
{
    return func_020071CC(save, 0x31);
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 30 bytes, 0x0200BAD4..0x0200BAF4, one function, which carries no label in
 * the generated listing.
 *
 * One 0x88-byte entry assigned into a two-dimensional array: the outer stride
 * is 0x330 and the inner 0x88, and the copy is an inline counted `ldm`/`stm`
 * loop of 17 iterations, which is 0x88 divided by eight.  The eight-byte step
 * is what says the entry is word aligned; declared as a byte array the same
 * assignment becomes a `ldrb`/`strb` loop of 0x88 iterations.  See
 * docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md.
 *
 * It is a range of its own because the function on either side of it is a
 * near miss: BATTLE_BOX_GetFromSave before it, which has no witness for 0x020271CC,
 * and func_0200BAF4 after it, which is fifteen bytes of register numbering.
 * Its only caller, BATTLE_BOX_StoreParty, is therefore outside this range and is what
 * attests it. *
 */
void BATTLE_BOX_SetMon(struct BoxMonGroup *groups, u32 group, u32 index, const struct BoxMon *src)
{
    groups[group].mon[index] = *src;
}

/*
 * Build a party from the Battle Box members, up to the first empty slot.
 * The temporary-heap value (heap & 0x7fff) | 0x8000 is computed inside the
 * loop, after the existence test is bound to its own local; hoisted above
 * the loop it swaps r6 and r7 across the body.  One local holds the boxed
 * Pokemon and then the party Pokemon made from it, as in the original.
 *
 * `i` is u32, not int: the loop bound at +0x0058 is `blo`, not `blt`.
 * The failing test `break`s out of the loop (beq to the epilogue at
 * +0x005A), it does not `continue`.
 */
struct Party *BATTLE_BOX_CreateParty(struct BoxMonGroup *box, int heap)
{
    struct Party *party;
    u32 i;

    party = POKEPARTY_Create(heap);
    POKEPARTY_InitEx(party, 6);
    for (i = 0; i < 6; i++) {
        void *mon = BATTLE_BOX_GetMon(box, 0, i);
        int exists = POKE_TOOL_GetBoxValue(mon, 0xa9, 0);
        int tempHeap = (heap & 0x7fff) | 0x8000;

        if (exists == 0) {
            break;
        }
        mon = POKE_TOOL_CreateFromBoxParam(mon, (u16)tempHeap);
        POKEPARTY_Add(party, mon);
        func_020307B0(mon);
    }
    return party;
}

/*
 * Clear the six Battle Box slots, then copy each party member in.  The bound
 * of the second loop is a call: POKEPARTY_GetCount(party) is re-invoked at the bottom of
 * every iteration and its result compared against the counter (`cmp r5, r0`
 * right after the `bl`), and the entry test is the peeled copy of that same
 * call, which is exactly how mwcc lowers `for (i = 0; i < f(party); i++)`.
 */
void BATTLE_BOX_StoreParty(struct BoxMonGroup *box, struct Party *party)
{
    u32 i;
    u32 group = 0;

    for (i = 0; i < 6; i++)
        POKE_TOOL_ClearBoxParam(&box->mon[i]);

    for (i = 0; i < (u32)POKEPARTY_GetCount(party); i++)
        BATTLE_BOX_SetMon(box, group, i, POKE_TOOL_GetBoxParam(POKEPARTY_GetMember(party, i)));
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 30 bytes, 0x0200BBA8..0x0200BBC8, one function, which carries a label in
 * the generated listing.
 *
 * Whether entry zero of the record is present.  The result is a local
 * initialised to 0 and set to 1 inside the `if`, not a `return 1` /
 * `return 0` pair: there is one epilogue and the arm is a single `movs`.
 *
 * BATTLE_BOX_GetMon, which it calls, is the first function of
 * src/matched/unit_0200BBC8.c; the other caller of that address is
 * func_0200BAF4 at 0x0200BB1E, and that call is what attests it here.
 *
 * func_0200BAF4 itself is a near miss.  Its 100 bytes reproduce in size and
 * in every instruction, and fifteen bytes differ, all of them register
 * numbers: the original keeps the id parameter in r5 and the loop counter in
 * r4, where this source coalesces the two into r4 because the counter is born
 * after the id dies.  Twenty shapes were tried, five declaration orders for
 * the three locals crossed with two statement orders, plus four forms that
 * give the counter a live range reaching back past the id's last use; the
 * best is fifteen and the ranking is flat between fifteen and twenty-eight. *
 */
u32 BATTLE_BOX_HasMon(struct BoxMonGroup *box)
{
    u32 result = 0;

    if (POKE_TOOL_GetBoxValue(BATTLE_BOX_GetMon(box, 0, 0), 0xA9, 0) != 0) {
        result = 1;
    }
    return result;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           DAYCARE_SetEggReady, DAYCARE_ClearEggReady, DAYCARE_GetSlotMon, DAYCARE_SetSlotMon,
 *           DAYCARE_ClearSlot, DAYCARE_GetEggReady, DAYCARE_IsSlotInUse, DAYCARE_GetInUseCount,
 *           DAYCARE_GetSlotSteps, DAYCARE_SwapSlots
 *
 * 384 bytes, 0x0200BBC8..0x0200BD48, 14 functions, none of which carries a
 * label in the generated listing: not one of them saves lr, so the whole
 * range arrives as a run of `.word`s between two literal pools.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * The object is two 0xE4-byte slots at +0x000, each an in-use word, a
 * 0xDC-byte payload and a word behind it, plus a flag word at +0x1C8.  That
 * is 0x1CC bytes and it is exactly what DAYCARE_GetSize in
 * src/matched/unit_0200BD98.c returns as the size of the save block with id
 * 0x32, so the record is pinned from both ends.  The halfword of bits at
 * +0x358 that BATTLE_BOX_SetLockFlags, BATTLE_BOX_ClearLockFlags and BATTLE_BOX_IsLocked reach is past
 * that end: it is the lock flags of the 0x35C-byte Battle Box record.  The
 * three sizes are pinned by the three
 * `ldm`/`stm` copies and agree: 0x1B pairs plus a word is the 0xDC payload
 * DAYCARE_SetSlotMon stores, and 0x1C pairs plus a word is the whole 0xE4 slot
 * DAYCARE_SwapSlots swaps through a stack temporary.  See
 * docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md; both copies are
 * eight-byte stepped, which is what says the payload is word aligned rather
 * than a byte array.
 *
 * BATTLE_BOX_GetMon belongs to a different object: it is pure address arithmetic
 * over a 0x330-byte record holding six 0x88-byte entries, and it is here only
 * because the file it was written in also holds the accessors above.  Its one
 * caller in this region, BATTLE_BOX_HasMon, is outside this range.
 *
 * Every guard in the file that ends in a shared exit is written as one
 * conjunction rather than as a run of early returns, which is what gives the
 * single epilogue the original has; see
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md.
 */
void BATTLE_BOX_SetLockFlags(struct BattleBoxSave *box, u32 flags)
{
    box->lockFlags |= (u16)flags;
}

void BATTLE_BOX_ClearLockFlags(struct BattleBoxSave *box, int flags)
{
    box->lockFlags &= ~flags;
}

struct BoxMon *BATTLE_BOX_GetMon(struct BoxMonGroup *groups, u32 group, u32 index)
{
    return &groups[group].mon[index];
}

u32 BATTLE_BOX_IsLocked(struct BattleBoxSave *box, u32 flags)
{
    if ((box->lockFlags & flags) != 0) {
        return 1;
    }
    return 0;
}
