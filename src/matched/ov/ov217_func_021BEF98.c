/*
 * function: RESEARCH_GRAPH_HideAllPercentages
 * address:  0x021BEF98
 * packet:   pkt_ov217_021BEF98
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PERCENTAGE_SetVisible 0x021C2740 thumb ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25922.h"

typedef unsigned int u32;
typedef unsigned char u8;
extern void PERCENTAGE_SetVisible(u32 a, u32 b);
void RESEARCH_GRAPH_HideAllPercentages(char *p)
{
    int i;
    u8 z = 0;
    for (i = 0; i < 10; i++) {
        PERCENTAGE_SetVisible(*(u32 *)(p + i * 4 + 0x2d4), z);
    }
    ((struct Obj25922 *)p)->f2FD = z;
}
