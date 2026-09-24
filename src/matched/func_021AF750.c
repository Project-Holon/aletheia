/*
 * function: func_021AF750
 * address:  0x021AF750
 * packet:   pkt_021AF750
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
 *   func_02021288  0x02021288  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02021288(u32, u32, u32, u32);

int func_021AF750(u32 a, u32 b, u32 c, u32 d)
{
return ((func_02021288(a, b, c, d) << 16) >> 16);
}

