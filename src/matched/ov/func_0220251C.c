/*
 * function: func_0220251C
 * address:  0x0220251C
 * packet:   pkt_0220251C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 *
 * Store a pair of u16 values at +0xe0c and +0xe0e.
 */
#include "../include/Obj00018.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void func_0220251C(u8 *p, u16 a, u16 b)
{
    ((struct Obj00018 *)p)->fE0C = a;
    ((struct Obj00018 *)p)->fE0E = b;
}
