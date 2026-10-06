/*
 * function: func_021CCDFC
 * address:  0x021CCDFC
 * packet:   pkt_ov114_021CCDFC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_reciprocal (libcrypto.TWL.HYB.a(crypto_bobj1.o))
 *
 * symbols:
 *   func_021CACD0  0x021CACD0  arm  ov114
 *   func_021CAEC8  0x021CAEC8  arm  ov114
 *   func_021CB0C8  0x021CB0C8  arm  ov114
 *   func_021CBB80  0x021CBB80  arm  ov114
 *   func_021CABDC  0x021CABDC  arm  ov114
 */

typedef struct {
	unsigned long *d;
	int top;
	int dmax;
	int neg;
	int flags;
} BIGNUM;

typedef unsigned char  u8;
extern void func_021CACD0(int a);
extern int func_021CAEC8(u8 *a, unsigned long w);
extern int func_021CB0C8(BIGNUM *a, int n);
extern int func_021CBB80(BIGNUM *dv, BIGNUM *rem, BIGNUM *m, BIGNUM *d, void *ctx);
extern void func_021CABDC(u8 *p);

int func_021CCDFC(BIGNUM *r, BIGNUM *m, int len, void *ctx)
{
	BIGNUM t;
	int ret = -1;

	func_021CACD0((int)(&t));
	func_021CAEC8((u8 *)(&t), 0);
	if (func_021CB0C8(&t, len) != 0) {
		if (func_021CBB80(r, 0, &t, m, ctx) != 0)
			ret = len;
	}
	func_021CABDC((u8 *)(&t));
	return ret;
}
