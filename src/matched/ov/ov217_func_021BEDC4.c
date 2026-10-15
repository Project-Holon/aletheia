/*
 * function: RESEARCH_GRAPH_DrawCircles
 * address:  0x021BEDC4
 * packet:   pkt_ov217_021BEDC4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CircleGraph_Draw 0x021C112C thumb ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void CircleGraph_Draw(u8 *p);
void RESEARCH_GRAPH_DrawCircles(char *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        CircleGraph_Draw(*(u8 **)(p + i * 4 + 0x2bc));
        CircleGraph_Draw(*(u8 **)(p + i * 4 + 0x2c4));
    }
}
