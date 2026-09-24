/*
 * function: func_0218DD9C
 * address:  0x0218DD9C
 * packet:   pkt_0218DD9C
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

int func_0218DD9C(u32 a, u32 b, u32 c, u32 d)
{
*(u32 *)((u8 *)(a) + 4) = b;
*(u32 *)((u8 *)(a) + 8) = c;
*(u32 *)((u8 *)(a) + 12) = d;
return a;
}

