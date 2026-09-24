/*
 * function: func_021AE79C
 * address:  0x021AE79C
 * packet:   pkt_021AE79C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D5A8 (0x0216D5A8) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_0216D5A8  0x0216D5A8  thumb
 *   func_0216E434  0x0216E434  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D5A8(u32, u32, u32, u32);
extern u32 func_0216E434(u32);

int func_021AE79C(u32 a, u32 b, u32 c, u32 d)
{
return func_0216E434(func_0216D5A8(a, b, c, d));
}

