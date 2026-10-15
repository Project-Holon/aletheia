/*
 * function: RESEARCH_GRAPH_DestroyCircles
 * address:  0x021BFC28
 * packet:   pkt_ov217_021BFC28
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CircleGraph_Destroy 0x021C10D8 thumb ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u32 CircleGraph_Destroy(void *a0);
void RESEARCH_GRAPH_DestroyCircles(char *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        CircleGraph_Destroy((void *)(*(u32 *)(p + i * 4 + 0x2bc)));
        CircleGraph_Destroy((void *)(*(u32 *)(p + i * 4 + 0x2c4)));
    }
}
