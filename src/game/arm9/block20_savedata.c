/*
 * file:     block20_savedata.c
 * unit:     yes
 * function: BLOCK20_SAVEDATA_TestPanelMark, BLOCK20_SAVEDATA_SetPanelMark, BLOCK20_SAVEDATA_InitPanelMarks,
 *           BLOCK20_SAVEDATA_SetPanelState, BLOCK20_SAVEDATA_GetPanelState, BLOCK20_SAVEDATA_GetBlock,
 *           BLOCK20_SAVEDATA_GetBlockFromSys, BLOCK20_SAVEDATA_GetBlockSize, BLOCK20_SAVEDATA_InitBlock,
 *           BLOCK20_SAVEDATA_GetPokemon, BLOCK20_SAVEDATA_SetPokemon, BLOCK20_SAVEDATA_TestBit,
 *           BLOCK20_SAVEDATA_SetMode, BLOCK20_SAVEDATA_GetMode, BLOCK20_SAVEDATA_SetPending,
 *           BLOCK20_SAVEDATA_GetPending, BLOCK20_SAVEDATA_SetActive, BLOCK20_SAVEDATA_GetActive,
 *           BLOCK20_SAVEDATA_GetEntryId, BLOCK20_SAVEDATA_GetEntryValue, BLOCK20_SAVEDATA_SetEntry,
 *           BLOCK20_SAVEDATA_ClearEntry, BLOCK20_SAVEDATA_CountEntries, BLOCK20_SAVEDATA_GetRecord,
 *           BLOCK20_SAVEDATA_SetRecord, BLOCK20_SAVEDATA_GetDateStamp, BLOCK20_SAVEDATA_SetDateStamp,
 *           BLOCK20_SAVEDATA_GetSavedValue, BLOCK20_SAVEDATA_SetSavedValue, BLOCK20_SAVEDATA_GetProgress,
 *           BLOCK20_SAVEDATA_SetProgress, BLOCK20_SAVEDATA_GetFlag, BLOCK20_SAVEDATA_SetFlag
 * address:  0x02009160
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   SAVE_CONTROL_GetBlock   0x020071CC  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   POKE_TOOL_GetPartyParamSize  0x020173EC  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 */
struct Big;
struct SaveControl;
#include "../types.h"

/*
 * The C-Gear save object (0x2C bytes), shared with the file that owns
 * SAVE_CONTROL_GetBlock-family accessors.  panel is 9 rows of 4 cells: the
 * low nibble is the value, bit 7 is the flag, and bits 4 to 6 are a
 * three-valued mark these two functions read and write.
 */
struct CGearSave {
    u8  panel[9][4];
    u16 gsyncId;
    u8  gsyncState;
    u8  isObtained;
    u8  powerSetting;
    u8  commState;
    u8  reserved[2];
};

/* One of the five 0x1A-byte records at +0x120 of the block. */
struct CgearSaveRecord {
    u16 id;
    u8  payload[0x18];
};

/*
 * The save block with id 0x20, 0x1AA bytes:
 *   +0x000  u32              a date stamp (0xDA010100 until set)
 *   +0x004  s32              a saved value, -1 until set
 *   +0x008  u8[0xDC]         one PokemonParam copied in and out whole
 *   +0x0E4  u16[20]          paired with
 *   +0x10C  u8 [20]          ... one entry each
 *   +0x120  record[5]        0x1A bytes each, first halfword seeded to 0x7E
 *   +0x1A2  u8               reserved
 *   +0x1A3  u8               isActive
 *   +0x1A4  u8               mode
 *   +0x1A5  u8               isPending
 *   +0x1A6  bitfield         7-bit progress and 1-bit flag
 *   +0x1A7  u8[3]            reserved
 */
struct CgearSaveBlock {
    u32 dateStamp;
    s32 savedValue;
    u8  pokemon[0xDC];
    u16 entryIds[20];
    u8  entryValues[20];
    struct CgearSaveRecord records[5];
    u8  reservedByte;
    u8  isActive;
    u8  mode;
    u8  isPending;
    u8  progress : 7;
    u8  flag : 1;
    u8  reservedTail[3];
};

#include "save_control.h"
struct GameData;
#include "game_data.h"
#include "poke_tool.h"
#include "mi_memory.h"
void BLOCK20_SAVEDATA_SetEntry(struct CgearSaveBlock *block, int index, u16 id, u8 value);
u8   BLOCK20_SAVEDATA_GetEntryValue(const struct CgearSaveBlock *block, int index);
void BLOCK20_SAVEDATA_SetDateStamp(struct CgearSaveBlock *block, u32 value);
struct CgearSaveBlock *BLOCK20_SAVEDATA_GetBlock(void *sys);
struct CgearSaveBlock *BLOCK20_SAVEDATA_GetBlockFromSys(void *p);
u32 BLOCK20_SAVEDATA_GetBlockSize(void);

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           BLOCK20_SAVEDATA_GetPanelState
 *
 * alias: the rest of the 0x2C-byte object of src/matched/unit_020090D8.c and
 * src/matched/unit_02009110.c.  None of these five carries a label: the first
 * two save registers without lr and the last three have no prologue at all, so
 * the whole 176-byte run arrives in the listing as `.word` data.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * The 9 by 4 byte table at the front of the object is three fields per byte:
 * the low nibble is the count unit_02009110.c reads, bit 7 is the flag it
 * tests, and bits 4 to 6 are a three-valued mark that these two functions
 * read and write.  The mark is not a bit index computed from the kind: 1 maps
 * to 0x40, 3 to 0x20 and 2 to 0x10, in that source order, which no arithmetic
 * produces and which both functions spell out as the same three-armed chain.
 *
 * In BLOCK20_SAVEDATA_SetPanelMark each arm of that chain assigns only the mask
 * and the `orrs` is emitted once, with the no-match path branching past it, so
 * the `|=` is inside the arms in the source; see
 * docs/idioms/switch-arms-tail-merge.md.
 *
 * `subs r5, r3, #1; cmp r5, #2; bhi` is the folded range check, and it has to
 * be written as `(u32)(kind - 1) <= 2`: `kind >= 1 && kind <= 3` on the signed
 * parameter is two compares and two branches, two bytes longer, exactly as
 * docs/MATCHING.md records for MUSICAL_SAVE_AddProp.  The row and column checks next
 * to it do not fold, because they are written as two comparisons against a
 * signed index in the style of unit_02009110.c.
 *
 * In BLOCK20_SAVEDATA_TestPanelMark the `movs r4, #0` sits *after* the range
 * checks, so the mask is declared without an initialiser and assigned once the
 * guards have passed.  Written as `u32 mask = 0;` the compiler hoists it above
 * the first `cmp` and the whole prologue shifts by two bytes.
 *
 * BLOCK20_SAVEDATA_SetPanelState and BLOCK20_SAVEDATA_GetPanelState pay an
 * `adds r0, #0x29` before the `strb` and the `ldrb`, because the byte offset
 * 0x29 is past the 31 that the Thumb immediate form reaches; see
 * docs/idioms/thumb-immediate-reach-costs-an-adds.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009160.c \
 *       --addr 0x02009160 --thumb
 */
u32 BLOCK20_SAVEDATA_TestPanelMark(const struct CGearSave *save, int row, int col, int kind)
{
    u32 mask;

    if (row >= 9 || row < 0) {
        return 0;
    }
    if (col >= 4 || col < 0) {
        return 0;
    }
    mask = 0;
    if (kind == 1) {
        mask = 0x40;
    } else if (kind == 3) {
        mask = 0x20;
    } else if (kind == 2) {
        mask = 0x10;
    }
    if (save->panel[row][col] & mask) {
        return 1;
    }
    return 0;
}

void BLOCK20_SAVEDATA_SetPanelMark(struct CGearSave *save, int row, int col, int kind,
                  int marked, int flagged)
{
    u32 value;

    if (kind >= 5) {
        return;
    }
    if (row >= 9 || row < 0) {
        return;
    }
    if (col >= 4 || col < 0) {
        return;
    }
    value = kind;
    if (marked == 1) {
        if ((u32)(kind - 1) <= 2) {
            value |= 0x80;
        }
    }
    if (flagged) {
        if (kind == 1) {
            value |= 0x40;
        } else if (kind == 3) {
            value |= 0x20;
        } else if (kind == 2) {
            value |= 0x10;
        }
    }
    save->panel[row][col] = value;
}

void *BLOCK20_SAVEDATA_InitPanelMarks(void *save)
{
    return save;
}

void BLOCK20_SAVEDATA_SetPanelState(struct CGearSave *save, u8 value)
{
    save->commState = value;
}

u8 BLOCK20_SAVEDATA_GetPanelState(const struct CGearSave *save)
{
    return save->commState;
}

#define _CGEAR_BLOCK_ID 0x20

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           BLOCK20_SAVEDATA_GetRecord, BLOCK20_SAVEDATA_SetRecord,
 *           BLOCK20_SAVEDATA_TestBit, BLOCK20_SAVEDATA_SetMode, BLOCK20_SAVEDATA_GetMode,
 *           BLOCK20_SAVEDATA_SetPending, BLOCK20_SAVEDATA_GetPending, BLOCK20_SAVEDATA_SetActive,
 *           BLOCK20_SAVEDATA_GetActive, BLOCK20_SAVEDATA_GetEntryId, BLOCK20_SAVEDATA_GetEntryValue,
 *           BLOCK20_SAVEDATA_SetEntry, BLOCK20_SAVEDATA_ClearEntry, BLOCK20_SAVEDATA_CountEntries,
 *           BLOCK20_SAVEDATA_GetRecord, BLOCK20_SAVEDATA_SetRecord, BLOCK20_SAVEDATA_GetDateStamp,
 *           BLOCK20_SAVEDATA_SetDateStamp, BLOCK20_SAVEDATA_GetSavedValue, BLOCK20_SAVEDATA_SetSavedValue,
 *           BLOCK20_SAVEDATA_GetProgress, BLOCK20_SAVEDATA_SetProgress, BLOCK20_SAVEDATA_GetFlag,
 *           BLOCK20_SAVEDATA_SetFlag
 *
 * alias: the head of the save block with id 0x20, 0x1AA bytes.  The file opens
 * the way every block file in this region does: a twelve byte thunk that is
 * `SAVE_CONTROL_GetBlock(sys, 0x20)`, a four byte function returning the block size, and
 * a constructor that clears exactly that size.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md; only eight of
 * these twenty-eight functions carry a label.
 *
 * The bound on the two parallel arrays is off by one in the original and it is
 * off by one in both directions: the guard is `i > 20` on twenty entry arrays,
 * so index 20 writes the first byte of the array after it, while the counter
 * in BLOCK20_SAVEDATA_CountEntries stops at 19.  Writing the guard as `i >= 20` costs nothing
 * in the C and changes the compare, so the off-by-one is part of the match.
 *
 * BLOCK20_SAVEDATA_TestBit is the signed-index bit test: `n >> 3` is a plain `lsrs` and
 * `n % 8` is the four instruction `lsrs #31` / `lsls #29` / `subs` / `rors #29`
 * sequence, which is the same split docs/MATCHING.md records for
 * MUSICAL_SAVE_AddProp.  `& 7` would be two instructions and `/ 8` would add a rounding
 * correction, so the source really does spell the two halves differently.
 * The byte index is the one place a cast is needed: `n >> 3` on the signed
 * parameter is an `asrs`, and only `(u32)n >> 3` gives the original's `lsrs`.
 *
 * The byte at +0x1A6 is two bitfields, `u8 : 7` and `u8 : 1`, and the four
 * accessors on it say so: the getters end in `lsls #0x19` / `lsrs #0x19` and
 * `lsls #0x18` / `lsrs #0x1F`, widths that are not any integer type, which is
 * docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md.  Both setters
 * take `int`, not `u8`: the `cmp #5` in BLOCK20_SAVEDATA_SetProgress is `blt` rather than
 * `blo`, and both carry a `lsls #0x18` / `lsrs #0x18` truncation to u8 in
 * front of the field mask that an already-u8 parameter does not produce.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009210.c \
 *       --addr 0x02009210 --thumb
 */
struct CgearSaveBlock *BLOCK20_SAVEDATA_GetBlock(void *sys)
{
    return SAVE_CONTROL_GetBlock(sys, _CGEAR_BLOCK_ID);
}

struct CgearSaveBlock *BLOCK20_SAVEDATA_GetBlockFromSys(void *p)
{
    return BLOCK20_SAVEDATA_GetBlock(GAME_DATA_GetSaveControl(p));
}

u32 BLOCK20_SAVEDATA_GetBlockSize(void)
{
    return sizeof(struct CgearSaveBlock);
}

void BLOCK20_SAVEDATA_InitBlock(struct CgearSaveBlock *block)
{
    u8 i;

    MI_CpuFill8(block, 0, BLOCK20_SAVEDATA_GetBlockSize());
    BLOCK20_SAVEDATA_SetDateStamp(block, 0xDA010100);
    block->savedValue = -1;
    block->reservedTail[0] = 0;
    block->reservedTail[1] = 0;
    block->reservedTail[2] = 0;
    block->progress = 0x7F;
    for (i = 0; i < 5; i++) {
        block->records[i].id = 0x7E;
    }
}

u8 *BLOCK20_SAVEDATA_GetPokemon(struct CgearSaveBlock *block)
{
    return block->pokemon;
}

void BLOCK20_SAVEDATA_SetPokemon(struct CgearSaveBlock *block, const void *src)
{
    MI_CpuCopy8(src, block->pokemon, POKE_TOOL_GetPartyParamSize());
}

u32 BLOCK20_SAVEDATA_TestBit(const u8 *bits, int n)
{
    u32 ret = 1;

    if (!(bits[(u32)n >> 3] & (1 << (n % 8)))) {
        ret = 0;
    }
    return ret;
}

void BLOCK20_SAVEDATA_SetMode(struct CgearSaveBlock *block, u8 value)
{
    block->mode = value;
}

u8 BLOCK20_SAVEDATA_GetMode(const struct CgearSaveBlock *block)
{
    return block->mode;
}

void BLOCK20_SAVEDATA_SetPending(struct CgearSaveBlock *block, u8 value)
{
    block->isPending = value;
}

u8 BLOCK20_SAVEDATA_GetPending(const struct CgearSaveBlock *block)
{
    return block->isPending;
}

void BLOCK20_SAVEDATA_SetActive(struct CgearSaveBlock *block, u8 value)
{
    block->isActive = value;
}

u8 BLOCK20_SAVEDATA_GetActive(const struct CgearSaveBlock *block)
{
    return block->isActive;
}

u16 BLOCK20_SAVEDATA_GetEntryId(const struct CgearSaveBlock *block, int index)
{
    u16 id;

    if (index > 20) {
        return 0;
    }
    id = block->entryIds[index];
    if (id > 0x272) {
        id = 0;
    }
    return id;
}

u8 BLOCK20_SAVEDATA_GetEntryValue(const struct CgearSaveBlock *block, int index)
{
    u8 value;

    if (index > 20) {
        return 0;
    }
    value = block->entryValues[index];
    if (value > 20) {
        value = 0;
    }
    return value;
}

void BLOCK20_SAVEDATA_SetEntry(struct CgearSaveBlock *block, int index, u16 id, u8 value)
{
    if (index > 20) {
        return;
    }
    block->entryIds[index] = id;
    block->entryValues[index] = value;
}

void BLOCK20_SAVEDATA_ClearEntry(struct CgearSaveBlock *block, int index)
{
    BLOCK20_SAVEDATA_SetEntry(block, index, 0, 0);
}

u32 BLOCK20_SAVEDATA_CountEntries(const struct CgearSaveBlock *block)
{
    u32 count = 0;
    int i;

    for (i = 0; i < 20; i++) {
        if (BLOCK20_SAVEDATA_GetEntryValue(block, i) != 0) {
            count++;
        }
    }
    return count;
}

struct CgearSaveRecord *BLOCK20_SAVEDATA_GetRecord(struct CgearSaveBlock *block, int index)
{
    if (index < 5) {
        return &block->records[index];
    }
    return 0;
}

void BLOCK20_SAVEDATA_SetRecord(struct CgearSaveBlock *block, int index, const void *src)
{
    if (index < 5) {
        MI_CpuCopy8(src, &block->records[index], sizeof(block->records[0]));
    }
}

u32 BLOCK20_SAVEDATA_GetDateStamp(const struct CgearSaveBlock *block)
{
    return block->dateStamp;
}

void BLOCK20_SAVEDATA_SetDateStamp(struct CgearSaveBlock *block, u32 value)
{
    block->dateStamp = value;
}

s32 BLOCK20_SAVEDATA_GetSavedValue(const struct CgearSaveBlock *block)
{
    return block->savedValue;
}

void BLOCK20_SAVEDATA_SetSavedValue(struct CgearSaveBlock *block, s32 value)
{
    block->savedValue = value;
}

u32 BLOCK20_SAVEDATA_GetProgress(const struct CgearSaveBlock *block)
{
    u32 value = block->progress;

    if (value >= 5 && value != 0x7F) {
        value = 0x7F;
    }
    return value;
}

void BLOCK20_SAVEDATA_SetProgress(struct CgearSaveBlock *block, int value)
{
    if (value < 5 || value == 0x7F) {
        block->progress = value;
    }
}

u32 BLOCK20_SAVEDATA_GetFlag(const struct CgearSaveBlock *block)
{
    return block->flag;
}

void BLOCK20_SAVEDATA_SetFlag(struct CgearSaveBlock *block, int value)
{
    block->flag = value;
}
