/*
 * function: RESEARCH_GRAPH_DestroyCommandQueue
 * address:  0x021BFB24
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 28)) to RingQueue_Destroy.
 *
 * symbols:
 *   RingQueue_Destroy  0x021C0E3C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25949.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void RingQueue_Destroy(void *p);

void RESEARCH_GRAPH_DestroyCommandQueue(u8 *a0)
{
    RingQueue_Destroy((void *)((u32)(((struct Obj25949 *)a0)->f1C)));
}

