/*
 * function: func_021AE930
 * address:  0x021AE930
 * packet:   pkt_021AE930
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
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02158768  0x02158768  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02158768(u32, u32, u32, u32);
extern u32 func_02188C80(u32, u32, u32, u32);

int func_021AE930(u32 a, u32 b, u32 c, u32 d)
{
return func_02158768(func_02188C80(a, b, c, d), (226 << 4), b, 1);
}

