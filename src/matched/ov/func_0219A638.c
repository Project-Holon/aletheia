/*
 * function: func_0219A638
 * address:  0x0219A638
 * packet:   pkt_0219A638
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
 *   func_02197EDC  0x02197EDC  thumb  ov021
 *   func_0216D5A8  0x0216D5A8  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D5A8(u32);
extern u32 func_02197EDC(u32, u32, u32, u32);

int func_0219A638(u32 a, u32 b, u32 c, u32 d)
{
if (func_02197EDC(a, b, c, d) == 0) {
    return 0;
}
if (func_0216D5A8(a) != 11) {
    *(u32 *)((u8 *)(b) + 4) = 0;
}
*(u8 *)((u8 *)(b) + 2) = 2;
return 1;
}

