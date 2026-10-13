/*
 * function: invert_checksum
 * address:  0x02157808
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Maps the 0xffff sentinel onto itself and everything else onto its complement.
 *
 * symbols:

 */

unsigned int invert_checksum(unsigned int x)
{
    unsigned int y = x ^ 0xffffu;

    return y ? y : 0xffffu;
}

