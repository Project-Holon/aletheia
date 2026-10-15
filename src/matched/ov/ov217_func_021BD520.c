/*
 * function: RESEARCH_LIST_DestroyPaletteAnime
 * address:  0x021BD520
 * packet:   pkt_021BD520
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PALETTE_ANIME_Destroy  0x021C29D8  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
extern u32 PALETTE_ANIME_Destroy(void *a0);

void RESEARCH_LIST_DestroyPaletteAnime(int *p)
{
    int i;
    for (i = 0; i < 6; i++)
        PALETTE_ANIME_Destroy((void *)p[i + 0x27]);
}
