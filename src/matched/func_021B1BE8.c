/*
 * function: func_021B1BE8
 * address:  0x021B1BE8
 * packet:   pkt_021B1BE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0215A5EC (0x0215A5EC) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_0215A5EC  0x0215A5EC  thumb
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0215A5EC(u32, u32, u32, u32);
extern u32 func_0216D9E4(u32);

int func_021B1BE8(u32 a, u32 b, u32 c, u32 d)
{
return func_0216D9E4(func_0215A5EC(a, b, c, d));
}

