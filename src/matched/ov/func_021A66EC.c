/*
 * function: func_021A66EC
 * address:  0x021A66EC
 * packet:   pkt_021A66EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf: clears bits in the word at +4.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_021A66EC(u32 *p, u32 v)
{
    p[1] &= ~v;
}
