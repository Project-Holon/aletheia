/*
 * function: PSEL_GRAPHIC_GetClactBank
 * address: 0x021BC520
 * packet: pkt_ov223_021BC520
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PSEL_GRAPHIC_LoadWord 0x021BC65C thumb ov223
 */
extern unsigned PSEL_GRAPHIC_LoadWord(const unsigned *);
unsigned PSEL_GRAPHIC_GetClactBank(unsigned char *p){return PSEL_GRAPHIC_LoadWord((const unsigned *)(p+4));}
