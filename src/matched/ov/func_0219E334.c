/*
 * function: func_0219E334
 * address:  0x0219E334
 * packet:   pkt_0219E334
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
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_021B7DC0  0x021B7DC0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D69C(u32, u32, u32, u32);
extern u32 func_021B7DC0(u32, u32);

int func_0219E334(u32 a, u32 b, u32 c, u32 d)
{
return func_021B7DC0(*(u32 *)((u8 *)(func_0216D69C(a, b, c, d))), b);
}

