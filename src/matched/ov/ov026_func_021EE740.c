/*
 * function: func_021EE740
 * address:  0x021EE740
 * packet:   pkt_ov026_021EE740
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EE740 0x021EE740 thumb ov026
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A21F8 0x021A21F8 thumb ov021
 *   func_021A22E0 0x021A22E0 thumb ov021
 *   func_021A2424 0x021A2424 thumb ov021
 *   func_021EEA18 0x021EEA18 thumb ov026
 */

extern int *func_021A21B8(int);
extern void func_021A21F8(int, int, int, int, int, int, int, int, void *);
extern void func_021A22E0(int, int, int, int);
extern void func_021A2424(int);
extern void func_021EEA18(int a, int n, int idx);

int func_021EE740(int a, int b)
{
    int *p;

    p = func_021A21B8(a);
    func_021A21F8(a, 1, 8, 2, 0, -4, 2, 1, (void *)func_021EEA18);
    func_021A22E0(a, 8, 0x7FDF, b);
    *p = 1;
    func_021A2424(a);
    return 1;
}
