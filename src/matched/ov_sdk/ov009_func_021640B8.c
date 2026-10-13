/*
 * function: func_021640B8
 * address:  0x021640B8
 * packet:   pkt_ov009_021640B8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_big_sub (libssl.TWL.HYB.a(biginteger.o))
 *
 * symbols:
 *   func_02163F24  0x02163F24  arm  ov009
 *   MI_CpuFill8  0x02082BCC  arm
 */

extern int func_02163F24(const unsigned short *p, int n);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);

void func_021640B8(unsigned short *c, unsigned short *a, unsigned short *b, int digits)
{
	int digits_b;
	int digits_a;
	int i;
	int borrow;
	unsigned long tmp;

	digits_a = func_02163F24(a, digits);
	digits_b = func_02163F24(b, digits);
	if (digits_a < digits_b) {
		digits_a = digits_b;
	}
	if (digits_a != digits) {
		digits_a++;
	}
	borrow = 0;
	for (i = 0; i < digits_a || (i < digits && borrow != 0); i++) {
		tmp = a[i] - b[i] + borrow;
		c[i] = (unsigned short)tmp;
		borrow = (int)tmp >> 16;
	}
	if (c != a && c != b) {
		MI_CpuFill8(c + i, 0, (digits - i) * 2);
	}
}
