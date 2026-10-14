/*
 * function: CircleGraph_NextCommand
 * address:  0x021C16E8
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing.
 *
 * symbols:
 *   RingQueue_Pop  0x021C0E54  thumb  ov217
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

struct Ring;
extern u32 RingQueue_Pop(struct Ring *r);
extern void *CircleGraph_SetState(void *p, u32 v);
void CircleGraph_NextCommand(u32 a0)
{
    CircleGraph_SetState((void *)(a0 + 0 + 0), RingQueue_Pop((struct Ring *)(((struct Obj04641 *)(((u8*)a0 + 0)))->fC)) + 0);
}

