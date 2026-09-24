/*
 * function: func_021A7A28
 * address:  0x021A7A28
 * packet:   pkt_021A7A28
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

int func_021A7A28(u32 a, u32 b)
{
return (a + *(u32 *)((u8 *)((a + (b << 3))) + 4));
}

