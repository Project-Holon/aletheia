/*
 * function: func_021889A0
 * address:  0x021889A0
 * packet:   pkt_ov096_021889A0
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0201134C(int);
extern int func_0218A160(int, int);
extern int func_0218A2FC(int, int);
extern int func_0218A0F4(int, int, int, int, int);
extern int func_021D5BDC(int, int);

void func_021889A0(int a, int b, int c)
{
    int t1;
    int t2;
    int t3;
    int r;

    t1 = func_0201134C(a);
    t2 = func_0201134C(a);
    t3 = func_0201134C(a);
    r = func_0218A160(b, t1);
    r = func_0218A2FC(b, r);
    r = func_021D5BDC(r, t2);
    func_0218A0F4(a, c, r, 1, t3);
}
