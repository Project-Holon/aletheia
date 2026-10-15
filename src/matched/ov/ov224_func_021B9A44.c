/*
 * function: SUBWAY_MAP_GRAPHIC_DrawScreen
 * address:  0x021B9A44
 * packet:   pkt_021B9A44
 * region:   ov224
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SUBWAY_MAP_GRAPHIC_DrawClactUnit  0x021B9B6C  thumb  ov224
 *   SUBWAY_MAP_GRAPHIC_DrawBg  0x021B9B04  thumb  ov224
 *
 * Addresses are Black-image addresses.
 */

void SUBWAY_MAP_GRAPHIC_DrawScreen(void *p)
{
    void SUBWAY_MAP_GRAPHIC_DrawClactUnit(void *);
    void SUBWAY_MAP_GRAPHIC_DrawBg(void *);
    SUBWAY_MAP_GRAPHIC_DrawClactUnit((char *)p + 4);
    SUBWAY_MAP_GRAPHIC_DrawBg(p);
}
