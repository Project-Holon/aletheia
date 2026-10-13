/*
 * function: func_02164830
 * address:  0x02164830
 * packet:   pkt_ov009_02164830
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_big_modinv (libssl.TWL.HYB.a(biginteger.o))
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_02163F4C  0x02163F4C  arm  ov009
 *   func_021644D0  0x021644D0  arm  ov009
 *   func_02164230  0x02164230  arm  ov009
 *   func_021640B8  0x021640B8  arm  ov009
 *   func_02163F7C  0x02163F7C  arm  ov009
 */

extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern int func_02163F4C(unsigned short *a, int digits);
extern void func_021644D0(unsigned short *c, unsigned short *a, unsigned short *b,
                          unsigned short *r, int digits, unsigned short *work);
extern void func_02164230(unsigned short *c, unsigned short *a, unsigned short *b, int digits);
extern void func_021640B8(unsigned short *c, unsigned short *a, unsigned short *b, int digits);
extern void func_02163F7C(unsigned short *c, unsigned short *a, unsigned short *b, int digits);

static void func_02164830(unsigned short *c, unsigned short *a, unsigned short *n, int digits,
                          unsigned short *tmp_var)
{
    unsigned short *q;
    unsigned short *t;
    unsigned short *u;
    unsigned short *v;
    unsigned short *w;
    unsigned short *divwork;

    q = tmp_var + digits;
    t = q + digits;
    u = t + digits;
    v = u + digits;
    w = v + digits;
    divwork = w + digits;

    MI_CpuCopy8(a, tmp_var, digits * 2);
    MI_CpuCopy8(n, t, digits * 2);
    u[0] = 1;
    while (func_02163F4C(tmp_var, digits) > 0) {
        func_021644D0(q, t, tmp_var, w, digits, divwork);
        MI_CpuCopy8(tmp_var, t, digits * 2);
        MI_CpuCopy8(w, tmp_var, digits * 2);
        func_02164230(w, q, u, digits);
        func_021640B8(w, v, w, digits);
        MI_CpuCopy8(u, v, digits * 2);
        MI_CpuCopy8(w, u, digits * 2);
    }
    func_02163F7C(v, v, n, digits);
    func_021644D0(0, v, n, c, digits, divwork);
}
