/*
 * file:     record.c
 * unit:     yes
 * function: RECORD_GetSize, RECORD_Init, RECORD_GetFromSave, RECORD_Seal, RECORD_Unseal, RECORD_GetCounter, RECORD_SetCounter, RECORD_GetCeiling, RECORD_SetCounterClamped, RECORD_RaiseCounter, RECORD_AddCounter, RECORD_AddOne, RECORD_GetCounterClamped, RECORD_FoldPairs, RECORD_SetTrialRank, RECORD_GetTrialRank, RECORD_SetTrialScore, RECORD_GetTrialScore
 * address:  0x02008C20
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from mail.c by tools/splitfile.py.
 *
 * symbols:
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 *   MIi_CpuClear32  0x02082A7C  arm
 *   GF_STANDARD_Checksum  0x0203F2FC  arm
 *   GF_STANDARD_XorCrypt  0x0203F328  arm
 *   GF_STANDARD_XorCryptEx  0x0203F37C  arm
 *   RECORD_CeilingRowTable      0x020A70C4  data
 *   RECORD_CeilingTable      0x0209DDB4  data
 *   RECORD_FoldPairTable      0x0209DDA0  data
 */
#include "trcard_sign_shared_types.h"

/* Word the ARM7 keeps current in the shared region (the VBlank counter). */
#define SHARED_VBLANK_COUNT (*(volatile u32 *)0x02FFFC3C)

#define SAVE_BLOCK_RECORD                 0x26

/* ---- Save block 0x26: counters with ceilings, sealed by a checksum (0x1E0) ---- */
#include "record_types.h"

/* Counter pair: the source counter is folded into the target and cleared. */
struct CounterPair {
    u16 target;
    u16 source;
};

extern void MIi_CpuClear32(u32 value, void *dest, u32 size);

extern void *SAVE_CONTROL_GetBlock(struct SaveControl *control, u32 blockId);

/* The checksum pair over a byte range: GF_STANDARD_Checksum computes it, GF_STANDARD_XorCrypt
 * encodes the range with a key, GF_STANDARD_XorCryptEx decodes it again. */
extern u32 GF_STANDARD_Checksum(const u8 *data, u32 length);

extern void GF_STANDARD_XorCrypt(u16 *data, u32 size, u32 key);

extern void GF_STANDARD_XorCryptEx(void *data, u32 size, u32 key);

extern unsigned char RECORD_CeilingRowTable[];

extern int RECORD_CeilingTable[];

extern struct CounterPair RECORD_FoldPairTable[5];

void RECORD_Seal(struct RecordBlock *record, int enable);

/*
 * Save block 0x26, 0x1E0 bytes: a flat table of counters with two element
 * widths and its own checksum.
 *
 *   +0x000  u32[0x47]   counters 0x00..0x46
 *   +0x11C  u16[0x60]   counters 0x47..0xA6
 *   +0x1DC  u16         checksum over +4..+0x1DC (0x1D8 bytes)
 *   +0x1DE  u16         high half of the key that seals the range
 *
 * The seal key is checksum + (cryptSeed << 16), added not or-ed (the image
 * uses adds).  RECORD_Seal stores the checksum and encodes the range with
 * the key; RECORD_Unseal decodes it again.  RECORD_GetCounter and RECORD_SetCounter read
 * and write the split index space; both answer 0 for an index of 0xA7 or more.
 * The setter returns what the getter would, through a real call.
 *
 * 0x1E0 has no Thumb immediate, so the size is built as movs 0x1E / lsls 4.
 */
u32 RECORD_GetSize(void)
{
    return sizeof(struct RecordBlock);
}

/*
 * The block constructor: wipes 0x1E0 bytes, seeds the key from the shared
 * VBlank word (read twice, so the 0x02FFFC3C constant is volatile, and
 * combined as first << 8 | second with two named u32 locals, which puts the
 * pool address in r1 and the first value in r0 as the original does), then
 * seals the block.
 */
void RECORD_Init(struct RecordBlock *record)
{
    u32 first;
    u32 second;

    MIi_CpuClear32(0, record, sizeof(struct RecordBlock));
    first = SHARED_VBLANK_COUNT;
    second = SHARED_VBLANK_COUNT;
    record->cryptSeed = first << 8 | second;
    RECORD_Seal(record, 1);
}

struct RecordBlock *RECORD_GetFromSave(struct SaveControl *control)
{
    return SAVE_CONTROL_GetBlock(control, SAVE_BLOCK_RECORD);
}

/* Store the checksum and encode the counters.  Callers below pass the counter
 * index as `enable`, so nothing happens for counter 0. */
void RECORD_Seal(struct RecordBlock *record, int enable)
{
    if (enable) {
        record->checksum = GF_STANDARD_Checksum((const u8 *)(&record->wordCounters[1]),
                                        0x1D8);
        GF_STANDARD_XorCrypt((u16 *)(&record->wordCounters[1]), 0x1D8,
                     record->checksum + (record->cryptSeed << 16));
    }
}

/* Decode the counters. */
void RECORD_Unseal(struct RecordBlock *record, int enable)
{
    if (enable) {
        GF_STANDARD_XorCryptEx(&record->wordCounters[1], 0x1D8,
                     record->checksum + (record->cryptSeed << 16));
    }
}

u32 RECORD_GetCounter(const struct RecordBlock *record, int index)
{
    if (index < 0x47) {
        return record->wordCounters[index];
    }
    if (index < 0xA7) {
        return record->halfCounters[index - 0x47];
    }
    return 0;
}

u32 RECORD_SetCounter(struct RecordBlock *record, int index, u32 value)
{
    if (index < 0x47) {
        record->wordCounters[index] = value;
    } else if (index < 0xA7) {
        record->halfCounters[index - 0x47] = value;
    }
    return RECORD_GetCounter(record, index);
}

/*
 * The ceiling of counter `index`.  RECORD_CeilingRowTable maps a counter to a row of the
 * ceiling table RECORD_CeilingTable (999999999, 999999, 65535, 9999, 999, 6); an index
 * of 0xA7 or more, or a row of 6 or more, has no ceiling and gives 0.
 */
int RECORD_GetCeiling(int index)
{
    int row = RECORD_CeilingRowTable[index];

    if (row >= 0xa7) return 0;
    if (row >= 6) return 0;
    return RECORD_CeilingTable[row];
}

/*
 * Clamped read-modify-write layer over the block.  Each function takes the
 * block and a counter index, looks up the ceiling with RECORD_GetCeiling, decodes
 * with RECORD_Unseal, writes through RECORD_SetCounter and re-seals with
 * RECORD_Seal.
 */

/* Set the counter to `value`, at most the ceiling. */
u32 RECORD_SetCounterClamped(struct RecordBlock *record, int index, u32 value)
{
    u32 ceiling = RECORD_GetCeiling(index);
    u32 result;

    RECORD_Unseal(record, index);
    if (value < ceiling) {
        result = RECORD_SetCounter(record, index, value);
    } else {
        result = RECORD_SetCounter(record, index, ceiling);
    }
    RECORD_Seal(record, index);
    return result;
}

/* Raise the counter to `minimum` (itself clamped to the ceiling); a counter
 * already above the ceiling is lowered to it. */
u32 RECORD_RaiseCounter(struct RecordBlock *record, int index, u32 minimum)
{
    u32 ceiling = RECORD_GetCeiling(index);
    u32 result;

    RECORD_Unseal(record, index);
    result = RECORD_GetCounter(record, index);
    if (minimum > ceiling) {
        minimum = ceiling;
    }
    if (result < minimum) {
        result = RECORD_SetCounter(record, index, minimum);
    } else if (result > ceiling) {
        result = RECORD_SetCounter(record, index, ceiling);
    }
    RECORD_Seal(record, index);
    return result;
}

/* Add `delta`, at most the ceiling.  The sum needs a named local: written
 * inline in either operand order the compiler emits adds r2, r7, r0 instead
 * of adds r2, r0, r7
 * (docs/idioms/commutative-operand-order-names-the-temporary.md). */
u32 RECORD_AddCounter(struct RecordBlock *record, int index, u32 delta)
{
    u32 ceiling = RECORD_GetCeiling(index);
    u32 result;
    u32 current;

    RECORD_Unseal(record, index);
    current = RECORD_GetCounter(record, index);
    result = current + delta;
    if (result < ceiling) {
        result = RECORD_SetCounter(record, index, result);
    } else {
        result = RECORD_SetCounter(record, index, ceiling);
    }
    RECORD_Seal(record, index);
    return result;
}

/* Add one: twelve bytes, no label. */
u32 RECORD_AddOne(struct RecordBlock *record, int index)
{
    return RECORD_AddCounter(record, index, 1);
}

/* Read the counter, at most the ceiling. */
u32 RECORD_GetCounterClamped(struct RecordBlock *record, int index)
{
    u32 ceiling = RECORD_GetCeiling(index);
    u32 result;

    RECORD_Unseal(record, index);
    result = RECORD_GetCounter(record, index);
    RECORD_Seal(record, index);
    if (result <= ceiling) {
        ceiling = result;
    }
    return ceiling;
}

/* Fold each pair of the table RECORD_FoldPairTable (1A 1B, 51 52, 53 54, 55 56,
 * 57 58): raise the target to the source's value, then clear the source.
 * The table is read as halfwords, so no string witness can attest its
 * address. */
void RECORD_FoldPairs(struct RecordBlock *record)
{
    u32 i;

    for (i = 0; i < 5; i++) {
        u16 source = RECORD_FoldPairTable[i].source;

        RECORD_RaiseCounter(record, RECORD_FoldPairTable[i].target,
                     RECORD_GetCounterClamped(record, source));
        RECORD_SetCounterClamped(record, source, 0);
    }
}

/* Counter 0x7B has a ceiling of 6 and counter 0x7C one of 9999; the writers
 * check their argument against that ceiling first.  Counter 0x7B is the Trial
 * House rank and 0x7C its score (callers: trial_house, trcard_sys). */
void RECORD_SetTrialRank(struct RecordBlock *record, u32 rank)
{
    if (rank < 7) {
        RECORD_RaiseCounter(record, 0x7B, rank);
    }
}

u8 RECORD_GetTrialRank(struct RecordBlock *record)
{
    return RECORD_GetCounterClamped(record, 0x7B);
}

void RECORD_SetTrialScore(struct RecordBlock *record, u32 score)
{
    if (score < 9999) {
        RECORD_RaiseCounter(record, 0x7C, score);
    }
}

/* Twelve bytes, no label. */
u32 RECORD_GetTrialScore(struct RecordBlock *record)
{
    return RECORD_GetCounterClamped(record, 0x7C);
}
