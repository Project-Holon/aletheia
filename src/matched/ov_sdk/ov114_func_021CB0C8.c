/*
 * function: func_021CB0C8
 * address:  0x021CB0C8
 * packet:   pkt_ov114_021CB0C8
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_set_bit (libcrypto.TWL.HYB.a(crypto_bobj1.o))
 *
 * symbols:
 *   func_021CADAC  0x021CADAC  arm  ov114
 */

typedef struct {
	unsigned long *d;
	int top;
	int dmax;
	int neg;
	int flags;
} BIGNUM;

extern BIGNUM *func_021CADAC(BIGNUM *a, int words);

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
