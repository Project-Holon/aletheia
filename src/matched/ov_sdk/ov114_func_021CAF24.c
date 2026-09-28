/*
 * function: func_021CAF24
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
 *   func_021CACE4  0x021CACE4  arm  ov114
 *   func_021CADAC  0x021CADAC  arm  ov114
 *   func_021CAC8C  0x021CAC8C  arm  ov114
 */

typedef struct {
	unsigned long *d;
	int top;
	int dmax;
	int neg;
	int flags;
} BIGNUM;

extern BIGNUM *func_021CACE4(void);
extern BIGNUM *func_021CADAC(BIGNUM *a, int words);
extern void func_021CAC8C(BIGNUM *a);

BIGNUM *func_021CAF24(unsigned char *s, unsigned int len, BIGNUM *ret)
{
	unsigned int i, m;
	unsigned long l;

	if (ret == 0)
		ret = func_021CACE4();
	if (ret == 0)
		return 0;
	l = 0;
	if (len == 0) {
		ret->top = 0;
		return ret;
	}
	if ((((((int)len + 2) * 8 + 31) / 32 <= ret->dmax) ? ret : func_021CADAC(ret, (((int)len + 2) * 8) / 32 + 1)) == 0)
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
	func_021CAC8C(ret);
	return ret;
}
