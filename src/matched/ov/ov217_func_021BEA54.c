/*
 * function: RESEARCH_GRAPH_SetEntryFromSlice
 * address:  0x021BEA54
 * packet:   pkt_ov217_021BEA54
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   RESEARCH_GRAPH_GetLeftCircle 0x021BF76C thumb ov217
 *   RESEARCH_GRAPH_GetGroupKey 0x021BF7CC thumb ov217
 *   CircleGraph_GetSliceKey 0x021C11D0 thumb ov217
 *   GRAPHTABLE_FindEntry 0x021C26AC thumb ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25910.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u8 *RESEARCH_GRAPH_GetLeftCircle(void *p);
extern u32 RESEARCH_GRAPH_GetGroupKey(void *p);
extern u8 CircleGraph_GetSliceKey(u8 *p, u8 n);
extern u32 GRAPHTABLE_FindEntry(const u8 *p, u8 unused, u8 key);
void RESEARCH_GRAPH_SetEntryFromSlice(char *p)
{
    u8 *o = RESEARCH_GRAPH_GetLeftCircle(p);

    u32 k = RESEARCH_GRAPH_GetGroupKey(p);
    int v = CircleGraph_GetSliceKey(o, 0);
    ((struct Obj25910 *)p)->f2B9 = GRAPHTABLE_FindEntry((const u8 *)(p + 0x38), (u8)k, (u8)v);
}
