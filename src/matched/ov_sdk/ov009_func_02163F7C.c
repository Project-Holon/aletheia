/*
 * function: func_02163F7C
 * address:  0x02163F7C
 * packet:   pkt_ov009_02163F7C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_big_add (libssl.TWL.HYB.a(biginteger.o))
 *
 * symbols:
 *   func_02163F24  0x02163F24  arm  ov009
 *   MI_CpuFill8  0x02082BCC  arm
 */

extern int func_02163F24(const unsigned short *p, int n);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);

void func_02163F7C(unsigned short *c, unsigned short *a, unsigned short *b, int digits)
{
	int digits_b;
	int digits_a;
	int i;
	int carry;
	unsigned long tmp;

	digits_a = func_02163F24(a, digits);
	digits_b = func_02163F24(b, digits);
	if (digits_a < digits_b) {
		digits_a = digits_b;
	}
	if (digits_a != digits) {
		digits_a++;
	}
	carry = 0;
	for (i = 0; i < digits_a; i++) {
		tmp = a[i] + b[i] + carry;
		c[i] = (unsigned short)tmp;
		carry = tmp >> 16;
	}
	if (c != a && c != b) {
		MI_CpuFill8(c + i, 0, (digits - i) * 2);
	}
}
