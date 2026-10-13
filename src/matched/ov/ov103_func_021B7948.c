/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_GetSpriteUnit
 * address:  0x021B7948
 * packet:   pkt_ov103_021B7948
 * region:   ov103
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unblocked by matching IRC_COMPATIBLE_TOUCH_TEST_SpriteSetGetUnit in ov103 (pkt_ov103_021B7C64).
 *
 * symbols:
 *   IRC_COMPATIBLE_TOUCH_TEST_SpriteSetGetUnit  0x021B7C64  thumb  ov103
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern u32 IRC_COMPATIBLE_TOUCH_TEST_SpriteSetGetUnit(u32 *p);
u32 IRC_COMPATIBLE_TOUCH_TEST_GetSpriteUnit(u8 *p) { return IRC_COMPATIBLE_TOUCH_TEST_SpriteSetGetUnit((u32 *)(p + 0xcc)); }
