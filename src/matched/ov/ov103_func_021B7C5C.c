/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_SpriteSetGetActor
 * address: 0x021B7C5C
 * packet: pkt_ov103_021B7C5C
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
u32 IRC_COMPATIBLE_TOUCH_TEST_SpriteSetGetActor(u8 *p,u32 i) { return *(u32 *)(p+i*4+16); }
