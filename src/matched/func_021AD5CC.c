/*
 * function: func_021AD5CC
 * address:  0x021AD5CC
 * packet:   pkt_021AD5CC
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
 *   func_021AC1E0  0x021AC1E0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021AC1E0(u32, u32, u32, u32);

int func_021AD5CC(u32 a, u32 b, u32 c, u32 d)
{
if (a != 0) {
    return *(u32 *)((u8 *)(func_021AC1E0(a, b, c, d)) + 12);
}
return 1;
}

