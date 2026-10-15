/*
 * function: RESEARCH_GRAPH_GetGroupKey
 * address:  0x021BF7CC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Element field: u8 at +0x3c of record 0xd4 bytes, selected by the u8 at +0x2b8.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25941.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 RESEARCH_GRAPH_GetGroupKey(void *p)
{
    u32 i = ((struct Obj25941 *)p)->f2B8;
    return *(u8 *)((char *)p + i * 0xd4 + 0x3c);
}
