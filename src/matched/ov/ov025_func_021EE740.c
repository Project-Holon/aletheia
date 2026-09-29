/*
 * function: func_021EE740
 * address:  0x021EE740
 * packet:   pkt_ov025_021EE740
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021EE740  0x021EE740  thumb  ov025
 *   func_021EEA34  0x021EEA34  thumb  ov025
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A21F8  0x021A21F8  thumb  ov021
 *   func_021A22E0  0x021A22E0  thumb  ov021
 *   func_021A2424  0x021A2424  thumb  ov021
 */

int *func_021A21B8(int a);
void func_021A21F8(int a, int b, int c, int d, int e, int f, int g, int h, void (*i)(void));
void func_021A22E0(int a, int b, int c, int d);
void func_021A2424(int a);
void func_021EEA34(void);

int func_021EE740(int a, int b)
{
    int *p = func_021A21B8(a);

    func_021A21F8(a, 1, 0x12, 1, 0x10, -3, 1, 0, func_021EEA34);
    p[1] = 0;
    p[2] = 0;
    func_021A22E0(a, 8, 0x7FDF, b);
    p[0] = 8;
    func_021A2424(a);
    return 1;
}
