/*
 * function: func_021D0084
 * address:  0x021D0084
 * packet:   pkt_021D0084
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
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021CFC4C  0x021CFC4C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02159B10(u32, u32);
extern u32 func_0215A5DC(u32);
extern u32 func_0215A5F4(u32, u32, u32, u32);
extern u32 func_021CFC4C(u32, u32, u32);

int func_021D0084(u32 a, u32 b, u32 c, u32 d)
{
func_0215A5F4(b, b, c, d);
func_021CFC4C(func_0215A5DC(b), func_02159B10(a, b), func_02159B10(a, b));
return 0;
}

