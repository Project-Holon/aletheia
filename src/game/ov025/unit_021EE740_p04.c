/*
 * file:     unit_021EE740_p04.c
 * unit:     yes
 * function: func_021EEB0C, func_021EEB74
 * address:  0x021EEB0C
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
 *   func_021EEE04  0x021EEE04  thumb  ov025
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A21F8  0x021A21F8  thumb  ov021
 *   func_021A22E0  0x021A22E0  thumb  ov021
 *   func_021A2424  0x021A2424  thumb  ov021
 *   func_021A25BC  0x021A25BC  thumb  ov021
 *   func_021EEEE0  0x021EEEE0  thumb  ov025
 *   func_021A223C  0x021A223C  thumb  ov021
 *   func_021A232C  0x021A232C  thumb  ov021
 *   func_021A2108  0x021A2108  thumb  ov021
 *   func_021A23B0  0x021A23B0  thumb  ov021
 *   func_021A2160  0x021A2160  thumb  ov021
 *   func_02014A10  0x02014A10  thumb
 */
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

extern int *func_021A21B8(int *p);
extern void func_021A21F8(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
extern void func_021A22E0(u32 *p, int a, int b, int c);
extern void func_021A2424(u8 *p);
extern void func_021A25BC(unsigned char *o, int arg);
extern void func_021EEE04(int a, int n, u16 idx);
extern int func_021A223C(unsigned char *o, int arg);
extern void func_021A232C(u8 *p, int a, int b, int c, int d);
extern int func_021A2108(unsigned int a, int b, int c);
extern int func_021A23B0(unsigned int a);
extern void func_021A2160(unsigned char *o, unsigned int v, int i);
extern u16 func_02014A10(u32 i);
extern void func_021EEEE0(int, int *);
int func_021EEB0C(int a, int b);
int func_021EEB74(int a, int b, int c);


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


int func_021EEB74(int a, int b, int c)
{
    int *p;
    int t;

    p = func_021A21B8((int *)a);
    t = func_021A223C((unsigned char *)a, c);
    if (*p > 0) {
        *p = *p - 1;
        if (*p == 0) {
            func_021A232C((u8 *)a, 4, 0x7B18, 0x5A, b);
            func_021A2108(a, 0x3E, func_02014A10(4));
        }
    } else if (func_021A23B0(a) != 0 && t != 0) {
        func_021A2160((unsigned char *)a, 1, 0);
        return 1;
    }
    func_021EEEE0(a, p);
    return 0;
}
