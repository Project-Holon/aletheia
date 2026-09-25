/*
 * function: func_021B7F7C
 * address:  0x021B7F7C
 * packet:   pkt_ov106_021B7F7C
 * region:   ov106
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

u32 func_021B7F7C(u8 *p, u32 i) { return i ? *(u32 *)(p + 4) : *(u32 *)(p + 8); }
