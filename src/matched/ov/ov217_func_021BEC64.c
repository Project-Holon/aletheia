/*
 * function: RESEARCH_GRAPH_SetCenterDepth
 * address:  0x021BEC64
 * packet:   pkt_ov217_021BEC64
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   RESEARCH_GRAPH_GetLeftCircle 0x021BF76C thumb ov217
 *   RESEARCH_GRAPH_GetRightCircle 0x021BF77C thumb ov217
 *   CircleGraph_SetCenterDepth 0x021C11A4 thumb ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *RESEARCH_GRAPH_GetLeftCircle(void *p);
extern u8 *RESEARCH_GRAPH_GetRightCircle(void *p);
extern void CircleGraph_SetCenterDepth(u8 *p, int a1);

void RESEARCH_GRAPH_SetCenterDepth(void *p)
{
    CircleGraph_SetCenterDepth(RESEARCH_GRAPH_GetLeftCircle(p), 0xFFFFE000);
    CircleGraph_SetCenterDepth(RESEARCH_GRAPH_GetRightCircle(p), 0);
}
