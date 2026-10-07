/*
 * file:     unit_021CAB34_p12.c
 * unit:     yes
 * function: func_021CCA80, func_021CCAAC, func_021CCAE4
 * address:  0x021CCA80
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021CABDC  0x021CABDC  arm  ov114
 *   func_021CAAE8  0x021CAAE8  arm  ov114
 *   func_021CAE20  0x021CAE20  arm  ov114
 *   func_021CAEC8  0x021CAEC8  arm  ov114
 *   func_021CAB94  0x021CAB94  arm  ov114
 *   func_021CC178  0x021CC178  arm  ov114
 *   func_021CB9BC  0x021CB9BC  arm  ov114
 *   func_021CCB88  0x021CCB88  arm  ov114
 */
typedef unsigned char u8;

typedef unsigned int u32;

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

extern void func_021CABDC(u8 *);
extern void func_021CAAE8(void *);
extern u8 *func_021CAE20(u8 *a, u8 *b);
extern int func_021CAEC8(u8 *, unsigned long);
extern char *func_021CAB94(u8 *p);
extern int func_021CC178(BIGNUM *r, BIGNUM *a, BN_CTX *ctx);
extern int func_021CB9BC(BIGNUM *r, BIGNUM *a, BIGNUM *b, BN_CTX *ctx);
extern int func_021CCB88(BIGNUM *dv, BIGNUM *rem, BIGNUM *m, void *recp, BN_CTX *ctx);
void func_021CCA80(u8 *p);
int func_021CCAAC(u8 *p, u8 *b);
int func_021CCAE4(BIGNUM *r, BIGNUM *x, BIGNUM *y, void *recp, BN_CTX *ctx);


/*
 * sdk:      CRYPTOi__BN_RECP_CTX_free (crypto_bobj1.o)
 */
void func_021CCA80(u8 *p)
{
    func_021CABDC(p);
    func_021CABDC(p + 0x14);
    if (*(u32 *)(p + 0x30) & 1)
        func_021CAAE8(p);
}


/*
 * sdk:      CRYPTOi__BN_RECP_CTX_set (crypto_bobj1.o)
 */
int func_021CCAAC(u8 *p, u8 *b)
{
    func_021CAE20(p, b);
    func_021CAEC8(p + 0x14, 0);
    *(u32 *)(p + 0x28) = (u32)func_021CAB94(b);
    *(u32 *)(p + 0x2c) = 0;
    return 1;
}


/*
 * sdk:      CRYPTOi__BN_mod_mul_reciprocal (libcrypto.TWL.HYB.a(crypto_bobj1.o))
 */
int func_021CCAE4(BIGNUM *r, BIGNUM *x, BIGNUM *y, void *recp, BN_CTX *ctx)
{
	int ret = 0;
	BIGNUM *a;

	a = &ctx->bn[ctx->tos++];
	if (y != 0) {
		if (x == y) {
			if (func_021CC178(a, x, ctx) == 0)
				goto err;
		} else {
			if (func_021CB9BC(a, x, y, ctx) == 0)
				goto err;
		}
	} else {
		a = x;
	}
	func_021CCB88(0, r, a, recp, ctx);
	ret = 1;
err:
	ctx->tos--;
	return ret;
}
