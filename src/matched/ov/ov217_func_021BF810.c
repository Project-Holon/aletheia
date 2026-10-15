/*
 * function: RESEARCH_GRAPH_GetGroupValue
 * address:  0x021BF810
 * packet:   pkt_ov217_021BF810
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   RESEARCH_GRAPH_GetGroupTotalA 0x021BF834 thumb ov217
 *   RESEARCH_GRAPH_GetGroupTotalB 0x021BF844 thumb ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25943.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u32 RESEARCH_GRAPH_GetGroupTotalA(void *p);
extern u32 RESEARCH_GRAPH_GetGroupTotalB(void *p);
u32 RESEARCH_GRAPH_GetGroupValue(void *p)
{
    u32 r = 0;
    switch (((struct Obj25943 *)p)->f2CC) {
    case 0:
        r = RESEARCH_GRAPH_GetGroupTotalA(p);
        break;
    case 1:
        r = RESEARCH_GRAPH_GetGroupTotalB(p);
        break;
    }
    return r;
}
