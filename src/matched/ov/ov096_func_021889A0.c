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
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern int func_0218A0F4(u8 *a, int op, int x, int y, int z);
struct UtilWork;
extern int func_021D5BDC(struct UtilWork *p, u32 n);

void func_021889A0(int a, int b, int c)
{
    int t1;
    int t2;
    int t3;
    int r;
    u8 s;

    t1 = func_0201134C(a);
    t2 = func_0201134C(a);
    t3 = func_0201134C(a);
    s = func_0218A160((u8 *)b, t1);
    r = func_021D5BDC((struct UtilWork *)func_0218A2FC((u8 *)b, s), t2);
    func_0218A0F4((u8 *)a, c, r, 1, t3);
}
