/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_VBlankSpriteSystem
 * address: 0x021B7C54
 * packet: pkt_ov103_021B7C54
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_VBlankSystem 0x0204A648 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void CLACT_VBlankSystem(void);
void IRC_COMPATIBLE_TOUCH_TEST_VBlankSpriteSystem(void *a0) { CLACT_VBlankSystem(); }
