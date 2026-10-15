/*
 * function: RESEARCH_LIST_PushCommand
 * address:  0x021BB910
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 24)) to RingQueue_Push.
 *
 * symbols:
 *   RingQueue_Push  0x021C0E4C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25844.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void RingQueue_Push(u32, u32);

void RESEARCH_LIST_PushCommand(u8 *a0, u32 a1)
{
    RingQueue_Push((u32)(((struct Obj25844 *)a0)->f18), a1);
}

