/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_Get3DModel
 * address:  0x021B7D4C
 * packet:   pkt_ov103_021B7D4C
 * region:   ov103
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

u8 *IRC_COMPATIBLE_TOUCH_TEST_Get3DModel(u8 *p, u16 i) { return p + 4 + i * 0x60; }
