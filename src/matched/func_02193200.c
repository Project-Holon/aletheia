/*
 * function: func_02193200
 * address:  0x02193200
 * packet:   pkt_02193200
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

int func_02193200(u32 a, u32 b)
{
*(u8 *)((u8 *)(a) + 1) = 0;
*(u8 *)((u8 *)(a) + 2) = 0;
return a;
}

