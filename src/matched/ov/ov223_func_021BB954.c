/*
 * function: PSEL_GRAPHIC_UpdateFadeNop
 * address:  0x021BB954
 * packet:   pkt_ov223_021BB954
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * This address is also matched as PSEL_GRAPHIC_UpdateFadeNop in ov021; the ov223 copy is a
 * distinct function and gets its own shard.
 *
 * symbols:
 *   PSEL_GRAPHIC_NopFade  0x021BB62C  thumb  ov223
 *   PSEL_GRAPHIC_NopBlend  0x021BB840  thumb  ov223
 *
 * Addresses are Black-image addresses.
 */

extern void PSEL_GRAPHIC_NopFade(void *);
extern void PSEL_GRAPHIC_NopBlend(void *);

void PSEL_GRAPHIC_UpdateFadeNop(char *p)
{
    PSEL_GRAPHIC_NopFade(p);
    PSEL_GRAPHIC_NopBlend(p);
}
