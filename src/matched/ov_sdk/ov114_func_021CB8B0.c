/*
 * function: CRYPTOi__BN_sub
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
 *   CRYPTOi__BN_uadd                    0x021cb664 arm ov114
 *   CRYPTOi__bn_expand2                    0x021cadac arm ov114
 *   CRYPTOi__BN_ucmp                    0x021cb078 arm ov114
 *   CRYPTOi__BN_usub                    0x021cb764 arm ov114
 */

typedef unsigned long BN_ULONG;

typedef struct {
    BN_ULONG *d;
    int top;
    int dmax;
    int neg;
    int flags;
} BIGNUM;

extern BIGNUM *CRYPTOi__bn_expand2(BIGNUM *a, int words);
extern int CRYPTOi__BN_uadd(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
extern int CRYPTOi__BN_ucmp(const BIGNUM *a, const BIGNUM *b);
extern int CRYPTOi__BN_usub(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);

#define bn_wexpand(a, words) (((words) <= (a)->dmax) ? (a) : CRYPTOi__bn_expand2((a), (words)))

int CRYPTOi__BN_sub(BIGNUM *r, const BIGNUM *a, const BIGNUM *b)
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
        if (!CRYPTOi__BN_uadd(r, a, b))
            return 0;
        r->neg = neg;
        return 1;
    }

    max = (a->top > b->top) ? a->top : b->top;
    if (bn_wexpand(r, max) == 0)
        return 0;
    if (CRYPTOi__BN_ucmp(a, b) < 0) {
        if (!CRYPTOi__BN_usub(r, b, a))
            return 0;
        r->neg = 1;
    } else {
        if (!CRYPTOi__BN_usub(r, a, b))
            return 0;
        r->neg = 0;
    }
    return 1;
}
