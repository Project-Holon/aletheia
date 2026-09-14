/*
 * function: sub_0207C768
 * address:  0x0207C768
 * packet:   pkt_0207C768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_0207C930   0x0207C930  arm
 *   sub_0207C86C   0x0207C86C  arm
 *
 * Start the hardware unit through sub_0207C930 with the caller's two
 * operands, then block on it and return its result through sub_0207C86C.
 * Both arguments reach sub_0207C930 as leftovers in r0/r1; nothing is
 * spent setting them up
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0207C768.c \
 *       --func sub_0207C768 --addr 0x0207C768 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void sub_0207C930(u32 a, u32 b);
extern u32  sub_0207C86C(void);

u32 sub_0207C768(u32 a, u32 b)
{
    sub_0207C930(a, b);
    return sub_0207C86C();
}
