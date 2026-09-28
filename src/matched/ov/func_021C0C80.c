/*
 * function: func_021C0C80
 * address:  0x021C0C80
 * packet:   pkt_021C0C80
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
 *   func_0218C8D8  0x0218C8D8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0218C8D8(u32, u32, u32, u32);

int func_021C0C80(u32 a, u32 b, u32 c, u32 d)
{
if (*(u32 *)((u8 *)(a) + 52) != 0) {
    return func_0218C8D8(*(u32 *)((u8 *)(a) + 56), *(u32 *)((u8 *)(a) + 52), c, d);
}
return 1;
}

