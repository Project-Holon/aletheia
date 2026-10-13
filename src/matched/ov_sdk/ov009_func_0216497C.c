/*
 * function: func_0216497C
 * address:  0x0216497C
 * packet:   pkt_ov009_0216497C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_big_montmult (libssl.TWL.HYB.a(biginteger.o))
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_02164358  0x02164358  arm  ov009
 *   func_02164230  0x02164230  arm  ov009
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_02163F7C  0x02163F7C  arm  ov009
 *   func_02092364  0x02092364  arm
 *   func_021641C4  0x021641C4  arm  ov009
 *   func_021640B8  0x021640B8  arm  ov009
 */

extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void func_02164358(unsigned short *c, unsigned short *a, int digits);
extern void func_02164230(unsigned short *c, unsigned short *a, unsigned short *b, int digits);
extern void func_02163F7C(unsigned short *c, unsigned short *a, unsigned short *b, int digits);
extern void *func_02092364(void *dst, const void *src, unsigned long n);
extern int func_021641C4(unsigned short *a, unsigned short *b, int digits);
extern void func_021640B8(unsigned short *c, unsigned short *a, unsigned short *b, int digits);

static void func_0216497C(unsigned short *c, unsigned short *a, unsigned short *b, int digits,
                          int rdigits, unsigned short *n, unsigned short *np,
                          unsigned short *m, unsigned short *m2)
{
    MI_CpuCopy8(c, a, digits * 2);
    if (b == (unsigned short *)1)
        func_02164358(c, a, digits);
    else if (b != 0)
        func_02164230(c, a, b, digits);
    func_02164230(m, c, np, rdigits);
    MI_CpuFill8(m + rdigits, 0, (digits - rdigits) * 2);
    func_02164230(m2, m, n, digits);
    func_02163F7C(c, c, m2, digits);
    func_02092364(c, c + rdigits, (digits - rdigits) * 2);
    MI_CpuFill8(c + digits - rdigits, 0, rdigits * 2);
    switch (func_021641C4(c, n, digits)) {
    case 0:
        MI_CpuFill8(c, 0, digits * 2);
        break;
    case 1:
        func_021640B8(c, c, n, digits);
        break;
    }
}
