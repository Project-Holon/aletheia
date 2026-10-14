/*
 * function: CircleGraph_UpdateErase
 * address:  0x021C1648
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   CircleGraph_SetState  0x021C16FC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04641.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void *CircleGraph_SetState(void *p, u32 v);
void CircleGraph_UpdateErase(u8 *a0)
{
    if (((struct Obj04641 *)(((u8*)a0)))->f10 >= 20) {
    CircleGraph_SetState(a0, 0);
    }
}

