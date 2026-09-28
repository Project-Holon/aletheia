/*
 * function: func_021CC2B0
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
 *   func_021CDA38  0x021CDA38  arm  ov114
 *   func_021CD984  0x021CD984  arm  ov114
 *   func_021CDB08  0x021CDB08  arm  ov114
 *   func_021CDAC0  0x021CDAC0  arm  ov114
 */

extern unsigned long func_021CDA38(unsigned long *rp, unsigned long *ap, int num, unsigned long w);
extern unsigned long func_021CD984(unsigned long *rp, unsigned long *ap, int num, unsigned long w);
extern unsigned long func_021CDB08(unsigned long *r, unsigned long *a, unsigned long *b, int n);
extern void func_021CDAC0(unsigned long *r, unsigned long *a, int n);

void func_021CC2B0(unsigned long *r, unsigned long *a, int n, unsigned long *tmp)
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
		rp[j] = func_021CDA38(rp, ap, j, a[0]);
		rp += 2;
	}

	for (i = n - 2; i > 0; i--) {
		unsigned long *prev = ap;
		j--;
		ap++;
		rp[j] = func_021CD984(rp, ap, j, *prev);
		rp += 2;
	}

	func_021CDB08(r, r, r, max);
	func_021CDAC0(tmp, a, n);
	func_021CDB08(r, r, tmp, max);
}
