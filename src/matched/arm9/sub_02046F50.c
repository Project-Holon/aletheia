/*
 * function: G3D_SYSTEM_CheckResourceType
 * address:  0x02046F50
 * packet:   pkt_02046EFC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A five-way predicate over the halfword at +2: the second argument picks
 * which set of values counts as a hit.  The dispatch is the ARM dense-switch
 * form, `addls pc, pc, r1, lsl #2` over four `b`s with the default reached by
 * the `b` that falls out of the bounds test, so the cases really are 0 to 3
 * with nothing missing (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md
 * is the Thumb form of the same tell).
 *
 * Case 1 is a range test written as one in the source, not a disjunction:
 * this front end does not fold `v == 1 || v == 2` into a range, it emits the
 * `cmp`/`cmpne` pair that cases 2 and 3 show.  The `lsl #16`/`lsr #16`
 * narrowing and the unsigned `cmp #1` are likewise spelled in the C.
 *
 * The bias is written `+ 0xFFFF`, not `- 1`.  Both mean the same thing after
 * the halfword narrowing, but `- 1` compiles to a single `sub r0, r0, #1`
 * and `+ 0xFFFF` to the pair `add r0, r0, #0xff` / `add r0, r0, #0xff00`,
 * because 0xFFFF is not an ARM rotated immediate and splits into two that
 * are.  Four bytes, and the only thing that separates the two readings.  See
 * docs/idioms/a-plus-0xffff-bias-is-two-adds-and-a-minus-one-is-one-sub.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02046F50.c \
 *       --func G3D_SYSTEM_CheckResourceType --addr 0x02046F50 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Tagged {
    u16 tag;
    u16 kind;
};

u32 G3D_SYSTEM_CheckResourceType(struct Tagged *p, u32 sel)
{
    u16 v = p->kind;

    switch (sel) {
    case 0:
        return v == 0;
    case 1:
        return (u16)(v + 0xFFFF) <= 1;
    case 2:
        return v == 1 || v == 3;
    case 3:
        return v == 4;
    }
    return 0;
}
