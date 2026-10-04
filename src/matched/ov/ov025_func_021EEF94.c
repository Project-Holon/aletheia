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

typedef unsigned int   u32;
typedef unsigned char  u8;
extern int *func_021A21B8(int *p);
extern void func_021A21F8(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
extern void func_021A22E0(u32 *p, int a, int b, int c);
extern void func_021A2424(u8 *p);
extern void func_021A25BC(unsigned char *o, int arg);
extern void func_021EF2D4(int a, int n, int idx);

int func_021EEF94(int a, int b)
{
    int *p;

    p = func_021A21B8((int *)a);
    func_021A21F8((u8 *)a, 0, 8, 1, 1, -4, 2, 1, (int)((void *)func_021EF2D4));
    func_021A22E0((u32 *)a, 9, 0x7FDF, b);
    *p = 1;
    func_021A2424((u8 *)a);
    func_021A25BC((unsigned char *)a, 0x6E4);
    return 1;
}
