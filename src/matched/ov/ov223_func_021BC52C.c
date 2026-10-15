/*
 * function: PSEL_GRAPHIC_GetCamera
 * address: 0x021BC52C
 * packet: pkt_ov223_021BC52C
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PSEL_GRAPHIC_LoadWordC6F8 0x021BC6F8 thumb ov223
 */
extern unsigned PSEL_GRAPHIC_LoadWordC6F8(unsigned char *);
unsigned PSEL_GRAPHIC_GetCamera(unsigned char *p){return PSEL_GRAPHIC_LoadWordC6F8(p+8);}
