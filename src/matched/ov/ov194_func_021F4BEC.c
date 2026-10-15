/*
 * function: NAMEIN_GRAPHIC_GetDisplayHandle
 * address: 0x021F4BEC
 * packet: pkt_ov194_021F4BEC
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   NAMEIN_GRAPHIC_LoadWord 0x021F4D1C thumb ov194
 */
extern unsigned NAMEIN_GRAPHIC_LoadWord(const unsigned *);
unsigned NAMEIN_GRAPHIC_GetDisplayHandle(unsigned char *p){return NAMEIN_GRAPHIC_LoadWord((const unsigned *)(p+4));}
