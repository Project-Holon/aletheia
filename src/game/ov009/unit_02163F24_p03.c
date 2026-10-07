/*
 * file:     unit_02163F24_p03.c
 * unit:     yes
 * function: func_0216469C, func_02164830, func_0216497C
 * address:  0x0216469C
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
 *   func_02082BCC  0x02082BCC  arm
 *   func_02163F24  0x02163F24  arm  ov009
 *   func_02082D44  0x02082D44  arm
 *   func_02164358  0x02164358  arm  ov009
 *   func_021644D0  0x021644D0  arm  ov009
 *   func_02164230  0x02164230  arm  ov009
 *   g_021A8280     0x021A8280  data
 *   g_021A82B0     0x021A82B0  data
 *   func_02163F4C  0x02163F4C  arm  ov009
 *   func_021640B8  0x021640B8  arm  ov009
 *   func_02163F7C  0x02163F7C  arm  ov009
 *   func_02092364  0x02092364  arm
 *   func_021641C4  0x021641C4  arm  ov009
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32;

extern void func_02082BCC(void *dstp, u8 data, u32 size);
extern int func_02163F24(const unsigned short *p, int n);
extern void func_02082D44(void *srcp, void *dstp, u32 size);
extern void func_02164358(u16 *c, u16 *a, int digits);
extern void func_021644D0(u16 *c, u16 *a, u16 *b, u16 *r, int digits, u16 *work);
extern void func_02164230(u16 *c, u16 *a, u16 *b, int digits);
extern int func_02163F4C(unsigned short *a, int digits);
extern void func_021640B8(unsigned short *c, unsigned short *a, unsigned short *b, int digits);
extern void func_02163F7C(unsigned short *c, unsigned short *a, unsigned short *b, int digits);
extern void *func_02092364(void *dst, const void *src, unsigned long n);
extern int func_021641C4(unsigned short *a, unsigned short *b, int digits);
void func_0216469C(u16 *c, u16 *a, u16 *b, int digits, u16 *n);

extern void *(*g_021A8280)(u32 size);

extern void (*g_021A82B0)(void *ptr);


/*
 * sdk:      CPSi_big_power (libssl.TWL.HYB.a(biginteger.o))
 */
void func_0216469C(u16 *c, u16 *a, u16 *b, int digits, u16 *n)
{
    u16 *tmp;
    u16 *divwork;
    int i;

    tmp = g_021A8280(digits * sizeof(u16) * 4);
    if (tmp == 0)
        return;
    divwork = tmp + digits;
    func_02082BCC(c + 1, 0, (digits - 1) * sizeof(u16));
    c[0] = 1;
    for (i = (digits - func_02163F24(b, digits)) * 16; i < digits * sizeof(u16) * 8; i++) {
        if (b[digits - (i >> 4) - 1] & (0x8000u >> (i & 15))) {
            func_02082D44(a, c, digits * sizeof(u16));
            i++;
            break;
        }
    }
    for (; i < digits * sizeof(u16) * 8; i++) {
        func_02164358(tmp, c, digits);
        func_02082D44(tmp, c, digits * sizeof(u16));
        if (n)
            func_021644D0(0, c, n, c, digits, divwork);
        if (b[digits - (i >> 4) - 1] & (0x8000u >> (i & 15))) {
            func_02164230(tmp, c, a, digits);
            func_02082D44(tmp, c, digits * sizeof(u16));
            if (n)
                func_021644D0(0, c, n, c, digits, divwork);
        }
    }
    g_021A82B0(tmp);
}


/*
 * sdk:      CPSi_big_modinv (libssl.TWL.HYB.a(biginteger.o))
 */
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

    func_02082D44(a, tmp_var, digits * 2);
    func_02082D44(n, t, digits * 2);
    u[0] = 1;
    while (func_02163F4C(tmp_var, digits) > 0) {
        func_021644D0(q, t, tmp_var, w, digits, divwork);
        func_02082D44(tmp_var, t, digits * 2);
        func_02082D44(w, tmp_var, digits * 2);
        func_02164230(w, q, u, digits);
        func_021640B8(w, v, w, digits);
        func_02082D44(u, v, digits * 2);
        func_02082D44(w, u, digits * 2);
    }
    func_02163F7C(v, v, n, digits);
    func_021644D0(0, v, n, c, digits, divwork);
}


/*
 * sdk:      CPSi_big_montmult (libssl.TWL.HYB.a(biginteger.o))
 */
static void func_0216497C(unsigned short *c, unsigned short *a, unsigned short *b, int digits,
                          int rdigits, unsigned short *n, unsigned short *np,
                          unsigned short *m, unsigned short *m2)
{
    func_02082D44(c, a, digits * 2);
    if (b == (unsigned short *)1)
        func_02164358(c, a, digits);
    else if (b != 0)
        func_02164230(c, a, b, digits);
    func_02164230(m, c, np, rdigits);
    func_02082BCC(m + rdigits, 0, (digits - rdigits) * 2);
    func_02164230(m2, m, n, digits);
    func_02163F7C(c, c, m2, digits);
    func_02092364(c, c + rdigits, (digits - rdigits) * 2);
    func_02082BCC(c + digits - rdigits, 0, rdigits * 2);
    switch (func_021641C4(c, n, digits)) {
    case 0:
        func_02082BCC(c, 0, digits * 2);
        break;
    case 1:
        func_021640B8(c, c, n, digits);
        break;
    }
}
