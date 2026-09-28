/*
 * function: func_02189BFC
 * address:  0x02189BFC
 * packet:   pkt_ov096_02189BFC
 * region:   ov096
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_020113B0  0x020113B0  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_0218A390  0x0218A390  thumb  ov096
 *   func_021D67A8  0x021D67A8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021C7E14  0x021C7E14  thumb  ov093
 */

extern int func_0201134C(int);
extern void func_020113B0(int, int);
extern int func_0218A160(int, int);
extern int func_0218A2FC(int, int);
extern int func_0218A390(int, int, int, int);
extern int func_021D67A8(int);
extern int func_021D5440(int);
extern int func_021C7E14(int, int, int, int, int, int);

int func_02189BFC(int a, int b)
{
    int t0;
    int t1;
    int t2;
    int v;
    unsigned int w;
    int x;
    int y;
    int z;
    unsigned int r;

    t0 = func_0201134C(a);
    t1 = func_0201134C(a);
    t2 = func_0201134C(a);
    v = func_0218A2FC(b, func_0218A160(b, t0));
    w = func_0218A390(b, *(int *)(b + 0xbc), *(int *)(b + 0xc0), t1);
    x = func_021D67A8(v);
    y = func_021D5440(v);
    z = func_021D5440(*(int *)(b + 0xc0));
    r = func_021C7E14(*(int *)(b + 0xb4), y, z, x, 1, t1);
    if (w < r)
        func_020113B0(a, *(int *)(a + 0x14) + t2);
    return *(int *)(b + 0xc4);
}
