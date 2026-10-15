/*
 * function: RESEARCH_GRAPH_UpdateCircles
 * address:  0x021BED9C
 * packet:   pkt_ov217_021BED9C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CircleGraph_Update 0x021C1124 thumb ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void CircleGraph_Update(u8 *p);
void RESEARCH_GRAPH_UpdateCircles(char *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        CircleGraph_Update(*(u8 **)(p + i * 4 + 0x2bc));
        CircleGraph_Update(*(u8 **)(p + i * 4 + 0x2c4));
    }
}
