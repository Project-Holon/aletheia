/*
 * function: INTRO_GRAPHIC_GetClactOwner
 * address: 0x021BDD78
 * packet: pkt_ov204_021BDD78
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRO_GRAPHIC_GetClactBank 0x021BDFA0 thumb ov204
 */
extern unsigned INTRO_GRAPHIC_GetClactBank(char *);
unsigned INTRO_GRAPHIC_GetClactOwner(char *p){return INTRO_GRAPHIC_GetClactBank(p+4);}
