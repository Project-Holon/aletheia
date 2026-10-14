/*
 * function: POKETRADE_2D_FadePaletteAll
 * address: 0x021E71E0
 * packet: pkt_ov119_021E71E0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_2D_FadePaletteCopy 0x021E7160 thumb ov119
 */
extern void POKETRADE_2D_FadePaletteCopy(void *p, int a1, int a2, int a3);

void POKETRADE_2D_FadePaletteAll(void *p, int a)
{
    POKETRADE_2D_FadePaletteCopy(p, a, 3, 0xfffe);
}
