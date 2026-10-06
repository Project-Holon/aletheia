/*
 * function: func_021D6CA8
 * address:  0x021D6CA8
 * packet:   pkt_021D6CA8
 * region:   ov118
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj13881.h"

extern void func_020307B0(void *);

void func_021D6CA8(void *p, int a1)
{
    void *q = ((struct Obj13881 *)p)->f85C;
    if (q != 0) {
        func_020307B0(q);
        ((struct Obj13881 *)p)->f85C = 0;
    }
}
