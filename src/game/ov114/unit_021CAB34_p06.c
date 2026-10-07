/*
 * file:     unit_021CAB34_p06.c
 * unit:     yes
 * function: func_021CB0C8, func_021CB15C, func_021CB1A8
 * address:  0x021CB0C8
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

typedef unsigned int u32;

typedef struct
{
    u32 *bits;
    int count;
} Bitset;

extern BIGNUM *func_021CADAC(BIGNUM *a, int words);
extern void func_02082BCC(void *dst, int data, unsigned long size);
extern void func_021CAC8C(BIGNUM *a);
int func_021CB0C8(BIGNUM *a, int n);
int func_021CB15C(Bitset *p, int bit);
int func_021CB1A8(BIGNUM *r, BIGNUM *a, int n);


/*
 * sdk:      CRYPTOi__BN_set_bit (libcrypto.TWL.HYB.a(crypto_bobj1.o))
 */
int func_021CB0C8(BIGNUM *a, int n)
{
	int i, j, k;

	i = n / 32;
	j = n % 32;
	if (a->top <= i) {
		if (((i + 1 > a->dmax) ? func_021CADAC(a, i + 1) : a) == 0)
			return 0;
		for (k = a->top; k < i + 1; k++)
			a->d[k] = 0;
		a->top = i + 1;
	}
	a->d[i] |= (1 << j);
	return 1;
}


int func_021CB15C(Bitset *p, int bit)
{
    int idx;
    int sh;

    if (bit < 0)
        return 0;
    idx = bit / 32;
    sh = bit % 32;
    if (p->count <= idx)
        return 0;
    return (p->bits[idx] & (1u << sh)) ? 1 : 0;
}


/*
 * sdk:      CRYPTOi__BN_lshift (libcrypto.TWL.HYB.a(crypto_bobj1.o))
 */
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
