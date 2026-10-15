/*
 * function: gt2GetOutgoingBufferFreeSpace
 * address:  0x02195E50
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Difference of the two words at +0x54 and +0x58.
 */

int gt2GetOutgoingBufferFreeSpace(const int *p)
{
    return p[0x15] - p[0x16];
}
