/*
 * file:     unit_02163F24_p04.c
 * unit:     yes
 * function: func_02164AA8, func_02164CC4, func_02164D20
 * address:  0x02164AA8
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
void CPSi_big_montpower(unsigned short *c, unsigned short *m, unsigned short *e, int digits, unsigned short *n);
void CPSi_big_from_char(unsigned short *d, unsigned char *s, int numbytes, int digits);
void CPSi_char_from_big(unsigned char *d, unsigned short *s, int numbytes);

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


void CPSi_big_from_char(unsigned short *d, unsigned char *s, int numbytes, int digits)
{
    MI_CpuFill8(d, 0, digits * 2);
    s += numbytes - 1;
    while (numbytes > 1) {
        *d++ = (unsigned short)(s[0] + (s[-1] << 8));
        s -= 2;
        numbytes -= 2;
    }
    if (numbytes > 0)
        *d = *s;
}

void CPSi_char_from_big(unsigned char *d, unsigned short *s, int numbytes)
{
    unsigned char *p;

    d += numbytes - 1;
    while (numbytes > 1) {
        p = d - 1;
        *d = (unsigned char)*s;
        d -= 2;
        *p = (unsigned char)(*s++ >> 8);
        numbytes -= 2;
    }
    if (numbytes > 0)
        *d = (unsigned char)*s;
}
