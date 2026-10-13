/*
 * function: CRYPTOi__bn_sqr_normal
 * address:  0x021CC2B0
 * packet:   pkt_ov114_021CC2B0
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__bn_sqr_normal (libcrypto.TWL.HYB.a(crypto_bobj1.o))
 *
 * symbols:
 *   CRYPTOi__bn_mul_words  0x021CDA38  arm  ov114
 *   CRYPTOi__bn_mul_add_words  0x021CD984  arm  ov114
 *   CRYPTOi__bn_add_words  0x021CDB08  arm  ov114
 *   CRYPTOi__bn_sqr_words  0x021CDAC0  arm  ov114
 */

extern unsigned long CRYPTOi__bn_mul_words(unsigned long *rp, unsigned long *ap, int num, unsigned long w);
extern unsigned long CRYPTOi__bn_mul_add_words(unsigned long *rp, unsigned long *ap, int num, unsigned long w);
extern unsigned long CRYPTOi__bn_add_words(unsigned long *r, unsigned long *a, unsigned long *b, int n);
extern void CRYPTOi__bn_sqr_words(unsigned long *r, unsigned long *a, int n);

void CRYPTOi__bn_sqr_normal(unsigned long *r, unsigned long *a, int n, unsigned long *tmp)
{
	int i, j, max;
	unsigned long *ap, *rp;

	max = n * 2;
	ap = a;
	rp = r;
	rp[0] = rp[max - 1] = 0;
	rp++;
	j = n;

	if (--j > 0) {
		ap++;
		rp[j] = CRYPTOi__bn_mul_words(rp, ap, j, a[0]);
		rp += 2;
	}

	for (i = n - 2; i > 0; i--) {
		unsigned long *prev = ap;
		j--;
		ap++;
		rp[j] = CRYPTOi__bn_mul_add_words(rp, ap, j, *prev);
		rp += 2;
	}

	CRYPTOi__bn_add_words(r, r, r, max);
	CRYPTOi__bn_sqr_words(tmp, a, n);
	CRYPTOi__bn_add_words(r, r, tmp, max);
}
