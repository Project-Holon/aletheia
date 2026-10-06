/*
 * function: func_021B7948
 * address:  0x021B7948
 * packet:   pkt_ov103_021B7948
 * region:   ov103
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unblocked by matching func_021B7C64 in ov103 (pkt_ov103_021B7C64).
 *
 * symbols:
 *   func_021B7C64  0x021B7C64  thumb  ov103
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern u32 func_021B7C64(u32 *p);
u32 func_021B7948(u8 *p) { return func_021B7C64((u32 *)(p + 0xcc)); }
