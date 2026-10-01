/*
 * function: func_021A3AD8
 * address:  0x021A3AD8
 * packet:   pkt_ov021_021A3AD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0219D208  0x0219D208  thumb  ov021
 *   func_0216CD88  0x0216CD88  thumb  ov010
 *   func_021A398C  0x021A398C  thumb  ov021
 *   func_021A31A4  0x021A31A4  thumb  ov021
 *   func_0216E204  0x0216E204  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned int  u32;

u32 func_021A3960(u8 *p);
u32 func_0216D67C(u32 h);
int func_0216D598(u32 h);
void func_0219D208(u32 h, int a);
void func_0216CD88(u32 g);
u32 func_021A398C(u8 *p);
int func_021A31A4(u32 x, int a);
void func_0216E204(u32 h, int v);

void func_021A3AD8(u8 *p, int a)
{
    u32 h = func_021A3960(p);
    u32 g = func_0216D67C(h);
    int r = func_0216D598(h);

    if (a == 1 || a == 4 || r == 1 || r == 4) {
        func_0219D208(h, a);
        func_0216CD88(g);
        return;
    }
    func_0216E204(h, func_021A31A4(func_021A398C(p), 0));
    func_0216CD88(g);
    func_0219D208(h, a);
    func_0216CD88(g);
}
