/*
 * function: WORLDTRADE_SetNextState
 * address:  0x021F4E98
 * packet:   pkt_021F4E98
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *

 *
 * Store two words into the object at +0x28 and +0x2c.
 */
#include "../include/Obj00018.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
void WORLDTRADE_SetNextState(u8 *p, u32 a, u32 b)
{
    ((struct Obj00018 *)p)->f28 = a;
    ((struct Obj00018 *)p)->f2C = b;
}
