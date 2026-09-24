/*
 * function: func_021CA250
 * address:  0x021CA250
 * packet:   pkt_021CA250
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

int func_021CA250(u32 a, u32 b)
{
*(u16 *)((u8 *)(a) + 14) = 0;
return a;
}

