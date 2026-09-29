/*
 * function: func_021B4FB0
 * address:  0x021B4FB0
 * packet:   pkt_ov021_021B4FB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_021C5BD0  0x021C5BD0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0215A5F4(u32 a);
extern u32 func_0215A5DC(u32 a);
extern void func_0215897C(u32 a, u32 b);
extern u32 func_02159AE8(u32 a, u32 b);
extern u32 func_02159B10(u32 a, u32 b);
extern u32 func_0201210C(u32 a);
extern u32 func_020120F4(u32 a);
extern u32 func_02012EBC(u32 a);
extern u32 func_021C5BD0(u32 a, u32 b, u32 c);

int func_021B4FB0(u32 a, u32 b)
{
    u32 r0;
    u32 r7;
    u32 r4;
    u32 x;
    u32 y;

    r0 = func_0215A5F4(b);
    r7 = func_0215A5DC(b);
    func_02012EBC(func_020120F4(r7));
    func_0201210C(r7);
    r4 = func_02159B10(a, b);
    x = func_02159AE8(a, b);
    if (r4 == 0 || r4 != 1)
        y = 0;
    else
        y = 1;
    func_0215897C(r0, func_021C5BD0(r7, y, x));
    return 1;
}
