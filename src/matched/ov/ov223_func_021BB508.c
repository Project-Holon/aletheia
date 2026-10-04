/*
 * function: func_021BB508
 * address:  0x021BB508
 * packet:   pkt_021BB508
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02027A04  0x02027A04  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
extern u8 func_02027A04(const u8 *p);

int func_021BB508(int *p)
{
    return func_02027A04((const u8 *)p[0x99]) == 0;
}
