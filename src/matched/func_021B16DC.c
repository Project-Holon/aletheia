/*
 * function: func_021B16DC
 * address:  0x021B16DC
 * packet:   pkt_021B16DC
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
 *   func_0215A6FC  0x0215A6FC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0215A6FC(u32, u32, u32, u32);

int func_021B16DC(u32 a, u32 b, u32 c, u32 d)
{
if (func_0215A6FC(b, b, c, d) == 0) {
    return 1;
}
return 0;
}

