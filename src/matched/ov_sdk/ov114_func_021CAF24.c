/*
 * function: CRYPTOi__BN_bin2bn
 * address:  0x021CAF24
 * packet:   pkt_ov114_021CAF24
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_bin2bn (libcrypto.TWL.HYB.a(crypto_bobj1.o))
 *
 * symbols:
 *   CRYPTOi__BN_new  0x021CACE4  arm  ov114
 *   CRYPTOi__bn_expand2  0x021CADAC  arm  ov114
 *   CRYPTOi__bn_fix_top  0x021CAC8C  arm  ov114
 */

typedef struct {
	unsigned long *d;
	int top;
	int dmax;
	int neg;
	int flags;
} BIGNUM;

extern void *CRYPTOi__BN_new(void);
extern BIGNUM *CRYPTOi__bn_expand2(BIGNUM *a, int words);
extern void CRYPTOi__bn_fix_top(BIGNUM *a);

BIGNUM *CRYPTOi__BN_bin2bn(unsigned char *s, unsigned int len, BIGNUM *ret)
{
	unsigned int i, m;
	unsigned long l;

	if (ret == 0)
		ret = CRYPTOi__BN_new();
	if (ret == 0)
		return 0;
	l = 0;
	if (len == 0) {
		ret->top = 0;
		return ret;
	}
	if ((((((int)len + 2) * 8 + 31) / 32 <= ret->dmax) ? ret : CRYPTOi__bn_expand2(ret, (((int)len + 2) * 8) / 32 + 1)) == 0)
		return 0;
	i = ((len - 1) / 4) + 1;
	m = ((len - 1) % 4);
	ret->top = i;
	while (len--) {
		l = (l << 8) | *(s++);
		if (m-- == 0) {
			ret->d[--i] = l;
			l = 0;
			m = 3;
		}
	}
	CRYPTOi__bn_fix_top(ret);
	return ret;
}
