/*
 * function: CPSi_big_mult_small
 * address:  0x021642E0
 * packet:   pkt_ov009_021642E0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_big_mult_small (biginteger.o)
 *
 * symbols:
 *   count_digits                     0x02163f24 arm
 *   MI_CpuFill8                      0x02082bcc arm
 */

int count_digits(unsigned short *a, int digits);
void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);

void CPSi_big_mult_small(unsigned short *c, unsigned short *a, unsigned short b, int digits)
{
    unsigned long tmp;
    unsigned long carry;
    int digits_a;
    int i;

    digits_a = count_digits(a, digits);
    carry = 0;
    for (i = 0; i < digits_a; i++) {
        tmp = b * a[i] + carry;
        c[i] = (unsigned short)tmp;
        carry = tmp >> 16;
    }
    if (i < digits) {
        c[i] = (unsigned short)carry;
        i++;
    }
    MI_CpuFill8(&c[i], 0, (digits - i) * 2);
}
