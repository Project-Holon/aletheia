/*
 * function: MANUAL_GRAPHIC_DrawScreen
 * address:  0x021B99F4
 * packet:   pkt_021B99F4
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Destructor pair: tears down the tail field then the head.
 *
 * symbols:
 *   MANUAL_GRAPHIC_DrawClactUnit  0x021B9B28  thumb  ov225
 *   MANUAL_GRAPHIC_DrawBg  0x021B9AC0  thumb  ov225
 *
 * Addresses are Black-image addresses.
 */

extern void MANUAL_GRAPHIC_DrawClactUnit(void *);
extern void MANUAL_GRAPHIC_DrawBg(void *);

void MANUAL_GRAPHIC_DrawScreen(char *p)
{
    MANUAL_GRAPHIC_DrawClactUnit(p + 4);
    MANUAL_GRAPHIC_DrawBg(p);
}
