/*
 * file:     unit_021EE740_p01.c
 * unit:     yes
 * function: func_021EE740, func_021EE7A4, func_021EE814, func_021EE888
 * address:  0x021EE740
 * region:   ov027
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A21F8  0x021A21F8  thumb  ov021
 *   func_021A22E0  0x021A22E0  thumb  ov021
 *   func_021A2424  0x021A2424  thumb  ov021
 *   func_021A25BC  0x021A25BC  thumb  ov021
 *   func_021EEA04  0x021EEA04  thumb  ov027
 *   func_021A223C  0x021A223C  thumb  ov021
 *   func_021A232C  0x021A232C  thumb  ov021
 *   func_02014A10  0x02014A10  thumb
 *   func_021A2108  0x021A2108  thumb  ov021
 *   func_021A23B0  0x021A23B0  thumb  ov021
 *   func_021A2160  0x021A2160  thumb  ov021
 *   func_021EEAF4  0x021EEAF4  thumb  ov027
 *   func_021A2254  0x021A2254  thumb  ov021
 *   func_021A2114  0x021A2114  thumb  ov021
 *   func_021A2248  0x021A2248  thumb  ov021
 *   func_0209C0A4  0x0209C0A4  arm
 *   d_021EEB48     0x021EEB48  data  ov027  a4
 */
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

int *func_021A21B8(int *p);
void func_021A21F8(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
void func_021A22E0(u32 *p, int a, int b, int c);
void func_021A2424(u8 *p);
void func_021A25BC(unsigned char *o, int arg);
void func_021EEA04(int a, int b, int c);
int func_021A223C(unsigned char *o, int arg);
void func_021A232C(u8 *p, int a, int b, int c, int d);
u16 func_02014A10(u32 i);
int func_021A2108(u32 a, int b, int c);
int func_021A23B0(u32 a);
void func_021A2160(unsigned char *o, unsigned int v, int i);
void func_021EEAF4(int a, int *p);
void func_021A2254(int a, void (*b)(int, int, int), int c, int d, int e, int f);
int func_021A2114(u32 a, int b, u32 c);
int func_021A2248(unsigned char *o, int arg);
int func_0209C0A4(int a, int b);
int func_021EE740(int a, int b);
int func_021EE7A4(int a, int b, int c);
int func_021EE814(unsigned int *a, int b, int c);
int func_021EE888(int a, int b, int c);
extern int d_021EEB48[];


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


int func_021EE7A4(int a, int b, int c)
{
    int *p = func_021A21B8((int *)a);
    int t = func_021A223C((unsigned char *)a, c);

    if (*p > 0) {
        *p = *p - 1;
        if (*p == 0) {
            func_021A232C((u8 *)a, 8, 0x7f5e, 0x5a, b);
            func_021A2108(a, 0x3e, func_02014A10(3));
        }
    } else if (func_021A23B0(a) != 0 && t != 0) {
        func_021A2160((unsigned char *)a, 1, 0);
        return 1;
    }
    func_021EEAF4(a, p);
    return 0;
}


int func_021EE814(unsigned int *a, int b, int c)
{
    func_021A21B8((int *)a);
    func_021A21F8((u8 *)a, 1, 2, 1, 2, -2, 4, 1, (int)func_021EEA04);
    func_021A22E0(a, 8, 0x7f5e, b);
    func_021A2254((int)a, func_021EEA04, 24, 2, 2, c);
    func_021A2160((unsigned char *)a, 1, 0);
    func_021A2114((u32)a, 0x3e, func_02014A10(3));
    return 1;
}


int func_021EE888(int a, int b, int c)
{
    int *p = func_021A21B8((int *)a);

    if (func_021A2248((unsigned char *)a, c) != 0) {
        int v = d_021EEB48[func_0209C0A4(p[1], 40)];
        p[3] = v;
        if (v <= -6)
            func_021EEA04(a, 1, c);
    }
    func_021EEAF4(a, p);
    return 0;
}
