/*
 * function: func_021EEBE4
 * address:  0x021EEBE4
 * packet:   pkt_ov025_021EEBE4
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021EEBE4  0x021EEBE4  thumb  ov025
 *   func_021EEE04  0x021EEE04  thumb  ov025
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A21F8  0x021A21F8  thumb  ov021
 *   func_021A22E0  0x021A22E0  thumb  ov021
 *   func_021A2254  0x021A2254  thumb  ov021
 *   func_021A2160  0x021A2160  thumb  ov021
 *   func_021A2114  0x021A2114  thumb  ov021
 *   func_02014A10  0x02014A10  thumb
 */

typedef unsigned char  u8;
extern int *func_021A21B8(int *p);
extern void func_021A21F8(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
extern void func_021A22E0(int, int, int, int);
extern void func_021A2254(int, void *, int, int, int, int);
extern void func_021A2160(unsigned char *o, unsigned int v, int i);
extern void func_021A2114(int, int, int);
typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 func_02014A10(u32 i);
extern void func_021EEE04(int a, int n, u16 idx);

int func_021EEBE4(int a, int b, int c)
{
    int *p = func_021A21B8((int *)a);

    func_021A21F8((u8 *)a, 1, 2, 1, 2, -2, 2, 1, (int)((void *)func_021EEE04));
    func_021A22E0(a, 4, 0x7B18, b);
    p[1] = 0;
    p[2] = 0;
    p[9] = 0;
    func_021A2254(a, (void *)func_021EEE04, 0x14, 2, 2, c);
    func_021A2160((unsigned char *)a, 1, 0);
    func_021A2114(a, 0x3E, func_02014A10(4));
    return 1;
}
