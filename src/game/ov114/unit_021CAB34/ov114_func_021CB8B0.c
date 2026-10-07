/*
 * function: func_021CB8B0
 * address:  0x021CB8B0
 * packet:   pkt_ov114_021CB8B0
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_sub (libcrypto.TWL.HYB.a crypto_bobj1.o)
 * symbols:
 *   func_021CB664                    0x021cb664 arm ov114
 *   func_021CADAC                    0x021cadac arm ov114
 *   func_021CB078                    0x021cb078 arm ov114
 *   func_021CB764                    0x021cb764 arm ov114
 */

typedef unsigned long BN_ULONG;

typedef struct {
    BN_ULONG *d;
    int top;
    int dmax;
    int neg;
    int flags;
} BIGNUM;

extern BIGNUM *func_021CADAC(BIGNUM *a, int words);
extern int func_021CB664(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
extern int func_021CB078(const BIGNUM *a, const BIGNUM *b);
extern int func_021CB764(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);

#define bn_wexpand(a, words) (((words) <= (a)->dmax) ? (a) : func_021CADAC((a), (words)))

int func_021CB8B0(BIGNUM *r, const BIGNUM *a, const BIGNUM *b)
{
    int max;
    int add = 0, neg = 0;
    const BIGNUM *tmp;

    if (a->neg) {
        if (b->neg) {
            tmp = a;
            a = b;
            b = tmp;
        } else {
            add = 1;
            neg = 1;
        }
    } else {
        if (b->neg) {
            add = 1;
            neg = 0;
        }
    }

    if (add) {
        if (!func_021CB664(r, a, b))
            return 0;
        r->neg = neg;
        return 1;
    }

    max = (a->top > b->top) ? a->top : b->top;
    if (bn_wexpand(r, max) == 0)
        return 0;
    if (func_021CB078(a, b) < 0) {
        if (!func_021CB764(r, b, a))
            return 0;
        r->neg = 1;
    } else {
        if (!func_021CB764(r, a, b))
            return 0;
        r->neg = 0;
    }
    return 1;
}
