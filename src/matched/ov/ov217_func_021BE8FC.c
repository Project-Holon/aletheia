/*
 * function: RESEARCH_GRAPH_FadeIn
 * address:  0x021BE8FC
 * packet:   pkt_ov217_021BE8FC
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * This address is also matched as RESEARCH_GRAPH_FadeIn in ov208; the ov217 copy is a
 * distinct function and gets its own shard.
 *
 * symbols:
 *   FADE_Start  0x0204E720  arm
 *
 * Addresses are Black-image addresses.
 */

typedef signed int     s32;
typedef unsigned int   u32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);

void RESEARCH_GRAPH_FadeIn(void)
{
    FADE_Start(3, 0x10, 0, 0);
}
