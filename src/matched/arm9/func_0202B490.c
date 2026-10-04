/*
 * function: func_0202B490
 * address:  0x0202B490
 * packet:   pkt_0202B1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears the object's active word when it is set.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B490.c \
 *       --func func_0202B490 --addr 0x0202B490 --thumb --cc 1.1p1
 */
#include "../include/Obj11315.h"

typedef unsigned char u8;
typedef unsigned int  u32;

void func_0202B490(u8 *p)
{
    if (((struct Obj11315 *)p)->fC != 0) {
        ((struct Obj11315 *)p)->fC = 0;
    }
}
