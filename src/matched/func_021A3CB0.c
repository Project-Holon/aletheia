/*
 * function: func_021A3CB0
 * address:  0x021A3CB0
 * packet:   pkt_021A3CB0
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

int func_021A3CB0(u32 a, u32 b)
{
*(u32 *)((u8 *)(a) + 36) = b;
*(u16 *)((u8 *)(a) + 48) = 0;
*(u16 *)((u8 *)(a) + 50) = 0;
*(u16 *)((u8 *)(a) + 44) = 0;
*(u16 *)((u8 *)(a) + 46) = 0;
return a;
}

