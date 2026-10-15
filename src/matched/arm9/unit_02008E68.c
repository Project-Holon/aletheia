/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x02008E68
 * packet:   pkt_02008CF8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: RECORD_SetTrialRank, RECORD_GetTrialRank, RECORD_SetTrialScore, RECORD_GetTrialScore
 *
 * alias: the named entry points on top of the clamped counter layer of
 * src/matched/unit_02008D1C.c and src/matched/unit_02008DAC.c.  Counter 0x7B
 * has a ceiling of 6 and counter 0x7C a ceiling of 9999, and each writer range
 * checks its argument against that ceiling before writing.
 *
 * The ceiling table sub_02008CF8 indexes is at 0x0209DDB4 and is six words:
 * 999999999, 999999, 65535, 9999, 999, 6.  That is what makes the bare 9999
 * here and the 7 in RECORD_SetTrialRank readable.
 *
 * RECORD_GetTrialScore is twelve bytes with no prologue and no label:
 * `ldr r3, [pc, #4]; movs r1, #0x7c; bx r3` over the pool word 0x02008DFD,
 * that is `return RECORD_GetCounterClamped(obj, 0x7C);`.
 *
 * NEAR MISS, 0x02008E30, 56 bytes, MATCH with every concrete byte right,
 * skipped.  It walks a five entry table of counter index pairs at 0x0209DDA0,
 *
 *   1A 1B  51 52  53 54  55 56  57 58
 *
 * copying the value of each pair's second counter into its first through
 * RECORD_RaiseCounter and then zeroing the second with RECORD_SetCounterClamped.  Written as
 *
 *   for (i = 0; i < 5; i++) {
 *       int src = tbl[i].unk02;
 *       RECORD_RaiseCounter(obj, tbl[i].unk00, RECORD_GetCounterClamped(obj, src));
 *       RECORD_SetCounterClamped(obj, src, 0);
 *   }
 *
 * over `struct { u16 unk00; u16 unk02; }` it reproduces all 56 bytes, both
 * loads of the one pool word included, and caps at MATCH on the pool word
 * itself: 0x0209DDA0 is named by exactly one word in the 3.9 MB image, its own
 * at 0x02008E64, so the `literal` class discards its only witness and no cut
 * helps.  `--suggest-split` reports the same and leaves this one function out.
 * It is a table of halfwords, not a string, so the `string` class cannot reach
 * it either.  It closes the day anything else in the image loads 0x0209DDA0.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008E68.c \
 *       --addr 0x02008E68 --thumb
 *
 * symbols:
 *   RECORD_RaiseCounter  0x02008D58  thumb
 *   RECORD_GetCounterClamped  0x02008DFC  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub02008C20Obj;

extern u32 RECORD_RaiseCounter(struct Sub02008C20Obj *obj, int i, u32 limit);
extern u32 RECORD_GetCounterClamped(struct Sub02008C20Obj *obj, int i);

void RECORD_SetTrialRank(struct Sub02008C20Obj *obj, u32 value)
{
    if (value < 7) {
        RECORD_RaiseCounter(obj, 0x7B, value);
    }
}

u8 RECORD_GetTrialRank(struct Sub02008C20Obj *obj)
{
    return RECORD_GetCounterClamped(obj, 0x7B);
}

void RECORD_SetTrialScore(struct Sub02008C20Obj *obj, u32 value)
{
    if (value < 9999) {
        RECORD_RaiseCounter(obj, 0x7C, value);
    }
}

u32 RECORD_GetTrialScore(struct Sub02008C20Obj *obj)
{
    return RECORD_GetCounterClamped(obj, 0x7C);
}
