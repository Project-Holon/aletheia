/*
 * function: PSEL_GRAPHIC_InitFadePalettes
 * address:  0x021BB944
 * packet:   pkt_021BB944
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PSEL_GRAPHIC_LoadFadeSources  0x021BB540  thumb  ov223
 *   PSEL_GRAPHIC_LoadPaletteBuffers  0x021BB7A4  thumb  ov223
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
extern void PSEL_GRAPHIC_LoadFadeSources(u8 *p);
extern void PSEL_GRAPHIC_LoadPaletteBuffers(char *p);

void PSEL_GRAPHIC_InitFadePalettes(char *p)
{
    PSEL_GRAPHIC_LoadFadeSources((u8 *)p);
    PSEL_GRAPHIC_LoadPaletteBuffers(p);
}
