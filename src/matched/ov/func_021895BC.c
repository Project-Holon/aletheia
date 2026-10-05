/*
 * function: func_021895BC
 * address:  0x021895BC
 * packet:   pkt_021895BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC4  0x02012AC4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020127A4(u32, u32, u32, u32);
extern u32 func_02012AC4(u32, u32);

int func_021895BC(u32 a, u32 b, u32 c, u32 d)
{
return func_02012AC4(func_020127A4(a, b, c, d), ((b << 16) >> 16));
}

