/*
 * function: func_020365E8
 * address:  0x020365E8
 * packet:   pkt_02036568
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * 36 bytes with no call: the distance from the cursor at p+0x0C to the end of
 * the buffer at p+0x0E, answered from the buffer base at p+4 when the cursor is
 * past the end.
 *
 * The halfword at p+0x0E is read three times in the original (condition, both
 * arms), which is why it is spelled as a field read in each place rather than
 * bound to a local. Spelling all three as plain field reads is not enough on
 * this front end: it CSEs the two arm reads into the condition's register and
 * the function comes out one instruction (4 bytes) short at 32. Declaring the
 * two arm reads `volatile` keeps all three loads, which is the original's shape.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020365E8.c \
 *       --func func_020365E8 --addr 0x020365E8 --cc 1.1p1 --arm
 */
#include "../include/Obj01465.h"

typedef unsigned int u32;

int func_020365E8(char *p, int a1, int a2, int a3)
{
    int a = ((struct Obj01465 *)p)->fC;

    if (a > ((struct Obj01465 *)p)->fE)
        return ((struct Obj01465 *)p)->f4 + *(volatile short *)&((struct Obj01465 *)p)->fE - a;
    return *(volatile short *)&((struct Obj01465 *)p)->fE - a;
}
