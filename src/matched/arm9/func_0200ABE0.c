/*
 * function: IRC_RANKING_HasEntryByTrainerId
 * address:  0x0200ABE0
 * packet:   pkt_0200A940
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The comparison has to be written with the *caller's* object on the left
 * (`*(u32 *)(b + 0x14) == *(u32 *)(p + 0x14)`): both sides are loads, and the
 * one the source names first is the one that lands in `cmp`'s left slot, so
 * swapping them is one byte (`cmp r2, r5` against `cmp r5, r2`).  Leaving the
 * invariant load in the condition rather than hoisting it into a local is
 * also load-bearing: as a local it is materialised before the `n <= 0` guard
 * and the entry test moves.  EXACT*: the 2-byte linker filler at 0x0200AC12
 * is inside the packet but the listing extent runs to the next label.
 */
#include "../include/Obj11230.h"
#include "../include/Obj15588.h"

typedef unsigned char u8;
typedef unsigned int  u32;

int IRC_RANKING_HasEntryByTrainerId(u8 *a0, int n, u8 *b)
{
    int i;

    for (i = 0; i < n; i++) {
        u8 *p = a0 + i * 0x1c;

        if (((struct Obj15588 *)b)->f14 == ((struct Obj11230 *)p)->f14 && ((struct Obj11230 *)p)->f10 >> 31 == 1)
            return 1;
    }
    return 0;
}
