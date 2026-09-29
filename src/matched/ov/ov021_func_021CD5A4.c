/*
 * function: func_021CD5A4
 * address:  0x021CD5A4
 * packet:   pkt_ov021_021CD5A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021CE760  0x021CE760  thumb  ov021
 *   func_021CE81C  0x021CE81C  thumb  ov021
 *   func_021909BC  0x021909BC  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_02190E40  0x02190E40  thumb  ov021
 *   func_021904C8  0x021904C8  thumb  ov021
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0203CD98  0x0203CD98  arm
 *   func_021CF17C  0x021CF17C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 func_021CE760(void *p);
extern void func_021CE81C(void *p);
extern void func_021909BC(u32 h);
extern void func_02045808(u32 h);
extern void func_02190E40(u32 h);
extern void func_021904C8(u32 h);
extern void func_0201ED04(u32 h);
extern int func_0203CD98(void);
extern void func_021CF17C(void);
extern void func_020307B0(void *p);

u32 func_021CD5A4(u32 *p)
{
    u32 r;

    r = func_021CE760(p);
    func_021CE81C(p);
    if (p[0x4c]) {
        func_021909BC(p[0x4c]);
        p[0x4c] = 0;
    }
    func_02045808(p[10]);
    func_02045808(p[9]);
    func_02045808(p[8]);
    func_02045808(p[7]);
    func_02045808(p[6]);
    func_02190E40(p[5]);
    func_021904C8(p[2]);
    func_0201ED04(p[1]);
    if (func_0203CD98() == 1) {
        func_021CF17C();
    }
    func_020307B0(p);
    return r;
}
