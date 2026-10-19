/*
 * function: CPSi_big_montmult
 * address:  0x0216497C
 * packet:   pkt_ov009_0216497C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_big_montmult (libssl.TWL.HYB.a(biginteger.o))
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 *   CPSi_big_sqr  0x02164358  arm  ov009
 *   CPSi_big_mult  0x02164230  arm  ov009
 *   MI_CpuFill8  0x02082BCC  arm
 *   CPSi_big_add  0x02163F7C  arm  ov009
 *   memmove  0x02092364  arm
 *   CPSi_big_compare  0x021641C4  arm  ov009
 *   CPSi_big_sub  0x021640B8  arm  ov009
 */

extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void CPSi_big_sqr(unsigned short *c, unsigned short *a, int digits);
extern void CPSi_big_mult(unsigned short *c, unsigned short *a, unsigned short *b, int digits);
extern void CPSi_big_add(unsigned short *c, unsigned short *a, unsigned short *b, int digits);
extern void *memmove(void *dst, const void *src, unsigned long n);
extern int CPSi_big_compare(unsigned short *a, unsigned short *b, int digits);
extern void CPSi_big_sub(unsigned short *c, unsigned short *a, unsigned short *b, int digits);

static void CPSi_big_montmult(unsigned short *c, unsigned short *a, unsigned short *b, int digits,
                          int rdigits, unsigned short *n, unsigned short *np,
                          unsigned short *m, unsigned short *m2)
{
    MI_CpuCopy8(c, a, digits * 2);
    if (b == (unsigned short *)1)
        CPSi_big_sqr(c, a, digits);
    else if (b != 0)
        CPSi_big_mult(c, a, b, digits);
    CPSi_big_mult(m, c, np, rdigits);
    MI_CpuFill8(m + rdigits, 0, (digits - rdigits) * 2);
    CPSi_big_mult(m2, m, n, digits);
    CPSi_big_add(c, c, m2, digits);
    memmove(c, c + rdigits, (digits - rdigits) * 2);
    MI_CpuFill8(c + digits - rdigits, 0, rdigits * 2);
    switch (CPSi_big_compare(c, n, digits)) {
    case 0:
        MI_CpuFill8(c, 0, digits * 2);
        break;
    case 1:
        CPSi_big_sub(c, c, n, digits);
        break;
    }
}
