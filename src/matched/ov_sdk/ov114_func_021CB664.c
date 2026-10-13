/*
 * function: CRYPTOi__BN_uadd
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
 *   CRYPTOi__bn_expand2                    0x021cadac arm ov114
 *   CRYPTOi__bn_add_words                    0x021cdb08 arm ov114
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
extern BN_ULONG CRYPTOi__bn_add_words(BN_ULONG *rp, const BN_ULONG *ap, const BN_ULONG *bp, int num);

#define bn_wexpand(a, words) (((words) <= (a)->dmax) ? (a) : CRYPTOi__bn_expand2((a), (words)))

int CRYPTOi__BN_uadd(BIGNUM *r, const BIGNUM *a, const BIGNUM *b)
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

    carry = CRYPTOi__bn_add_words(rp, ap, bp, min);
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
