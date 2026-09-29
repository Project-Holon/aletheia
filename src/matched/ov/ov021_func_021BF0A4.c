/*
 * function: func_021BF0A4
 * address:  0x021BF0A4
 * packet:   pkt_ov021_021BF0A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0218774C  0x0218774C  thumb  ov020
 *   func_02012374  0x02012374  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0218774C(u32 a, u32 b, u32 c, u32 d);
extern void func_02012374(u32 a, u32 b);

int func_021BF0A4(u32 p0, int *st, u8 *q)
{
    u32 a = *(u32 *)q;
    u32 b = *(u32 *)(q + 4);

    switch (*st) {
    case 0: {
        u32 r = func_0218774C(a, b, q[0x20], q[0x21]);
        func_02012374(p0, r);
        *st = *st + 1;
        break;
    }
    case 1:
        return 1;
    }
    return 0;
}
