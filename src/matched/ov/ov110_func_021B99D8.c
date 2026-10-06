/*
 * function: func_021B99D8
 * address:  0x021B99D8
 * packet:   pkt_ov110_021B99D8
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B98F8  0x021B98F8  thumb  ov110
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern u32 func_021B98F8(u8 *p, u16 *src, u16 *out, u32 n);
u32 func_021B99D8(u32 a, u32 b, u32 c) { return func_021B98F8((u8 *)a, (u16 *)b, (u16 *)c, 0); }
