/*
 * function: IRC_COMPATIBLE_MENU_VBlankSpriteSystem
 * address: 0x021B7C0C
 * packet: pkt_ov102_021B7C0C
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * CLACT_VBlankSystem 0x0204A648 arm
 */
extern void CLACT_VBlankSystem(void);
void IRC_COMPATIBLE_MENU_VBlankSpriteSystem(void *p) { CLACT_VBlankSystem(); }
