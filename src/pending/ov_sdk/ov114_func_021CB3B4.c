/*
 * function: func_021CB3B4
 * address:  0x021CB3B4
 * packet:   pkt_ov114_021CB3B4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  20 mismatched words; original hoists constant 0 into r2 at entry (used by the neg/top stores), compiler here does not; 9 variants tried
 *
 * sdk:      CRYPTOi__BN_add_word (libcrypto.TWL.HYB.a(crypto_bobj1.o))
 *
 * symbols:
 *   func_021CB494  0x021CB494  arm  ov114
 *   func_021CADAC  0x021CADAC  arm  ov114
 */

typedef struct {
	unsigned long *d;
	int top;
	int dmax;
	int neg;
	int flags;
} BIGNUM;

extern int func_021CB494(BIGNUM *a, unsigned long w);
extern BIGNUM *func_021CADAC(BIGNUM *a, int words);

int func_021CB3B4(BIGNUM *a, unsigned long w)
{
	unsigned long l;
	int i;

	if (w == 0)
		return 1;
	if (a->neg) {
		if (a->top > 1) {
			a->neg = 0;
			i = func_021CB494(a, w);
			a->neg = 1;
			return i;
		}
		l = a->d[0];
		if (l > w) {
			a->d[0] = l - w;
		} else {
			a->neg = 0;
			if (l < w)
				a->d[0] = w - l;
			else
				a->top = 0;
		}
		return 1;
	}
	if (((a->top + 1 > a->dmax) ? func_021CADAC(a, a->top + 1) : a) == 0)
		return 0;
	a->d[a->top] = 0;
	i = 0;
	for (;;) {
		l = a->d[i];
		l = w + l;
		a->d[i] = l;
		if (w > l) {
			w = 1;
			i++;
		} else {
			break;
		}
	}
	if (i >= a->top)
		a->top++;
	return 1;
}
