/*
 * function: func_021AF430
 * address:  0x021AF430
 * packet:   pkt_021AF430
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0215A6AC (0x0215A6AC) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_0215A6AC  0x0215A6AC  thumb
 *   func_02006BD0  0x02006BD0  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02006BD0(u32);
extern u32 func_0215A6AC(u32, u32, u32, u32);

int func_021AF430(u32 a, u32 b, u32 c, u32 d)
{
if (func_02006BD0(func_0215A6AC(b, b, c, d)) == 0) {
    return 1;
}
return 0;
}

