/*
 * function: OPTION_MENU_DrawSprites
 * address: 0x021BA010
 * packet: pkt_ov068_021BA010
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_VBlankSystem 0x0204A648 arm
 */
extern void CLACT_VBlankSystem(void);
void OPTION_MENU_DrawSprites(char *a0) { CLACT_VBlankSystem(); }
