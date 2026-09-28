/*
 * function: func_02166680
 * address:  0x02166680
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Byte compare over n units: 0 at the first difference, 1 when all agree.
 *
 * symbols:
 *

 */

int func_02166680(unsigned char *a, unsigned char *b, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
        if (a[i] != b[i]) return 0;
    return 1;
}


