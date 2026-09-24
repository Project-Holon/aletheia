/*
 * function: func_021AEEE0
 * address:  0x021AEEE0
 * packet:   pkt_021AEEE0
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
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02005F38  0x02005F38  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02005F38(u32);
extern u32 func_0215A5DC(u32, u32, u32, u32);
extern u32 func_0215A5F4(u32);

int func_021AEEE0(u32 a, u32 b, u32 c, u32 d)
{
func_0215A5DC(b, b, c, d);
if (func_02005F38(func_0215A5F4(b)) == 0) {
    return 1;
}
return 0;
}

