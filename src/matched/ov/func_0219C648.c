/*
 * function: func_0219C648
 * address:  0x0219C648
 * packet:   pkt_0219C648
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
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D520  0x0216D520  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D520(u32);
extern u32 func_0216D67C(u32, u32, u32, u32);

int func_0219C648(u32 a, u32 b, u32 c, u32 d)
{
return *(u8 *)((u8 *)(func_0216D520(func_0216D67C(a, b, c, d))));
}

