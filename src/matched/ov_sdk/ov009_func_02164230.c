/*
 * function: func_02164230
 * address:  0x02164230
 * packet:   pkt_ov009_02164230
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_big_mult (libssl.TWL.HYB.a(biginteger.o))
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02163F24  0x02163F24  arm  ov009
 *   func_021641FC  0x021641FC  arm  ov009
 */

extern void func_02082BCC(void *dstp, unsigned char data, unsigned long size);
extern int func_02163F24(const unsigned short *p, int n);
extern void func_021641FC(unsigned short *a, unsigned long b, int i, int digits);

void func_02164230(unsigned short *c, unsigned short *a, unsigned short *b, int digits)
{
	int digits_b;
	int digits_a;
	int i;
	int j;

	func_02082BCC(c, 0, digits * 2);
	digits_a = func_02163F24(a, digits);
	digits_b = func_02163F24(b, digits);
	for (i = 0; i < digits_b; i++) {
		for (j = 0; j < digits_a && j < digits - i; j++) {
			func_021641FC(c, a[j] * b[i], i + j, digits);
		}
	}
}
