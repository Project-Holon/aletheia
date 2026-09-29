/*
 * function: func_021C1D68
 * address:  0x021C1D68
 * packet:   pkt_ov021_021C1D68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017EAC  0x02017EAC  thumb
 *   func_021C1D18  0x021C1D18  thumb  ov021
 */

int func_020120F4(int a);
int func_02012934(int a);
int func_0201AB28(int a, int b);
int func_02017E1C(int a, int b, int c);
int func_02017EAC(int a);
int func_021C1D18(int a, int b, int c, int d, int e, int f, int g);

int func_021C1D68(int a, int b, int c)
{
    int p;
    int x5;
    int x6f;
    int x6e;
    int xe;
    int x4c;

    p = func_0201AB28(func_02012934(func_020120F4(a)), c);
    x5 = func_02017E1C(p, 5, 0);
    x6f = func_02017E1C(p, 0x6f, 0);
    x6e = func_02017E1C(p, 0x6e, 0);
    xe = func_02017EAC(p);
    x4c = func_02017E1C(p, 0x4c, 0);
    return func_021C1D18(a, b, x5, x6f, x6e, xe, x4c);
}
