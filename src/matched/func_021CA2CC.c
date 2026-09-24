/*
 * function: func_021CA2CC
 * address:  0x021CA2CC
 * packet:   pkt_021CA2CC
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
 *   func_0209C0A4  0x0209C0A4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0209C0A4(u32, u32, u32, u32);

int func_021CA2CC(u32 a, u32 b, u32 c, u32 d)
{
return ((func_0209C0A4(a, 7, c, d) << 16) >> 16);
}

