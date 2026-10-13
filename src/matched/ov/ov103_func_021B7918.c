/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_UpdateScene
 * address: 0x021B7918
 * packet: pkt_ov103_021B7918
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   IRC_COMPATIBLE_TOUCH_TEST_DrawSpriteSystem 0x021B7C4C thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_Begin3DFrame 0x021B7D30 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_UpdateMarkers 0x021B8C4C thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_End3DFrame 0x021B7D44 thumb ov103
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void IRC_COMPATIBLE_TOUCH_TEST_DrawSpriteSystem(void *);
extern void IRC_COMPATIBLE_TOUCH_TEST_Begin3DFrame(u8 *p);
extern void IRC_COMPATIBLE_TOUCH_TEST_UpdateMarkers(u8 **);
extern void IRC_COMPATIBLE_TOUCH_TEST_End3DFrame(void *);
void IRC_COMPATIBLE_TOUCH_TEST_UpdateScene(u8 *p) { IRC_COMPATIBLE_TOUCH_TEST_DrawSpriteSystem(p+204); IRC_COMPATIBLE_TOUCH_TEST_Begin3DFrame(p+4); IRC_COMPATIBLE_TOUCH_TEST_UpdateMarkers((u8 **)(p+352)); IRC_COMPATIBLE_TOUCH_TEST_End3DFrame(p+4); }
