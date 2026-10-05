/*
 * function: func_022007A0
 * address:  0x022007A0
 * packet:   pkt_022007A0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *

 * One of the two fixed 0/3 openers, then state 0.
 */
#include "../include/Obj12229.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);

int func_022007A0(u8 *p)
{
    if (((struct Obj12229 *)p)->f14 == 0) {
        func_0202208C(0, 0, 0, 0, 6, 1, 0x48);
    } else {
        func_0202208C((void *)3, 0, 0, 0, 6, 1, 0x48);
    }
    ((struct Obj12229 *)p)->f28 = 0;
    return 3;
}
