/*
 * function: RESEARCH_LIST_UpdatePaletteAnimes
 * address:  0x021BC5D4
 * packet:   pkt_ov217_021BC5D4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * This address is also matched as RESEARCH_LIST_UpdatePaletteAnimes in ov021; the ov217 copy is a
 * distinct function and gets its own shard.
 *
 * symbols:
 *   PALETTE_ANIME_Update  0x021C29F0  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

extern void PALETTE_ANIME_Update(int);

void RESEARCH_LIST_UpdatePaletteAnimes(int *p)
{
    int i;
    for (i = 0; i < 6; i++)
        PALETTE_ANIME_Update(p[i + 0x27]);
}
