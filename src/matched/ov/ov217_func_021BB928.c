/*
 * function: RESEARCH_LIST_GetEntryHandled
 * address:  0x021BB928
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0)) to RESEARCH_COMMON_GetEntryHandled.
 *
 * symbols:
 *   RESEARCH_COMMON_GetEntryHandled  0x021C09CC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25846.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u32 RESEARCH_COMMON_GetEntryHandled(void *p);

u32 RESEARCH_LIST_GetEntryHandled(u8 *a0)
{
    return RESEARCH_COMMON_GetEntryHandled((void *)((u32)(((struct Obj25846 *)a0)->f0)));
}

