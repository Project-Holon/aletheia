/*
 * function: func_021A66E4
 * address:  0x021A66E4
 * packet:   pkt_021A66E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: sets bits in the word at +4.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_021A66E4(u32 *p, u32 v)
{
    p[1] |= v;
}
