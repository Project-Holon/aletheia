/*
 * file:     daycare.c
 * unit:     yes
 * function: DAYCARE_SetEggReady, DAYCARE_ClearEggReady, DAYCARE_GetSlotMon, DAYCARE_SetSlotMon, DAYCARE_ClearSlot, DAYCARE_GetEggReady, DAYCARE_IsSlotInUse, DAYCARE_GetInUseCount, DAYCARE_GetSlotSteps, DAYCARE_SwapSlots, DAYCARE_AddSteps, DAYCARE_GetSize, DAYCARE_Init, DAYCARE_GetFromSave
 * address:  0x0200BC10
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
 *   MI_CpuFill8          0x02082BCC  arm
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

/* Save block 0x32: the day care, two slots and the egg flag. */
struct DaycareSlot {
    s32 inUse;
    struct PokeParam mon;
    u32 steps;
};

struct DaycareSave {
    struct DaycareSlot slot[2];
    u32 eggReady;
};

extern void MI_CpuFill8(void *dest, u8 value, u32 size);

extern void *func_020071CC(struct SaveControl *save, u32 blockId);

void DAYCARE_SetEggReady(struct DaycareSave *daycare);

void DAYCARE_ClearEggReady(struct DaycareSave *daycare);

struct PokeParam *DAYCARE_GetSlotMon(struct DaycareSave *daycare, s32 slot);

void DAYCARE_SetSlotMon(struct DaycareSave *daycare, s32 slot, const struct PokeParam *mon);

void DAYCARE_ClearSlot(struct DaycareSave *daycare, s32 slot);

u32 DAYCARE_GetEggReady(struct DaycareSave *daycare);

u32 DAYCARE_IsSlotInUse(struct DaycareSave *daycare, u32 slot);

u32 DAYCARE_GetInUseCount(struct DaycareSave *daycare);

u32 DAYCARE_GetSlotSteps(struct DaycareSave *daycare, u32 slot);

void DAYCARE_SwapSlots(struct DaycareSave *daycare, s32 slotA, s32 slotB);

void DAYCARE_AddSteps(struct DaycareSlot *slots, u32 steps);

u32 DAYCARE_GetSize(void);

void DAYCARE_Init(struct DaycareSave *daycare);

struct DaycareSave *DAYCARE_GetFromSave(struct SaveControl *save);

void DAYCARE_SetEggReady(struct DaycareSave *daycare)
{
    if (daycare->eggReady != 1) {
        daycare->eggReady = 1;
    }
}

void DAYCARE_ClearEggReady(struct DaycareSave *daycare)
{
    daycare->eggReady = 0;
}

struct PokeParam *DAYCARE_GetSlotMon(struct DaycareSave *daycare, s32 slot)
{
    if (slot < 0 || slot >= 2 || daycare->slot[slot].inUse != 1) {
        slot = 0;
    }
    return &daycare->slot[slot].mon;
}

void DAYCARE_SetSlotMon(struct DaycareSave *daycare, s32 slot, const struct PokeParam *mon)
{
    if (slot >= 0 && slot < 2 && daycare->slot[slot].inUse != 1) {
        daycare->slot[slot].mon = *mon;
        daycare->slot[slot].inUse = 1;
        daycare->slot[slot].steps = 0;
    }
}

void DAYCARE_ClearSlot(struct DaycareSave *daycare, s32 slot)
{
    if (slot >= 0 && slot < 2 && daycare->slot[slot].inUse == 1) {
        daycare->slot[slot].inUse = 0;
    }
}

u32 DAYCARE_GetEggReady(struct DaycareSave *daycare)
{
    return daycare->eggReady;
}

u32 DAYCARE_IsSlotInUse(struct DaycareSave *daycare, u32 slot)
{
    if (slot >= 2) {
        return 0;
    }
    return daycare->slot[slot].inUse;
}

u32 DAYCARE_GetInUseCount(struct DaycareSave *daycare)
{
    s32 slot;
    u32 count = 0;

    for (slot = 0; slot < 2; slot++) {
        if (daycare->slot[slot].inUse == 1) {
            count++;
        }
    }
    return count;
}

u32 DAYCARE_GetSlotSteps(struct DaycareSave *daycare, u32 slot)
{
    if (slot >= 2) {
        return 0;
    }
    return daycare->slot[slot].steps;
}

void DAYCARE_SwapSlots(struct DaycareSave *daycare, s32 slotA, s32 slotB)
{
    struct DaycareSlot tmp;

    if (slotA >= 0 && slotA < 2 && slotB >= 0 && slotB < 2) {
        tmp = daycare->slot[slotA];
        daycare->slot[slotA] = daycare->slot[slotB];
        daycare->slot[slotB] = tmp;
    }
}

/*
 * Unlabelled arm9 leaf, filed as the relocation witness for ov021 func_021C3378
 * (wave A1, lane 13).
 */
void DAYCARE_AddSteps(struct DaycareSlot *slots, u32 steps)
{
    int i;
    u64 total;

    for (i = 0; i < 2; i++) {
        if (slots[i].inUse == 1) {
            total = (u64)slots[i].steps + steps;
            if (total > 0xFFFFFFFF)
                total = 0xFFFFFFFF;
            slots[i].steps = total;
        }
    }
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 36 bytes, 0x0200BD98..0x0200BDBC, 3 functions, none of which carries a
 * label in the generated listing.
 *
 * The size, constructor and lookup of the save block with id 0x32.  0x1CC is
 * exactly 2 * 0xE4 + 4, which is the two-slot record the accessors of
 * src/matched/unit_0200BBC8.c reach through a slot stride of 0xE4 and a flag
 * word at +0x1C8, so this is that object's header and the range immediately
 * before it is its accessor set.
 *
 * Both of the last two functions are bare tail calls, which is why neither
 * has a prologue and why each spends a literal pool word on its callee: see
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md.  The constructor does
 * nothing but clear the block, so there is no field this file pins.
 */
u32 DAYCARE_GetSize(void)
{
    return sizeof(struct DaycareSave);
}

void DAYCARE_Init(struct DaycareSave *daycare)
{
    MI_CpuFill8(daycare, 0, sizeof(struct DaycareSave));
}

struct DaycareSave *DAYCARE_GetFromSave(struct SaveControl *save)
{
    return func_020071CC(save, 0x32);
}
