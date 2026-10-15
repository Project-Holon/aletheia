/*
 * function: RESEARCH_GRAPH_SetIndex
 * address:  0x021BE930
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter, u32 at +0x34.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25907.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void RESEARCH_GRAPH_SetIndex(void *p, u32 v)
{
    ((struct Obj25907 *)p)->f34 = v;
}
