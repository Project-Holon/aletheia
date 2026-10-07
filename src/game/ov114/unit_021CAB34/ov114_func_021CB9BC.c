/*
 * function: func_021CB9BC
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
 *   func_021CAEC8  0x021CAEC8  arm  ov114
 *   func_021CADAC  0x021CADAC  arm  ov114
 *   func_021CBA90  0x021CBA90  arm  ov114
 *   func_021CAC8C  0x021CAC8C  arm  ov114
 *   func_021CAE20  0x021CAE20  arm  ov114
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
extern int func_021CAEC8(u8 *a, unsigned long w);
extern BIGNUM *func_021CADAC(BIGNUM *a, int words);
extern void func_021CBA90(unsigned long *r, unsigned long *a, int na, unsigned long *b, int nb);
extern void func_021CAC8C(BIGNUM *a);
extern u8 *func_021CAE20(u8 *a, u8 *b);

int func_021CB9BC(BIGNUM *r, BIGNUM *a, BIGNUM *b, BN_CTX *ctx)
{
	int top, al, bl;
	BIGNUM *rr;
	int neg;

	al = a->top;
	bl = b->top;
	if (al == 0 || bl == 0) {
		func_021CAEC8((u8 *)r, 0);
		return 1;
	}
	top = al + bl;
	neg = a->neg ^ b->neg;
	if (r == a || r == b)
		rr = &ctx->bn[ctx->tos + 1];
	else
		rr = r;
	if (((top > rr->dmax) ? func_021CADAC(rr, top) : rr) == 0)
		return 0;
	rr->top = top;
	func_021CBA90(rr->d, a->d, al, b->d, bl);
	r->neg = neg;
	func_021CAC8C(rr);
	if (r != rr)
		func_021CAE20((u8 *)r, (u8 *)rr);
	return 1;
}
