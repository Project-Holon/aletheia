/*
 * function: CRYPTOi__BN_rshift
 * address:  0x021CB2A4
 * packet:   pkt_ov114_021CB2A4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_rshift (libcrypto.TWL.HYB.a crypto_bobj1.o)
 * symbols:
 *   CRYPTOi__BN_set_word                    0x021caec8 arm ov114
 *   CRYPTOi__bn_expand2                    0x021cadac arm ov114
 *   CRYPTOi__bn_fix_top                    0x021cac8c arm ov114
 */

typedef unsigned long BN_ULONG;

typedef struct {
    BN_ULONG *d;
    int top;
    int dmax;
    int neg;
    int flags;
} BIGNUM;

typedef unsigned char  u8;
extern int CRYPTOi__BN_set_word(u8 *a, unsigned long w);
extern BIGNUM *CRYPTOi__bn_expand2(BIGNUM *a, int words);
extern void CRYPTOi__bn_fix_top(BIGNUM *a);

#define bn_wexpand(a, words) (((words) <= (a)->dmax) ? (a) : CRYPTOi__bn_expand2((a), (words)))

int CRYPTOi__BN_rshift(BIGNUM *r, const BIGNUM *a, int n)
{
    int i, j, nw, lb, rb;
    BN_ULONG *t, *f;
    BN_ULONG l, tmp;

    nw = n / 32;
    rb = n % 32;
    lb = 32 - rb;
    if (nw > a->top) {
        CRYPTOi__BN_set_word((u8 *)r, 0);
        return 1;
    }
    if (r != a) {
        if (bn_wexpand(r, a->top - nw + 2) == 0)
            return 0;
        r->neg = a->neg;
    }

    f = &(a->d[nw]);
    t = r->d;
    j = a->top - nw;
    r->top = j;

    if (rb == 0) {
        for (i = j + 1; i > 0; i--)
            *(t++) = *(f++);
    } else {
        l = *(f++);
        for (i = 1; i < j; i++) {
            tmp = l >> rb;
            l = *(f++);
            *(t++) = tmp | (l << lb);
        }
        *(t++) = l >> rb;
        *t = 0;
    }
    CRYPTOi__bn_fix_top(r);
    return 1;
}
