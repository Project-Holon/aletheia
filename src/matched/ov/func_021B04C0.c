/*
 * function: func_021B04C0
 * address:  0x021B04C0
 * packet:   pkt_021B04C0
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
 *   func_0215A61C  0x0215A61C  thumb  ov010
 *   func_021910C0  0x021910C0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0215A61C(u32, u32, u32, u32);
extern u32 func_021910C0(u32 *p);

int func_021B04C0(u32 a, u32 b, u32 c, u32 d)
{
if (func_021910C0((u32 *)func_0215A61C(b, b, c, d)) == 1) {
    return 1;
}
return 0;
}

