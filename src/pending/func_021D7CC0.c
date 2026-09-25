/*
 * function: func_021D7CC0
 * address:  0x021D7CC0
 * packet:   pkt_021D7CC0
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * blocker:  data relocation to 0x021DA174 has no witness outside the compared
 *           range: its only referring literal pool words are inside this
 *           function (and its twin), and the address is not a known data
 *           start, so the site caps at MATCH.
 *
 * symbols:
 *   func_02086078  0x02086078  arm
 *   d_021DA174     0x021DA174  data  ov121  a4
 *
 * Addresses are Black-image addresses.
 */

extern void func_02086078(void *);
extern char d_021DA174[];

void func_021D7CC0(void)
{
    func_02086078(d_021DA174);
}
