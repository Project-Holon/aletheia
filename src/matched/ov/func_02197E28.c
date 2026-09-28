/*
 * function: func_02197E28
 * address:  0x02197E28
 * packet:   pkt_02197E28
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
 *   func_0216D454  0x0216D454  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D454(u32, u32, u32, u32);

int func_02197E28(u32 a, u32 b, u32 c, u32 d)
{
if (func_0216D454(*(u32 *)((u8 *)(a) + 12), b, c, d) == 0) {
    return 0;
}
*(u32 *)((u8 *)(a)) = 4;
return 1;
}

