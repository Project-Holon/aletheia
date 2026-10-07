/*
 * file:     unit_021EE740_p01.c
 * unit:     yes
 * function: func_021EE740, func_021EE798
 * address:  0x021EE740
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021EEA34  0x021EEA34  thumb  ov025
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A21F8  0x021A21F8  thumb  ov021
 *   func_021A22E0  0x021A22E0  thumb  ov021
 *   func_021A2424  0x021A2424  thumb  ov021
 *   func_021A223C  0x021A223C  thumb  ov021
 *   func_021A232C  0x021A232C  thumb  ov021
 *   func_021A2108  0x021A2108  thumb  ov021
 *   func_021A23B0  0x021A23B0  thumb  ov021
 *   func_021A244C  0x021A244C  thumb  ov021
 *   func_021A2564  0x021A2564  thumb  ov021
 *   func_02014A10  0x02014A10  thumb
 */
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed int     s32;

typedef unsigned short u16;

int *func_021A21B8(int *p);
void func_021A21F8(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
void func_021A22E0(u32 *p, int a, int b, int c);
void func_021A2424(u8 *p);
void func_021EEA34(int a, int n, int idx);
extern int func_021A223C(unsigned char *o, int arg);
extern void func_021A232C(u8 *p, int a, int b, int c, int d);
extern int func_021A2108(unsigned int a, int b, int c);
extern int func_021A23B0(unsigned int a);
extern void func_021A244C(u8 *o, s32 *outX, s32 *outY);
extern void func_021A2564(int, int, int);
extern u16 func_02014A10(u32 i);
int func_021EE740(int a, int b);
int func_021EE798(int a, int b, int c);


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


int func_021EE798(int a, int b, int c)
{
    int *p;
    int t;
    int x;
    int y;

    p = func_021A21B8((int *)a);
    t = func_021A223C((unsigned char *)a, c);
    if (*p > 0) {
        *p = *p - 1;
        if (*p == 0) {
            func_021A232C((u8 *)a, 8, 0x7F5F, 0x5A, b);
            func_021A2108(a, 0x3E, func_02014A10(1));
        }
    } else if (func_021A23B0(a) != 0 && t != 0) {
        return 1;
    }
    func_021A244C((u8 *)a, &x, &y);
    func_021A2564(a, x, y);
    return 0;
}
