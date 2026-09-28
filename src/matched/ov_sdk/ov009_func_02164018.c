/*
 * function: CPSi_big_add_small
 * address:  0x02164018
 * packet:   pkt_ov009_02164018
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_big_add_small (biginteger.o)
 *
 * symbols:
 */

void CPSi_big_add_small(unsigned short *c, unsigned short *a, unsigned short _b, int digits)
{
    unsigned long b = _b;
    unsigned long tmp;
    int i;

    for (i = 0; i < digits; i++) {
        tmp = b + a[i];
        c[i] = (unsigned short)tmp;
        b = tmp >> 16;
        if (b == 0)
            break;
    }
    if (c != a) {
        i++;
        for (; i < digits; i++)
            c[i] = a[i];
    }
}
