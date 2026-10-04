/*
 * function: func_021EEB0C
 * address:  0x021EEB0C
 * packet:   pkt_ov025_021EEB0C
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021EEB0C  0x021EEB0C  thumb  ov025
 *   func_021EEE04  0x021EEE04  thumb  ov025
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A21F8  0x021A21F8  thumb  ov021
 *   func_021A22E0  0x021A22E0  thumb  ov021
 *   func_021A2424  0x021A2424  thumb  ov021
 *   func_021A25BC  0x021A25BC  thumb  ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern int *func_021A21B8(int *p);
extern void func_021A21F8(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
extern void func_021A22E0(u32 *p, int a, int b, int c);
extern void func_021A2424(u8 *p);
extern void func_021A25BC(unsigned char *o, int arg);
typedef unsigned short u16;
extern void func_021EEE04(int a, int n, u16 idx);

int func_021EEB0C(int a, int b)
{
    int *p = func_021A21B8((int *)a);

    func_021A21F8((u8 *)a, 1, 6, 1, 2, -2, 2, 1, (int)((void *)func_021EEE04));
    func_021A22E0((u32 *)a, 4, 0x7FFF, b);
    p[0] = 8;
    p[1] = 0;
    p[2] = 0;
    p[9] = 0;
    p[8] = 0;
    func_021A2424((u8 *)a);
    func_021A25BC((unsigned char *)a, 0x6E3);
    return 1;
}
