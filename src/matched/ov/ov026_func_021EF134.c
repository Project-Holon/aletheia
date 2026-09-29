/*
 * function: func_021EF134
 * address:  0x021EF134
 * packet:   pkt_ov026_021EF134
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EF134 0x021EF134 thumb ov026
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A2228 0x021A2228 thumb ov021
 *   func_021A25CC 0x021A25CC thumb ov021
 *   func_021A2390 0x021A2390 thumb ov021
 *   func_021A2160 0x021A2160 thumb ov021
 */

extern int *func_021A21B8(int);
extern void func_021A2228(int, int, int, int, int);
extern void func_021A25CC(int);
extern void func_021A2390(int, int, int, int);
extern void func_021A2160(int, int, int);

int func_021EF134(int a, int b)
{
    func_021A21B8(a);
    func_021A2228(a, 0, 4, 4, -1);
    func_021A25CC(a);
    func_021A2390(a, 0x7FDF, 0x32, b);
    func_021A2160(a, 0, 0);
    func_021A2160(a, 0, 1);
    return 1;
}
