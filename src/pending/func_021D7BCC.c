/*
 * function: func_021D7BCC
 * address:  0x021D7BCC
 * packet:   pkt_021D7BCC
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * blocker:  data relocation to 0x021D9E40 has no witness outside the compared
 *           range: its only referring literal pool words are inside this
 *           function (and its twin), and the address is not a known data
 *           start, so the site caps at MATCH.
 *
 * symbols:
 *   d_021D9E40  0x021D9E40  data  ov121  a4
 *
 * Addresses are Black-image addresses.
 */

extern unsigned int d_021D9E40[];

unsigned int func_021D7BCC(void)
{
    return d_021D9E40[0x4f];
}
