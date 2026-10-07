/*
 * file:     unit_021EE740_p01.c
 * unit:     yes
 * function: func_021EE740, func_021EE790
 * address:  0x021EE740
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A21F8 0x021A21F8 thumb ov021
 *   func_021A22E0 0x021A22E0 thumb ov021
 *   func_021A2424 0x021A2424 thumb ov021
 *   func_021EEA18 0x021EEA18 thumb ov026
 *   func_021A223C 0x021A223C thumb ov021
 *   func_021A232C 0x021A232C thumb ov021
 *   func_021A2108 0x021A2108 thumb ov021
 *   func_021A25BC 0x021A25BC thumb ov021
 *   func_021A23B0 0x021A23B0 thumb ov021
 *   func_021A244C 0x021A244C thumb ov021
 *   func_021A2564 0x021A2564 thumb ov021
 *   func_02014A10 0x02014A10 thumb
 */
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed int     s32;

typedef unsigned short u16;

extern int *func_021A21B8(int *p);
extern void func_021A21F8(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
extern void func_021A22E0(u32 *p, int a, int b, int c);
extern void func_021A2424(u8 *p);
extern void func_021EEA18(int a, int n, int idx);
extern int func_021A223C(unsigned char *o, int arg);
extern void func_021A232C(u8 *p, int a, int b, int c, int d);
extern int func_021A2108(unsigned int a, int b, int c);
extern void func_021A25BC(unsigned char *o, int arg);
extern int func_021A23B0(unsigned int a);
extern void func_021A244C(u8 *o, s32 *outX, s32 *outY);
extern void func_021A2564(int, int, int);
extern u16 func_02014A10(u32 i);
int func_021EE740(int a, int b);
int func_021EE790(int a, int b, int c);


int func_021EE740(int a, int b)
{
    int *p;

    p = func_021A21B8((int *)a);
    func_021A21F8((u8 *)a, 1, 8, 2, 0, -4, 2, 1, (int)((void *)func_021EEA18));
    func_021A22E0((u32 *)a, 8, 0x7FDF, b);
    *p = 1;
    func_021A2424((u8 *)a);
    return 1;
}


int func_021EE790(int a, int b, int c)
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
            func_021A2108(a, 0x3E, func_02014A10(2));
            func_021A25BC((unsigned char *)a, 0x691);
        }
    } else if (func_021A23B0(a) != 0 && t != 0) {
        return 1;
    }
    func_021A244C((u8 *)a, &x, &y);
    func_021A2564(a, x, y);
    return 0;
}
