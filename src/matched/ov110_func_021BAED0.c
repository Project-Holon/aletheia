/*
 * function: func_021BAED0
 * address:  0x021BAED0
 * packet:   pkt_ov110_021BAED0
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BFC20  0x021BFC20  thumb  ov110
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_021BFC20(u32, int);
void func_021BAED0(u8 *p) { func_021BFC20(*(u32 *)(p + 0x5c), 1); }
