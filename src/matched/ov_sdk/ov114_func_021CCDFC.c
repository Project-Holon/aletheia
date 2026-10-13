/*
 * function: CRYPTOi__BN_reciprocal
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
 *   CRYPTOi__BN_init  0x021CACD0  arm  ov114
 *   CRYPTOi__BN_set_word  0x021CAEC8  arm  ov114
 *   CRYPTOi__BN_set_bit  0x021CB0C8  arm  ov114
 *   CRYPTOi__BN_div  0x021CBB80  arm  ov114
 *   CRYPTOi__BN_free  0x021CABDC  arm  ov114
 */

typedef struct {
	unsigned long *d;
	int top;
	int dmax;
	int neg;
	int flags;
} BIGNUM;

typedef unsigned char  u8;
extern void CRYPTOi__BN_init(int a);
extern int CRYPTOi__BN_set_word(u8 *a, unsigned long w);
extern int CRYPTOi__BN_set_bit(BIGNUM *a, int n);
extern int CRYPTOi__BN_div(BIGNUM *dv, BIGNUM *rem, BIGNUM *m, BIGNUM *d, void *ctx);
extern void CRYPTOi__BN_free(u8 *p);

int CRYPTOi__BN_reciprocal(BIGNUM *r, BIGNUM *m, int len, void *ctx)
{
	BIGNUM t;
	int ret = -1;

	CRYPTOi__BN_init((int)(&t));
	CRYPTOi__BN_set_word((u8 *)(&t), 0);
	if (CRYPTOi__BN_set_bit(&t, len) != 0) {
		if (CRYPTOi__BN_div(r, 0, &t, m, ctx) != 0)
			ret = len;
	}
	CRYPTOi__BN_free((u8 *)(&t));
	return ret;
}
