/*
 * function: CPSi_big_montpower
 * address:  0x02164AA8
 * packet:   pkt_ov009_02164AA8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_big_montpower (biginteger.o)
 *
 * symbols:
 *   MI_CpuFill8         0x02082BCC  arm
 *   count_digits        0x02163F24  arm  ov009
 *   CPSi_big_modinv     0x02164830  arm  ov009
 *   CPSi_big_mult       0x02164230  arm  ov009
 *   CPSi_big_sub_small  0x02164160  arm  ov009
 *   CPSi_big_div        0x021644D0  arm  ov009
 *   CPSi_big_montmult   0x0216497C  arm  ov009
 *   g_021A8280          0x021A8280  data
 *   g_021A82B0          0x021A82B0  data
 */

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int count_digits(unsigned short *a, int digits);
extern void CPSi_big_modinv(unsigned short *c, unsigned short *a, unsigned short *n, int digits, unsigned short *tmp_var);
extern void CPSi_big_mult(unsigned short *c, unsigned short *a, unsigned short *b, int digits);
extern void CPSi_big_sub_small(unsigned short *c, unsigned short *a, unsigned short _b, int digits);
extern void CPSi_big_div(unsigned short *c, unsigned short *a, unsigned short *b, unsigned short *r, int digits, unsigned short *work);
extern void CPSi_big_montmult(unsigned short *c, unsigned short *a, unsigned short *b, int digits, int rdigits, unsigned short *n, unsigned short *np, unsigned short *m, unsigned short *m2);
extern unsigned short *(*g_021A8280)(unsigned long size);
extern void (*g_021A82B0)(void *ptr);

void CPSi_big_montpower(unsigned short *c, unsigned short *m, unsigned short *e, int digits, unsigned short *n)
{
    int rdigits;
    int i;
    unsigned short *tmp_var;
    unsigned short *ri;
    unsigned short *mr;
    unsigned short *tmp;
    unsigned short *tmp2;
    unsigned short *tmp3;
    unsigned short *divwork;

    tmp_var = g_021A8280(digits * 22);
    if (tmp_var == 0)
        return;
    i = 0;
    MI_CpuFill8(tmp_var, 0, digits * 22);
    ri = tmp_var + digits;
    mr = ri + digits;
    tmp = mr + digits;
    tmp2 = tmp + digits;
    tmp3 = tmp2 + digits;
    divwork = tmp3 + digits;
    rdigits = count_digits(n, digits);
    tmp_var[rdigits] = 1;
    CPSi_big_modinv(ri, tmp_var, n, digits, mr);
    CPSi_big_mult(tmp, tmp_var, ri, digits);
    CPSi_big_sub_small(ri, tmp, 1, digits);
    CPSi_big_div(ri, ri, n, 0, digits, divwork);
    CPSi_big_mult(mr, m, tmp_var, digits);
    CPSi_big_div(0, mr, n, mr, digits, divwork);
    CPSi_big_div(0, tmp_var, n, c, digits, divwork);
    for (i = 0; (unsigned)i < (unsigned)(rdigits * 16); i++) {
        CPSi_big_montmult(c, tmp3, (unsigned short *)1, digits, rdigits, n, ri, tmp, tmp2);
        if (e[rdigits - (i >> 4) - 1] & (0x8000u >> (i & 15)))
            CPSi_big_montmult(c, tmp3, mr, digits, rdigits, n, ri, tmp, tmp2);
    }
    CPSi_big_montmult(c, tmp3, 0, digits, rdigits, n, ri, tmp, tmp2);
    g_021A82B0(tmp_var);
}
