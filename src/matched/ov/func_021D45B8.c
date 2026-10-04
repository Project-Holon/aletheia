/*
 * function: func_021D45B8
 * address:  0x021D45B8
 * packet:   pkt_021D45B8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (hidden in the pool run after func_021D4558).  Setter
 * through d_021F3B88: a special value for b==4, otherwise a plain u32
 * store.
 *
 * symbols:
 *   d_021F3B88  0x021F3B88  data
 */
#include "../include/Obj12142.h"

extern int d_021F3B88;

void func_021D45B8(int a, int b)
{
    if (b == 4) {
        char *q = (char *)d_021F3B88 + 0xbf4 + a * 0xbbc;
        ((struct Obj12142 *)q)->fBB8 = b;
        ((struct Obj12142 *)q)->fBBA = 0;
    } else {
        *(int *)((char *)d_021F3B88 + a * 4 + 0x3af4) = b;
    }
}
