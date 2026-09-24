/*
 * function: func_021C2ECC
 * address:  0x021C2ECC
 * packet:   pkt_021C2ECC
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

int func_021C2ECC(u32 a, u32 b)
{
return ((*(u16 *)((u8 *)(b)) << 3) + ((*(u32 *)((u8 *)(a) + 44) << 16) >> 13));
}

