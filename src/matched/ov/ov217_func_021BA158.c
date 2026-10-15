/*
 * function: RESEARCH_TOP_ProcessCommand
 * address:  0x021BA158
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   RESEARCH_TOP_StartCommand  0x021BA180  thumb  ov217
 *   RingQueue_Pop  0x021C0E54  thumb  ov217
 *   RingQueue_IsEmpty  0x021C0E64  thumb  ov217
 *
 * When the +0x80 guard word is set and the +0x14 handle is idle, hand it
 * to RESEARCH_TOP_StartCommand with the value RingQueue_Pop() reports.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00511.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Ring;
extern void RESEARCH_TOP_StartCommand(void *p, u32 v);
extern u32 RingQueue_Pop(struct Ring *r);
extern u32 RingQueue_IsEmpty();
void RESEARCH_TOP_ProcessCommand(u32 a0)
{
    if (((struct Obj00511 *)((u8*)a0))->f80 != 0) {
    if (RingQueue_IsEmpty(((struct Obj00511 *)(((u8*)a0)))->f14) == 0) {
    RESEARCH_TOP_StartCommand((void *)a0, RingQueue_Pop((struct Ring *)(((struct Obj00511 *)(((u8*)a0)))->f14)));
    }
    }
}
