/*
 * function: func_021BDAA8
 * address:  0x021BDAA8
 * packet:   pkt_ov021_021BDAA8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BDC2C  0x021BDC2C  thumb  ov021
 *   func_021BDBF8  0x021BDBF8  thumb  ov021
 *   func_021BDC0C  0x021BDC0C  thumb  ov021
 *   func_021BDC80  0x021BDC80  thumb  ov021
 *   func_021618E0  0x021618E0  thumb  ov010
 *   func_02012374  0x02012374  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021BDC2C(u32 *, u32);
extern void func_021BDBF8(u32 *);
extern void func_021BDC0C(u32 *, u32);
extern void func_021BDC80(u32 *);
extern u32 func_021618E0(u32, u32);
extern void func_02012374(u32, u32);

u32 func_021BDAA8(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[0];
    u32 x = *(u32 *)(p + 4);
    u32 y = *(u32 *)(p + 0xc);

    switch (*st) {
    case 0:
        func_021BDC2C(ctx, a);
        (*st)++;
        break;
    case 1:
        if (*(u32 *)(p + 0x48) != 0)
            func_021BDBF8(ctx);
        else if (*(u32 *)(p + 0x4c) != 0)
            func_021BDC0C(ctx, a);
        (*st)++;
        break;
    case 2:
        func_02012374(a, func_021618E0(x, y));
        (*st)++;
        break;
    case 3:
        func_021BDC80(ctx);
        return 1;
    }
    return 0;
}
