/*
 * function: sub_020353B0
 * address:  0x020353B0
 * packet:   pkt_020353B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203568C  0x0203568C  arm
 *
 * The "is the lid state low enough to keep running" predicate: normalise
 * func_0203568C's level to a boolean at the threshold 2.  Written as a
 * signed compare, so the two constant arms come out as movle/movgt off one
 * `cmp r0, #2` instead of a branch.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020353B0.c \n *       --func sub_020353B0 --addr 0x020353B0 --cc 1.1p1 --arm
 */

extern int func_0203568C(void);

int sub_020353B0(void)
{
    return func_0203568C() <= 2;
}
