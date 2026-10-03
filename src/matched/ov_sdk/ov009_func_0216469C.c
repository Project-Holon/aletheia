/*
 * function: func_0216469C
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
 *   func_02082BCC  0x02082BCC  arm
 *   func_02163F24  0x02163F24  arm  ov009
 *   func_02082D44  0x02082D44  arm
 *   func_02164358  0x02164358  arm  ov009
 *   func_021644D0  0x021644D0  arm  ov009
 *   func_02164230  0x02164230  arm  ov009
 *   g_021A8280     0x021A8280  data
 *   g_021A82B0     0x021A82B0  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

extern void func_02082BCC(void *dstp, u8 data, u32 size);
extern int func_02163F24(const unsigned short *p, int n);
extern void func_02082D44(void *srcp, void *dstp, u32 size);
extern void func_02164358(u16 *c, u16 *a, int digits);
extern void func_021644D0(u16 *c, u16 *a, u16 *b, u16 *r, int digits, u16 *work);
extern void func_02164230(u16 *c, u16 *a, u16 *b, int digits);
extern void *(*g_021A8280)(u32 size);
extern void (*g_021A82B0)(void *ptr);

void func_0216469C(u16 *c, u16 *a, u16 *b, int digits, u16 *n)
{
    u16 *tmp;
    u16 *divwork;
    int i;

    tmp = g_021A8280(digits * sizeof(u16) * 4);
    if (tmp == 0)
        return;
    divwork = tmp + digits;
    func_02082BCC(c + 1, 0, (digits - 1) * sizeof(u16));
    c[0] = 1;
    for (i = (digits - func_02163F24(b, digits)) * 16; i < digits * sizeof(u16) * 8; i++) {
        if (b[digits - (i >> 4) - 1] & (0x8000u >> (i & 15))) {
            func_02082D44(a, c, digits * sizeof(u16));
            i++;
            break;
        }
    }
    for (; i < digits * sizeof(u16) * 8; i++) {
        func_02164358(tmp, c, digits);
        func_02082D44(tmp, c, digits * sizeof(u16));
        if (n)
            func_021644D0(0, c, n, c, digits, divwork);
        if (b[digits - (i >> 4) - 1] & (0x8000u >> (i & 15))) {
            func_02164230(tmp, c, a, digits);
            func_02082D44(tmp, c, digits * sizeof(u16));
            if (n)
                func_021644D0(0, c, n, c, digits, divwork);
        }
    }
    g_021A82B0(tmp);
}
