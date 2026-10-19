/*
 * file:     symbol_save.c
 * unit:     yes
 * function: SYMBOL_SAVE_UpdateChecksum, SYMBOL_SAVE_FinalizeChecksum, SYMBOL_SAVE_GetBlockSize, SYMBOL_SAVE_InitBlock, SYMBOL_SAVE_GetBlock, SYMBOL_SAVE_FindBand, SYMBOL_SAVE_FindFreeSlot, SYMBOL_SAVE_RemoveSlot, SYMBOL_SAVE_RemoveSlotAndFind, SYMBOL_SAVE_FindBandThunk, SYMBOL_SAVE_RemoveSlotAndCommit, SYMBOL_SAVE_WriteRecord, SYMBOL_SAVE_SetRank, SYMBOL_SAVE_FindRecord, SYMBOL_SAVE_GetBitBlockSize, SYMBOL_SAVE_InitBitBlock, SYMBOL_SAVE_GetBitBlock, SYMBOL_SAVE_GetQuestionnaireBits, SYMBOL_SAVE_ReadBitField, SYMBOL_SAVE_WriteBitField, SYMBOL_SAVE_SetBitDescriptor
 * address:  0x0200E024
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from bsubway_savedata.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 *   MI_CpuFill8         0x02082BCC  arm
 *   GF_STANDARD_Checksum  0x0203F2FC  arm
 *   GF_STANDARD_XorCrypt  0x0203F328  arm
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 *   sSymbolBandRanges  0x0209DE90  data
 *   _s32_div_f  0x0209C0A4  arm
 *   GFL_HEAP_Alloc     0x02030734  arm
 *   GFL_HEAP_Free     0x020307B0  arm
 *   SAVE_CONTROL_ReadRecordFromFlash     0x02007248  thumb
 *   GF_STANDARD_CompareBytes            0x0203EFC8  arm
 *   sFileName_symbol_save    0x020A720C  data
 *   QUESTIONNAIRE_GetAnswerBitOffset  0x02167380  thumb  ov010
 *   QUESTIONNAIRE_GetAnswerBitWidth  0x02167358  thumb  ov010
 *   GF_STANDARD_XorCryptEx  0x0203F37C  arm
 */
#include "bsubway_savedata_shared_types.h"

#define _RANDOM32 (*(volatile u32 *)0x02FFFC3C)

struct SaveBlockTable;

typedef enum { BAND_FIRST = 0, BAND_COUNT = 4 } BandIdx;

struct BandRange { u16 first; u16 limit; };

/* Symbol save block, 0x850 bytes (SYMBOL_SAVE_UpdateChecksum refreshes its checksum). */
struct SymbolSave {
    u32 records[530];
    u8  kind2Count;
    u8  rank;
    u8  reserved[2];
    u16 checksum;
    u16 seed;
};

/* Second save block, 0x284 bytes: a 0x280 byte bit table and four trailing bytes. */
struct SymbolBitSave {
    u8 bits[0x280];
    u8 descriptor[4];
};

/* One packed 32-bit record of SymbolSave.rec. */
struct SymbolRec {
    u32 id       : 11;
    u32 param    : 10;
    u32 flags    : 2;
    u32 category : 6;
    u32 status   : 3;
};

extern void MI_CpuCopy8(const void *src, void *dest, unsigned int size);

extern void  MI_CpuFill8(void *dest, u8 value, u32 size);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 GF_STANDARD_Checksum(const void *p, u32 len);

extern void GF_STANDARD_XorCrypt(void *p, u32 size, u32 seed);

extern void GF_STANDARD_XorCryptEx(void *p, unsigned int size, unsigned int seed);

extern void *SAVE_CONTROL_GetBlock(struct SaveBlockTable *ctrl, u32 id);

extern u32 GFL_HEAP_Free(void *p);

extern u32   SAVE_CONTROL_ReadRecordFromFlash(void *a, u32 b, u32 c, void *d, u32 e);

extern int   GF_STANDARD_CompareBytes(const void *a, const void *b, u32 n);

extern u8 QUESTIONNAIRE_GetAnswerBitOffset(u32 id);

extern u8 QUESTIONNAIRE_GetAnswerBitWidth(u32 id);

void SYMBOL_SAVE_UpdateChecksum(struct SymbolSave *save);

void SYMBOL_SAVE_FinalizeChecksum(struct SymbolSave *save);

u32 SYMBOL_SAVE_GetBlockSize(void);

void SYMBOL_SAVE_InitBlock(struct SymbolSave *save);

void *SYMBOL_SAVE_GetBlock(void *saveData);

u32 SYMBOL_SAVE_FindBand(u32 value);

u32 SYMBOL_SAVE_FindFreeSlot(const struct SymbolRec *records, int band);

void SYMBOL_SAVE_RemoveSlot(u32 *records, u32 index);

u32 SYMBOL_SAVE_RemoveSlotAndFind(struct SymbolSave *save, u32 band);

unsigned int SYMBOL_SAVE_FindBandThunk(unsigned int value);

void SYMBOL_SAVE_RemoveSlotAndCommit(struct SymbolSave *save, u32 index);

void SYMBOL_SAVE_WriteRecord(struct SymbolSave *save, u16 id, u16 param, u8 flags, u8 category, u8 status, u32 kind);

void SYMBOL_SAVE_SetRank(struct SymbolSave *save, int index);

u32 SYMBOL_SAVE_FindRecord(void *saveData, u32 *keyWord, void *heapId, u32 matchMode);

int SYMBOL_SAVE_GetBitBlockSize(void);

void SYMBOL_SAVE_InitBitBlock(struct SymbolBitSave *save);

void *SYMBOL_SAVE_GetBitBlock(void *saveData);

u8 *SYMBOL_SAVE_GetQuestionnaireBits(struct SymbolBitSave *save);

u32 SYMBOL_SAVE_ReadBitField(const u8 *bits, int fieldId);

void SYMBOL_SAVE_WriteBitField(u8 *bits, int fieldId, u32 value);

void SYMBOL_SAVE_SetBitDescriptor(struct SymbolBitSave *save, int value, int index);

extern const struct BandRange sSymbolBandRanges[];

extern char  sFileName_symbol_save[];

/*
 * The 0x84C-byte save block's commit, and the second instance of the
 * 0x02FFFC3C idiom (see src/matched/unit_02008C58.c, which is the same block
 * 0x1E0 bytes smaller): the shared word is read TWICE and the two reads are not
 * commoned up, which is a `volatile` read and nothing else, and the two halves
 * are combined as `a << 8 | b`.
 *
 * The write at +0x84E is followed by a readback test against 0 and a store of 1
 * if it came back 0 -- the field is volatile all the way through, which is why
 * the `ldrh` is not folded away.  The checksum pair is the same shape as the
 * one in unit_02008C58.c: GF_STANDARD_Checksum computes it over (obj, 0x84C) and
 * GF_STANDARD_XorCrypt writes it back with the +0x84E halfword as the high word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SYMBOL_SAVE_UpdateChecksum.c \
 *       --func SYMBOL_SAVE_UpdateChecksum --addr 0x0200E024 --cc 1.1p1 --thumb
 */
void SYMBOL_SAVE_UpdateChecksum(struct SymbolSave *save)
{
    u32 seedHigh = _RANDOM32;
    u32 seedLow = _RANDOM32;

    save->seed = seedHigh << 8 | seedLow;
    if (save->seed == 0) {
        save->seed = 1;
    }
    save->checksum = GF_STANDARD_Checksum(save, 0x84c);
    GF_STANDARD_XorCrypt(save, 0x84c,
                  save->checksum +
                  (save->seed << 16));
}

void SYMBOL_SAVE_FinalizeChecksum(struct SymbolSave *save)
{
    GF_STANDARD_XorCryptEx(save, 0x84c,
        save->checksum + (save->seed << 16));
    save->seed = 0;
}

/*
 * Save-table size callback: returns 0x850, the size of the block whose
 * init is SYMBOL_SAVE_InitBlock.  Pointer word 0x0200E091 at 0x0209DD08.
 */
u32 SYMBOL_SAVE_GetBlockSize(void)
{
    return 0x850;
}

/*
 * Zeroes 0x850 bytes then runs the initialiser.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SYMBOL_SAVE_InitBlock.c \
 *       --func SYMBOL_SAVE_InitBlock --addr 0x0200E098 --thumb --cc 1.1p1
 */
void SYMBOL_SAVE_InitBlock(struct SymbolSave *save)
{
    MI_CpuFill8(save, 0, 0x850);
    SYMBOL_SAVE_UpdateChecksum(save);
}

/*
 * Unlabelled leaf: tail-calls SAVE_CONTROL_GetBlock(p, 0x3d).
 */
void *SYMBOL_SAVE_GetBlock(void *saveData)
{
    return SAVE_CONTROL_GetBlock(saveData, 0x3d);
}

/*
 * Band lookup: the index of the first of four records whose .b bound is
 * above value, or 3. SYMBOL_SAVE_RemoveSlot indexes the same table with the result.
 *
 * THE LEVER (wave 18, lane ties_b; it was DIFF 44/44, 9 out, the "pool load
 * in the preheader" wall of docs/notes/pkt_0200E0BC.c.txt): the counter AND
 * the result are enum-typed, as in src/matched/GPOWER_CountDownTimers.c. An enum
 * induction variable keeps the unfolded `cmp #4; bhs` entry guard with the
 * table load after it, and no redundant `if (i >= 4) break;` is needed. The
 * bound is compared unsigned (`(u32)BAND_COUNT`) for the image's bhs/blo; with
 * that compare a u32 result swaps r3/r4, an enum result does not.
 */
u32 SYMBOL_SAVE_FindBand(u32 value)
{
    BandIdx band;
    BandIdx result = 3;

    for (band = 0; band < (u32)BAND_COUNT; band++) {
        if (value < sSymbolBandRanges[band].limit) {
            result = band;
            break;
        }
    }
    return result;
}

/*
 * Wave 17 lane untried_small. Three levers together: the range table read as
 * `struct BandRange { u16 first; u16 limit; }` (two pool words, tbl and tbl + 2, as in
 * SYMBOL_SAVE_RemoveSlot); the slot word read as an 11-bit bitfield (the image masks
 * with `lsls #21; lsrs #21`, which `& 0x7ff` never produces); and an element
 * pointer walked beside the index in a `while` loop.
 */
u32 SYMBOL_SAVE_FindFreeSlot(const struct SymbolRec *records, int band)
{
    u32 freeSlot = 0xffff;
    u32 slot = sSymbolBandRanges[band].first;
    u32 bandLimit = sSymbolBandRanges[band].limit;
    const struct SymbolRec *record = &records[slot];

    while (slot < bandLimit) {
        if (record->id == 0) {
            freeSlot = slot;
            break;
        }
        slot++;
        record++;
    }
    return freeSlot;
}

/*
 * The third pass's one in-lane conversion (lane 1 of the 0-64 byte band).
 * The two earlier attempts on this address both stopped at MATCH/DIFF on the
 * *pool word* rather than on any instruction: the entry point is a two-field
 * record table, and the field the original reads is the SECOND one, so its
 * `ldr r0, [pc, #0x28]` loads `sSymbolBandRanges + 2` (the address of `.b`), not the
 * table base.  Reading `struct BandRange { u16 first; u16 limit; } sSymbolBandRanges[]` and taking
 * `.b` folds that +2 into the pool word exactly as the original does;
 * reading the same address as `u16[]` at `[i * 2]` gives `.a` (the wrong
 * field, one byte off in the pool) and `[i * 2 + 1]` gives 68 bytes instead
 * of 64.  See `docs/idioms/table-field-offset-folds-into-the-pool-word.md`
 * for the lever and docs/notes/pkt_0200E0BC.c.txt for the two residues.
 *
 * `u32 *o = obj;` is load-bearing: without it mwcc strength-reduces
 * `obj + (idx + 1)` to `(obj + idx) + 4`, which is the same address but a
 * different instruction order in the argument set-up.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SYMBOL_SAVE_RemoveSlot.c \
 *       --func SYMBOL_SAVE_RemoveSlot --addr 0x0200E124 --cc 1.1p1 --thumb
 */
void SYMBOL_SAVE_RemoveSlot(u32 *records, u32 index)
{
    u32 bandLimit = sSymbolBandRanges[SYMBOL_SAVE_FindBand(index)].limit;
    u32 *recordBase = records;

    if (index < bandLimit)
        MI_CpuCopy8(recordBase + (index + 1), recordBase + index, (bandLimit - (index + 1)) * 4);
    recordBase[bandLimit - 1] &= 0xfffff800;
}

/*
 * Runs SYMBOL_SAVE_FinalizeChecksum, then SYMBOL_SAVE_FindFreeSlot, then the initialiser, returning
 * the middle result.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SYMBOL_SAVE_RemoveSlotAndFind.c \
 *       --func SYMBOL_SAVE_RemoveSlotAndFind --addr 0x0200E164 --thumb --cc 1.1p1
 */
u32 SYMBOL_SAVE_RemoveSlotAndFind(struct SymbolSave *save, u32 band)
{
    SYMBOL_SAVE_FinalizeChecksum(save);
    {
        u32 found = SYMBOL_SAVE_FindFreeSlot((const struct SymbolRec *)save->records, (int)band);

        SYMBOL_SAVE_UpdateChecksum(save);
        return found;
    }
}

/*
 * notes:    Thumb thunk (ldr r3,[pc]; bx r3) to SYMBOL_SAVE_FindBand; a tail call. Witness for the call in ov010 SYMBOL_MAP_MoveRecordToPairedBand (2026-10-05, lane W-B).
 */
unsigned int SYMBOL_SAVE_FindBandThunk(unsigned int value)
{
    return SYMBOL_SAVE_FindBand(value);
}

/*
 * Runs SYMBOL_SAVE_FinalizeChecksum, then SYMBOL_SAVE_RemoveSlot, then the initialiser.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SYMBOL_SAVE_RemoveSlotAndCommit.c \
 *       --func SYMBOL_SAVE_RemoveSlotAndCommit --addr 0x0200E18C --thumb --cc 1.1p1
 */
void SYMBOL_SAVE_RemoveSlotAndCommit(struct SymbolSave *save, u32 index)
{
    SYMBOL_SAVE_FinalizeChecksum(save);
    SYMBOL_SAVE_RemoveSlot(save->records, index);
    SYMBOL_SAVE_UpdateChecksum(save);
}

/*
 * The record writer of the same two-field table object SYMBOL_SAVE_RemoveSlot walks:
 * it appends (or overwrites) one 32-bit packed record in the ring at
 * obj[slot] and then runs the checksum refresh at SYMBOL_SAVE_UpdateChecksum.
 *
 * The record is six unsigned bitfields in one u32, laid out 11 / 10 / 2 /
 * 6 / 3 from bit 0; the pool masks 0xFFFFF800, 0xFFE007FF, 0xFF9FFFFF,
 * 0xE07FFFFF and 0x1FFFFFFF are the complement of each field in turn, which
 * is what a plain unsigned bitfield store compiles to.  The three `str
 * r2, [r0]` in the middle of the sequence are the statement boundaries: the
 * first three fields fold into one store, the fourth and the fifth each get
 * their own.
 *
 * sSymbolBandRanges is the { u16 first; u16 limit; } record table of
 * src/matched/SYMBOL_SAVE_RemoveSlot.c; this function reads BOTH fields of the same
 * row (a into the stack slot at sp+0xC, b into r7), so the two pool words
 * 0x0209DE90 and 0x0209DE92 are one symbol at two field offsets, not two
 * symbols.  See docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md.
 *
 * The parameter widths are the whole of the codegen here, not a guess: the
 * spill order in the prologue (`str r1, [sp]` and `str r2, [sp, #4]` BEFORE
 * `ldr r4, [sp, #0x30]`, with `str r3, [sp, #8]` after it) only comes out
 * right when a1/a2 are u16 and a3 is u8.  Every wider spelling tried --
 * (u32,u32,u32), (u32,u32,u8), (u16,u16,u32), (int,int,int) -- reproduces
 * all 212 bytes but swaps those two instruction pairs, three or four bytes
 * wrong in the first ten.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SYMBOL_SAVE_WriteRecord.c \
 *       --func SYMBOL_SAVE_WriteRecord --addr 0x0200E1A8 --cc 1.1p1 --thumb
 */
void SYMBOL_SAVE_WriteRecord(struct SymbolSave *save, u16 id, u16 param, u8 flags, u8 category, u8 status, u32 kind)
{
    struct SymbolRec *record;
    u32 bandLimit, bandFirst, freeSlot;
    u32 band;

    SYMBOL_SAVE_FinalizeChecksum(save);
    band = kind;
    bandFirst = sSymbolBandRanges[band].first;
    bandLimit = sSymbolBandRanges[band].limit;
    freeSlot = SYMBOL_SAVE_FindFreeSlot((const struct SymbolRec *)save->records, band);
    if (freeSlot == 0xFFFF) {
        SYMBOL_SAVE_RemoveSlot(save->records, bandFirst);
        record = (struct SymbolRec *)(save->records + (bandLimit - 1));
    } else {
        record = (struct SymbolRec *)(save->records + freeSlot);
    }

    record->id = id;
    record->param = param;
    record->flags = flags;
    record->category = category;
    record->status = status;

    if (band == 2) {
        if (save->kind2Count < 1)
            save->kind2Count++;
    } else if (band == 3) {
        SYMBOL_SAVE_SetRank(save, (u16)freeSlot);
    }
    SYMBOL_SAVE_UpdateChecksum(save);
}

/*
 * Slot-index arithmetic for the 0x84A/u8 table at +0x849: the byte written is
 * `(idx - 0x32) / 0x3c - 1` clamped to 6, and the three guards answer for
 * 0xffff, below 0xaa and above 0x212.  The divide is SIGNED (`_s32_div_f` at
 * 0x0209C0A4) while the two range tests are UNSIGNED, so the index parameter is
 * an `int` and the guards cast it to u32; spelling the parameter u32 instead
 * moves the divide to `_u32_div_f` and loses the site.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SYMBOL_SAVE_SetRank.c \
 *       --func SYMBOL_SAVE_SetRank --addr 0x0200E27C --cc 1.1p1 --thumb
 */
void SYMBOL_SAVE_SetRank(struct SymbolSave *save, int index)
{
    u8 rank = (index - 0x32) / 0x3c - 1;

    if (index == 0xffff) {
        return;
    }
    if ((u32)index < 0xaa) {
        return;
    }
    if ((u32)index > 0x212) {
        return;
    }
    if (rank > 6) {
        rank = 6;
    }
    save->rank = rank;
}

u32 SYMBOL_SAVE_FindRecord(void *saveData, u32 *keyWord, void *heapId, u32 matchMode)
{
    struct SymbolSave *save;
    struct SymbolRec *keyRecord = (struct SymbolRec *)keyWord;
    u32 found = 0;
    s32 slotIndex;
    s32 recordIndex;

    save = GFL_HEAP_Alloc((u32)heapId, 0x850, 1, sFileName_symbol_save, 0x1ac);
    for (slotIndex = 0; slotIndex < 2; slotIndex++) {
        if (SAVE_CONTROL_ReadRecordFromFlash(saveData, 0x3d, slotIndex, save, 0x850) == 1) {
            SYMBOL_SAVE_FinalizeChecksum(save);
            for (recordIndex = 0; recordIndex < 530; recordIndex++) {
                if (matchMode == 1) {
                    if (keyRecord->id != ((struct SymbolRec *)save->records)[recordIndex].id) continue;
                    if (keyRecord->category != ((struct SymbolRec *)save->records)[recordIndex].category) continue;
                    found = 1;
                    break;
                } else {
                    if (GF_STANDARD_CompareBytes(&save->records[recordIndex], keyWord, 4) != 0) continue;
                    found = 1;
                    break;
                }
            }
        }
        if (found == 1) break;
    }
    GFL_HEAP_Free(save);
    return found;
}

int SYMBOL_SAVE_GetBitBlockSize(void)
{
    return 0xa1 * 4;
}

/*
 * Zeroes 0x284 bytes and sets the three trailing descriptor bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SYMBOL_SAVE_InitBitBlock.c \
 *       --func SYMBOL_SAVE_InitBitBlock --addr 0x0200E370 --thumb --cc 1.1p1
 */
void SYMBOL_SAVE_InitBitBlock(struct SymbolBitSave *save)
{
    MI_CpuFill8(save, 0, 0x284);
    save->descriptor[0] = 0;
    save->descriptor[1] = 8;
    save->descriptor[2] = 0x1d;
}

void *SYMBOL_SAVE_GetBitBlock(void *saveData)
{
    return SAVE_CONTROL_GetBlock(saveData, 0x3f);
}

/*
 * Returns the argument plus 0xd2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SYMBOL_SAVE_GetQuestionnaireBits.c \
 *       --func SYMBOL_SAVE_GetQuestionnaireBits --addr 0x0200E3A0 --thumb --cc 1.1p1
 */
u8 *SYMBOL_SAVE_GetQuestionnaireBits(struct SymbolBitSave *save)
{
    return &save->bits[0xd2];
}

/*
 * note:     wave 16: promoted.  0x02167380 and 0x02167358 are unlabelled ov010
 *           leaves matched in src/matched/QUESTIONNAIRE_GetAnswerBitOffset.c and QUESTIONNAIRE_GetAnswerBitWidth.c
 *           (ov010/pkt_02167358); both attest as `matched, overlay`.
 */
u32 SYMBOL_SAVE_ReadBitField(const u8 *bits, int fieldId)
{
    u32 bitPos  = QUESTIONNAIRE_GetAnswerBitOffset(fieldId);
    u32 width    = QUESTIONNAIRE_GetAnswerBitWidth(fieldId);
    u32 byteIndex = bitPos >> 3;
    u32 bitInByte    = bitPos & 7;
    u32 result  = 0;
    u32 i    = 0;

    while (width != 0) {
        result |= (u32)((bits[byteIndex] >> bitInByte) & 1) << i;
        if (++bitInByte > 7) {
            byteIndex++;
            bitInByte = 0;
        }
        i++;
        width--;
    }
    return result;
}

/*
 * note:     wave 16: promoted.  0x02167380 and 0x02167358 are unlabelled ov010
 *           leaves matched in src/matched/QUESTIONNAIRE_GetAnswerBitOffset.c and QUESTIONNAIRE_GetAnswerBitWidth.c
 *           (ov010/pkt_02167358); both attest as `matched, overlay`.
 *
 * near miss resolved (wave 4, permuter): the note's 88-byte version was a
 * six-register permutation away. Two spellings closed it, neither of which
 * the permuter's mutation set can reach (both change the emitted
 * instruction kinds, not the allocation):
 *   - the clear mask is (u8)(0xFFu ^ (1u << b)), which emits
 *     `movs r6,#0xff; eors r6,r7`; the ~ spelling emits a single `mvns`
 *     and is the whole 2-byte size gap.
 *   - inside the wrap test, `byte++` must precede `b = 0`; the reverse
 *     order emits `movs #0` before the `adds` and shifts the allocation.
 */
void SYMBOL_SAVE_WriteBitField(u8 *bits, int fieldId, u32 value)
{
    u32 bitPos = QUESTIONNAIRE_GetAnswerBitOffset(fieldId);
    u32 width   = QUESTIONNAIRE_GetAnswerBitWidth(fieldId);
    u32 byteIndex = bitPos >> 3;
    u32 bitInByte    = bitPos & 7;

    while (width != 0) {
        bits[byteIndex] &= (u8)(0xFFu ^ (1u << bitInByte));
        bits[byteIndex] |= (u8)((value & 1) << bitInByte);
        bitInByte++;
        if (bitInByte > 7) {
            byteIndex++;
            bitInByte = 0;
        }
        value >>= 1;
        width--;
    }
}

void SYMBOL_SAVE_SetBitDescriptor(struct SymbolBitSave *save, int value, int index)
{
    save->descriptor[index] = value;
}
