/*
 * function: func_021EEF58
 * address:  0x021EEF58
 * packet:   pkt_ov026_021EEF58
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EEF58 0x021EEF58 thumb ov026
 *   func_021EF220 0x021EF220 thumb ov026
 *   func_021EF93C 0x021EF93C thumb ov026
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A21F8 0x021A21F8 thumb ov021
 *   func_021A22E0 0x021A22E0 thumb ov021
 *   func_021A2424 0x021A2424 thumb ov021
 */

extern int *func_021A21B8(int);
extern void func_021A21F8(int, int, int, int, int, int, int, int, void *);
extern void func_021A22E0(int, int, int, int);
extern void func_021A2424(int);
extern void func_021EF93C(int *);
extern void func_021EF220(int a, int n, int idx);

int func_021EEF58(int a, int b)
{
    int *p;

    p = func_021A21B8(a);
    func_021A21F8(a, 1, 4, 1, 1, -4, 1, 1, func_021EF220);
    func_021A22E0(a, 9, 0x7FDF, b);
    func_021A2424(a);
    func_021EF93C(p);
    return 1;
}
