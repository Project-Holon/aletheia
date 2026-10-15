/*
 * function: RESEARCH_GRAPH_SetTeamLabelVisible
 * address:  0x021BF38C
 * packet:   pkt_ov217_021BF38C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   RESEARCH_GRAPH_GetGroupValue 0x021BF810 thumb ov217
 *   BgTextLabel_SetVisible 0x021C0FF8 thumb ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14739.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u32 RESEARCH_GRAPH_GetGroupValue(void *p);
extern void BgTextLabel_SetVisible(u8 *p, int visible);
void RESEARCH_GRAPH_SetTeamLabelVisible(char *p)
{
    if (RESEARCH_GRAPH_GetGroupValue(p) == 0) {
        BgTextLabel_SetVisible((u8 *)(((struct Obj14739 *)p)->f360), 1);
    } else {
        BgTextLabel_SetVisible((u8 *)(((struct Obj14739 *)p)->f360), 0);
    }
}
