/*
 * function: RESEARCH_GRAPH_UpdateSlotPalettes
 * address:  0x021BF5E4
 * packet:   pkt_021BF5E4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PALETTE_ANIME_Update  0x021C29F0  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

extern void PALETTE_ANIME_Update(int);

void RESEARCH_GRAPH_UpdateSlotPalettes(int *p)
{
    int i;
    for (i = 0; i < 8; i++)
        PALETTE_ANIME_Update(p[i + 0xC9]);
}
