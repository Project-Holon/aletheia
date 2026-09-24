/*
 * function: func_021A5768
 * address:  0x021A5768
 * packet:   pkt_021A5768
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
 *   (none)
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int func_021A5768(u32 a, u32 b)
{
if (b == 1) {
    *(u32 *)((u8 *)(a) + 28) = 1;
    return a;
}
*(u32 *)((u8 *)(a) + 28) = 0;
return a;
}

