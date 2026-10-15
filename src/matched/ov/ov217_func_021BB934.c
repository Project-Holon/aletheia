/*
 * function: RESEARCH_LIST_SetEntryHandled
 * address:  0x021BB934
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0)) to RESEARCH_COMMON_SetEntryHandled.
 *
 * symbols:
 *   RESEARCH_COMMON_SetEntryHandled  0x021C09C4  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02928.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void RESEARCH_COMMON_SetEntryHandled(u8 *p, u32 v);

void RESEARCH_LIST_SetEntryHandled(u8 *a0, u32 a1)
{
    RESEARCH_COMMON_SetEntryHandled(*(u8 * *)&((struct Obj02928 *)a0)->f0, a1);
}

