/*
 * function: RESEARCH_GRAPH_PrintGroupLabel
 * address:  0x021BF11C
 * packet:   pkt_ov217_021BF11C
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
 *   d_021C36B8 0x021C36B8 data a1
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25924.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u32 RESEARCH_GRAPH_GetGroupKey(void *p);
extern u32 BgTextLabel_PrintMessage(u32 a0, u32 a1);
extern u8 d_021C36B8[];
void RESEARCH_GRAPH_PrintGroupLabel(char *p)
{
    u32 i = RESEARCH_GRAPH_GetGroupKey(p);
    BgTextLabel_PrintMessage(((struct Obj25924 *)p)->f34C, d_021C36B8[i]);
}
