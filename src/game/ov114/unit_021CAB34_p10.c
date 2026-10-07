/*
 * file:     unit_021CAB34_p10.c
 * unit:     yes
 * function: func_021CC4A0, func_021CC530
 * address:  0x021CC4A0
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _u32_div_f     0x0209C2B0  arm
 *   func_021CADAC  0x021CADAC  arm  ov114
 *   func_021CC674  0x021CC674  arm  ov114
 *   g_021CE1F8  0x021CE1F8  data  ov114
 *   g_021CE1EE  0x021CE1EE  data  ov114
 *   g_021CE1E4  0x021CE1E4  data  ov114
 */
#define bn_wexpand(a, w) (((w) <= (a)->dmax) ? (a) : func_021CADAC((a), (w)))
typedef unsigned int BN_ULONG;

typedef struct
{
    BN_ULONG *d;
    int top;
    int dmax;
    int neg;
    int flags;
} BIGNUM;

typedef struct
{
    int tos;
    BIGNUM bn[13];
    int flags;
    int depth;
} BN_CTX;

extern BIGNUM *func_021CADAC(BIGNUM *, int);
extern int func_021CC674(unsigned char *, const BIGNUM *, int);
unsigned long func_021CC4A0(unsigned long n);
int func_021CC530(const BIGNUM *e, unsigned char **out, int unused, BN_CTX *ctx);
extern unsigned char g_021CE1F8[10];
extern unsigned char g_021CE1EE[10];
extern unsigned char g_021CE1E4[10];

/*
 * sdk:      CRYPTOi__BN_mod_inverse_word (libcrypto.TWL.HYB.a(crypto_bobj1.o))
 */
unsigned long func_021CC4A0(unsigned long n)
{
	unsigned long a, b, q, r, t, res;
	unsigned long x0, x1;
	long sign;

	b = (0 - n) % n;
	x0 = 1;
	a = n;
	sign = -1;
	x1 = 0;
	while (b != 0) {
		q = a / b;
		r = a % b;
		t = q * x0 + x1;
		x1 = x0;
		x0 = t;
		a = b;
		b = r;
		sign = -sign;
	}
	if (sign < 0)
		x1 = n - x1;
	if (a == 1)
		res = x1 % n;
	else
		res = 0;
	return res;
}


/*
 * sdk:      CRYPTOi__BN_gen_exp_bits (crypto_bobj1.o)
 *
 * g_021CE1F8, g_021CE1EE, g_021CE1E4 are the object's local tables p16, p4, p2.
 */
int func_021CC530(const BIGNUM *e, unsigned char **out, int unused, BN_CTX *ctx)
{
    int top, bits, window, count, step, words, len;
    unsigned char *p;
    BIGNUM *tmp;

    tmp = &ctx->bn[ctx->tos];
    p = 0;
    top = e->top;
    bits = top << 5;
    if (top == 0)
        return 0;

    if (top == 1)
    {
        if (top == 1 && e->d[0] == 0x10001)
            p = g_021CE1F8;
        else if (e->d[0] == 0x11 && top == 1)
            p = g_021CE1EE;
        else if (e->d[0] == 3 && top == 1)
            p = g_021CE1E4;
        window = 1;
        count = 1;
        step = 32;
    }
    else if (bits >= 256)
    {
        window = 5;
        count = 16;
        step = 7;
    }
    else if (bits >= 128)
    {
        window = 4;
        count = 8;
        step = 8;
    }
    else
    {
        window = 3;
        count = 4;
        step = 11;
    }

    words = (top * step * 2 + 7) / 4;
    if (p == 0)
    {
        if (bn_wexpand(tmp, words) == 0)
            return 0;
        p = (unsigned char *)tmp->d;
        len = func_021CC674(p + 4, e, window) + 2;
        p[0] = len >> 8;
        p[1] = len;
        p[2] = window;
        p[3] = count;
    }
    else
    {
        len = 8;
    }
    *out = p;
    return len + 2;
}
