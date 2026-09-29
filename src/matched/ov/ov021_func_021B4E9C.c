/*
 * function: func_021B4E9C
 * address:  0x021B4E9C
 * packet:   pkt_ov021_021B4E9C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_021CD2A4  0x021CD2A4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0215A5F4(u32 a);
extern u32 func_0215A5DC(u32 a);
extern void func_0215897C(u32 a, u32 b);
extern u32 func_02159AE8(u32 a, u32 b);
extern u32 func_0201210C(u32 a);
extern u32 func_021CD2A4(u32 a, u32 b, u32 c, u32 d, u32 e);

int func_021B4E9C(u32 a, u32 b)
{
    u32 r6;
    u32 r7;
    u32 z;

    r6 = func_0215A5F4(b);
    r7 = func_0215A5DC(b);
    z = func_0201210C(r7);
    func_0215897C(r6, func_021CD2A4(r7, z, 0, 6, func_02159AE8(a, b)));
    return 1;
}
