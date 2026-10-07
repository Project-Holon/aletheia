/*
 * function: func_021CB664
 * address:  0x021CB664
 * packet:   pkt_ov114_021CB664
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_uadd (libcrypto.TWL.HYB.a crypto_bobj1.o)
 * symbols:
 *   func_021CADAC                    0x021cadac arm ov114
 *   func_021CDB08                    0x021cdb08 arm ov114
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
extern BN_ULONG func_021CDB08(BN_ULONG *rp, const BN_ULONG *ap, const BN_ULONG *bp, int num);

#define bn_wexpand(a, words) (((words) <= (a)->dmax) ? (a) : func_021CADAC((a), (words)))

int func_021CB664(BIGNUM *r, const BIGNUM *a, const BIGNUM *b)
{
    int max, min, i;
    BN_ULONG *ap, *bp, *rp, carry, t1;
    const BIGNUM *tmp;

    if (a->top < b->top) {
        tmp = a;
        a = b;
        b = tmp;
    }
    max = a->top;
    min = b->top;

    if (bn_wexpand(r, max + 1) == 0)
        return 0;

    r->top = max;

    ap = a->d;
    bp = b->d;
    rp = r->d;

    carry = func_021CDB08(rp, ap, bp, min);
    rp += min;
    ap += min;
    bp += min;
    i = min;

    if (carry) {
        while (i < max) {
            i++;
            t1 = *(ap++);
            if ((*(rp++) = t1 + 1) >= t1) {
                carry = 0;
                break;
            }
        }
        if ((i >= max) && carry) {
            *(rp++) = 1;
            r->top++;
        }
    }
    if (rp != ap) {
        for (; i < max; i++)
            *(rp++) = *(ap++);
    }
    return 1;
}
