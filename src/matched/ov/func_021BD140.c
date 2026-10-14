/*
 * function: ZUKAN_DETAIL_GRAPHIC_EndDraw
 * address:  0x021BD140
 * packet:   pkt_021BD140
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_DrawEnd 0x02047970  arm
 *
 * Tail call to the ARM9 function at 0x02047970, forwarding the first argument.
 */

extern void G3D_SYSTEM_DrawEnd(void);

void ZUKAN_DETAIL_GRAPHIC_EndDraw(char *p)
{
    G3D_SYSTEM_DrawEnd();
}
