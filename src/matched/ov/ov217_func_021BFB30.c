/*
 * function: RESEARCH_GRAPH_ClearFont
 * address:  0x021BFB30
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Clear the u32 at +8.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25950.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void RESEARCH_GRAPH_ClearFont(void *p)
{
    ((struct Obj25950 *)p)->f8 = 0;
}
