/*
 * function: RESEARCH_LIST_RestorePaletteAnime
 * address:  0x021BD56C
 * packet:   pkt_ov217_021BD56C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * This address is also matched as RESEARCH_LIST_RestorePaletteAnime in ov208; the ov217 copy is a
 * distinct function and gets its own shard.
 *
 * symbols:
 *   PALETTE_ANIME_Restore  0x021C2A08  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

extern int PALETTE_ANIME_Restore(char *p);

void RESEARCH_LIST_RestorePaletteAnime(int *p)
{
    int i;
    for (i = 0; i < 6; i++)
        PALETTE_ANIME_Restore((char *)p[i + 0x27]);
}
