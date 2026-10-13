/*
 * function: CRYPTOi__BN_mod_exp
 * address:  0x021CC124
 * packet:   pkt_ov114_021CC124
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_mod_exp (crypto_bobj1.o)
 *
 * symbols:
 *   CRYPTOi__BN_mod_exp_mont  0x021CD210  arm  ov114
 *   CRYPTOi__BN_mod_exp_recp  0x021CCE7C  arm  ov114
 *
 * Montgomery path when the modulus is odd, reciprocal path otherwise.
 * Deferred callees (same object, open SDK, too large for this lane):
 * CRYPTOi__BN_mod_exp_mont (0x021CD210, 1908 B) and
 * CRYPTOi__BN_mod_exp_recp (0x021CCE7C, 916 B).
 */

typedef struct
{
    unsigned int *d;
    int top;
} BIGNUM;

extern int CRYPTOi__BN_mod_exp_mont(BIGNUM *, const BIGNUM *, const BIGNUM *, const BIGNUM *, void *, void *);
extern int CRYPTOi__BN_mod_exp_recp(BIGNUM *, const BIGNUM *, const BIGNUM *, const BIGNUM *, void *);

int CRYPTOi__BN_mod_exp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, const BIGNUM *m, void *ctx)
{
    if (m->top > 0 && (m->d[0] & 1))
        return CRYPTOi__BN_mod_exp_mont(r, a, p, m, ctx, 0);
    return CRYPTOi__BN_mod_exp_recp(r, a, p, m, ctx);
}
