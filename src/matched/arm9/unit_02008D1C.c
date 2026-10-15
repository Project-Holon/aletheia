/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x02008D1C
 * packet:   pkt_02008CF8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: RECORD_SetCounterClamped, RECORD_RaiseCounter
 *
 * alias: the first half of the clamped read-modify-write layer over the save
 * block with id 0x26 (src/matched/unit_02008C58.c).  Each of these takes the
 * block and a counter index, looks the counter's ceiling up with
 * sub_02008CF8, unlocks the block with RECORD_Unseal, writes through
 * RECORD_SetCounter and re-checksums with RECORD_Seal.
 *
 * The cut at 0x02008DAC is the one the header of unit_02008C58.c recorded as
 * viable: sub_02008CF8, RECORD_Seal, RECORD_Unseal, RECORD_GetCounter and
 * RECORD_SetCounter are each called from both halves, so each half is the other's
 * outside witness and no site is left without one.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008D1C.c \
 *       --addr 0x02008D1C --thumb
 *
 * symbols:
 *   RECORD_Seal  0x02008C64  thumb
 *   RECORD_Unseal  0x02008C94  thumb
 *   RECORD_GetCounter  0x02008CB4  thumb
 *   RECORD_SetCounter  0x02008CD4  thumb
 */

typedef unsigned int u32;

struct Sub02008C20Obj;

extern int sub_02008CF8(int idx);
extern void RECORD_Seal(struct Sub02008C20Obj *obj, int i);
extern void RECORD_Unseal(struct Sub02008C20Obj *obj, int i);
extern u32 RECORD_GetCounter(const struct Sub02008C20Obj *obj, int i);
extern u32  RECORD_SetCounter(struct Sub02008C20Obj *obj, int i, u32 value);

u32 RECORD_SetCounterClamped(struct Sub02008C20Obj *obj, int i, u32 value)
{
    u32 max = sub_02008CF8(i);
    u32 result;

    RECORD_Unseal(obj, i);
    if (value < max) {
        result = RECORD_SetCounter(obj, i, value);
    } else {
        result = RECORD_SetCounter(obj, i, max);
    }
    RECORD_Seal(obj, i);
    return result;
}

u32 RECORD_RaiseCounter(struct Sub02008C20Obj *obj, int i, u32 limit)
{
    u32 max = sub_02008CF8(i);
    u32 result;

    RECORD_Unseal(obj, i);
    result = RECORD_GetCounter(obj, i);
    if (limit > max) {
        limit = max;
    }
    if (result < limit) {
        result = RECORD_SetCounter(obj, i, limit);
    } else if (result > max) {
        result = RECORD_SetCounter(obj, i, max);
    }
    RECORD_Seal(obj, i);
    return result;
}
