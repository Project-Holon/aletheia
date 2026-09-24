/*
 * function: func_021B9510
 * address:  0x021B9510
 * packet:   pkt_021B9510
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
 *   func_021B94C0  0x021B94C0  thumb  ov021
 *   func_021B87FC  0x021B87FC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021B87FC(u32, u32);
extern u32 func_021B94C0(u32, u32, u32, u32);

int func_021B9510(u32 a, u32 b, u32 c, u32 d)
{
if (func_021B94C0(a, ((c << 16) >> 16), c, d) == 0) {
    return func_021B87FC(b, c);
}
return 0;
}

