/*
 * function: CPSi_big_add_part
 * address:  0x021641FC
 * packet:   pkt_ov009_021641FC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_big_add_part (biginteger.o)
 *
 * symbols:
 */

void CPSi_big_add_part(unsigned short *a, unsigned long b, int i, int digits)
{
    unsigned long tmp;

    while (b != 0 && i < digits) {
        tmp = a[i] + b;
        a[i] = (unsigned short)tmp;
        i++;
        b = tmp >> 16;
    }
}
