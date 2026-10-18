/*
 * function: CPSi_big_div
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
 *   count_digits  0x02163F24  arm  ov009
 *   MI_CpuCopy8  0x02082D44  arm
 *   get48bits_3  0x021644A0  arm  ov009
 *   get48bits_2  0x02164490  arm  ov009
 *   get48bits_1  0x02164484  arm  ov009
 *   memmove  0x02092364  arm
 *   get64bits  0x021644B4  arm  ov009
 *   _ll_udiv  0x0209C00C  arm
 *   func_021642E0  0x021642E0  arm  ov009
 *   CPSi_big_compare  0x021641C4  arm  ov009
 *   CPSi_big_sub  0x021640B8  arm  ov009
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

extern void MI_CpuFill8(void *dstp, unsigned char data, u32 size);
extern int count_digits(const unsigned short *p, int n);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern u64 get48bits_3(u16 *s);
extern u64 get48bits_2(u16 *s);
extern u64 get48bits_1(u16 *s);
extern void *memmove(void *dst, const void *src, u32 n);
extern u64 get64bits(u16 *s);
extern void func_021642E0(u16 *c, u16 *a, u16 b, int digits);
extern int CPSi_big_compare(u16 *a, u16 *b, int digits);
extern void CPSi_big_sub(u16 *c, u16 *a, u16 *b, int digits);

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
                    func_021642E0(work, b, (u16)guess, digits);
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
