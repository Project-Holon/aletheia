/*
 * function: func_021B631C
 * address:  0x021B631C
 * packet:   pkt_ov021_021B631C
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
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021C5AAC  0x021C5AAC  thumb  ov021
 *   func_0215897C  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0215A5F4(u32 a);
extern u32 func_0215A5DC(u32 a);
extern u16 *func_02159AE8(u32 a, u32 b);
extern u32 func_02159B10(u32 a, u32 b);
extern u32 func_021C5AAC(u32 a, u16 *b, u32 c, u32 d);
extern void func_0215897C(u32 a, u32 b);

int func_021B631C(u32 a, u32 b)
{
    u32 x;
    u32 y;
    u16 *p;
    u32 q;

    x = func_0215A5F4(b);
    y = func_0215A5DC(b);
    p = func_02159AE8(a, b);
    q = func_02159B10(a, b);
    func_0215897C(x, func_021C5AAC(y, p, q, func_02159B10(a, b)));
    return 1;
}
