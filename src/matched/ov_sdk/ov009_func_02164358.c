/*
 * function: func_02164358
 * address:  0x02164358
 * packet:   pkt_ov009_02164358
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_big_sqr (libssl.TWL.HYB.a(biginteger.o))
 *
 * symbols:
 *   func_02163F24  0x02163F24  arm  ov009
 *   func_02082BCC  0x02082BCC  arm
 *   func_021641FC  0x021641FC  arm  ov009
 */

extern int func_02163F24(unsigned short *a, int digits);
extern void func_02082BCC(void *dst, unsigned char data, unsigned long size);
extern void func_021641FC(unsigned short *a, unsigned long b, int i, int digits);

void func_02164358(unsigned short *c, unsigned short *a, int digits)
{
    int i;
    int j;
    int digits_a;
    unsigned long tmp;

    digits_a = func_02163F24(a, digits);
    if (digits > digits_a * 2)
        func_02082BCC(c + digits_a * 2, 0, (digits - digits_a * 2) * 2);
    for (i = 0; i < digits_a; i++) {
        j = i * 2;
        if (j >= digits)
            break;
        tmp = a[i] * a[i];
        c[j] = (unsigned short)tmp;
        if (j == digits - 1)
            break;
        c[j + 1] = (unsigned short)(tmp >> 16);
    }
    for (i = 0; i < digits_a; i++) {
        for (j = i + 1; j < digits_a && i + j < digits; j++) {
            tmp = a[j] * a[i];
            if (tmp <= 0x7FFF8000)
                func_021641FC(c, tmp * 2, i + j, digits);
            else {
                func_021641FC(c, tmp, i + j, digits);
                func_021641FC(c, tmp, i + j, digits);
            }
        }
    }
}
