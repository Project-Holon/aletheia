/*
 * function: WORLDTRADE_AdvanceScreenId
 * address:  0x021F4EC8
 * packet:   pkt_021F4EC8
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
 * Save the current value at +0x10 into +0x1c and move +0x14 down into +0x10.
 */
#include "../include/Obj00287.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
void WORLDTRADE_AdvanceScreenId(u8 *p)
{
    ((struct Obj00287 *)p)->f1C = ((struct Obj00287 *)p)->f10;
    ((struct Obj00287 *)p)->f10 = ((struct Obj00287 *)p)->f14;
}
