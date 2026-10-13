/*
 * function: IRC_COMPATIBLE_MENU_GetSpriteUnit
 * address: 0x021B78F4
 * packet: pkt_ov102_021B78F4
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   IRC_COMPATIBLE_MENU_SpriteSetGetUnit 0x021B7C1C thumb ov102
 */
extern unsigned IRC_COMPATIBLE_MENU_SpriteSetGetUnit(unsigned *);
unsigned IRC_COMPATIBLE_MENU_GetSpriteUnit(unsigned *p) { return IRC_COMPATIBLE_MENU_SpriteSetGetUnit(p); }
