/*
 * function: func_021EEAEC
 * address:  0x021EEAEC
 * packet:   pkt_ov026_021EEAEC
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EEAEC 0x021EEAEC thumb ov026
 *   func_021EEE38 0x021EEE38 thumb ov026
 *   func_021EF9B0 0x021EF9B0 thumb ov026
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A21F8 0x021A21F8 thumb ov021
 *   func_021A22E0 0x021A22E0 thumb ov021
 *   func_021A2424 0x021A2424 thumb ov021
 */

typedef signed short s16;

extern s16 *func_021A21B8(int);
extern void func_021EF9B0(void *, int);
extern void func_021A21F8(int, int, int, int, int, int, int, int, void *);
extern void func_021A22E0(int, int, int, int);
extern void func_021A2424(int);
extern void func_021EEE38(int a, int n, int idx);

int func_021EEAEC(int a, int b)
{
    s16 *p;

    p = func_021A21B8(a);
    func_021EF9B0(p + 6, 2);
    func_021A21F8(a, 1, 0xF, 2, 0, -3, 1, 1, func_021EEE38);
    func_021A22E0(a, 9, 0x7FDF, b);
    p[1] = 0;
    p[0] = 0;
    func_021A2424(a);
    return 1;
}
