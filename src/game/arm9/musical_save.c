/*
 * file:     musical_save.c
 * unit:     yes
 * function: MUSICAL_SAVE_GetSize, MUSICAL_SAVE_Init, MUSICAL_SAVE_GetFromSave, MUSICAL_SAVE_InitOutfits, MUSICAL_SAVE_GetOutfits, MUSICAL_SAVE_IsShowActive, MUSICAL_SAVE_NoOp, MUSICAL_SAVE_IsPropOwned, MUSICAL_SAVE_IsPropNew, MUSICAL_SAVE_AddProp, MUSICAL_SAVE_ClearNewProps, MUSICAL_SAVE_CountOwnedProps, MUSICAL_SAVE_HasAllProps, MUSICAL_SAVE_GetProgram, MUSICAL_SAVE_GetShowCount, MUSICAL_SAVE_IncrementShowCount, MUSICAL_SAVE_GetTopRankCount, MUSICAL_SAVE_IncrementTopRankCount, MUSICAL_SAVE_GetEquippedProp, MUSICAL_SAVE_SetEquippedProp, MUSICAL_SAVE_GetSelectedProgram, MUSICAL_SAVE_SetSelectedProgram, MUSICAL_SAVE_GetScriptSetting, MUSICAL_SAVE_SetScriptSetting, MUSICAL_SAVE_GetHasDistData, MUSICAL_SAVE_SetHasDistData, MUSICAL_SAVE_GetStageData, MUSICAL_SAVE_AddFanPoints, MUSICAL_SAVE_GetFanPoints, MUSICAL_SAVE_GetFittingSetting, MUSICAL_SAVE_SetFittingSetting
 * address:  0x0200A53C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from mystery_data.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_020071CC  0x020071CC  thumb
 */
#include "wifilist_tail_shared_types.h"
#include "musical_save_shared_types.h"

/*
 * Save block 0x2A, the musical save (0x2A4 bytes): a 100-entry prop
 * collection held as two bitmaps (owned, new), outfit and program tables,
 * and counters.
 */
struct MusicalOutfit {
    u8 pokeSlot;                          /* 10: none */
    u8 props[5];
};

struct MusicalProgram {
    u8 state;                             /* 4: initial */
    u8 data[3];
};

struct MusicalSave {
    u32 showcaseMonsNo : 16;
    u32 shotState : 5;
    u32 showcaseFlags : 11;
    u8  showcase[0x1AC];
    struct MusicalOutfit outfits[8];
    struct MusicalProgram programs[10];
    u8  stageData[0x4A];
    u16 showCount;
    u16 topRankCount;
    u16 fanPoints;
    u8  ownedProps[0x20];
    u8  newProps[0x20];
    u8  equippedProps[4];
    u8  selectedProgram;
    u8  scriptSetting;
    u8  hasDistData;
    u8  fittingSetting;
    u8  reserved[4];
};

extern void MI_CpuFill8(void *dest, u8 data, u32 size);

extern void *func_020071CC(struct SaveControl *save, u32 blockId);

u32 MUSICAL_SAVE_GetSize(void);

void MUSICAL_SAVE_Init(struct MusicalSave *musical);

struct MusicalSave *MUSICAL_SAVE_GetFromSave(struct SaveControl *save);

void MUSICAL_SAVE_InitOutfits(struct MusicalSave *musical);

struct MusicalOutfit *MUSICAL_SAVE_GetOutfits(struct MusicalSave *musical);

u32 MUSICAL_SAVE_IsShowActive(struct MusicalSave *musical);

void MUSICAL_SAVE_NoOp(void);

u32 MUSICAL_SAVE_IsPropOwned(struct MusicalSave *musical, u8 prop);

u32 MUSICAL_SAVE_IsPropNew(struct MusicalSave *musical, u8 prop);

void MUSICAL_SAVE_AddProp(struct MusicalSave *musical, u32 prop);

void MUSICAL_SAVE_ClearNewProps(struct MusicalSave *musical);

u32 MUSICAL_SAVE_CountOwnedProps(struct MusicalSave *musical);

u32 MUSICAL_SAVE_HasAllProps(struct MusicalSave *musical);

struct MusicalProgram *MUSICAL_SAVE_GetProgram(struct MusicalSave *musical, u32 index);

u16 MUSICAL_SAVE_GetShowCount(struct MusicalSave *musical);

void MUSICAL_SAVE_IncrementShowCount(struct MusicalSave *musical);

u16 MUSICAL_SAVE_GetTopRankCount(struct MusicalSave *musical);

void MUSICAL_SAVE_IncrementTopRankCount(struct MusicalSave *musical);

u8 MUSICAL_SAVE_GetEquippedProp(struct MusicalSave *musical, u32 index);

void MUSICAL_SAVE_SetEquippedProp(struct MusicalSave *musical, u32 index, u8 prop);

u8 MUSICAL_SAVE_GetSelectedProgram(struct MusicalSave *musical);

void MUSICAL_SAVE_SetSelectedProgram(struct MusicalSave *musical, u8 value);

u8 MUSICAL_SAVE_GetScriptSetting(struct MusicalSave *musical);

void MUSICAL_SAVE_SetScriptSetting(struct MusicalSave *musical, u8 value);

u8 MUSICAL_SAVE_GetHasDistData(struct MusicalSave *musical);

void MUSICAL_SAVE_SetHasDistData(struct MusicalSave *musical, u8 value);

u8 *MUSICAL_SAVE_GetStageData(struct MusicalSave *musical);

void MUSICAL_SAVE_AddFanPoints(struct MusicalSave *musical, s32 delta);

u16 MUSICAL_SAVE_GetFanPoints(struct MusicalSave *musical);

u32 MUSICAL_SAVE_GetFittingSetting(struct MusicalSave *musical);

void MUSICAL_SAVE_SetFittingSetting(struct MusicalSave *musical, u8 value);

u32 MUSICAL_SAVE_GetSize(void)
{
    return sizeof(struct MusicalSave);
}

void MUSICAL_SAVE_Init(struct MusicalSave *musical)
{
    u8 i;

    MI_CpuFill8(musical, 0, sizeof(struct MusicalSave));
    MUSICAL_SAVE_InitOutfits(musical);
    for (i = 0; i < 10; i++) {
        musical->programs[i].state = 4;
    }
    musical->scriptSetting = 0;
    musical->hasDistData = 0;
    MUSICAL_SAVE_AddProp(musical, 0x30);
    MUSICAL_SAVE_AddProp(musical, 0x46);
    MUSICAL_SAVE_AddProp(musical, 0x53);
    MUSICAL_SAVE_AddProp(musical, 0x4B);
    MUSICAL_SAVE_AddProp(musical, 0x00);
    MUSICAL_SAVE_AddProp(musical, 0x01);
    MUSICAL_SAVE_AddProp(musical, 0x0A);
    MUSICAL_SAVE_AddProp(musical, 0x1C);
    MUSICAL_SAVE_AddProp(musical, 0x08);
    MUSICAL_SAVE_AddProp(musical, 0x3B);
    MUSICAL_SAVE_AddProp(musical, 0x3F);
    MUSICAL_SAVE_AddProp(musical, 0x42);
    MUSICAL_SAVE_AddProp(musical, 0x10);
    MUSICAL_SAVE_AddProp(musical, 0x59);
    MUSICAL_SAVE_AddProp(musical, 0x4C);
}

struct MusicalSave *MUSICAL_SAVE_GetFromSave(struct SaveControl *save)
{
    return func_020071CC(save, 0x2A);
}

void MUSICAL_SAVE_InitOutfits(struct MusicalSave *musical)
{
    u8 i;

    for (i = 0; i < 8; i++) {
        musical->outfits[i].pokeSlot = 10;
    }
}

struct MusicalOutfit *MUSICAL_SAVE_GetOutfits(struct MusicalSave *musical)
{
    return musical->outfits;
}

u32 MUSICAL_SAVE_IsShowActive(struct MusicalSave *musical)
{
    return musical->shotState != 0;
}

void MUSICAL_SAVE_NoOp(void)
{
}

u32 MUSICAL_SAVE_IsPropOwned(struct MusicalSave *musical, u8 prop)
{
    if (prop < 100) {
        u8 shift = (s32)prop % 8;
        u8 byte  = prop >> 3;
        if ((musical->ownedProps[byte] & (1 << shift)) > 0) {
            return 1;
        }
    }
    return 0;
}

u32 MUSICAL_SAVE_IsPropNew(struct MusicalSave *musical, u8 prop)
{
    if (prop < 100) {
        u8 shift = (s32)prop % 8;
        u8 byte  = prop >> 3;
        if ((musical->newProps[byte] & (1 << shift)) > 0) {
            return 1;
        }
    }
    return 0;
}

void MUSICAL_SAVE_AddProp(struct MusicalSave *musical, u32 prop)
{
    u8 shift, byte;

    if (prop >= 100) {
        return;
    }
    shift = (s32)prop % 8;
    byte  = prop >> 3;
    musical->ownedProps[byte] |= (u8)(1 << shift);
    musical->newProps[byte] |= (u8)(1 << shift);
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           MUSICAL_SAVE_GetShowCount, MUSICAL_SAVE_IncrementShowCount, MUSICAL_SAVE_GetTopRankCount, MUSICAL_SAVE_IncrementTopRankCount,
 *           MUSICAL_SAVE_GetEquippedProp, MUSICAL_SAVE_SetEquippedProp, MUSICAL_SAVE_GetSelectedProgram, MUSICAL_SAVE_SetSelectedProgram,
 *           MUSICAL_SAVE_GetScriptSetting, MUSICAL_SAVE_SetScriptSetting, MUSICAL_SAVE_GetHasDistData, MUSICAL_SAVE_SetHasDistData,
 *           MUSICAL_SAVE_AddFanPoints, MUSICAL_SAVE_GetStageData, MUSICAL_SAVE_GetFanPoints, MUSICAL_SAVE_GetFittingSetting,
 *           MUSICAL_SAVE_SetFittingSetting
 *
 * 328 bytes, 0x0200A6F8..0x0200A840, 21 functions, and the direct
 * continuation of src/matched/unit_0200A3FC.c: every one of them reaches the
 * same 0x2A4-byte `struct MusicalSave`, and the accessors here are what pin the last
 * quarter of its layout (three counters at 0x252, 0x254 and 0x256, a
 * four-entry byte array at 0x298 and four separate bytes at 0x29C..0x29F).
 *
 * Fourteen of the twenty-one carry no label in the generated listing: none of
 * them saves lr, so disasm.py's prologue sweep does not fire and the listing
 * prints their bytes as `.word` data.  They are the accessor half of the file
 * and were read out of those words, the same way the sixteen accessors of
 * unit_0200852C.c were.
 *
 * 0x0200A6F8 is the one docs/MATCHING.md already named under "The two
 * missing labels": the 28-byte loop that clears the second of the two
 * bitmaps MUSICAL_SAVE_AddProp sets a bit in.  It is in
 * layout/function_starts.txt, attested by the bl from ov133 at 0x021B62A2,
 * which is why it has a label here and its fourteen neighbours do not.
 *
 * 0x0200A714 counts how many of the 256 bit positions are set in the first
 * bitmap by calling MUSICAL_SAVE_IsPropOwned on every one of them, and 0x0200A73C asks
 * whether that count has reached 100, which is the same bound the three
 * bitmap routines in unit_0200A3FC.c check their index against.  So 100 is
 * the population of whatever the bitmap enumerates and this pair is its
 * "have you seen all of them" test.
 *
 * Two details pin source shapes here, both of them one-line fixes that look
 * like body diffs:
 *
 *  - in 0x0200A714 the accumulator has to be declared before the loop
 *    counter.  Declared the other way round the two locals swap registers,
 *    which is six differing bytes spread over the whole function and nothing
 *    else.  Same finding as docs/idioms/local-declaration-order-is-stack-
 *    order.md, one level up: the rule holds for register-allocated locals and
 *    not only for stack slots.
 *  - 0x0200A800 saturates at 0xFFFF, and the source tests `v < 0xFFFF` with
 *    the saturating store in the `else`.  Written the other way round the
 *    compiler emits `blt` where the original has `bge` and swaps the two
 *    stores, which is four bytes and reads as a different function.
 */
void MUSICAL_SAVE_ClearNewProps(struct MusicalSave *musical)
{
    u8 i;

    for (i = 0; i < 0x20; i++) {
        musical->newProps[i] = 0;
    }
}

u32 MUSICAL_SAVE_CountOwnedProps(struct MusicalSave *musical)
{
    u32 count;
    s32 prop;

    count = 0;
    for (prop = 0; prop < 256; prop++) {
        if (MUSICAL_SAVE_IsPropOwned(musical, (u8)prop) == 1) {
            count++;
        }
    }
    return count;
}

u32 MUSICAL_SAVE_HasAllProps(struct MusicalSave *musical)
{
    if (MUSICAL_SAVE_CountOwnedProps(musical) == 100) {
        return 1;
    }
    return 0;
}

struct MusicalProgram *MUSICAL_SAVE_GetProgram(struct MusicalSave *musical, u32 index)
{
    return &musical->programs[index];
}

u16 MUSICAL_SAVE_GetShowCount(struct MusicalSave *musical)
{
    return musical->showCount;
}

void MUSICAL_SAVE_IncrementShowCount(struct MusicalSave *musical)
{
    if (musical->showCount < 0xFFFF) {
        musical->showCount++;
    }
}

u16 MUSICAL_SAVE_GetTopRankCount(struct MusicalSave *musical)
{
    return musical->topRankCount;
}

void MUSICAL_SAVE_IncrementTopRankCount(struct MusicalSave *musical)
{
    if (musical->topRankCount < 0xFFFF) {
        musical->topRankCount++;
    }
}

u8 MUSICAL_SAVE_GetEquippedProp(struct MusicalSave *musical, u32 index)
{
    return musical->equippedProps[index];
}

void MUSICAL_SAVE_SetEquippedProp(struct MusicalSave *musical, u32 index, u8 prop)
{
    musical->equippedProps[index] = prop;
}

u8 MUSICAL_SAVE_GetSelectedProgram(struct MusicalSave *musical)
{
    return musical->selectedProgram;
}

void MUSICAL_SAVE_SetSelectedProgram(struct MusicalSave *musical, u8 value)
{
    musical->selectedProgram = value;
}

u8 MUSICAL_SAVE_GetScriptSetting(struct MusicalSave *musical)
{
    return musical->scriptSetting;
}

void MUSICAL_SAVE_SetScriptSetting(struct MusicalSave *musical, u8 value)
{
    musical->scriptSetting = value;
}

u8 MUSICAL_SAVE_GetHasDistData(struct MusicalSave *musical)
{
    return musical->hasDistData;
}

void MUSICAL_SAVE_SetHasDistData(struct MusicalSave *musical, u8 value)
{
    musical->hasDistData = value;
}

u8 *MUSICAL_SAVE_GetStageData(struct MusicalSave *musical)
{
    return musical->stageData;
}

void MUSICAL_SAVE_AddFanPoints(struct MusicalSave *musical, s32 delta)
{
    s32 points = musical->fanPoints + delta;
    if (points < 0xFFFF) {
        musical->fanPoints = points;
    } else {
        musical->fanPoints = 0xFFFF;
    }
}

u16 MUSICAL_SAVE_GetFanPoints(struct MusicalSave *musical)
{
    return musical->fanPoints;
}

u32 MUSICAL_SAVE_GetFittingSetting(struct MusicalSave *musical)
{
    return musical->fittingSetting;
}

void MUSICAL_SAVE_SetFittingSetting(struct MusicalSave *musical, u8 value)
{
    musical->fittingSetting = value;
}
