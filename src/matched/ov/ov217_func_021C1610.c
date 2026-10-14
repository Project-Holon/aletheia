/*
 * function: CircleGraph_UpdateHidden
 * address:  0x021C1610
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   RingQueue_IsEmpty  0x021C0E64  thumb  ov217
 *   CircleGraph_NextCommand  0x021C16E8  thumb  ov217
 *
 * When the +0x0c handle is idle, runs CircleGraph_NextCommand().
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj26010.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 RingQueue_IsEmpty();
extern void CircleGraph_NextCommand(u32 a0);
void CircleGraph_UpdateHidden(u32 a0)
{
    if (RingQueue_IsEmpty(((struct Obj26010 *)(((u8*)a0)))->fC) == 0) {
    CircleGraph_NextCommand(a0);
    }
}
