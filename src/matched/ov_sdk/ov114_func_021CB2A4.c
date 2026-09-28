/*
 * function: func_021CB2A4
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
 *   func_021CAEC8                    0x021caec8 arm ov114
 *   func_021CADAC                    0x021cadac arm ov114
 *   func_021CAC8C                    0x021cac8c arm ov114
 */

typedef unsigned long BN_ULONG;

typedef struct {
    BN_ULONG *d;
    int top;
    int dmax;
    int neg;
    int flags;
} BIGNUM;

extern int func_021CAEC8(BIGNUM *a, BN_ULONG w);
extern BIGNUM *func_021CADAC(BIGNUM *a, int words);
extern void func_021CAC8C(BIGNUM *a);

#define bn_wexpand(a, words) (((words) <= (a)->dmax) ? (a) : func_021CADAC((a), (words)))

int func_021CB2A4(BIGNUM *r, const BIGNUM *a, int n)
{
    int i, j, nw, lb, rb;
    BN_ULONG *t, *f;
    BN_ULONG l, tmp;

    nw = n / 32;
    rb = n % 32;
    lb = 32 - rb;
    if (nw > a->top) {
        func_021CAEC8(r, 0);
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
    func_021CAC8C(r);
    return 1;
}
