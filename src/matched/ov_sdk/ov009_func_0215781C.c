/*
 * function: calc_checksum
 * address:  0x0215781C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The halfword the three-argument call lands on, tested.
 *
 * symbols:
 *   calc_checksum_do  0x02157700  arm  ov009
 *   invert_checksum  0x02157808  arm
 */

extern unsigned long calc_checksum_do(unsigned char *s, unsigned long len, unsigned long sum);
extern unsigned int invert_checksum(unsigned int x);

int calc_checksum(int a, int b)
{
    return invert_checksum((unsigned short)calc_checksum_do((unsigned char *)a, b, 0));
}

