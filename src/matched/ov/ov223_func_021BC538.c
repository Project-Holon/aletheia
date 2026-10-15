/*
 * function: PSEL_GRAPHIC_VBlank
 * address:  0x021BC538
 * packet:   pkt_021BC538
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PSEL_GRAPHIC_UpdateBg  0x021BC5E8  thumb  ov223
 *   PSEL_GRAPHIC_ClactVBlank  0x021BC654  thumb  ov223
 *
 * Addresses are Black-image addresses.
 */

extern void PSEL_GRAPHIC_UpdateBg(void *);
extern void PSEL_GRAPHIC_ClactVBlank(void *);

void PSEL_GRAPHIC_VBlank(void *unused, char *p)
{
    PSEL_GRAPHIC_UpdateBg(p);
    PSEL_GRAPHIC_ClactVBlank(p + 4);
}
