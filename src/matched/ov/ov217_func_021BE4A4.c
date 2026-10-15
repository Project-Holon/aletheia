/*
 * function: RESEARCH_GRAPH_ProcessCommand
 * address:  0x021BE4A4
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   RESEARCH_GRAPH_StartSubState  0x021BE4CC  thumb  ov217
 *   RingQueue_Pop  0x021C0E54  thumb  ov217
 *   RingQueue_IsEmpty  0x021C0E64  thumb  ov217
 *
 * When the +0x3DC guard word is set and the +0x1c handle is idle, hand it
 * to RESEARCH_GRAPH_StartSubState with the value RingQueue_Pop() reports.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00021.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Ring;
extern void RESEARCH_GRAPH_StartSubState(void *p, u32 v);
extern u32 RingQueue_Pop(struct Ring *r);
extern u32 RingQueue_IsEmpty();
void RESEARCH_GRAPH_ProcessCommand(u32 a0)
{
    if (((struct Obj00021 *)(((u8*)a0)))->f3DC != 0) {
    if (RingQueue_IsEmpty(((struct Obj00021 *)(((u8*)a0)))->f1C) == 0) {
    RESEARCH_GRAPH_StartSubState((void *)a0, RingQueue_Pop((struct Ring *)(((struct Obj00021 *)(((u8*)a0)))->f1C)));
    }
    }
}
