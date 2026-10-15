/*
 * function: MYSTERY_GRAPHIC_GetClactUnit
 * address: 0x021D9744
 * packet: pkt_ov121_021D9744
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MYSTERY_GRAPHIC_GetFirstWord 0x021D98F0 thumb ov121
 */
extern unsigned MYSTERY_GRAPHIC_GetFirstWord(unsigned *);
unsigned MYSTERY_GRAPHIC_GetClactUnit(char *p) { return MYSTERY_GRAPHIC_GetFirstWord((unsigned *)(p+4)); }
