/*
 * unit:     no
 * address:  0x020222CC
 * packet:   pkt_02022174
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_020222CC
 *
 * symbols:
 *   func_0207D534  0x0207D534  arm
 *
 * Selects one of two hardware register addresses (0x0400006C, 0x0400106C:
 * the two DS display engines' BLDCNT-adjacent blend registers) from its
 * first argument and passes it straight to func_0207D534.  The second
 * argument is never read: every caller in this packet passes a colour
 * value here that this function ignores entirely
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-
 * leftovers.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020222CC.c \
 *       --func func_020222CC --addr 0x020222CC --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern void func_0207D534(u32 addr);

void func_020222CC(u32 which, u32 unused)
{
    if (which == 0) {
        func_0207D534(0x0400006C);
    } else {
        func_0207D534(0x0400106C);
    }
}
