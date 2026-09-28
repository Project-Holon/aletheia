/*
 * function: CPSi_big_sign
 * address:  0x02163F4C
 * packet:   pkt_ov009_02163F4C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_big_sign (biginteger.o)
 *
 * symbols:
 *   count_digits                     0x02163f24 arm
 */

int count_digits(unsigned short *a, int digits);

int CPSi_big_sign(unsigned short *a, int digits)
{
    if (a[digits - 1] & 0x8000)
        return -1;
    return count_digits(a, digits) != 0;
}
