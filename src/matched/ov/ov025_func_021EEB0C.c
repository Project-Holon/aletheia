/*
 * function: func_021EEB0C
 * address:  0x021EEB0C
 * packet:   pkt_ov025_021EEB0C
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021EEB0C  0x021EEB0C  thumb  ov025
 *   func_021EEE04  0x021EEE04  thumb  ov025
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A21F8  0x021A21F8  thumb  ov021
 *   func_021A22E0  0x021A22E0  thumb  ov021
 *   func_021A2424  0x021A2424  thumb  ov021
 *   func_021A25BC  0x021A25BC  thumb  ov021
 */

extern int *func_021A21B8(int);
extern void func_021A21F8(int, int, int, int, int, int, int, int, void *);
extern void func_021A22E0(int, int, int, int);
extern void func_021A2424(int);
extern void func_021A25BC(int, int);
typedef unsigned short u16;
extern void func_021EEE04(int a, int n, u16 idx);

int func_021EEB0C(int a, int b)
{
    int *p = func_021A21B8(a);

    func_021A21F8(a, 1, 6, 1, 2, -2, 2, 1, (void *)func_021EEE04);
    func_021A22E0(a, 4, 0x7FFF, b);
    p[0] = 8;
    p[1] = 0;
    p[2] = 0;
    p[9] = 0;
    p[8] = 0;
    func_021A2424(a);
    func_021A25BC(a, 0x6E3);
    return 1;
}
