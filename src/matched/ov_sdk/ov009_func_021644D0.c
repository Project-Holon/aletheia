/*
 * function: func_021644D0
 * address:  0x021644D0
 * packet:   pkt_ov009_021644D0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_big_div (libssl.TWL.HYB.a(biginteger.o))
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_02163F24  0x02163F24  arm  ov009
 *   func_02082D44  0x02082D44  arm
 *   func_021644A0  0x021644A0  arm  ov009
 *   func_02164490  0x02164490  arm  ov009
 *   func_02164484  0x02164484  arm  ov009
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

extern void MI_CpuFill8(void *dstp, unsigned char data, u32 size);
extern int func_02163F24(const unsigned short *p, int n);
extern void func_02082D44(const void *srcp, void *dstp, u32 size);
extern u64 func_021644A0(u16 *s);
extern u64 func_02164490(u16 *s);
extern u64 func_02164484(u16 *s);
extern void *func_02092364(void *dst, const void *src, u32 n);
extern u64 func_021644B4(u16 *s);
extern void func_021642E0(u16 *c, u16 *a, u16 b, int digits);
extern int func_021641C4(u16 *a, u16 *b, int digits);
extern void func_021640B8(u16 *c, u16 *a, u16 *b, int digits);

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
    MI_CpuFill8(ca, 0, digits * 4);
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
