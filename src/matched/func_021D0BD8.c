/*
 * function: func_021D0BD8
 * address:  0x021D0BD8
 * packet:   pkt_021D0BD8
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
 *   func_021680C8  0x021680C8  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021680C8(u32, u32, u32, u32);

int func_021D0BD8(u32 a, u32 b, u32 c, u32 d)
{
return func_021680C8(a, b, c, ((d << 16) >> 16));
}

