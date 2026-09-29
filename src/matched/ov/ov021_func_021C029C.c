/*
 * function: func_021C029C
 * address:  0x021C029C
 * packet:   pkt_ov021_021C029C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021C7D28  0x021C7D28  thumb  ov021
 *   func_021C7260  0x021C7260  thumb  ov021
 *   func_021C71D4  0x021C71D4  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern u32 func_02188D38(u32 a);
extern u32 func_02188CB4(u32 a);
extern u32 func_021A3074(void);
extern u32 func_021C7D28(u32 a, u32 b, u32 c, u32 d);
extern u32 func_021C7260(u32 a, u32 b, u32 c);
extern u32 func_021C71D4(u32 a, u32 b, u32 c);
extern void func_021C6DE0(u32 a, u32 b, u32 c);

void func_021C029C(u8 *p)
{
    u32 s;
    u32 a;
    u32 b;
    u32 c;
    u32 d;

    s = *(u32 *)(p + 4);
    a = func_02188D38(s);
    func_02188CB4(s);
    b = func_021C7D28(s, func_021A3074(), 0x28, 6);
    c = func_021C7260(s, 0x14, 4);
    d = func_021C71D4(s, 0x14, 5);
    func_021C6DE0(a, b, 0);
    func_021C6DE0(a, c, 0);
    func_021C6DE0(a, d, c);
}
