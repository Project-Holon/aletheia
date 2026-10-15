/*
 * function: PSEL_GRAPHIC_UpdateFade
 * address:  0x021BB964
 * packet:   pkt_ov223_021BB964
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * This address is also matched as PSEL_GRAPHIC_UpdateFade in ov093; the ov223 copy is a
 * distinct function and gets its own shard.
 *
 * symbols:
 *   PSEL_GRAPHIC_StepFade  0x021BB630  thumb  ov223
 *   PSEL_GRAPHIC_BlendPalettes  0x021BB844  thumb  ov223
 *
 * Addresses are Black-image addresses.
 */

extern void PSEL_GRAPHIC_StepFade(void *);
extern void PSEL_GRAPHIC_BlendPalettes(char *p);

void PSEL_GRAPHIC_UpdateFade(char *p)
{
    PSEL_GRAPHIC_StepFade(p);
    PSEL_GRAPHIC_BlendPalettes(p);
}
