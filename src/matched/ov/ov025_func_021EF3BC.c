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

typedef unsigned int   u32;
typedef unsigned char  u8;
extern int *func_021A21B8(int *p);
extern void func_021A21F8(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
extern void func_021A22E0(u32 *p, int a, int b, int c);
extern void func_021EF634(int *a, int n, int idx);

int func_021EF3BC(int a, int b)
{
    int *p;

    p = func_021A21B8((int *)a);
    func_021A21F8((u8 *)a, 2, 0x10, 0x14, 2, -2, 4, 2, (int)((void *)func_021EF634));
    func_021A22E0((u32 *)a, 8, 0x7FFF, b);
    *p = 0;
    return 1;
}
