/*
 * function: CRYPTOi__bn_from_montgomery_words
 * address:  0x021CC38C
 * packet:   pkt_ov114_021CC38C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__bn_from_montgomery_words (libcrypto.TWL.HYB.a crypto_bobj1.o)
 * symbols:
 *   CRYPTOi__bn_mul_add_words                    0x021cd984 arm ov114
 *   CRYPTOi__bn_sub_words                    0x021cdb9c arm ov114
 */

typedef unsigned long BN_ULONG;

extern BN_ULONG CRYPTOi__bn_mul_add_words(BN_ULONG *rp, const BN_ULONG *ap, int num, BN_ULONG w);
extern BN_ULONG CRYPTOi__bn_sub_words(BN_ULONG *rp, const BN_ULONG *ap, const BN_ULONG *bp, int num);

void CRYPTOi__bn_from_montgomery_words(BN_ULONG *ret, BN_ULONG *a, const BN_ULONG *np, int num, BN_ULONG n0)
{
    BN_ULONG carry, v;
    BN_ULONG *ap2;
    int i;

    carry = 0;
    ap2 = a + num;
    for (i = 0; i < num; i++, a++, ap2++) {
        v = CRYPTOi__bn_mul_add_words(a, np, num, a[0] * n0);
        v += carry;
        carry = (v < carry) ? 1 : 0;
        *ap2 += v;
        if (*ap2 < v)
            carry++;
    }
    i = num - 1;
    if (carry == 0) {
        if (a[i] == np[i]) {
            for (; i > 0; i--) {
                if (a[i] != np[i])
                    break;
            }
        }
        carry = (a[i] >= np[i]) ? 1 : 0;
    }
    if (carry) {
        CRYPTOi__bn_sub_words(ret, a, np, num);
    } else {
        for (i = 0; i < num; i++)
            ret[i] = a[i];
    }
}
