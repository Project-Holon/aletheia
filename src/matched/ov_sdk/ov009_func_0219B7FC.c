/*
 * function: swap_byte
 * address:  0x0219B7FC
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Swaps two bytes.
 */

void swap_byte(unsigned char *p, unsigned char *q)
{
    unsigned char t = *p;

    *p = *q;
    *q = t;
}
