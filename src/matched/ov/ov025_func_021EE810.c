/*
 * function: func_021EE810
 * address:  0x021EE810
 * packet:   pkt_ov025_021EE810
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021EE810  0x021EE810  thumb  ov025
 *   func_021EEA34  0x021EEA34  thumb  ov025
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A21F8  0x021A21F8  thumb  ov021
 *   func_021A22E0  0x021A22E0  thumb  ov021
 *   func_021A2254  0x021A2254  thumb  ov021
 *   func_021A2114  0x021A2114  thumb  ov021
 *   func_02014A10  0x02014A10  thumb
 */

extern int *func_021A21B8(int);
extern void func_021A21F8(int, int, int, int, int, int, int, int, void *);
extern void func_021A22E0(int, int, int, int);
extern void func_021A2254(int, void *, int, int, int, int);
extern void func_021A2114(int, int, int);
typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 func_02014A10(u32 i);
extern void func_021EEA34(int a, int n, int idx);

int func_021EE810(int a, int b, int c)
{
    int *p = func_021A21B8(a);

    func_021A21F8(a, 1, 0x10, 1, 0x10, -3, 1, 0, (void *)func_021EEA34);
    p[1] = 1;
    p[2] = 0;
    func_021A22E0(a, 8, 0x7F5F, b);
    func_021A2254(a, (void *)func_021EEA34, 0x14, 1, 0x12, c);
    func_021A2114(a, 0x3E, func_02014A10(1));
    return 1;
}
