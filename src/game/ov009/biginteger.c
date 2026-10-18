/*
 * file:     biginteger.c
 * unit:     yes
 * function: count_digits, CPSi_big_sign, CPSi_big_add, CPSi_big_add_small, CPSi_big_negate, CPSi_big_sub, CPSi_big_sub_small, CPSi_big_compare, CPSi_big_add_part, CPSi_big_mult, CPSi_big_mult_small, CPSi_big_sqr, get48bits_1, get48bits_2, get48bits_3, get64bits, CPSi_big_div, CPSi_big_power, CPSi_big_modinv, CPSi_big_montmult, CPSi_big_montpower, CPSi_big_from_char, CPSi_char_from_big
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
 *   MI_CpuFill8  0x02082BCC  arm
 *   CPSi_big_add_part  0x021641FC  arm  ov009
 *   MI_CpuFill8                      0x02082bcc arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   get48bits_3  0x021644A0  arm  ov009
 *   get48bits_2  0x02164490  arm  ov009
 *   memmove  0x02092364  arm
 *   get64bits  0x021644B4  arm  ov009
 *   _ll_udiv  0x0209C00C  arm
 *   CPSi_big_mult_small  0x021642E0  arm  ov009
 *   CPSiAlloc     0x021A8280  data
 *   CPSiFree     0x021A82B0  data
 *   CPSi_big_sign  0x02163F4C  arm  ov009
 *   CPSi_big_modinv     0x02164830  arm  ov009
 *   CPSi_big_mult       0x02164230  arm  ov009
 *   CPSi_big_div        0x021644D0  arm  ov009
 *   CPSi_big_montmult   0x0216497C  arm  ov009
 */
typedef unsigned short u16;

typedef unsigned long u32;

typedef unsigned long long u64;

typedef unsigned char  u8;

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern u64 get48bits_3(u16 *s);
extern u64 get48bits_2(u16 *s);
extern void *memmove(void *dst, const void *src, u32 n);
extern u64 get64bits(u16 *s);
extern void CPSi_big_modinv(unsigned short *c, unsigned short *a, unsigned short *n, int digits, unsigned short *tmp_var);
extern void CPSi_big_mult(unsigned short *c, unsigned short *a, unsigned short *b, int digits);
extern void CPSi_big_div(unsigned short *c, unsigned short *a, unsigned short *b, unsigned short *r, int digits, unsigned short *work);
extern void CPSi_big_montmult(unsigned short *c, unsigned short *a, unsigned short *b, int digits, int rdigits, unsigned short *n, unsigned short *np, unsigned short *m, unsigned short *m2);
int count_digits(const unsigned short *p, int n);
int CPSi_big_sign(unsigned short *a, int digits);
void CPSi_big_add(unsigned short *c, unsigned short *a, unsigned short *b, int digits);
void CPSi_big_add_small(unsigned short *c, unsigned short *a, unsigned short _b, int digits);
void CPSi_big_negate(unsigned short *a, int digits);
void CPSi_big_sub(unsigned short *c, unsigned short *a, unsigned short *b, int digits);
void CPSi_big_sub_small(unsigned short *c, unsigned short *a, unsigned short _b, int digits);
int CPSi_big_compare(unsigned short *a, unsigned short *b, int n);
void CPSi_big_add_part(unsigned short *a, unsigned long b, int i, int digits);
void CPSi_big_mult(unsigned short *c, unsigned short *a, unsigned short *b, int digits);
void CPSi_big_mult_small(unsigned short *c, unsigned short *a, unsigned short b, int digits);
void CPSi_big_sqr(unsigned short *c, unsigned short *a, int digits);
unsigned long long get48bits_1(unsigned short *p);
void CPSi_big_div(u16 *c, u16 *a, u16 *b, u16 *r, int digits, u16 *work);
void CPSi_big_power(u16 *c, u16 *a, u16 *b, int digits, u16 *n);
void CPSi_big_montpower(unsigned short *c, unsigned short *m, unsigned short *e, int digits, unsigned short *n);
void CPSi_big_from_char(unsigned short *d, unsigned char *s, int numbytes, int digits);
void CPSi_char_from_big(unsigned char *d, unsigned short *s, int numbytes);




/*
 * Drops trailing zero halfwords from a counted array.
 */
int count_digits(const unsigned short *p, int n)
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
void CPSi_big_add(unsigned short *c, unsigned short *a, unsigned short *b, int digits)
{
	int digits_b;
	int digits_a;
	int i;
	int carry;
	unsigned long tmp;

	digits_a = count_digits(a, digits);
	digits_b = count_digits(b, digits);
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
void CPSi_big_sub(unsigned short *c, unsigned short *a, unsigned short *b, int digits)
{
	int digits_b;
	int digits_a;
	int i;
	int borrow;
	unsigned long tmp;

	digits_a = count_digits(a, digits);
	digits_b = count_digits(b, digits);
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
int CPSi_big_compare(unsigned short *a, unsigned short *b, int n)
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
void CPSi_big_mult(unsigned short *c, unsigned short *a, unsigned short *b, int digits)
{
	int digits_b;
	int digits_a;
	int i;
	int j;

	MI_CpuFill8(c, 0, digits * 2);
	digits_a = count_digits(a, digits);
	digits_b = count_digits(b, digits);
	for (i = 0; i < digits_b; i++) {
		for (j = 0; j < digits_a && j < digits - i; j++) {
			CPSi_big_add_part(c, a[j] * b[i], i + j, digits);
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





/*
 * sdk:      CPSi_big_sqr (libssl.TWL.HYB.a(biginteger.o))
 */
void CPSi_big_sqr(unsigned short *c, unsigned short *a, int digits)
{
    int i;
    int j;
    int digits_a;
    unsigned long tmp;

    digits_a = count_digits(a, digits);
    if (digits > digits_a * 2)
        MI_CpuFill8(c + digits_a * 2, 0, (digits - digits_a * 2) * 2);
    for (i = 0; i < digits_a; i++) {
        j = i * 2;
        if (j >= digits)
            break;
        tmp = a[i] * a[i];
        c[j] = (unsigned short)tmp;
        if (j == digits - 1)
            break;
        c[j + 1] = (unsigned short)(tmp >> 16);
    }
    for (i = 0; i < digits_a; i++) {
        for (j = i + 1; j < digits_a && i + j < digits; j++) {
            tmp = a[j] * a[i];
            if (tmp <= 0x7FFF8000)
                CPSi_big_add_part(c, tmp * 2, i + j, digits);
            else {
                CPSi_big_add_part(c, tmp, i + j, digits);
                CPSi_big_add_part(c, tmp, i + j, digits);
            }
        }
    }
}




/*
 * Halfword at p as the high word of a 64-bit value.
 */
unsigned long long get48bits_1(unsigned short *p)
{
    return (unsigned long long)*p << 32;
}




/* hand-written in the original: biginteger.o (libssl) asm routine, one debug row per instruction and no DWARF locals; no C spelling gives the bare lsl */
asm u64 get48bits_2(u16 *s)
{
	ldrh r1, [r0]
	ldrh r0, [r0, #-2]
	mov r0, r0, lsl #16
	bx lr
}




/* hand-written in the original: biginteger.o (libssl) asm routine, one debug row per instruction and no DWARF locals; no C spelling gives the bare lsl */
asm u64 get48bits_3(u16 *s)
{
	ldrh r1, [r0]
	ldrh r2, [r0, #-2]
	ldrh r3, [r0, #-4]
	orr r0, r3, r2, lsl #16
	bx lr
}




/* hand-written in the original: biginteger.o (libssl) asm routine, one debug row per instruction and no DWARF locals; no C spelling gives the bare lsl */
asm u64 get64bits(u16 *s)
{
	ldrh r2, [r0]
	ldrh r3, [r0, #-2]
	orr r1, r3, r2, lsl #16
	ldrh r2, [r0, #-4]
	ldrh r3, [r0, #-6]
	orr r0, r3, r2, lsl #16
	bx lr
}





/*
 * sdk:      CPSi_big_div (libssl.TWL.HYB.a(biginteger.o))
 */
void CPSi_big_div(u16 *c, u16 *a, u16 *b, u16 *r, int digits, u16 *work)
{
    int digits_a;
    int digits_b;
    int i;
    u64 msd;
    u32 guess;
    u16 *ca;
    u16 *cca;

    ca = work + digits;
    cca = ca + digits;
    MI_CpuFill8(ca, 0, digits * 4);
    digits_a = count_digits(a, digits);
    digits_b = count_digits(b, digits);
    if (digits_a > 0 && digits_b > 0) {
        i = digits_b + (digits - digits_a) - 1;
        if (i >= digits) {
            MI_CpuCopy8(a, cca, digits * 2);
        } else {
            MI_CpuCopy8(a, ca + i, digits_a * 2);
            if (digits_b > 2)
                msd = get48bits_3(b + digits_b - 1);
            else if (digits_b > 1)
                msd = get48bits_2(b + digits_b - 1);
            else
                msd = get48bits_1(b + digits_b - 1);
            for (; i < digits; i++) {
                memmove(ca + 1, ca, (digits * 2 - 1) * 2);
                guess = get64bits(cca + digits_b) / msd;
                if (guess > 0xffff)
                    guess = 0xffff;
                while (1) {
                    CPSi_big_mult_small(work, b, (u16)guess, digits);
                    if (CPSi_big_compare(cca, work, digits) >= 0)
                        break;
                    guess--;
                }
                CPSi_big_sub(cca, cca, work, digits);
                *ca = guess;
            }
        }
    }
    if (c)
        MI_CpuCopy8(ca, c, digits * 2);
    if (r)
        MI_CpuCopy8(cca, r, digits * 2);
}



extern void *(*CPSiAlloc)(u32 size);



extern void (*CPSiFree)(void *ptr);




/*
 * sdk:      CPSi_big_power (libssl.TWL.HYB.a(biginteger.o))
 */
void CPSi_big_power(u16 *c, u16 *a, u16 *b, int digits, u16 *n)
{
    u16 *tmp;
    u16 *divwork;
    int i;

    tmp = CPSiAlloc(digits * sizeof(u16) * 4);
    if (tmp == 0)
        return;
    divwork = tmp + digits;
    MI_CpuFill8(c + 1, 0, (digits - 1) * sizeof(u16));
    c[0] = 1;
    for (i = (digits - count_digits(b, digits)) * 16; i < digits * sizeof(u16) * 8; i++) {
        if (b[digits - (i >> 4) - 1] & (0x8000u >> (i & 15))) {
            MI_CpuCopy8(a, c, digits * sizeof(u16));
            i++;
            break;
        }
    }
    for (; i < digits * sizeof(u16) * 8; i++) {
        CPSi_big_sqr(tmp, c, digits);
        MI_CpuCopy8(tmp, c, digits * sizeof(u16));
        if (n)
            CPSi_big_div(0, c, n, c, digits, divwork);
        if (b[digits - (i >> 4) - 1] & (0x8000u >> (i & 15))) {
            CPSi_big_mult(tmp, c, a, digits);
            MI_CpuCopy8(tmp, c, digits * sizeof(u16));
            if (n)
                CPSi_big_div(0, c, n, c, digits, divwork);
        }
    }
    CPSiFree(tmp);
}




/*
 * sdk:      CPSi_big_modinv (libssl.TWL.HYB.a(biginteger.o))
 */
static void CPSi_big_modinv(unsigned short *c, unsigned short *a, unsigned short *n, int digits,
                          unsigned short *tmp_var)
{
    unsigned short *q;
    unsigned short *t;
    unsigned short *u;
    unsigned short *v;
    unsigned short *w;
    unsigned short *divwork;

    q = tmp_var + digits;
    t = q + digits;
    u = t + digits;
    v = u + digits;
    w = v + digits;
    divwork = w + digits;

    MI_CpuCopy8(a, tmp_var, digits * 2);
    MI_CpuCopy8(n, t, digits * 2);
    u[0] = 1;
    while (CPSi_big_sign(tmp_var, digits) > 0) {
        CPSi_big_div(q, t, tmp_var, w, digits, divwork);
        MI_CpuCopy8(tmp_var, t, digits * 2);
        MI_CpuCopy8(w, tmp_var, digits * 2);
        CPSi_big_mult(w, q, u, digits);
        CPSi_big_sub(w, v, w, digits);
        MI_CpuCopy8(u, v, digits * 2);
        MI_CpuCopy8(w, u, digits * 2);
    }
    CPSi_big_add(v, v, n, digits);
    CPSi_big_div(0, v, n, c, digits, divwork);
}




/*
 * sdk:      CPSi_big_montmult (libssl.TWL.HYB.a(biginteger.o))
 */
static void CPSi_big_montmult(unsigned short *c, unsigned short *a, unsigned short *b, int digits,
                          int rdigits, unsigned short *n, unsigned short *np,
                          unsigned short *m, unsigned short *m2)
{
    MI_CpuCopy8(c, a, digits * 2);
    if (b == (unsigned short *)1)
        CPSi_big_sqr(c, a, digits);
    else if (b != 0)
        CPSi_big_mult(c, a, b, digits);
    CPSi_big_mult(m, c, np, rdigits);
    MI_CpuFill8(m + rdigits, 0, (digits - rdigits) * 2);
    CPSi_big_mult(m2, m, n, digits);
    CPSi_big_add(c, c, m2, digits);
    memmove(c, c + rdigits, (digits - rdigits) * 2);
    MI_CpuFill8(c + digits - rdigits, 0, rdigits * 2);
    switch (CPSi_big_compare(c, n, digits)) {
    case 0:
        MI_CpuFill8(c, 0, digits * 2);
        break;
    case 1:
        CPSi_big_sub(c, c, n, digits);
        break;
    }
}


extern void *(*CPSiAlloc)(unsigned long size);


extern void (*CPSiFree)(void *ptr);



void CPSi_big_montpower(unsigned short *c, unsigned short *m, unsigned short *e, int digits, unsigned short *n)
{
    int rdigits;
    int i;
    unsigned short *tmp_var;
    unsigned short *ri;
    unsigned short *mr;
    unsigned short *tmp;
    unsigned short *tmp2;
    unsigned short *tmp3;
    unsigned short *divwork;

    tmp_var = (unsigned short *)CPSiAlloc(digits * 22);
    if (tmp_var == 0)
        return;
    i = 0;
    MI_CpuFill8(tmp_var, 0, digits * 22);
    ri = tmp_var + digits;
    mr = ri + digits;
    tmp = mr + digits;
    tmp2 = tmp + digits;
    tmp3 = tmp2 + digits;
    divwork = tmp3 + digits;
    rdigits = count_digits(n, digits);
    tmp_var[rdigits] = 1;
    CPSi_big_modinv(ri, tmp_var, n, digits, mr);
    CPSi_big_mult(tmp, tmp_var, ri, digits);
    CPSi_big_sub_small(ri, tmp, 1, digits);
    CPSi_big_div(ri, ri, n, 0, digits, divwork);
    CPSi_big_mult(mr, m, tmp_var, digits);
    CPSi_big_div(0, mr, n, mr, digits, divwork);
    CPSi_big_div(0, tmp_var, n, c, digits, divwork);
    for (i = 0; (unsigned)i < (unsigned)(rdigits * 16); i++) {
        CPSi_big_montmult(c, tmp3, (unsigned short *)1, digits, rdigits, n, ri, tmp, tmp2);
        if (e[rdigits - (i >> 4) - 1] & (0x8000u >> (i & 15)))
            CPSi_big_montmult(c, tmp3, mr, digits, rdigits, n, ri, tmp, tmp2);
    }
    CPSi_big_montmult(c, tmp3, 0, digits, rdigits, n, ri, tmp, tmp2);
    CPSiFree(tmp_var);
}



void CPSi_big_from_char(unsigned short *d, unsigned char *s, int numbytes, int digits)
{
    MI_CpuFill8(d, 0, digits * 2);
    s += numbytes - 1;
    while (numbytes > 1) {
        *d++ = (unsigned short)(s[0] + (s[-1] << 8));
        s -= 2;
        numbytes -= 2;
    }
    if (numbytes > 0)
        *d = *s;
}


void CPSi_char_from_big(unsigned char *d, unsigned short *s, int numbytes)
{
    unsigned char *p;

    d += numbytes - 1;
    while (numbytes > 1) {
        p = d - 1;
        *d = (unsigned char)*s;
        d -= 2;
        *p = (unsigned char)(*s++ >> 8);
        numbytes -= 2;
    }
    if (numbytes > 0)
        *d = (unsigned char)*s;
}
