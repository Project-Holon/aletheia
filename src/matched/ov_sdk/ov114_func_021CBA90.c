/*
 * function: CRYPTOi__bn_mul_normal
 * address:  0x021CBA90
 * packet:   pkt_ov114_021CBA90
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__bn_mul_normal (libcrypto.TWL.HYB.a(crypto_bobj1.o))
 *
 * symbols:
 *   CRYPTOi__bn_mul_words  0x021CDA38  arm  ov114
 *   CRYPTOi__bn_mul_add_words  0x021CD984  arm  ov114
 */

extern unsigned long CRYPTOi__bn_mul_words(unsigned long *rp, unsigned long *ap, int num, unsigned long w);
extern unsigned long CRYPTOi__bn_mul_add_words(unsigned long *rp, unsigned long *ap, int num, unsigned long w);

void CRYPTOi__bn_mul_normal(unsigned long *r, unsigned long *a, int na, unsigned long *b, int nb)
{
	unsigned long *rr;

	if (na < nb) {
		int itmp;
		unsigned long *ltmp;

		itmp = na;
		na = nb;
		nb = itmp;
		ltmp = a;
		a = b;
		b = ltmp;
	}
	rr = &(r[na]);
	rr[0] = CRYPTOi__bn_mul_words(r, a, na, b[0]);
	for (;;) {
		if (--nb <= 0)
			return;
		rr[1] = CRYPTOi__bn_mul_add_words(&(r[1]), a, na, b[1]);
		if (--nb <= 0)
			return;
		rr[2] = CRYPTOi__bn_mul_add_words(&(r[2]), a, na, b[2]);
		if (--nb <= 0)
			return;
		rr[3] = CRYPTOi__bn_mul_add_words(&(r[3]), a, na, b[3]);
		if (--nb <= 0)
			return;
		rr[4] = CRYPTOi__bn_mul_add_words(&(r[4]), a, na, b[4]);
		rr += 4;
		r += 4;
		b += 4;
	}
}
