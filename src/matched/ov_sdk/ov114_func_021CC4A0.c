/*
 * function: func_021CC4A0
 * address:  0x021CC4A0
 * packet:   pkt_ov114_021CC4A0
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_mod_inverse_word (libcrypto.TWL.HYB.a(crypto_bobj1.o))
 *
 * symbols:
 *   _u32_div_f     0x0209C2B0  arm
 */

unsigned long func_021CC4A0(unsigned long n)
{
	unsigned long a, b, q, r, t, res;
	unsigned long x0, x1;
	long sign;

	b = (0 - n) % n;
	x0 = 1;
	a = n;
	sign = -1;
	x1 = 0;
	while (b != 0) {
		q = a / b;
		r = a % b;
		t = q * x0 + x1;
		x1 = x0;
		x0 = t;
		a = b;
		b = r;
		sign = -sign;
	}
	if (sign < 0)
		x1 = n - x1;
	if (a == 1)
		res = x1 % n;
	else
		res = 0;
	return res;
}
