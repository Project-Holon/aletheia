/*
 * unit:     no
 * function: ISS_SWITCH_Setup
 * address:  0x0202C550
 * packet:   pkt_0202C4CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * One pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md), split out of the
 * nine-trampoline run in src/pending/unit_0202C548.c so that the matched
 * class has a witness at this address: sub_0202C3E0's call site needs it,
 * and the callee ISS_SWITCH_SetParam is EXACT (src/matched/sub_0202C5C4.c).
 * Same move as sub_0202C4D8.c and unit_0202C510.c for their sibling units.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_Setup.c \
 *       --func ISS_SWITCH_Setup --addr 0x0202C550 --cc 1.1p1 --thumb
 *
 * symbols:
 *   ISS_SWITCH_SetParam  0x0202C5C4  thumb
 */

typedef unsigned int u32;

extern u32 ISS_SWITCH_SetParam(void *p, u32 a, u32 b);

u32 ISS_SWITCH_Setup(void *p, u32 a, u32 b)
{
    return ISS_SWITCH_SetParam(p, a, b);
}
