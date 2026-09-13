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
 * function: sub_02008DAC, sub_02008DF0, sub_02008DFC
 *
 * alias: the second half of the clamped read-modify-write layer over the save
 * block with id 0x26; see src/matched/unit_02008D1C.c for the cut.
 *
 * sub_02008DF0 is twelve bytes with no prologue and carries no label in the
 * listing: `ldr r3, [pc, #4]; movs r2, #1; bx r3` plus the pool word
 * 0x02008DAD.  That is `return sub_02008DAC(obj, i, 1);`, the increment-by-one
 * spelling of the function above it, and it is `local` to this range because
 * sub_02008DAC is in it.
 *
 * The one byte that had to be found: `adds r2, r0, r7` in sub_02008DAC is the
 * counter plus the delta with the *call result* in the left slot, and that
 * only happens when a named local holds it.  Written inline in either operand
 * order, `sub_02008CB4(obj, i) + delta` and `delta + sub_02008CB4(obj, i)`
 * both give `adds r2, r7, r0`.  See
 * docs/idioms/commutative-operand-order-names-the-temporary.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008DAC.c \
 *       --addr 0x02008DAC --thumb
 */

typedef unsigned int u32;

struct Sub02008C20Obj;

extern u32  sub_02008CF8(int i);
extern void sub_02008C64(struct Sub02008C20Obj *obj, int i);
extern void sub_02008C94(struct Sub02008C20Obj *obj, int i);
extern u32  sub_02008CB4(struct Sub02008C20Obj *obj, int i);
extern u32  sub_02008CD4(struct Sub02008C20Obj *obj, int i, u32 value);

u32 sub_02008DAC(struct Sub02008C20Obj *obj, int i, u32 delta);

u32 sub_02008DAC(struct Sub02008C20Obj *obj, int i, u32 delta)
{
    u32 max = sub_02008CF8(i);
    u32 result;
    u32 cur;

    sub_02008C94(obj, i);
    cur = sub_02008CB4(obj, i);
    result = cur + delta;
    if (result < max) {
        result = sub_02008CD4(obj, i, result);
    } else {
        result = sub_02008CD4(obj, i, max);
    }
    sub_02008C64(obj, i);
    return result;
}

u32 sub_02008DF0(struct Sub02008C20Obj *obj, int i)
{
    return sub_02008DAC(obj, i, 1);
}

u32 sub_02008DFC(struct Sub02008C20Obj *obj, int i)
{
    u32 max = sub_02008CF8(i);
    u32 result;

    sub_02008C94(obj, i);
    result = sub_02008CB4(obj, i);
    sub_02008C64(obj, i);
    if (result <= max) {
        max = result;
    }
    return max;
}
