/*
 * function: func_02163558
 * address:  0x02163558
 * packet:   pkt_ov009_02163558
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      R (libssl.TWL.HYB.a(sha1.o))
 *
 * symbols:
 *   (none)
 */

unsigned long func_02163558(int t, unsigned long *w)
{
	unsigned long temp;

	temp = w[(t + 13) & 15] ^ w[t ^ 8] ^ w[(t + 2) & 15] ^ w[t];
	temp = (temp << 1) | (temp >> 31);
	w[t] = temp;
	return temp;
}
