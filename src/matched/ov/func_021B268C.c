/*
 * function: func_021B268C
 * address:  0x021B268C
 * packet:   pkt_021B268C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_021F42A8  0x021F42A8  thumb  ov043
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *func_0215A5DC();
extern u32 func_021F42A8(u32);

int func_021B268C(u32 a, u32 b, u32 c, u32 d)
{
func_021F42A8(func_0215A5DC(b, b, c, d));
return 0;
}

