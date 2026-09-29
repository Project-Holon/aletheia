/*
 * function: func_021EF068
 * address:  0x021EF068
 * packet:   pkt_ov025_021EF068
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EF068 0x021EF068 thumb ov025
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A21F8 0x021A21F8 thumb ov021
 *   func_021A22E0 0x021A22E0 thumb ov021
 *   func_021A2254 0x021A2254 thumb ov021
 *   func_021A2114 0x021A2114 thumb ov021
 *   func_02014A10 0x02014A10 thumb
 *   func_021EF2D4 0x021EF2D4 thumb ov025
 */

extern int *func_021A21B8(int);
extern void func_021A21F8(int, int, int, int, int, int, int, int, void *);
extern void func_021A22E0(int, int, int, int);
extern void func_021A2254(int, void *, int, int, int, int);
extern void func_021A2114(int, int, int);
extern int func_02014A10(int);
extern void func_021EF2D4(void);

int func_021EF068(int a, int b, int c)
{
    func_021A21B8(a);
    func_021A21F8(a, 1, 1, 1, 1, -4, 2, 1, (void *)func_021EF2D4);
    func_021A22E0(a, 9, 0x7F80, b);
    func_021A2254(a, (void *)func_021EF2D4, 0x14, 10, 1, c);
    func_021A2114(a, 0x3E, func_02014A10(5));
    return 1;
}
