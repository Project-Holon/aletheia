/*
 * function: CRYPTOi__BN_add
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
 *   CRYPTOi__BN_ucmp  0x021CB078  arm  ov114
 *   CRYPTOi__BN_usub  0x021CB764  arm  ov114
 *   CRYPTOi__BN_uadd  0x021CB664  arm  ov114
 */

typedef struct {
	unsigned long *d;
	int top;
	int dmax;
	int neg;
	int flags;
} BIGNUM;

extern int CRYPTOi__BN_ucmp(BIGNUM *a, BIGNUM *b);
extern int CRYPTOi__BN_usub(BIGNUM *r, BIGNUM *a, BIGNUM *b);
extern int CRYPTOi__BN_uadd(BIGNUM *r, BIGNUM *a, BIGNUM *b);

int CRYPTOi__BN_add(BIGNUM *r, BIGNUM *a, BIGNUM *b)
{
	BIGNUM *tmp;
	int a_neg = a->neg;

	if (a_neg ^ b->neg) {
		if (a_neg) {
			tmp = a;
			a = b;
			b = tmp;
		}
		if (CRYPTOi__BN_ucmp(a, b) < 0) {
			if (CRYPTOi__BN_usub(r, b, a) == 0)
				return 0;
			r->neg = 1;
		} else {
			if (CRYPTOi__BN_usub(r, a, b) == 0)
				return 0;
			r->neg = 0;
		}
		return 1;
	}
	if (a_neg)
		r->neg = 1;
	else
		r->neg = 0;
	if (CRYPTOi__BN_uadd(r, a, b) == 0)
		return 0;
	return 1;
}
