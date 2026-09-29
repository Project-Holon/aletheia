/*
 * function: func_021EEF94
 * address:  0x021EEF94
 * packet:   pkt_ov025_021EEF94
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EEF94 0x021EEF94 thumb ov025
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A21F8 0x021A21F8 thumb ov021
 *   func_021A22E0 0x021A22E0 thumb ov021
 *   func_021A2424 0x021A2424 thumb ov021
 *   func_021A25BC 0x021A25BC thumb ov021
 *   func_021EF2D4 0x021EF2D4 thumb ov025
 */

extern int *func_021A21B8(int);
extern void func_021A21F8(int, int, int, int, int, int, int, int, void *);
extern void func_021A22E0(int, int, int, int);
extern void func_021A2424(int);
extern void func_021A25BC(int, int);
extern void func_021EF2D4(void);

int func_021EEF94(int a, int b)
{
    int *p;

    p = func_021A21B8(a);
    func_021A21F8(a, 0, 8, 1, 1, -4, 2, 1, (void *)func_021EF2D4);
    func_021A22E0(a, 9, 0x7FDF, b);
    *p = 1;
    func_021A2424(a);
    func_021A25BC(a, 0x6E4);
    return 1;
}
