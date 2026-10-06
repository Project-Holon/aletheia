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

typedef unsigned int   u32;
typedef unsigned char  u8;
extern int *func_021A21B8(int *p);
extern void func_021A21F8(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
extern void func_021A22E0(u32 *p, int a, int b, int c);
extern void func_021A2424(u8 *p);
typedef signed short   s16;
extern void func_021EF93C(s16 *p);
extern void func_021EF220(int a, int n, int idx);

int func_021EEF58(int a, int b)
{
    int *p;

    p = func_021A21B8((int *)a);
    func_021A21F8((u8 *)a, 1, 4, 1, 1, -4, 1, 1, (int)func_021EF220);
    func_021A22E0((u32 *)a, 9, 0x7FDF, b);
    func_021A2424((u8 *)a);
    func_021EF93C((s16 *)p);
    return 1;
}
