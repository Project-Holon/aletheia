/*
 * function: func_021FEB50
 * address:  0x021FEB50
 * packet:   pkt_021FEB50
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 * When the countdown at +0xd3c is spent, run the fixed 3/6/1/0x48 opener, then state 0.
 */
#include "../include/Obj12213.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);

int func_021FEB50(u8 *p)
{
    if (((struct Obj12213 *)p)->fD3C == 0) {
        func_0202208C((void *)3, 0, 0, 0, 6, 1, 0x48);
    }
    ((struct Obj12213 *)p)->f28 = 0;
    return 3;
}
