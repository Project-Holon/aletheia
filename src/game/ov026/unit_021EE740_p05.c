/*
 * file:     unit_021EE740_p05.c
 * unit:     yes
 * function: func_021EF078, func_021EF104, func_021EF134, func_021EF180, func_021EF1D4, func_021EF1F4, func_021EF220, func_021EF2D8, func_021EF364, func_021EF3E0, func_021EF454
 * address:  0x021EF078
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
 *   func_021EF614 0x021EF614 thumb ov026
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A21F8 0x021A21F8 thumb ov021
 *   func_021A22E0 0x021A22E0 thumb ov021
 *   func_021A2254 0x021A2254 thumb ov021
 *   func_021A25BC 0x021A25BC thumb ov021
 *   func_021A2160 0x021A2160 thumb ov021
 *   func_021A2114 0x021A2114 thumb ov021
 *   func_02014A10 0x02014A10 thumb
 *   func_021A2248 0x021A2248 thumb ov021
 *   func_021EF664 0x021EF664 thumb ov026
 *   func_021EF830 0x021EF830 thumb ov026
 *   func_021A2228 0x021A2228 thumb ov021
 *   func_021A25CC 0x021A25CC thumb ov021
 *   func_021A2390 0x021A2390 thumb ov021
 *   func_021A223C  0x021A223C  thumb  ov021
 *   func_021A23B0  0x021A23B0  thumb  ov021
 *   func_021A21BC  0x021A21BC  thumb  ov021
 *   func_021A231C 0x021A231C thumb ov021
 *   func_021A2120 0x021A2120 thumb ov021
 *   func_021A2630 0x021A2630 thumb ov021
 *   func_021A2638 0x021A2638 thumb ov021
 *   d_021EFDCC 0x021EFDCC data ov026 a4
 *   func_020056EC  0x020056EC  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_021A21C8  0x021A21C8  thumb  ov021
 *   d_021EFDC0     0x021EFDC0  data  a4
 *   func_021A2640  0x021A2640  thumb  ov021
 *   func_021A26C4  0x021A26C4  thumb  ov021
 *   func_021A21E0  0x021A21E0  thumb  ov021
 *   func_0204B878  0x0204B878  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B954  0x0204B954  arm
 */
#include "../../matched/include/Obj20382.h"
#include "../../matched/include/Obj09778.h"

struct PtS;
struct Actor;
struct Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short s16_021EF104;

typedef signed short   s16_021EF180;

typedef signed short   s16_021EF220;

typedef signed int     s32;

typedef signed short   s16_021EF2D8;

typedef signed short   s16_021EF364;

typedef signed short   s16_021EF3E0;

typedef signed short   s16_021EF454;

extern int *func_021A21B8(int *p);
extern void func_021A21F8(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
extern void func_021A22E0(u32 *p, int a, int b, int c);
extern void func_021A2254(u8 *p, void (*fn)(u8 *, int, u32), int n, int m, int k, u16 w);
extern void func_021A25BC(unsigned char *o, int arg);
extern void func_021A2160(unsigned char *o, unsigned int v, int i);
extern int func_021A2114(u32 a, int b, u32 c);
extern u16 func_02014A10(u32 i);
extern void func_021EF614(int a, u16 *p, int c, int d);
extern int func_021A2248(u8 *, int);
extern void func_021EF664(int, s16_021EF104 *, int, int);
extern void func_021EF830(int, s16_021EF104 *);
extern void func_021A2228(u8 *p, int a, int b, int c, int d);
extern void func_021A25CC(u8 *p);
extern void func_021A2390(u32 *p, int a, int b, int c);
extern int func_021A223C(unsigned char *o, int arg);
extern int func_021A23B0(u32 a);
extern int func_021A21BC(unsigned char *o);
extern void func_021A231C(u32 *, int);
extern void func_021A2120(u32 *, int);
extern u8 *func_021A2630(u8 *);
extern u32 func_021A2638(u8 *);
extern u32 func_020056EC(u32 v);
extern void *func_021A21C8(void *p, int a1);
extern void func_021A2640(unsigned char *, struct PtS *);
extern int func_021A26C4(unsigned int a, unsigned int b);
extern void func_021A21E0(u32 *p);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *, unsigned int);
extern void func_0204B954(struct Actor *a, u32 v);
int func_021EF078(int a, int b, u16 c);
int func_021EF104(u8 *a, int b, int c);
int func_021EF134(int a, int b);
int func_021EF180(int a, int b, int c);
int func_021EF1D4(u32 *a, int b);
void func_021EF1F4(u8 *a);
void func_021EF220(int a, int n, int idx);
void func_021EF2D8(int a, s16_021EF2D8 *b, s16_021EF2D8 *c);
void func_021EF364(int a, s16_021EF364 *b, s16_021EF364 *c, int d);
void func_021EF3E0(int a, s16_021EF3E0 *b, s16_021EF3E0 *c);
void func_021EF454(int a, s16_021EF454 *b, s16_021EF454 *c, int d);


int func_021EF078(int a, int b, u16 c)
{
    int *p;

    p = func_021A21B8((int *)a);
    func_021A21F8((u8 *)a, 1, 1, 1, 1, -4, 1, 1, (int)func_021EF220);
    func_021A22E0((u32 *)a, 9, 0x7F80, b);
    func_021A2254((u8 *)a, (void (*)(u8 *, int,  u32))func_021EF220, 0x14, 5, 1, c);
    func_021A25BC((unsigned char *)a, 0x690);
    func_021EF614(a, (u16 *)p, b, 0);
    func_021A2160((unsigned char *)a, 1, 0);
    func_021A2114(a, 0x3E, func_02014A10(7));
    return 1;
}

int func_021EF104(u8 *a, int b, int c)
{
    s16_021EF104 *p;
    p = (s16_021EF104 *)func_021A21B8((int *)a);
    func_021A2248(a, c);
    func_021EF664((int)a, p, b, 0);
    func_021EF830((int)a, p);
    return 0;
}


int func_021EF134(int a, int b)
{
    func_021A21B8((int *)a);
    func_021A2228((u8 *)a, 0, 4, 4, -1);
    func_021A25CC((u8 *)a);
    func_021A2390((u32 *)a, 0x7FDF, 0x32, b);
    func_021A2160((unsigned char *)a, 0, 0);
    func_021A2160((unsigned char *)a, 0, 1);
    return 1;
}


int func_021EF180(int a, int b, int c)
{
    int x;
    int y;
    int t;

    x = (int)func_021A21B8((int *)a);
    y = func_021A223C((unsigned char *)a, c);
    t = (b != 0) ? func_021A23B0(a) : 1;
    if (t != 0 && y != 0 && func_021A21BC((unsigned char *)a) == 0) {
        return 1;
    }
    func_021EF664(a, (s16_021EF180 *)x, b, 1);
    func_021EF830(a, (s16_021EF180 *)x);
    return 0;
}

int func_021EF1D4(u32 *a, int b)
{
    func_021A21B8((int *)a);
    func_021A231C(a, b);
    func_021A2120(a, b);
    return 1;
}

extern void (*d_021EFDCC[])(u8 *, int, u8 *, u32);

void func_021EF1F4(u8 *a)
{
    u8 *p;
    u32 q;
    p = func_021A2630(a);
    q = func_021A2638(a);
    d_021EFDCC[*(int *)p](a, ((struct Obj20382 *)p)->f4, p + 8, q);
}

extern void (*d_021EFDC0[])(int, s32, s32 *, int);


void func_021EF220(int a, int n, int idx)
{
    u32 r;
    u32 rem;
    u8 *w;
    int i;
    int obj;
    s32 *e;
    int q;

    r = func_020056EC(0);
    w = (u8 *)func_021A21B8((int *)a);
    if (((struct Obj09778 *)w)->f10 == 0) {
        return;
    }
    if (((struct Obj09778 *)w)->f10 == 2 && (r & 1)) {
        return;
    }
    i = 0;
    if (n <= 0) {
        return;
    }
    rem = r % 100;
    do {
        obj = (int)func_021A21C8((void *)a, idx);
        if (obj == 0) {
            return;
        }
        e = (s32 *)func_021A2630((unsigned char *)obj);
        q = func_021A2638((unsigned char *)obj);
        e[1] = (s32)w;
        switch (((struct Obj09778 *)w)->f10) {
        case 0:
            break;
        case 1:
            e[0] = 1;
            break;
        case 2:
            if (rem <= 0x32) { e[0] = 2; } else { e[0] = 0; }
            break;
        case 3:
        case 4:
            if (rem <= 0x50) { e[0] = 1; } else { e[0] = 2; }
            break;
        }
        d_021EFDC0[e[0]](obj, e[1], e + 2, q);
        i++;
    } while (i < n);
}


void func_021EF2D8(int a, s16_021EF2D8 *b, s16_021EF2D8 *c)
{
    s16_021EF2D8 v[2];
    int x;
    int y;

    x = b[11];
    if (x == 0) {
        x = c[4];
        y = c[5];
    } else {
        y = b[12];
        c[4] = x;
        c[5] = y;
    }
    func_021A2640((unsigned char *)a, (struct PtS *)v);
    c[0] = c[0] + (s16_021EF2D8)(c[2] + x);
    c[1] = c[1] + (s16_021EF2D8)(c[3] + y);
    v[0] = c[0] / 8;
    v[1] = c[1] / 8;
    if (v[0] >= 256 || v[1] >= 192) {
        func_021A21E0((u32 *)a);
        return;
    }
    func_021A26C4(a, (unsigned int)v);
}


void func_021EF364(int a, s16_021EF364 *b, s16_021EF364 *c, int d)
{
    u32 r;
    s16_021EF364 v[2];
    int one;
    int t;

    r = func_020056EC(0);
    c[2] = r % 24 + 0x10;
    t = b[11];
    c[3] = r % 24 + 8;
    c[4] = t;
    c[5] = b[12];
    v[0] = (r & 7) - 8;
    v[1] = r % 160 - 16;
    func_021A26C4(a, (u32)v);
    c[0] = v[0] << 3;
    c[1] = v[1] << 3;
    func_0204B878((struct Obj *)d, 0);
    one = 1;
    func_0204B92C((struct Obj *)d, 1);
    func_0204B954((struct Actor *)d, one << 13);
}


void func_021EF3E0(int a, s16_021EF3E0 *b, s16_021EF3E0 *c)
{
    s16_021EF3E0 v[2];

    func_021A2640((unsigned char *)a, (struct PtS *)v);
    c[0] = c[0] + (s16_021EF3E0)(c[2] + b[11]);
    c[1] = c[1] + (s16_021EF3E0)(c[3] + b[12]);
    v[0] = c[0] / 8;
    v[1] = c[1] / 8;
    if (v[0] >= 256 || v[1] >= 160) {
        func_021A21E0((u32 *)a);
        return;
    }
    func_021A26C4(a, (unsigned int)v);
}


void func_021EF454(int a, s16_021EF454 *b, s16_021EF454 *c, int d)
{
    u32 r;
    s16_021EF454 v[2];
    int one;

    r = func_020056EC(0);
    c[2] = r % 43 + 0x56;
    c[3] = (r % 43) * 2 + 0x102;
    v[0] = r % 336 - 0x50;
    v[1] = r % 40 - 0x50;
    func_021A26C4(a, (u32)v);
    c[0] = v[0] << 3;
    c[1] = v[1] << 3;
    func_0204B878((struct Obj *)d, 1);
    one = 1;
    func_0204B92C((struct Obj *)d, 1);
    func_0204B954((struct Actor *)d, one << 13);
}
