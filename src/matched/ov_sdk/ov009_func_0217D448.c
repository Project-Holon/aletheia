/*
 * function: gsiLargeIntCompare
 * address:  0x0217D448
 * packet:   pkt_02156B70
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Big-number vector compare.  Both operands are little-endian limbs with the
 * length given separately; trailing zero limbs are trimmed off each operand
 * first, then the trimmed lengths decide, then the limbs are walked from the
 * top.  -1 / 1 / 0 as usual.
 */

typedef unsigned int u32;

int gsiLargeIntCompare(const u32 *a, u32 n, const u32 *b, u32 m)
{
    while (a[n - 1] == 0 && n != 0)
        n--;
    while (b[m - 1] == 0 && m != 0)
        m--;
    if (n < m)
        return -1;
    if (n > m)
        return 1;
    while (n != 0) {
        if (a[n - 1] < b[n - 1])
            return -1;
        if (a[n - 1] > b[n - 1])
            return 1;
        n--;
    }
    return 0;
}
