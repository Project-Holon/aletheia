/*
 * function: CPSi_big_power
 * address:  0x0216469C
 * packet:   pkt_ov009_0216469C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_big_power (libssl.TWL.HYB.a(biginteger.o))
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   count_digits  0x02163F24  arm  ov009
 *   MI_CpuCopy8  0x02082D44  arm
 *   CPSi_big_sqr  0x02164358  arm  ov009
 *   CPSi_big_div  0x021644D0  arm  ov009
 *   CPSi_big_mult  0x02164230  arm  ov009
 *   CPSiAlloc     0x021A8280  data
 *   CPSiFree     0x021A82B0  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern int count_digits(const unsigned short *p, int n);
extern void MI_CpuCopy8(void *srcp, void *dstp, u32 size);
extern void CPSi_big_sqr(u16 *c, u16 *a, int digits);
extern void CPSi_big_div(u16 *c, u16 *a, u16 *b, u16 *r, int digits, u16 *work);
extern void CPSi_big_mult(u16 *c, u16 *a, u16 *b, int digits);
extern void *(*CPSiAlloc)(u32 size);
extern void (*CPSiFree)(void *ptr);

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
