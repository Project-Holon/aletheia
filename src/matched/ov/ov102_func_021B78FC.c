/*
 * function: IRC_COMPATIBLE_MENU_VBlankTask
 * address: 0x021B78FC
 * packet: pkt_ov102_021B78FC
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * IRC_COMPATIBLE_MENU_VBlankSpriteSystem 0x021B7C0C thumb ov102
 */
extern void IRC_COMPATIBLE_MENU_VBlankSpriteSystem(void *);
void IRC_COMPATIBLE_MENU_VBlankTask(unsigned a,void *p) { IRC_COMPATIBLE_MENU_VBlankSpriteSystem(p); }
