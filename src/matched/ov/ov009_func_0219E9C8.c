/*
 * function: SBServerSetState
 * address:  0x0219E9C8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores a byte at +0x14.
 */

void SBServerSetState(unsigned char *p, unsigned char v)
{
    p[0x14] = v;
}
