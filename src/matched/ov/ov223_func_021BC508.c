/*
 * function: PSEL_GRAPHIC_ApplyLight
 * address: 0x021BC508
 * packet: pkt_ov223_021BC508
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PSEL_GRAPHIC_ApplyLookAt 0x021BC6DC thumb ov223
 */
extern void PSEL_GRAPHIC_ApplyLookAt(int *);
void PSEL_GRAPHIC_ApplyLight(unsigned char *p){PSEL_GRAPHIC_ApplyLookAt((int *)(p+8));}
