/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_VBlankTask
 * address: 0x021B795C
 * packet: pkt_ov103_021B795C
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRC_COMPATIBLE_TOUCH_TEST_BackgroundVBlank 0x021B7B34 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_VBlankSpriteSystem 0x021B7C54 thumb ov103
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void IRC_COMPATIBLE_TOUCH_TEST_BackgroundVBlank(void *);
extern void IRC_COMPATIBLE_TOUCH_TEST_VBlankSpriteSystem(void *);
void IRC_COMPATIBLE_TOUCH_TEST_VBlankTask(void *unused,u8 *p) { IRC_COMPATIBLE_TOUCH_TEST_BackgroundVBlank(p); IRC_COMPATIBLE_TOUCH_TEST_VBlankSpriteSystem(p+204); }
