/*
 * function: PSEL_GRAPHIC_DrawEnd
 * address: 0x021BC514
 * packet: pkt_ov223_021BC514
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PSEL_GRAPHIC_G3dDrawEnd 0x021BC6F0 thumb ov223
 */
extern void PSEL_GRAPHIC_G3dDrawEnd(unsigned char *);
void PSEL_GRAPHIC_DrawEnd(unsigned char *p){PSEL_GRAPHIC_G3dDrawEnd(p+8);}
