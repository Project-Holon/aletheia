/*
 * function: func_02188A08
 * address:  0x02188A08
 * packet:   pkt_ov096_02188A08
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   func_021C82D0  0x021C82D0  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0201134C(int);
extern int func_0218A160(int, int);
extern void func_0218A0F4(int, int, int, int, int);
extern int func_021C82D0(int, int, int);

void func_02188A08(int a, int b, int c)
{
    int t0;
    int t1;
    int t2;
    int r;

    t0 = func_0201134C(a);
    t1 = func_0201134C(a);
    t2 = func_0201134C(a);
    r = func_0218A160(b, t0);
    r = func_021C82D0(*(int *)(b + 0xb4), r, t1);
    func_0218A0F4(a, c, r != 0, 1, t2);
}
