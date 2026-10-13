/*
 * function: CRYPTOi__BN_add_word
 * address:  0x021CB3B4
 * packet:   pkt_ov114_021CB3B4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_add_word (libcrypto.TWL.HYB.a(crypto_bobj1.o))
 *
 * symbols:
 *   CRYPTOi__BN_sub_word  0x021CB494  arm  ov114
 *   CRYPTOi__bn_expand2  0x021CADAC  arm  ov114
 *
 * BN_add_word: negative-a path either delegates to BN_sub_word (>1 word) or
 * inlines the single-word subtract, else expands and ripple-adds w.
 *
 * The vendor build pools the literal 0 in one register hoisted to the frame
 * head, and it is shared by all three sign/top stores (a->neg = 0 in the
 * multi-word branch, a->neg = 0 and a->top = 0 in the two single-word
 * branches).  Folding the shared `a->neg = 0` out of the inner if/else -- the
 * obvious spelling, and two literals instead of three -- loses the pool and
 * costs 46 bytes of register churn.  `l = w + a->d[i]` keeps the loop add's
 * operand order.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov114_func_021CB3B4.c \
 *       --func CRYPTOi__BN_add_word --addr 0x021CB3B4 --region ov114 --arm --cc 1.1p1 \
 *       --lang c99
 */

typedef struct {
	unsigned long *d;
	int top;
	int dmax;
	int neg;
	int flags;
} BIGNUM;

extern int CRYPTOi__BN_sub_word(BIGNUM *a, unsigned long w);
extern BIGNUM *CRYPTOi__bn_expand2(BIGNUM *a, int words);

int CRYPTOi__BN_add_word(BIGNUM *a, unsigned long w)
{
	unsigned long l;
	int i;

	if (w == 0)
		return 1;
	if (a->neg) {
		if (a->top > 1) {
			a->neg = 0;
			i = CRYPTOi__BN_sub_word(a, w);
			a->neg = 1;
			return i;
		}
		l = a->d[0];
		if (l > w) {
			a->d[0] = l - w;
		} else if (l < w) {
			a->neg = 0;
			a->d[0] = w - l;
		} else {
			a->neg = 0;
			a->top = 0;
		}
		return 1;
	}
	if (((a->top + 1 > a->dmax) ? CRYPTOi__bn_expand2(a, a->top + 1) : a) == 0)
		return 0;
	a->d[a->top] = 0;
	i = 0;
	for (;;) {
		l = w + a->d[i];
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
