/*
 * function: func_02164358
 * address:  0x02164358
 * region:   ov009
 * status:   MATCH (near miss, lane w8_s5, no shard)
 * note:     CPSi_big_sqr, 13 B differ: cmp operand order (r1,r2 vs r2,r1) in the first loop and the second loop's i/j/sum registers (target i=r5 j=r6 sum=r4; ours i=r5 j=r4 sum=r6); vendor locals i,j,digits_a,tmp only. Draft uses an extra k.
 */
extern int func_02163F24(unsigned short *a, int digits);
extern void func_02082BCC(void *dst, unsigned char data, unsigned long size);
extern void func_021641FC(unsigned short *a, unsigned long b, int i, int digits);

void func_02164358(unsigned short *c, unsigned short *a, int digits)
{
    int i;
    int j;
    int k;
    int digits_a;
    unsigned long tmp;

    digits_a = func_02163F24(a, digits);
    if (digits > digits_a * 2)
        func_02082BCC(c + digits_a * 2, 0, (digits - digits_a * 2) * 2);
    for (i = 0; i < digits_a; i++) {
        if (i * 2 >= digits)
            break;
        tmp = a[i] * a[i];
        c[i * 2] = (unsigned short)tmp;
        if (i * 2 == digits - 1)
            break;
        c[i * 2 + 1] = (unsigned short)(tmp >> 16);
    }
    for (k = 0; k < digits_a; k++) {
        for (j = k + 1; j < digits_a && k + j < digits; j++) {
            tmp = a[j] * a[k];
            if (tmp <= 0x7FFF8000) {
                func_021641FC(c, tmp * 2, k + j, digits);
            } else {
                func_021641FC(c, tmp, k + j, digits);
                func_021641FC(c, tmp, k + j, digits);
            }
        }
    }
}
