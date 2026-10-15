/*
 * function: gti2GetBufferFreeSpace
 * address:  0x02194DD4
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Difference of the words at +4 and +8.
 */

int gti2GetBufferFreeSpace(const int *p)
{
    return p[1] - p[2];
}
