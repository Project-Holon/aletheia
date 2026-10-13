/*
 * function: CRYPTOi__BN_mul
 * address:  0x021CB9BC
 * packet:   pkt_ov114_021CB9BC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_mul (libcrypto.TWL.HYB.a(crypto_bobj1.o))
 *
 * symbols:
 *   CRYPTOi__BN_set_word  0x021CAEC8  arm  ov114
 *   CRYPTOi__bn_expand2  0x021CADAC  arm  ov114
 *   CRYPTOi__bn_mul_normal  0x021CBA90  arm  ov114
 *   CRYPTOi__bn_fix_top  0x021CAC8C  arm  ov114
 *   CRYPTOi__BN_copy  0x021CAE20  arm  ov114
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

typedef unsigned char  u8;
extern int CRYPTOi__BN_set_word(u8 *a, unsigned long w);
extern BIGNUM *CRYPTOi__bn_expand2(BIGNUM *a, int words);
extern void CRYPTOi__bn_mul_normal(unsigned long *r, unsigned long *a, int na, unsigned long *b, int nb);
extern void CRYPTOi__bn_fix_top(BIGNUM *a);
extern u8 *CRYPTOi__BN_copy(u8 *a, u8 *b);

int CRYPTOi__BN_mul(BIGNUM *r, BIGNUM *a, BIGNUM *b, BN_CTX *ctx)
{
	int top, al, bl;
	BIGNUM *rr;
	int neg;

	al = a->top;
	bl = b->top;
	if (al == 0 || bl == 0) {
		CRYPTOi__BN_set_word((u8 *)r, 0);
		return 1;
	}
	top = al + bl;
	neg = a->neg ^ b->neg;
	if (r == a || r == b)
		rr = &ctx->bn[ctx->tos + 1];
	else
		rr = r;
	if (((top > rr->dmax) ? CRYPTOi__bn_expand2(rr, top) : rr) == 0)
		return 0;
	rr->top = top;
	CRYPTOi__bn_mul_normal(rr->d, a->d, al, b->d, bl);
	r->neg = neg;
	CRYPTOi__bn_fix_top(rr);
	if (r != rr)
		CRYPTOi__BN_copy((u8 *)r, (u8 *)rr);
	return 1;
}
