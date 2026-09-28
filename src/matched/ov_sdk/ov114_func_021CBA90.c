/*
 * function: func_021CBA90
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
 *   func_021CDA38  0x021CDA38  arm  ov114
 *   func_021CD984  0x021CD984  arm  ov114
 */

extern unsigned long func_021CDA38(unsigned long *rp, unsigned long *ap, int num, unsigned long w);
extern unsigned long func_021CD984(unsigned long *rp, unsigned long *ap, int num, unsigned long w);

void func_021CBA90(unsigned long *r, unsigned long *a, int na, unsigned long *b, int nb)
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
	rr[0] = func_021CDA38(r, a, na, b[0]);
	for (;;) {
		if (--nb <= 0)
			return;
		rr[1] = func_021CD984(&(r[1]), a, na, b[1]);
		if (--nb <= 0)
			return;
		rr[2] = func_021CD984(&(r[2]), a, na, b[2]);
		if (--nb <= 0)
			return;
		rr[3] = func_021CD984(&(r[3]), a, na, b[3]);
		if (--nb <= 0)
			return;
		rr[4] = func_021CD984(&(r[4]), a, na, b[4]);
		rr += 4;
		r += 4;
		b += 4;
	}
}
