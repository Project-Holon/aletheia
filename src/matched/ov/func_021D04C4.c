/*
 * function: func_021D04C4
 * address:  0x021D04C4
 * packet:   pkt_021D04C4
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

int func_021D04C4(u32 a, u32 b, u32 c, u32 d)
{
if (a != 0) {
    return *(u16 *)((u8 *)(func_021AC1E0(a, b, c, d)) + 28);
}
return 1;
}

