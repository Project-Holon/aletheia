/*
 * file:     misc_savedata.c
 * unit:     yes
 * function: MISC_SAVEDATA_GetStatusByte, MISC_SAVEDATA_GetHalfword, MISC_SAVEDATA_AddHalfwordClamped, MISC_SAVEDATA_GetTallyWord, MISC_SAVEDATA_GetAnswerMessageOffset, MISC_SAVEDATA_IsTallyFull, MISC_SAVEDATA_GetTallyValue, MISC_SAVEDATA_AddTallyValue, MISC_SAVEDATA_GetScoreValue, MISC_SAVEDATA_FoldTally
 * address:  0x0200E44C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from misc_savedata.c by tools/splitfile.py.
 *
 * symbols:
 *   QUESTIONNAIRE_GetFirstAnswerMessageOffset    0x0216736C  thumb  ov010
 */
#include "misc_savedata_shared_types.h"

typedef struct Tally {
    u16 add16[30];      /* 0x000 */
    u8 add8[150];       /* 0x03C */
    u8 pad[10];         /* 0x0D2 */
    u32 total32[30];    /* 0x0DC */
    u16 total16[150];   /* 0x154 */
} Tally;

extern u8 QUESTIONNAIRE_GetFirstAnswerMessageOffset(u32 id);

int MISC_SAVEDATA_GetStatusByte(int tally, int index);

u16 MISC_SAVEDATA_GetHalfword(const u16 *p, int i);

void MISC_SAVEDATA_AddHalfwordClamped(char *p, int idx, int v);

u32 MISC_SAVEDATA_GetTallyWord(u8 *p, int i);

u32 MISC_SAVEDATA_GetAnswerMessageOffset(u32 fieldId, u32 index);

u32 MISC_SAVEDATA_IsTallyFull(u8 *p, u32 a, u32 count);

u32 MISC_SAVEDATA_GetTallyValue(u8 *tally, u32 fieldId, u32 index);

void MISC_SAVEDATA_AddTallyValue(u8 *tally, u32 fieldId, u32 index, int delta);

int MISC_SAVEDATA_GetScoreValue(int tally, int fieldId, int index);

void MISC_SAVEDATA_FoldTally(Tally *t);

int MISC_SAVEDATA_GetStatusByte(int tally, int index){ return *(unsigned char *)(((tally + index) + ((0xa << 6) << 0))); }

/*
 * Unlabelled Thumb leaf in the ARM9 module: halfword array index.
 *
 * Addresses are Black-image addresses.
 */
u16 MISC_SAVEDATA_GetHalfword(const u16 *array, int index)
{
    return array[index];
}

void MISC_SAVEDATA_AddHalfwordClamped(char *tally, int index, int delta)
{
    unsigned short *cell = (unsigned short *)(tally + index * 2);
    *cell = *cell + (unsigned short)delta;
    if (*cell > 0x270f)
        *cell = 0x270f;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module: word array at +0xDC, index i.
 * Filed by wave D4 lane 12 (blocked ov217 RESEARCH_GRAPH_BuildGraphTable).
 *
 * Addresses are Black-image addresses.
 */
u32 MISC_SAVEDATA_GetTallyWord(u8 *tally, int index)
{
    return *(u32 *)(tally + index * 4 + 0xdc);
}

/*
 * note:     wave 16: promoted.  0x0216736C is the unlabelled ov010 leaf matched
 *           in src/matched/QUESTIONNAIRE_GetFirstAnswerMessageOffset.c (ov010/pkt_02167358); it attests as
 *           `matched, overlay` under the ov010 hint.  The source shape that
 *           works: a1-1 must be a named local computed before the call;
 *           writing `f(a0) + (a1 - 1)` gives `adds r0, r1, r0` instead of
 *           `adds r0, r0, r1`.
 */
u32 MISC_SAVEDATA_GetAnswerMessageOffset(u32 fieldId, u32 index)
{
    u32 offset = index - 1;
    u32 base = QUESTIONNAIRE_GetFirstAnswerMessageOffset((u8)fieldId);

    return base + offset;
}

/*
 * Returns 1 when MISC_SAVEDATA_GetTallyValue's result is 0x63 or more, else 0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MISC_SAVEDATA_IsTallyFull.c \
 *       --func MISC_SAVEDATA_IsTallyFull --addr 0x0200E49C --thumb --cc 1.1p1
 */
u32 MISC_SAVEDATA_IsTallyFull(u8 *tally, u32 fieldId, u32 index)
{
    return MISC_SAVEDATA_GetTallyValue(tally, fieldId, index) >= 0x63 ? 1 : 0;
}

u32 MISC_SAVEDATA_GetTallyValue(u8 *tally, u32 fieldId, u32 index)
{
    if (index == 0)
        return 0;
    return *(tally + MISC_SAVEDATA_GetAnswerMessageOffset(fieldId, index) + 0x3c);
}

/*
 * Two tells on the source, both four bytes each.  The base has to be taken as
 * a pointer (`p = a0 + 0x3c` then `p[off]`) rather than as one subscript
 * `a0[off + 0x3c]`: the original adds the 0x3c to the object pointer and then
 * indexes off against that, not the other way round.  And the guard is
 * written `a3 + v`, not `v + a3`: the add is commutative but this front end
 * keeps the source order in the encoding, and `v + a3` emits `adds r1, r2,
 * r4` where the original has `adds r1, r4, r2`.  The fourth parameter is
 * signed (the guard is `ble`, not `bls`).
 */
void MISC_SAVEDATA_AddTallyValue(u8 *tally, u32 fieldId, u32 index, int delta)
{
    u8 *base;
    u32 offset;
    u8 value;

    if (index == 0)
        return;
    offset = MISC_SAVEDATA_GetAnswerMessageOffset(fieldId, index);
    base = tally + 0x3c;
    value = base[offset];
    if (delta + value > 0x63) {
        base[offset] = 0x63;
        return;
    }
    base[offset] = value + (u8)delta;
}

int MISC_SAVEDATA_GetScoreValue(int tally, int fieldId, int index){ int offset; if ((unsigned int)(index) == (unsigned int)(0)) {  return 0; } else { offset = MISC_SAVEDATA_GetAnswerMessageOffset((int)(fieldId + 0), (int)(index + 0)); return *(unsigned short *)(((char *)(((tally + 0) + (offset << 1))) + ((int)((0x55 << 2)) << 0))); } }

/*
 * Folds two arrays of pending increments into their saturating totals and
 * clears the increments: 30 u16 into u32 totals capped at 999999, then 150
 * u8 into u16 totals capped at 9999.  Seeded in layout/function_starts.txt
 * from its only caller, the bl at ov010 0x02169056 (w6_fix18).
 */
void MISC_SAVEDATA_FoldTally(Tally *tally)
{
    int i;

    for (i = 0; i < 30; i++) {
        tally->total32[i] += tally->add16[i];
        if (tally->total32[i] > 999999) {
            tally->total32[i] = 999999;
        }
        tally->add16[i] = 0;
    }
    for (i = 0; i < 150; i++) {
        tally->total16[i] += tally->add8[i];
        if (tally->total16[i] > 9999) {
            tally->total16[i] = 9999;
        }
        tally->add8[i] = 0;
    }
}
