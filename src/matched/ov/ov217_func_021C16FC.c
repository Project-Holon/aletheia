/*
 * function: CircleGraph_SetState
 * address:  0x021C16FC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Set +8 and clear +0x10.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04641.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void *CircleGraph_SetState(void *p, u32 v)
{
    ((struct Obj04641 *)p)->f8 = v;
    ((struct Obj04641 *)p)->f10 = 0;
    return p;
}
