/*
 * function: func_021EF47C
 * address:  0x021EF47C
 * packet:   pkt_ov025_021EF47C
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EF47C 0x021EF47C thumb ov025
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A21F8 0x021A21F8 thumb ov021
 *   func_021A22E0 0x021A22E0 thumb ov021
 *   func_021A2254 0x021A2254 thumb ov021
 *   func_021A2114 0x021A2114 thumb ov021
 *   func_02014A10 0x02014A10 thumb
 *   func_021EF634 0x021EF634 thumb ov025
 */

extern int *func_021A21B8(int);
extern void func_021A21F8(int, int, int, int, int, int, int, int, void *);
extern void func_021A22E0(int, int, int, int);
extern void func_021A2254(int, void *, int, int, int, int);
extern void func_021A2114(int, int, int);
typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 func_02014A10(u32 i);
extern void func_021EF634(int *a, int n, int idx);

int func_021EF47C(int a, int b, int c)
{
    func_021A21B8(a);
    func_021A21F8(a, 0x14, 2, 0x14, 2, -2, 4, 2, (void *)func_021EF634);
    func_021A22E0(a, 8, 0x7F57, b);
    func_021A2254(a, (void *)func_021EF634, 0x14, 10, 1, c);
    func_021A2114(a, 0x3E, func_02014A10(8));
    return 1;
}
