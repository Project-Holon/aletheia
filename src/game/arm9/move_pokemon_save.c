/*
 * file:     move_pokemon_save.c
 * unit:     yes
 * function: MOVE_POKEMON_SAVE_GetSize, MOVE_POKEMON_SAVE_GetBlock, MOVE_POKEMON_SAVE_Init, MOVE_POKEMON_SAVE_RollStartLocation, MOVE_POKEMON_SAVE_GetStartLocation, MOVE_POKEMON_SAVE_SetCommonArea, MOVE_POKEMON_SAVE_GetEntryState, MOVE_POKEMON_SAVE_SetEntryState, MOVE_POKEMON_SAVE_GetEntryLocation, MOVE_POKEMON_SAVE_SetEntryLocation, MOVE_POKEMON_SAVE_IsEntryActive, MOVE_POKEMON_SAVE_InitEntry, MOVE_POKEMON_SAVE_GetEntry, MOVE_POKEMON_SAVE_GetEntryField, MOVE_POKEMON_SAVE_SetEntryField, MOVE_POKEMON_SAVE_SetCooldown, MOVE_POKEMON_SAVE_TickCooldown, MOVE_POKEMON_SAVE_IsCooldownDone
 * address:  0x0200D414
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from musical_dist_save.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 *   GFL_USE_GetRandomBelow  0x02005728  thumb
 */
#include "musical_dist_save_shared_types.h"
#include "zukan_save_shared_types.h"

struct MovePokemonEntry {
    u16 entryId;                        /* +0x00, 0xFFFF when empty */
    u8  extraData;                      /* +0x02 */
    u8  pad03;
    u32 ivData;                         /* +0x04 */
    u32 personality;                    /* +0x08 */
    u16 species;                        /* +0x0C */
    u16 hp;                             /* +0x0E */
    u8  level;                          /* +0x10 */
    u8  status;                         /* +0x11 */
    u8  isActive;                       /* +0x12 */
    u8  spawned;                        /* +0x13 */
};                                      /* 0x14 */

struct MovePokemonSave {
    u16 commonArea;                     /* +0x00 */
    u16 prevCommonArea;                 /* +0x02 */
    struct MovePokemonEntry entries[2]; /* +0x04 */
    u8  entryLocation[2];               /* +0x2C */
    u8  entryState[2];                  /* +0x2E */
    u8  startLocation;                  /* +0x30 */
    volatile u8 moveCooldown;           /* +0x31 */
    u8  pad32[2];
};                                      /* 0x34 */

#include "mi_memory.h"
struct SaveControl;

#include "save_control.h"

#include "gfl_use.h"

u32 MOVE_POKEMON_SAVE_GetSize(void);

void *MOVE_POKEMON_SAVE_GetBlock(void *saveControl);

void MOVE_POKEMON_SAVE_Init(struct MovePokemonSave *pSave);

void MOVE_POKEMON_SAVE_RollStartLocation(void *saveControl);

u8 MOVE_POKEMON_SAVE_GetStartLocation(struct MovePokemonSave *pSave);

void MOVE_POKEMON_SAVE_SetCommonArea(struct MovePokemonSave *pSave, u16 area);

u8 MOVE_POKEMON_SAVE_GetEntryState(struct MovePokemonSave *pSave, u32 slot);

void MOVE_POKEMON_SAVE_SetEntryState(struct MovePokemonSave *pSave, u32 slot, u32 state);

u8 MOVE_POKEMON_SAVE_GetEntryLocation(struct MovePokemonSave *pSave, u32 slot);

void MOVE_POKEMON_SAVE_SetEntryLocation(struct MovePokemonSave *pSave, u32 slot, u8 location);

u8 MOVE_POKEMON_SAVE_IsEntryActive(struct MovePokemonSave *pSave, u32 slot);

void MOVE_POKEMON_SAVE_InitEntry(struct MovePokemonEntry *pEntry);

struct MovePokemonEntry *MOVE_POKEMON_SAVE_GetEntry(struct MovePokemonSave *pSave, u32 slot);

u32 MOVE_POKEMON_SAVE_GetEntryField(const struct MovePokemonEntry *pEntry, u32 field);

void MOVE_POKEMON_SAVE_SetEntryField(struct MovePokemonEntry *pEntry, u32 field, u32 value);

void MOVE_POKEMON_SAVE_SetCooldown(struct MovePokemonSave *pSave, u8 cooldown);

u32 MOVE_POKEMON_SAVE_TickCooldown(struct MovePokemonSave *pSave);

u32 MOVE_POKEMON_SAVE_IsCooldownDone(struct MovePokemonSave *pSave);

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           MOVE_POKEMON_SAVE_GetStartLocation, MOVE_POKEMON_SAVE_SetCommonArea, MOVE_POKEMON_SAVE_GetEntryState, MOVE_POKEMON_SAVE_SetEntryState,
 *           MOVE_POKEMON_SAVE_GetEntryLocation, MOVE_POKEMON_SAVE_SetEntryLocation, MOVE_POKEMON_SAVE_IsEntryActive, MOVE_POKEMON_SAVE_InitEntry,
 *           MOVE_POKEMON_SAVE_GetEntry, MOVE_POKEMON_SAVE_GetEntryField, MOVE_POKEMON_SAVE_SetEntryField, MOVE_POKEMON_SAVE_SetCooldown,
 *           MOVE_POKEMON_SAVE_TickCooldown, MOVE_POKEMON_SAVE_IsCooldownDone
 *
 * 392 bytes, 0x0200D414..0x0200D59C, 18 functions, sixteen of which carry no
 * label in the generated listing: everything here but the constructor and
 * MOVE_POKEMON_SAVE_RollStartLocation is a leaf that saves nothing.
 *
 * The object is the save block with id 0x38: MOVE_POKEMON_SAVE_GetSize returns 0x34,
 * MOVE_POKEMON_SAVE_GetBlock is the whole of the lookup `SAVE_CONTROL_GetBlock(sys, 0x38)`, and
 * MOVE_POKEMON_SAVE_Init clears exactly 0x34 bytes, which is the block-file opening
 * this region keeps producing.  The record is a pair of 0x14-byte entries at
 * +0x04 with four byte fields and two counters behind them.
 *
 * Three things cost time here.
 *
 *  - the two dispatchers at 0x0200D4B8 and 0x0200D50C emit their arms in the
 *    order 1, 2, 3, 10, 4, 5, 6, 7, 8, 9, which is the order the source wrote
 *    them in and not the numeric order of the labels; the `.hword` table is
 *    what says so, since the entry for 10 sits between the entries for 3 and
 *    4 in address order.  See
 *    docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 *  - both tables have an eleventh entry, for 0, pointing at the function's
 *    exit.  That entry is before every real arm, so it is an empty `case 0:`
 *    the source wrote rather than a gap: without it the labels are 1..10 and
 *    this front end emits a compare chain instead of a table.  See
 *    docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *  - MOVE_POKEMON_SAVE_TickCooldown reads +0x31 three times and stores it once with the
 *    address recomputed before each access, and nothing that leaves the field
 *    ordinary reproduces that: every spelling folds the three reads into one.
 *    Declaring it `volatile` keeps them, and it costs nothing in
 *    MOVE_POKEMON_SAVE_SetCooldown or MOVE_POKEMON_SAVE_IsCooldownDone, which touch it once each.  The same
 *    reading as `volatile u16 unkE0` in src/matched/unit_0200C0E8.c.
 */
u32 MOVE_POKEMON_SAVE_GetSize(void)
{
    return sizeof(struct MovePokemonSave);
}

void *MOVE_POKEMON_SAVE_GetBlock(void *saveControl)
{
    return SAVE_CONTROL_GetBlock(saveControl, 0x38);
}

void MOVE_POKEMON_SAVE_Init(struct MovePokemonSave *pSave)
{
    MI_CpuFill8(pSave, 0, sizeof(struct MovePokemonSave));
    pSave->startLocation = 0;
    pSave->moveCooldown = 0;
}

void MOVE_POKEMON_SAVE_RollStartLocation(void *saveControl)
{
    struct MovePokemonSave *pSave = MOVE_POKEMON_SAVE_GetBlock(saveControl);

    pSave->startLocation = GFL_USE_GetRandomBelow(0x11);
}

u8 MOVE_POKEMON_SAVE_GetStartLocation(struct MovePokemonSave *pSave)
{
    return pSave->startLocation;
}

void MOVE_POKEMON_SAVE_SetCommonArea(struct MovePokemonSave *pSave, u16 area)
{
    if (pSave->commonArea != area) {
        pSave->prevCommonArea = pSave->commonArea;
        pSave->commonArea = area;
    }
}

u8 MOVE_POKEMON_SAVE_GetEntryState(struct MovePokemonSave *pSave, u32 slot)
{
    return pSave->entryState[slot];
}

void MOVE_POKEMON_SAVE_SetEntryState(struct MovePokemonSave *pSave, u32 slot, u32 state)
{
    pSave->entryState[slot] = state;
}

u8 MOVE_POKEMON_SAVE_GetEntryLocation(struct MovePokemonSave *pSave, u32 slot)
{
    return pSave->entryLocation[slot];
}

void MOVE_POKEMON_SAVE_SetEntryLocation(struct MovePokemonSave *pSave, u32 slot, u8 location)
{
    pSave->entryLocation[slot] = location;
}

u8 MOVE_POKEMON_SAVE_IsEntryActive(struct MovePokemonSave *pSave, u32 slot)
{
    return pSave->entries[slot].isActive;
}

void MOVE_POKEMON_SAVE_InitEntry(struct MovePokemonEntry *pEntry)
{
    MI_CpuFill8(pEntry, 0, sizeof(struct MovePokemonEntry));
    pEntry->entryId = 0xFFFF;
}

struct MovePokemonEntry *MOVE_POKEMON_SAVE_GetEntry(struct MovePokemonSave *pSave, u32 slot)
{
    return &pSave->entries[slot];
}

u32 MOVE_POKEMON_SAVE_GetEntryField(const struct MovePokemonEntry *pEntry, u32 field)
{
    switch (field) {
    case 0:
        break;
    case 1:
        return pEntry->entryId;
    case 2:
        return pEntry->ivData;
    case 3:
        return pEntry->personality;
    case 10:
        return pEntry->extraData;
    case 4:
        return pEntry->species;
    case 5:
        return pEntry->hp;
    case 6:
        return pEntry->level;
    case 7:
        return pEntry->status;
    case 8:
        return pEntry->isActive;
    case 9:
        return pEntry->spawned;
    }
    return 0;
}

void MOVE_POKEMON_SAVE_SetEntryField(struct MovePokemonEntry *pEntry, u32 field, u32 value)
{
    switch (field) {
    case 0:
        break;
    case 1:
        pEntry->entryId = value;
        break;
    case 2:
        pEntry->ivData = value;
        break;
    case 3:
        pEntry->personality = value;
        break;
    case 10:
        pEntry->extraData = value;
        break;
    case 4:
        pEntry->species = value;
        break;
    case 5:
        pEntry->hp = value;
        break;
    case 6:
        pEntry->level = value;
        break;
    case 7:
        pEntry->status = value;
        break;
    case 8:
        pEntry->isActive = value;
        break;
    case 9:
        pEntry->spawned = value;
        break;
    }
}

void MOVE_POKEMON_SAVE_SetCooldown(struct MovePokemonSave *pSave, u8 cooldown)
{
    pSave->moveCooldown = cooldown;
}

u32 MOVE_POKEMON_SAVE_TickCooldown(struct MovePokemonSave *pSave)
{
    if (pSave->moveCooldown != 0) {
        pSave->moveCooldown = pSave->moveCooldown - 1;
        if (pSave->moveCooldown == 0) {
            return 1;
        }
    }
    return 0;
}

u32 MOVE_POKEMON_SAVE_IsCooldownDone(struct MovePokemonSave *pSave)
{
    if (pSave->moveCooldown == 0) {
        return 1;
    }
    return 0;
}
