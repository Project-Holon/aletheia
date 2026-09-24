/*
 * function: func_021A0FA0
 * address:  0x021A0FA0
 * packet:   pkt_021A0FA0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Guarded store of the second argument at +0x10.
 *
 * symbols:
 *   func_021A0FA0  0x021A0FA0  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_021A0FA0(int *p, int v)
{
    if (p == 0)
        return;
    p[4] = v;
}
