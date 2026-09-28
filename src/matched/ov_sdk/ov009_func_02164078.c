/*
 * function: CPSi_big_negate
 * address:  0x02164078
 * packet:   pkt_ov009_02164078
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_big_negate (biginteger.o)
 *
 * symbols:
 *   CPSi_big_add_small               0x02164018 arm
 */

void CPSi_big_add_small(unsigned short *c, unsigned short *a, unsigned short _b, int digits);

void CPSi_big_negate(unsigned short *a, int digits)
{
    int i;

    for (i = 0; i < digits; i++)
        a[i] = ~a[i];
    CPSi_big_add_small(a, a, 1, digits);
}
