/*
 * function: RESEARCH_GRAPH_CreateCommandQueue
 * address:  0x021BFB14
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
 *   RingQueue_Create  0x021C0E08  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14742.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern int RingQueue_Create(int a0, int a1);
void RESEARCH_GRAPH_CreateCommandQueue(u32 a0)
{
    ((struct Obj14742 *)(((u8*)a0 + 0)))->f1C = RingQueue_Create(10, ((struct Obj14742 *)(((u8*)a0 + 0)))->f4);
}

