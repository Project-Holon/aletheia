/*
 * function: func_021B99E4
 * address:  0x021B99E4
 * packet:   pkt_ov110_021B99E4
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

u8 *func_021B99E4(u8 *p) { return p + 4 + (*(u16 *)(p + 2) - 1) * 2; }
