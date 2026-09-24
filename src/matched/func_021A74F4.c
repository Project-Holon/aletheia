/*
 * function: func_021A74F4
 * address:  0x021A74F4
 * packet:   pkt_021A74F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns 0 when the word at +0x8 is zero, else p[0] + 12 * i.
 *
 * symbols:
 *   func_021A74F4  0x021A74F4  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int func_021A74F4(int *p, int i)
{
    if (p[2] != 0)
        return p[0] + 12 * i;
    return 0;
}
