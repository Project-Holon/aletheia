/*
 * function: MANUAL_GRAPHIC_VBlankScreen
 * address:  0x021B9A14
 * packet:   pkt_ov225_021B9A14
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MANUAL_GRAPHIC_VBlankBg  0x021B9AC4  thumb  ov225
 *   MANUAL_GRAPHIC_VBlankClactUnit  0x021B9B30  thumb  ov225
 *
 * Addresses are Black-image addresses.
 */

extern void MANUAL_GRAPHIC_VBlankBg(void *);
extern void MANUAL_GRAPHIC_VBlankClactUnit(void *);

void MANUAL_GRAPHIC_VBlankScreen(void *unused, char *p)
{
    MANUAL_GRAPHIC_VBlankBg(p);
    MANUAL_GRAPHIC_VBlankClactUnit(p + 4);
}
