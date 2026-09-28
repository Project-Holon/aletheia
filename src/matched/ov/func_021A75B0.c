/*
 * function: func_021A75B0
 * address:  0x021A75B0
 * packet:   pkt_021A75B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: clears bit 0 of the word at +0.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_021A75B0(u32 *p)
{
    p[0] &= ~1;
}
