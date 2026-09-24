/*
 * function: func_0219E764
 * address:  0x0219E764
 * packet:   pkt_0219E764
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
 *   func_0219E348  0x0219E348  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0219E784  0x0219E784  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D5F8(u32);
extern u32 func_0219E348(u32, u32, u32, u32);
extern u32 func_0219E784(u32, u32, u32);

int func_0219E764(u32 a, u32 b, u32 c, u32 d)
{
func_0219E348(a, b, c, d);
return func_0219E784(a, ((func_0216D5F8(a) << 16) >> 16), b);
}

