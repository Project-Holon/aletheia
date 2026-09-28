/*
 * function: func_021CB5A0
 * address:  0x021CB5A0
 * packet:   pkt_ov114_021CB5A0
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_add (libcrypto.TWL.HYB.a(crypto_bobj1.o))
 *
 * symbols:
 *   func_021CB078  0x021CB078  arm  ov114
 *   func_021CB764  0x021CB764  arm  ov114
 *   func_021CB664  0x021CB664  arm  ov114
 */

typedef struct {
	unsigned long *d;
	int top;
	int dmax;
	int neg;
	int flags;
} BIGNUM;

extern int func_021CB078(BIGNUM *a, BIGNUM *b);
extern int func_021CB764(BIGNUM *r, BIGNUM *a, BIGNUM *b);
extern int func_021CB664(BIGNUM *r, BIGNUM *a, BIGNUM *b);

int func_021CB5A0(BIGNUM *r, BIGNUM *a, BIGNUM *b)
{
	BIGNUM *tmp;
	int a_neg = a->neg;

	if (a_neg ^ b->neg) {
		if (a_neg) {
			tmp = a;
			a = b;
			b = tmp;
		}
		if (func_021CB078(a, b) < 0) {
			if (func_021CB764(r, b, a) == 0)
				return 0;
			r->neg = 1;
		} else {
			if (func_021CB764(r, a, b) == 0)
				return 0;
			r->neg = 0;
		}
		return 1;
	}
	if (a_neg)
		r->neg = 1;
	else
		r->neg = 0;
	if (func_021CB664(r, a, b) == 0)
		return 0;
	return 1;
}
