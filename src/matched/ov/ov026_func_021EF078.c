/*
 * function: func_021EF078
 * address:  0x021EF078
 * packet:   pkt_ov026_021EF078
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EF078 0x021EF078 thumb ov026
 *   func_021EF220 0x021EF220 thumb ov026
 *   func_021EF614 0x021EF614 thumb ov026
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A21F8 0x021A21F8 thumb ov021
 *   func_021A22E0 0x021A22E0 thumb ov021
 *   func_021A2254 0x021A2254 thumb ov021
 *   func_021A25BC 0x021A25BC thumb ov021
 *   func_021A2160 0x021A2160 thumb ov021
 *   func_021A2114 0x021A2114 thumb ov021
 *   func_02014A10 0x02014A10 thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int *func_021A21B8(int);
extern void func_021A21F8(int, int, int, int, int, int, int, int, void *);
extern void func_021A22E0(int, int, int, int);
extern void func_021A2254(u8 *p, void (*fn)(u8 *, int, u32), int n, int m, int k, u16 w);
extern void func_021A25BC(int, int);
extern void func_021A2160(int, int, int);
extern void func_021A2114(int, int, int);
extern int func_02014A10(int);
extern void func_021EF614(int, int *, int, int);
extern void func_021EF220(u8 *, int, u32);

int func_021EF078(int a, int b, u16 c)
{
    int *p;

    p = func_021A21B8(a);
    func_021A21F8(a, 1, 1, 1, 1, -4, 1, 1, func_021EF220);
    func_021A22E0(a, 9, 0x7F80, b);
    func_021A2254((u8 *)a, func_021EF220, 0x14, 5, 1, c);
    func_021A25BC(a, 0x690);
    func_021EF614(a, p, b, 0);
    func_021A2160(a, 1, 0);
    func_021A2114(a, 0x3E, func_02014A10(7));
    return 1;
}
