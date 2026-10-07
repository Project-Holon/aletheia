/*
 * file:     unit_02163F24_p02.c
 * unit:     yes
 * function: func_02164358, func_02164484, func_02164490, func_021644A0, func_021644B4, func_021644D0
 * address:  0x02164358
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
 *   func_02163F24  0x02163F24  arm  ov009
 *   func_02082BCC  0x02082BCC  arm
 *   func_021641FC  0x021641FC  arm  ov009
 *   func_02082D44  0x02082D44  arm
 *   func_021644A0  0x021644A0  arm  ov009
 *   func_02164490  0x02164490  arm  ov009
 *   func_02092364  0x02092364  arm
 *   func_021644B4  0x021644B4  arm  ov009
 *   _ll_udiv  0x0209C00C  arm
 *   func_021642E0  0x021642E0  arm  ov009
 *   func_021641C4  0x021641C4  arm  ov009
 *   func_021640B8  0x021640B8  arm  ov009
 */
typedef unsigned short u16;

typedef unsigned long u32;

typedef unsigned long long u64;

extern int func_02163F24(const unsigned short *p, int n);
extern void func_02082BCC(void *dst, unsigned char data, unsigned long size);
extern void func_021641FC(unsigned short *a, unsigned long b, int i, int digits);
extern void func_02082D44(const void *srcp, void *dstp, u32 size);
extern u64 func_021644A0(u16 *s);
extern u64 func_02164490(u16 *s);
extern void *func_02092364(void *dst, const void *src, u32 n);
extern u64 func_021644B4(u16 *s);
extern void func_021642E0(u16 *c, u16 *a, u16 b, int digits);
extern int func_021641C4(u16 *a, u16 *b, int digits);
extern void func_021640B8(u16 *c, u16 *a, u16 *b, int digits);
void func_02164358(unsigned short *c, unsigned short *a, int digits);
unsigned long long func_02164484(unsigned short *p);
asm void get48bits_2(void);
asm void get48bits_3(void);
asm void get64bits(void);
void func_021644D0(u16 *c, u16 *a, u16 *b, u16 *r, int digits, u16 *work);


/*
 * sdk:      CPSi_big_sqr (libssl.TWL.HYB.a(biginteger.o))
 */
void func_02164358(unsigned short *c, unsigned short *a, int digits)
{
    int i;
    int j;
    int digits_a;
    unsigned long tmp;

    digits_a = func_02163F24(a, digits);
    if (digits > digits_a * 2)
        func_02082BCC(c + digits_a * 2, 0, (digits - digits_a * 2) * 2);
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
                func_021641FC(c, tmp * 2, i + j, digits);
            else {
                func_021641FC(c, tmp, i + j, digits);
                func_021641FC(c, tmp, i + j, digits);
            }
        }
    }
}

/*
 * Halfword at p as the high word of a 64-bit value.
 */
unsigned long long func_02164484(unsigned short *p)
{
    return (unsigned long long)*p << 32;
}

asm void get48bits_2(void)
{
	ldrh r1, [r0]
	ldrh r0, [r0, #-2]
	mov r0, r0, lsl #16
	bx lr
}

asm void get48bits_3(void)
{
	ldrh r1, [r0]
	ldrh r2, [r0, #-2]
	ldrh r3, [r0, #-4]
	orr r0, r3, r2, lsl #16
	bx lr
}

asm void get64bits(void)
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
void func_021644D0(u16 *c, u16 *a, u16 *b, u16 *r, int digits, u16 *work)
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
    func_02082BCC(ca, 0, digits * 4);
    digits_a = func_02163F24(a, digits);
    digits_b = func_02163F24(b, digits);
    if (digits_a > 0 && digits_b > 0) {
        i = digits_b + (digits - digits_a) - 1;
        if (i >= digits) {
            func_02082D44(a, cca, digits * 2);
        } else {
            func_02082D44(a, ca + i, digits_a * 2);
            if (digits_b > 2)
                msd = func_021644A0(b + digits_b - 1);
            else if (digits_b > 1)
                msd = func_02164490(b + digits_b - 1);
            else
                msd = func_02164484(b + digits_b - 1);
            for (; i < digits; i++) {
                func_02092364(ca + 1, ca, (digits * 2 - 1) * 2);
                guess = func_021644B4(cca + digits_b) / msd;
                if (guess > 0xffff)
                    guess = 0xffff;
                while (1) {
                    func_021642E0(work, b, (u16)guess, digits);
                    if (func_021641C4(cca, work, digits) >= 0)
                        break;
                    guess--;
                }
                func_021640B8(cca, cca, work, digits);
                *ca = guess;
            }
        }
    }
    if (c)
        func_02082D44(ca, c, digits * 2);
    if (r)
        func_02082D44(cca, r, digits * 2);
}
