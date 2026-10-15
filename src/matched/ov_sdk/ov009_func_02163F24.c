/*
 * function: count_digits
 * address:  0x02163F24
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Drops trailing zero halfwords from a counted array.
 */

int count_digits(const unsigned short *p, int n)
{
    while (n != 0 && p[n - 1] == 0)
        n--;
    return n;
}
