/*
 * function: func_021B78BC
 * address:  0x021B78BC
 * packet:   pkt_ov105_021B78BC
 * region:   ov105
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B7C04  0x021B7C04  thumb  ov021
 *
 * Target func_021B7C04 is the traced Thumb function start in ov021's listing
 * (sole-ref/code overlay); the overlap that hid it is disambiguated by token.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_021B7C04(void *);
void func_021B78BC(u8 *p) { func_021B7C04(p + 4); }
