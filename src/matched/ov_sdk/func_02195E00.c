/*
 * function: func_02195E00
 * address:  0x02195E00
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Maps the word at +0xc onto 0..3.
 */

int func_02195E00(const int *p)
{
    int v = p[3];

    if (v < 5)
        return 0;
    if (v == 5)
        return 1;
    return v == 6 ? 2 : 3;
}
