/*
 * function: RESEARCH_GRAPH_PrintKindLabel
 * address:  0x021BF13C
 * packet:   pkt_ov217_021BF13C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   RESEARCH_GRAPH_GetGroupKey 0x021BF7CC thumb ov217
 *   BgTextLabel_PrintMessage 0x021C0F5C thumb ov217
 *   d_021C369A 0x021C369A data a1
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25925.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u32 RESEARCH_GRAPH_GetGroupKey(void *p);
extern u32 BgTextLabel_PrintMessage(u32 a0, u32 a1);
extern u8 d_021C369A[];
void RESEARCH_GRAPH_PrintKindLabel(char *p)
{
    u32 o = ((struct Obj25925 *)p)->f350;
    u32 i = RESEARCH_GRAPH_GetGroupKey(p);
    BgTextLabel_PrintMessage(o, d_021C369A[i]);
}
