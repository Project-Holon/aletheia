/*
 * function: SUBWAY_MAP_GRAPHIC_VBlankScreen
 * address:  0x021B9A58
 * packet:   pkt_021B9A58
 * region:   ov224
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SUBWAY_MAP_GRAPHIC_VBlankBg  0x021B9B08  thumb  ov224
 *   SUBWAY_MAP_GRAPHIC_VBlankClactUnit  0x021B9B74  thumb  ov224
 *
 * Addresses are Black-image addresses.
 */

extern void SUBWAY_MAP_GRAPHIC_VBlankBg(void *);
extern void SUBWAY_MAP_GRAPHIC_VBlankClactUnit(void *);

void SUBWAY_MAP_GRAPHIC_VBlankScreen(void *unused, char *p)
{
    SUBWAY_MAP_GRAPHIC_VBlankBg(p);
    SUBWAY_MAP_GRAPHIC_VBlankClactUnit(p + 4);
}
