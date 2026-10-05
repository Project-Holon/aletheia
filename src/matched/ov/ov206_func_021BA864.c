/*
 * function: func_021BA864
 * address:  0x021BA864
 * packet:   pkt_021BA864
 * region:   ov206
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02041EE4 0x02041EE4 arm
 */
#include "../include/Obj08387.h"

typedef unsigned int   u32;
extern void func_02041EE4(u32 index, u32 a, u32 b);

void func_021BA864(int unused, char *p)
{
    if (((struct Obj08387 *)p)->f39 & 1)
    {
        func_02041EE4(((struct Obj08387 *)p)->f4E, 1, 1);
    }
    ((struct Obj08387 *)p)->f38 = 0;
    ((struct Obj08387 *)p)->f39 = 0;
}
