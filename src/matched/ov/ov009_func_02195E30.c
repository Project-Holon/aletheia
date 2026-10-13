/*
 * function: gt2GetRemotePort
 * address:  0x02195E30
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Halfword at +4.
 */

unsigned short gt2GetRemotePort(const unsigned short *p)
{
    return p[2];
}
