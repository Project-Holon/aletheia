/*
 * file:     unit_021CAB34_p07.c
 * unit:     yes
 * function: func_021CB494, func_021CB5A0
 * address:  0x021CB494
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
 *   func_021CADAC                    0x021cadac arm ov114
 *   func_021CB3B4                    0x021cb3b4 arm ov114
 *   func_021CB078  0x021CB078  arm  ov114
 *   func_021CB764  0x021CB764  arm  ov114
 *   func_021CB664  0x021CB664  arm  ov114
 */
#define bn_wexpand(a, words) (((words) <= (a)->dmax) ? (a) : func_021CADAC((a), (words)))
typedef unsigned long BN_ULONG;

typedef struct {
    BN_ULONG *d;
    int top;
    int dmax;
    int neg;
    int flags;
} BIGNUM_021CB494;

typedef struct {
	unsigned long *d;
	int top;
	int dmax;
	int neg;
	int flags;
} BIGNUM_021CB5A0;

extern BIGNUM_021CB494 *func_021CADAC(BIGNUM_021CB494 *a, int words);
extern int func_021CB3B4(BIGNUM_021CB494 *a, BN_ULONG w);
extern int func_021CB078(BIGNUM_021CB5A0 *a, BIGNUM_021CB5A0 *b);
extern int func_021CB764(BIGNUM_021CB5A0 *r, BIGNUM_021CB5A0 *a, BIGNUM_021CB5A0 *b);
extern int func_021CB664(BIGNUM_021CB5A0 *r, BIGNUM_021CB5A0 *a, BIGNUM_021CB5A0 *b);
int func_021CB494(BIGNUM_021CB494 *a, BN_ULONG w);
int func_021CB5A0(BIGNUM_021CB5A0 *r, BIGNUM_021CB5A0 *a, BIGNUM_021CB5A0 *b);


/*
 * sdk:      CRYPTOi__BN_sub_word (libcrypto.TWL.HYB.a crypto_bobj1.o)
 */
int func_021CB494(BIGNUM_021CB494 *a, BN_ULONG w)
{
    int i;

    if (w == 0)
        return 1;
    if (a->neg) {
        a->neg = 0;
        i = func_021CB3B4(a, w);
        a->neg = 1;
        return i;
    }
    if (a->top <= 1) {
        if (a->top == 0) {
            if (bn_wexpand(a, 1) == 0)
                return 0;
            a->d[0] = w;
            a->neg = 1;
            a->top = 1;
            return 1;
        }
        if (a->d[0] == w)
            a->top = 0;
        else if (a->d[0] > w)
            a->d[0] -= w;
        else {
            w -= a->d[0];
            a->neg = 1;
            a->d[0] = w;
        }
        return 1;
    }
    i = 0;
    for (;;) {
        if (a->d[i] >= w) {
            a->d[i] -= w;
            break;
        } else {
            a->d[i] -= w;
            i++;
            w = 1;
        }
    }
    if (a->d[i] == 0 && i == a->top - 1)
        a->top--;
    return 1;
}


/*
 * sdk:      CRYPTOi__BN_add (libcrypto.TWL.HYB.a(crypto_bobj1.o))
 */
int func_021CB5A0(BIGNUM_021CB5A0 *r, BIGNUM_021CB5A0 *a, BIGNUM_021CB5A0 *b)
{
	BIGNUM_021CB5A0 *tmp;
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
