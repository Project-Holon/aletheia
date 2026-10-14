/*
 * function: CircleGraph_TickHold
 * address:  0x021C16C4
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Count the u32 at +0x18 down to zero, clearing the u32 at +0x14 when it reaches it.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04640.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void CircleGraph_TickHold(void *p)
{
    u32 v;
    if (((struct Obj04640 *)p)->f14 == 0)
        return;
    if (((struct Obj04640 *)p)->f18 == 0)
        return;
    v = ((struct Obj04640 *)p)->f18 - 1;
    ((struct Obj04640 *)p)->f18 = v;
    if (v == 0)
        ((struct Obj04640 *)p)->f14 = 0;
}
