/*
 * function: func_021EE740
 * address:  0x021EE740
 * packet:   pkt_ov027_021EE740
 * region:   ov027
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A21F8  0x021A21F8  thumb  ov021
 *   func_021A22E0  0x021A22E0  thumb  ov021
 *   func_021A2424  0x021A2424  thumb  ov021
 *   func_021A25BC  0x021A25BC  thumb  ov021
 *   func_021EEA04  0x021EEA04  thumb  ov027
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
int *func_021A21B8(int *p);
void func_021A21F8(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
void func_021A22E0(u32 *p, int a, int b, int c);
void func_021A2424(u8 *p);
void func_021A25BC(unsigned char *o, int arg);
void func_021EEA04(int a, int b, int c);

int func_021EE740(int a, int b)
{
    int *p = func_021A21B8((int *)a);

    func_021A21F8((u8 *)a, 1, 15, 1, 2, -2, 4, 1, (int)func_021EEA04);
    func_021A22E0((u32 *)a, 8, 0x7fdf, b);
    p[0] = 1;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    func_021A2424((u8 *)a);
    func_021A25BC((unsigned char *)a, 0x6e3);
    return 1;
}
