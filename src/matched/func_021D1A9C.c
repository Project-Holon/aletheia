/*
 * function: func_021D1A9C
 * address:  0x021D1A9C
 * packet:   pkt_021D1A9C
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
 *   func_021D18E0  0x021D18E0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021D18E0(u32, u32, u32, u32);

int func_021D1A9C(u32 a, u32 b, u32 c, u32 d)
{
if (func_021D18E0(*(u32 *)((u8 *)(c)), b, c, d) == 1) {
    return 1;
}
return 0;
}

