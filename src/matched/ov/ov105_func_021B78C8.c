/*
 * function: func_021B78C8
 * address:  0x021B78C8
 * packet:   pkt_ov105_021B78C8
 * region:   ov105
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unblocked by matching func_021B7C14 in ov105 (pkt_ov105_021B7C14).
 *
 * symbols:
 *   func_021B7C14  0x021B7C14  thumb  ov105
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern u32 func_021B7C14(u8 *p, int i);
u32 func_021B78C8(u8 *p, int i) { return func_021B7C14(p + 4, i); }
