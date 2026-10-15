/*
 * function: RESEARCH_GRAPH_ShowPercentages
 * address:  0x021BEFD4
 * packet:   pkt_ov217_021BEFD4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   RESEARCH_GRAPH_ShowPercent 0x021BEFC0 thumb ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25923.h"

typedef unsigned int u32;
typedef unsigned char u8;
extern void RESEARCH_GRAPH_ShowPercent(u8 *a0, u32 a1);
void RESEARCH_GRAPH_ShowPercentages(char *p)
{
    int i;
    int n;
    n = ((struct Obj25923 *)p)->f2FC;
    for (i = 0; i < n; i++) {
        RESEARCH_GRAPH_ShowPercent((u8 *)p, (u8)i);
    }
}
