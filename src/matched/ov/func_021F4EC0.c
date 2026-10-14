/*
 * function: WORLDTRADE_SetStateAndReturn
 * address:  0x021F4EC0
 * packet:   pkt_021F4EC0
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
 * Store two words into the object at +0x14 and +0x20.
 */
#include "../include/Obj00018.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
void WORLDTRADE_SetStateAndReturn(u8 *p, u32 a, u32 b)
{
    ((struct Obj00018 *)p)->f14 = a;
    *(u32 *)&((struct Obj00018 *)p)->f20 = b;
}
