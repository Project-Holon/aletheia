/*
 * function: func_021EE740
 * address:  0x021EE740
 * packet:   pkt_ov025_021EE740
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021EE740  0x021EE740  thumb  ov025
 *   func_021EEA34  0x021EEA34  thumb  ov025
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A21F8  0x021A21F8  thumb  ov021
 *   func_021A22E0  0x021A22E0  thumb  ov021
 *   func_021A2424  0x021A2424  thumb  ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
int *func_021A21B8(int *p);
void func_021A21F8(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
void func_021A22E0(u32 *p, int a, int b, int c);
void func_021A2424(u8 *p);
void func_021EEA34(int a, int n, int idx);

int func_021EE740(int a, int b)
{
    int *p = func_021A21B8((int *)a);

    func_021A21F8((u8 *)a, 1, 0x12, 1, 0x10, -3, 1, 0, (int)func_021EEA34);
    p[1] = 0;
    p[2] = 0;
    func_021A22E0((u32 *)a, 8, 0x7FDF, b);
    p[0] = 8;
    func_021A2424((u8 *)a);
    return 1;
}
