/*
 * function: CRYPTOi__BN_lshift
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
 *   CRYPTOi__bn_expand2  0x021CADAC  arm  ov114
 *   MI_CpuFill8  0x02082BCC  arm
 *   CRYPTOi__bn_fix_top  0x021CAC8C  arm  ov114
 */

typedef struct {
	unsigned long *d;
	int top;
	int dmax;
	int neg;
	int flags;
} BIGNUM;

extern BIGNUM *CRYPTOi__bn_expand2(BIGNUM *a, int words);
extern void MI_CpuFill8(void *dst, int data, unsigned long size);
extern void CRYPTOi__bn_fix_top(BIGNUM *a);

int CRYPTOi__BN_lshift(BIGNUM *r, BIGNUM *a, int n)
{
	int i, nw, lb, rb;
	unsigned long *t, *f;
	unsigned long l;

	nw = n / 32;
	if (((a->top + nw + 1 > r->dmax) ? CRYPTOi__bn_expand2(r, a->top + nw + 1) : r) == 0)
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
	MI_CpuFill8(t, 0, nw * 4);
	r->top = a->top + nw + 1;
	CRYPTOi__bn_fix_top(r);
	return 1;
}
