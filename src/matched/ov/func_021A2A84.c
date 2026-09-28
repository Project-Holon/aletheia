/*
 * function: func_021A2A84
 * address:  0x021A2A84
 * packet:   pkt_021A2A84
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

int func_021A2A84(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 e1, u32 e2, u32 e3, u32 e4, u32 e5)
{
*(u32 *)((u8 *)(a)) = b;
*(u16 *)((u8 *)(a) + 6) = 0;
*(u16 *)((u8 *)(a) + 10) = 0;
*(u16 *)((u8 *)(a) + 4) = d;
*(u16 *)((u8 *)(a) + 12) = e0;
*(u16 *)((u8 *)(a) + 8) = c;
*(u16 *)((u8 *)(a) + 14) = e1;
*(u16 *)((u8 *)(a) + 16) = e2;
*(u16 *)((u8 *)(a) + 18) = e3;
*(u32 *)((u8 *)(a) + 20) = e4;
*(u32 *)((u8 *)(a) + 24) = e5;
return a;
}

