/*
 * function: func_021CB1A8
 * address:  0x021CB1A8
 * packet:   pkt_ov114_021CB1A8
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_lshift (libcrypto.TWL.HYB.a(crypto_bobj1.o))
 *
 * symbols:
 *   func_021CADAC  0x021CADAC  arm  ov114
 *   func_02082BCC  0x02082BCC  arm
 *   func_021CAC8C  0x021CAC8C  arm  ov114
 */

typedef struct {
	unsigned long *d;
	int top;
	int dmax;
	int neg;
	int flags;
} BIGNUM;

extern BIGNUM *func_021CADAC(BIGNUM *a, int words);
extern void func_02082BCC(void *dst, int data, unsigned long size);
extern void func_021CAC8C(BIGNUM *a);

int func_021CB1A8(BIGNUM *r, BIGNUM *a, int n)
{
	int i, nw, lb, rb;
	unsigned long *t, *f;
	unsigned long l;

	nw = n / 32;
	if (((a->top + nw + 1 > r->dmax) ? func_021CADAC(r, a->top + nw + 1) : r) == 0)
		return 0;
	r->neg = a->neg;
	lb = n % 32;
	rb = 32 - lb;
	f = a->d;
	t = r->d;
	t[a->top + nw] = 0;
	if (lb == 0)
		for (i = a->top - 1; i >= 0; i--)
			t[nw + i] = f[i];
	else
		for (i = a->top - 1; i >= 0; i--) {
			l = f[i];
			t[nw + i + 1] |= (l >> rb);
			t[nw + i] = (l << lb);
		}
	func_02082BCC(t, 0, nw * 4);
	r->top = a->top + nw + 1;
	func_021CAC8C(r);
	return 1;
}
