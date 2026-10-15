/*
 * function: DEMO3D_GRAPHIC_EndDraw
 * address: 0x021BDF24
 * packet: pkt_ov203_021BDF24
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DEMO3D_GRAPHIC_DrawEnd 0x021BE148 thumb ov203
 */
extern void DEMO3D_GRAPHIC_DrawEnd(void *);
void DEMO3D_GRAPHIC_EndDraw(char *p){DEMO3D_GRAPHIC_DrawEnd(p+8);}
