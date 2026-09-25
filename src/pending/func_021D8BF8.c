/*
 * function: func_021D8BF8
 * address:  0x021D8BF8
 * packet:   pkt_021D8BF8
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * blocker:  data relocation to 0x021DAA88 has no witness outside the compared
 *           range: its only referring literal pool words are inside this
 *           function (and its twin), and the address is not a known data
 *           start, so the site caps at MATCH.
 *
 * symbols:
 *   d_021DAA88  0x021DAA88  data  ov121  a4
 *
 * Addresses are Black-image addresses.
 */

extern unsigned int d_021DAA88;

void func_021D8BF8(int a, int b)
{
    *(unsigned int *)(d_021DAA88 + 0x814) = a;
    *(unsigned int *)(d_021DAA88 + 0x818) = b;
}
