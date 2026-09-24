/*
 * function: func_021641C4
 * address:  0x021641C4
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Lexicographic compare of two halfword arrays from the top down: 1, -1 or
 * 0.
 *
 * symbols:
 *

 */

int func_021641C4(unsigned short *a, unsigned short *b, int n)
{
    int i;

    for (i = n - 1; i >= 0; i--) {
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return -1;
    }
    return 0;
}


