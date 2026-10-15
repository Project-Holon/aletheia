/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x02008DAC
 * packet:   pkt_02008CF8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: RECORD_AddCounter, RECORD_AddOne, RECORD_GetCounterClamped
 *
 * alias: the second half of the clamped read-modify-write layer over the save
 * block with id 0x26; see src/matched/unit_02008D1C.c for the cut.
 *
 * RECORD_AddOne is twelve bytes with no prologue and carries no label in the
 * listing: `ldr r3, [pc, #4]; movs r2, #1; bx r3` plus the pool word
 * 0x02008DAD.  That is `return RECORD_AddCounter(obj, i, 1);`, the increment-by-one
 * spelling of the function above it, and it is `local` to this range because
 * RECORD_AddCounter is in it.
 *
 * The one byte that had to be found: `adds r2, r0, r7` in RECORD_AddCounter is the
 * counter plus the delta with the *call result* in the left slot, and that
 * only happens when a named local holds it.  Written inline in either operand
 * order, `RECORD_GetCounter(obj, i) + delta` and `delta + RECORD_GetCounter(obj, i)`
 * both give `adds r2, r7, r0`.  See
 * docs/idioms/commutative-operand-order-names-the-temporary.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008DAC.c \
 *       --addr 0x02008DAC --thumb
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

u32 RECORD_AddCounter(struct Sub02008C20Obj *obj, int i, u32 delta);

u32 RECORD_AddCounter(struct Sub02008C20Obj *obj, int i, u32 delta)
{
    u32 max = sub_02008CF8(i);
    u32 result;
    u32 cur;

    RECORD_Unseal(obj, i);
    cur = RECORD_GetCounter(obj, i);
    result = cur + delta;
    if (result < max) {
        result = RECORD_SetCounter(obj, i, result);
    } else {
        result = RECORD_SetCounter(obj, i, max);
    }
    RECORD_Seal(obj, i);
    return result;
}

u32 RECORD_AddOne(struct Sub02008C20Obj *obj, int i)
{
    return RECORD_AddCounter(obj, i, 1);
}

u32 RECORD_GetCounterClamped(struct Sub02008C20Obj *obj, int i)
{
    u32 max = sub_02008CF8(i);
    u32 result;

    RECORD_Unseal(obj, i);
    result = RECORD_GetCounter(obj, i);
    RECORD_Seal(obj, i);
    if (result <= max) {
        max = result;
    }
    return max;
}
