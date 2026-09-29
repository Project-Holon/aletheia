/*
 * function: func_021A6CB8
 * address:  0x021A6CB8
 * packet:   pkt_ov021_021A6CB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_021A6D58  0x021A6D58  thumb  ov021
 *   func_02188CAC  0x02188CAC  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D888  0x0216D888  thumb  ov010
 *   func_02188D40  0x02188D40  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AB8  0x02012AB8  thumb
 *   func_021A36B0  0x021A36B0  thumb  ov021
 *   func_021A36D4  0x021A36D4  thumb  ov021
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_021A305C  0x021A305C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02188C58(u32 p);
extern u32 func_02188C5C(u32 p);
extern u32 func_02188CB4(u32 p);
extern u32 func_02188C84(u32 p);
extern u32 func_021A6D58(u32 p, u32 q);
extern void func_02188CAC(u32 p, u32 v);
extern void func_021A3074(u32 p);
extern u32 func_0216D888();
extern void func_02188D40(u32 p, u32 v);
extern u32 func_02188C80(u32 p);
extern u32 func_020120F4();
extern u32 func_020127A4();
extern u32 func_02012AB8();
extern void func_021A36B0(u32 p, u32 v);
extern void func_021A36D4(u32 p, u32 v);
extern void func_021A3044(u32 p, u32 v);
extern void func_021A305C(u32 p, u32 v);

void func_021A6CB8(u32 a, u32 b, u32 c)
{
    u32 r4;

    func_02188C58(a);
    func_02188C5C(a);
    r4 = func_02188CB4(a);
    func_02188CAC(a, func_021A6D58(a, func_02188C84(a)));
    func_021A3074(r4);
    func_02188D40(a, func_0216D888());
    func_02188C80(a);
    func_020120F4();
    func_020127A4();
    func_021A36B0(r4, func_02012AB8());
    func_021A36D4(r4, b);
    func_021A3044(r4, b);
    func_021A305C(r4, c);
}
