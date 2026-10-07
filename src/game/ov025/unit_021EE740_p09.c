/*
 * file:     unit_021EE740_p09.c
 * unit:     yes
 * function: func_021EF2D4, func_021EF3BC, func_021EF404, func_021EF47C
 * address:  0x021EF2D4
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
 *   func_020056EC  0x020056EC  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_0204B908  0x0204B908  arm
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A21C8  0x021A21C8  thumb  ov021
 *   func_021A2630  0x021A2630  thumb  ov021
 *   func_021A2638  0x021A2638  thumb  ov021
 *   func_021A2654  0x021A2654  thumb  ov021
 *   func_021A21F8 0x021A21F8 thumb ov021
 *   func_021A22E0 0x021A22E0 thumb ov021
 *   func_021EF634 0x021EF634 thumb ov025
 *   func_021A223C 0x021A223C thumb ov021
 *   func_021A232C 0x021A232C thumb ov021
 *   func_021A2108 0x021A2108 thumb ov021
 *   func_021A23B0 0x021A23B0 thumb ov021
 *   func_021A244C 0x021A244C thumb ov021
 *   func_021A2564 0x021A2564 thumb ov021
 *   func_02014A10 0x02014A10 thumb
 *   func_021A2254 0x021A2254 thumb ov021
 *   func_021A2114 0x021A2114 thumb ov021
 */
typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef struct {
    s16 x;
    s16 y;
} Pt;

typedef unsigned char  u8;

typedef signed int     s32;

extern u32 func_020056EC(u32 v);
extern void func_0204B908(int a0, int a1);
extern int *func_021A21B8(int *p);
extern void *func_021A21C8(void *p, int a1);
extern unsigned char *func_021A2630(unsigned char *o);
extern unsigned int func_021A2638(unsigned char *o);
extern void func_021A2654(int obj, unsigned short *src);
extern void func_021A21F8(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
extern void func_021A22E0(u32 *p, int a, int b, int c);
extern void func_021EF634(int *a, int n, int idx);
extern int func_021A223C(unsigned char *o, int arg);
extern void func_021A232C(u8 *p, int a, int b, int c, int d);
extern int func_021A2108(unsigned int a, int b, int c);
extern int func_021A23B0(unsigned int a);
extern void func_021A244C(u8 *o, s32 *outX, s32 *outY);
extern void func_021A2564(int, int, int);
extern u16 func_02014A10(u32 i);
extern void func_021A2254(int, void *, int, int, int, int);
extern int func_021A2114(unsigned int a, int b, unsigned int c);
void func_021EF2D4(int a, int n, int idx);
int func_021EF3BC(int a, int b);
int func_021EF404(int a, int b, int c);
int func_021EF47C(unsigned int *a, int b, int c);


void func_021EF2D4(int a, int n, int idx)
{
    int i;
    int obj;
    int *e;
    int h;
    u32 r;
    u32 t;
    int m;
    int k;
    Pt pt;

    func_021A21B8((int *)a);
    for (i = 0; i < n; i++) {
        obj = (int)func_021A21C8((void *)a, idx);
        if (obj == 0) {
            return;
        }
        e = (int *)func_021A2630((unsigned char *)obj);
        h = func_021A2638((unsigned char *)obj);
        r = func_020056EC(0);
        e[0] = 0;
        t = r % 100;
        if (t < 30) {
            m = 0;
        } else if (t < 95) {
            m = 1;
        } else if (t < 100) {
            m = 2;
        }
        func_0204B908(h, (u16)(2 - m));
        k = r % 23;
        e[2] = k + (m + 1) * 10;
        if (m == 2) {
            e[2] += 3;
        }
        e[4] = k / 4 + (m + 1) * 4;
        if (m == 2) {
            e[4] -= 2;
        }
        e[3] = 0;
        e[1] = (r & 3) + 1;
        pt.x = r % 270 + (m * 15 - 0x40);
        pt.y = (r & 0xF) - 8;
        func_021A2654(obj, (short unsigned int *)(&pt));
        e[6] = r;
    }
}


int func_021EF3BC(int a, int b)
{
    int *p;

    p = func_021A21B8((int *)a);
    func_021A21F8((u8 *)a, 2, 0x10, 0x14, 2, -2, 4, 2, (int)((void *)func_021EF634));
    func_021A22E0((u32 *)a, 8, 0x7FFF, b);
    *p = 0;
    return 1;
}


int func_021EF404(int a, int b, int c)
{
    int *p;
    int t;
    int x;
    int y;

    p = func_021A21B8((int *)a);
    t = func_021A223C((unsigned char *)a, c);
    if (*p == 0) {
        *p = *p - 1;
        func_021A232C((u8 *)a, 8, 0x7F57, 0x5A, b);
        func_021A2108(a, 0x3E, func_02014A10(8));
    } else if (func_021A23B0(a) != 0 && t != 0) {
        return 1;
    }
    func_021A244C((u8 *)a, &x, &y);
    func_021A2564(a, x, y);
    return 0;
}


int func_021EF47C(unsigned int *a, int b, int c)
{
    func_021A21B8((int *)a);
    func_021A21F8((u8 *)a, 0x14, 2, 0x14, 2, -2, 4, 2, (int)((void *)func_021EF634));
    func_021A22E0(a, 8, 0x7F57, b);
    func_021A2254((int)a, (void *)func_021EF634, 0x14, 10, 1, c);
    func_021A2114((unsigned int)a, 0x3E, func_02014A10(8));
    return 1;
}
