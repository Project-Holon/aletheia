/*
 * function: CRYPTOi__BN_mod_mul_reciprocal
 * address:  0x021CCAE4
 * packet:   pkt_ov114_021CCAE4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_mod_mul_reciprocal (libcrypto.TWL.HYB.a(crypto_bobj1.o))
 *
 * symbols:
 *   CRYPTOi__BN_sqr  0x021CC178  arm  ov114
 *   CRYPTOi__BN_mul  0x021CB9BC  arm  ov114
 *   CRYPTOi__BN_div_recp  0x021CCB88  arm  ov114
 */

typedef struct {
	unsigned long *d;
	int top;
	int dmax;
	int neg;
	int flags;
} BIGNUM;

typedef struct {
	int tos;
	BIGNUM bn[16];
} BN_CTX;

extern int CRYPTOi__BN_sqr(BIGNUM *r, BIGNUM *a, BN_CTX *ctx);
extern int CRYPTOi__BN_mul(BIGNUM *r, BIGNUM *a, BIGNUM *b, BN_CTX *ctx);
extern int CRYPTOi__BN_div_recp(BIGNUM *dv, BIGNUM *rem, BIGNUM *m, void *recp, BN_CTX *ctx);

int CRYPTOi__BN_mod_mul_reciprocal(BIGNUM *r, BIGNUM *x, BIGNUM *y, void *recp, BN_CTX *ctx)
{
	int ret = 0;
	BIGNUM *a;

	a = &ctx->bn[ctx->tos++];
	if (y != 0) {
		if (x == y) {
			if (CRYPTOi__BN_sqr(a, x, ctx) == 0)
				goto err;
		} else {
			if (CRYPTOi__BN_mul(a, x, y, ctx) == 0)
				goto err;
		}
	} else {
		a = x;
	}
	CRYPTOi__BN_div_recp(0, r, a, recp, ctx);
	ret = 1;
err:
	ctx->tos--;
	return ret;
}
