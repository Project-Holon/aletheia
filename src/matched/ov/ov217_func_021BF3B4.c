/*
 * function: RESEARCH_GRAPH_SetDetailLabelVisible
 * address:  0x021BF3B4
 * packet:   pkt_ov217_021BF3B4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BgTextLabel_SetVisible 0x021C0FF8 thumb ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00021.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern void BgTextLabel_SetVisible(u8 *p, int visible);
void RESEARCH_GRAPH_SetDetailLabelVisible(char *p)
{
    if (((struct Obj00021 *)p)->f3D0 != 0) {
        BgTextLabel_SetVisible((u8 *)(((struct Obj00021 *)p)->f364), 1);
    } else {
        BgTextLabel_SetVisible((u8 *)(((struct Obj00021 *)p)->f364), 0);
    }
}
