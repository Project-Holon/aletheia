/*
 * function: func_021A0C50
 * address:  0x021A0C50
 * packet:   pkt_021A0C50
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

int func_021A0C50(u32 a, u32 b, u32 c, u32 d)
{
*(u16 *)((u8 *)(a)) = 1;
*(u16 *)((u8 *)(a) + 2) = b;
*(u16 *)((u8 *)(a) + 4) = c;
*(u16 *)((u8 *)(a) + 6) = d;
return a;
}

