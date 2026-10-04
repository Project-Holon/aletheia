/*
 * function: func_0220B2F8
 * address:  0x0220B2F8
 * packet:   pkt_0220B2F8
 * region:   ov207
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02040588 0x02040588 arm
 */
#include "../include/Obj14641.h"

typedef unsigned int   u32;
extern void func_02040588(u32 which, u32 enable);

void func_0220B2F8(int unused, char *p)
{
    if (((struct Obj14641 *)p)->f2C != 0)
    {
        func_02040588(0, 0);
        func_02040588(2, 0);
        ((struct Obj14641 *)p)->f2C = 0;
    }
}
