/*
 * function: func_021EF3BC
 * address:  0x021EF3BC
 * packet:   pkt_ov025_021EF3BC
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EF3BC 0x021EF3BC thumb ov025
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A21F8 0x021A21F8 thumb ov021
 *   func_021A22E0 0x021A22E0 thumb ov021
 *   func_021EF634 0x021EF634 thumb ov025
 */

extern int *func_021A21B8(int);
extern void func_021A21F8(int, int, int, int, int, int, int, int, void *);
extern void func_021A22E0(int, int, int, int);
extern void func_021EF634(void);

int func_021EF3BC(int a, int b)
{
    int *p;

    p = func_021A21B8(a);
    func_021A21F8(a, 2, 0x10, 0x14, 2, -2, 4, 2, (void *)func_021EF634);
    func_021A22E0(a, 8, 0x7FFF, b);
    *p = 0;
    return 1;
}
