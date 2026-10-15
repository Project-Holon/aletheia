/*
 * function: RESEARCH_GRAPH_RestorePaletteAnime
 * address:  0x021C08A8
 * packet:   pkt_021C08A8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PALETTE_ANIME_Restore  0x021C2A08  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

extern int PALETTE_ANIME_Restore(char *p);

void RESEARCH_GRAPH_RestorePaletteAnime(int *p)
{
    int i;
    for (i = 0; i < 8; i++)
        PALETTE_ANIME_Restore((char *)p[i + 0xC9]);
}
