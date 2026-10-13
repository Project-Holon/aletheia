/*
 * function: gt2SetConnectionData
 * address:  0x02195E70
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores a word at +0x40.
 */

void gt2SetConnectionData(int *p, int v)
{
    p[0x10] = v;
}
