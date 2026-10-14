/*
 * function: CircleGraph_ClearSlices
 * address:  0x021C1704
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
 *   RingQueue_Reset  0x021C0E5C  thumb  ov217
 *   CircleGraph_SetState  0x021C16FC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00554.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 RingQueue_Reset();
extern void *CircleGraph_SetState(void *p, u32 v);
u32 CircleGraph_ClearSlices(void *a0)
{
    ((struct Obj00554 *)(((u8*)a0)))->f1AC = 0;
    RingQueue_Reset(((struct Obj00554 *)(((u8*)a0)))->fC);
    return (u32)CircleGraph_SetState(a0, 0);
}

