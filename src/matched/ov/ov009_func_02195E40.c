/*
 * function: gt2GetLocalPort
 * address:  0x02195E40
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Halfword at +8.
 */

unsigned short gt2GetLocalPort(const unsigned short *p)
{
    return p[4];
}
