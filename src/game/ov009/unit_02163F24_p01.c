/*
 * file:     unit_02163F24_p01.c
 * unit:     yes
 * function: func_02163F24, func_02163F4C, func_02163F7C, func_02164018, func_02164078, func_021640B8, func_02164160, func_021641C4, func_021641FC, func_02164230, func_021642E0
 * address:  0x02163F24
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   count_digits                     0x02163f24 arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021641FC  0x021641FC  arm  ov009
 *   MI_CpuFill8                      0x02082bcc arm
 */
int count_digits(unsigned short *a, int digits);
extern void func_02082BCC(void *dstp, unsigned char data, unsigned long size);
extern void func_021641FC(unsigned short *a, unsigned long b, int i, int digits);
void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
int func_02163F24(const unsigned short *p, int n);
int CPSi_big_sign(unsigned short *a, int digits);
void func_02163F7C(unsigned short *c, unsigned short *a, unsigned short *b, int digits);
void CPSi_big_add_small(unsigned short *c, unsigned short *a, unsigned short _b, int digits);
void CPSi_big_negate(unsigned short *a, int digits);
void func_021640B8(unsigned short *c, unsigned short *a, unsigned short *b, int digits);
void CPSi_big_sub_small(unsigned short *c, unsigned short *a, unsigned short _b, int digits);
int func_021641C4(unsigned short *a, unsigned short *b, int n);
void CPSi_big_add_part(unsigned short *a, unsigned long b, int i, int digits);
void func_02164230(unsigned short *c, unsigned short *a, unsigned short *b, int digits);
void CPSi_big_mult_small(unsigned short *c, unsigned short *a, unsigned short b, int digits);

/*
 * Drops trailing zero halfwords from a counted array.
 */
int func_02163F24(const unsigned short *p, int n)
{
    while (n != 0 && p[n - 1] == 0)
        n--;
    return n;
}


int CPSi_big_sign(unsigned short *a, int digits)
{
    if (a[digits - 1] & 0x8000)
        return -1;
    return count_digits(a, digits) != 0;
}


/*
 * sdk:      CPSi_big_add (libssl.TWL.HYB.a(biginteger.o))
 */
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
		func_02082BCC(c + i, 0, (digits - i) * 2);
	}
}

void CPSi_big_add_small(unsigned short *c, unsigned short *a, unsigned short _b, int digits)
{
    unsigned long b = _b;
    unsigned long tmp;
    int i;

    for (i = 0; i < digits; i++) {
        tmp = b + a[i];
        c[i] = (unsigned short)tmp;
        b = tmp >> 16;
        if (b == 0)
            break;
    }
    if (c != a) {
        i++;
        for (; i < digits; i++)
            c[i] = a[i];
    }
}


void CPSi_big_negate(unsigned short *a, int digits)
{
    int i;

    for (i = 0; i < digits; i++)
        a[i] = ~a[i];
    CPSi_big_add_small(a, a, 1, digits);
}


/*
 * sdk:      CPSi_big_sub (libssl.TWL.HYB.a(biginteger.o))
 */
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
		func_02082BCC(c + i, 0, (digits - i) * 2);
	}
}

void CPSi_big_sub_small(unsigned short *c, unsigned short *a, unsigned short _b, int digits)
{
    unsigned long b = _b;
    unsigned long tmp;
    int i;

    for (i = 0; i < digits; i++) {
        tmp = a[i] - b;
        c[i] = (unsigned short)tmp;
        b = (tmp >> 16) & 1;
        if (b == 0)
            break;
    }
    if (c != a) {
        i++;
        for (; i < digits; i++)
            c[i] = a[i];
    }
}

/*
 * Lexicographic compare of two halfword arrays from the top down: 1, -1 or
 * 0.
 */
int func_021641C4(unsigned short *a, unsigned short *b, int n)
{
    int i;

    for (i = n - 1; i >= 0; i--) {
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return -1;
    }
    return 0;
}

void CPSi_big_add_part(unsigned short *a, unsigned long b, int i, int digits)
{
    unsigned long tmp;

    while (b != 0 && i < digits) {
        tmp = a[i] + b;
        a[i] = (unsigned short)tmp;
        i++;
        b = tmp >> 16;
    }
}


/*
 * sdk:      CPSi_big_mult (libssl.TWL.HYB.a(biginteger.o))
 */
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


void CPSi_big_mult_small(unsigned short *c, unsigned short *a, unsigned short b, int digits)
{
    unsigned long tmp;
    unsigned long carry;
    int digits_a;
    int i;

    digits_a = count_digits(a, digits);
    carry = 0;
    for (i = 0; i < digits_a; i++) {
        tmp = b * a[i] + carry;
        c[i] = (unsigned short)tmp;
        carry = tmp >> 16;
    }
    if (i < digits) {
        c[i] = (unsigned short)carry;
        i++;
    }
    MI_CpuFill8(&c[i], 0, (digits - i) * 2);
}
