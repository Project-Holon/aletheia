/*
 * file:     unit_021EE740.c
 * unit:     yes
 * function: func_021EE740, func_021EE790, func_021EE814, func_021EE888, func_021EE8B8, func_021EE8E4, func_021EE95C, func_021EE97C, func_021EEA18, func_021EEAEC, func_021EEB44, func_021EEC5C, func_021EECD8, func_021EED10, func_021EED44, func_021EEDB0, func_021EEDD8, func_021EEE38, func_021EEF0C, func_021EEF58, func_021EEFA8, func_021EF078, func_021EF104, func_021EF134, func_021EF180, func_021EF1D4, func_021EF1F4, func_021EF220, func_021EF2D8, func_021EF364, func_021EF3E0, func_021EF454, func_021EF4D0, func_021EF58C, func_021EF614, func_021EF664, func_021EF830, func_021EF920, func_021EF93C, func_021EF950, func_021EF9B0, func_021EF9CC, func_021EF9D8
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
 *   func_021A223C 0x021A223C thumb ov021
 *   func_021A232C 0x021A232C thumb ov021
 *   func_021A2108 0x021A2108 thumb ov021
 *   func_021A25BC 0x021A25BC thumb ov021
 *   func_021A23B0 0x021A23B0 thumb ov021
 *   func_021A244C 0x021A244C thumb ov021
 *   func_021A2564 0x021A2564 thumb ov021
 *   func_02014A10 0x02014A10 thumb
 *   func_021A2254 0x021A2254 thumb ov021
 *   func_021A2114 0x021A2114 thumb ov021
 *   func_021A2248 0x021A2248 thumb ov021
 *   func_021A2228 0x021A2228 thumb ov021
 *   func_021A25CC 0x021A25CC thumb ov021
 *   func_021A2390 0x021A2390 thumb ov021
 *   func_021A21BC 0x021A21BC thumb ov021
 *   func_021A231C 0x021A231C thumb ov021
 *   func_021A2120 0x021A2120 thumb ov021
 *   func_021A2630 0x021A2630 thumb ov021
 *   func_021A2638 0x021A2638 thumb ov021
 *   func_021A2640 0x021A2640 thumb ov021
 *   func_021A26C4 0x021A26C4 thumb ov021
 *   func_021A21E0 0x021A21E0 thumb ov021
 *   func_0204B908 0x0204B908 arm
 *   func_020056EC  0x020056EC  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_021A21C8  0x021A21C8  thumb  ov021
 *   func_021A2154  0x021A2154  thumb  ov021
 *   func_021A2130  0x021A2130  thumb  ov021
 *   func_021A25DC  0x021A25DC  thumb  ov021
 *   func_021A213C  0x021A213C  thumb  ov021
 *   func_021A2160  0x021A2160  thumb  ov021
 *   d_021EFD08     0x021EFD08  data  ov026  a4
 *   func_021A2190 0x021A2190 thumb ov021
 *   func_021A21A0 0x021A21A0 thumb ov021
 *   d_021EFDCC 0x021EFDCC data ov026 a4
 *   d_021EFDC0     0x021EFDC0  data  a4
 *   func_0204B878  0x0204B878  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B954  0x0204B954  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   func_021A2170  0x021A2170  thumb  ov021
 *   func_021A2180  0x021A2180  thumb  ov021
 *   d_021EFD74     0x021EFD74  data  ov026  a4
 *   d_021EFD78     0x021EFD78  data  ov026  a4
 *   d_021EFD3C     0x021EFD3C  data  ov026  a4
 *   func_02006148  0x02006148  thumb
 *   func_02006224  0x02006224  thumb
 *   func_021A2604  0x021A2604  thumb  ov021
 *   func_02082BCC 0x02082BCC arm
 *   func_021EFBA4  0x021EFBA4  thumb  ov026
 *   func_021EFBFC  0x021EFBFC  thumb  ov026
 *   func_021EFC3C  0x021EFC3C  thumb  ov026
 *   func_021EFCD4  0x021EFCD4  thumb  ov026
 *   d_021EFCF9     0x021EFCF9  data  a1
 */
#include "../../matched/include/Obj20382.h"
#include "../../matched/include/Obj09778.h"
#include "../../matched/include/Obj00086.h"
#include "../../matched/include/Obj13039.h"

struct PtS;
struct Actor;
struct Obj_021EE740;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed int     s32;

typedef unsigned short u16;

typedef struct { char pad[0x774]; int *list; } Obj_021EE740;

typedef signed short s16;

typedef struct {
    s16 x;
    s16 y;
} Pt;

typedef short s16_021EF104;

typedef signed short   s16_021EF180;

typedef signed short   s16_021EF220;

typedef signed short   s16_021EF2D8;

typedef signed short   s16_021EF364;

typedef signed short   s16_021EF3E0;

typedef signed short   s16_021EF454;

typedef short s16_021EF4D0;

struct PtS { s16_021EF4D0 x; s16_021EF4D0 y; };

struct B { char pad[0x16]; s16_021EF4D0 vx; s16_021EF4D0 vy; };

typedef signed short   s16_021EF58C;

typedef signed short   s16_021EF664;

typedef struct {
    int a;
    int b;
    int c;
} T3;

typedef signed short s16_021EF830;

typedef short s16_021EF920;

typedef short s16_021EF93C;

typedef signed short   s16_021EF950;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    s16 d;
    s16 e;
    u16 f;
} Ent;

typedef struct {
    u8 state;
    u8 mode;
    u16 x2;
    u16 count;
    u16 cur;
    Ent ent[4];
    int timer;
    s16 t3c;
    s16 t3e;
} Obj_021EF9CC;

extern int *func_021A21B8(int *p);
extern void func_021A21F8(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
extern void func_021A22E0(u32 *p, int a, int b, int c);
extern void func_021A2424(u8 *p);
extern int func_021A223C(unsigned char *o, int arg);
extern void func_021A232C(u8 *p, int a, int b, int c, int d);
extern int func_021A2108(unsigned int a, int b, int c);
extern void func_021A25BC(unsigned char *o, int arg);
extern int func_021A23B0(unsigned int a);
extern void func_021A244C(u8 *o, s32 *outX, s32 *outY);
extern void func_021A2564(int, int, int);
extern u16 func_02014A10(u32 i);
extern void func_021A2254(u8 *p, void (*fn)(u8 *, int, u32), int n, int m, int k, u16 w);
extern int func_021A2114(u32 a, int b, u32 c);
extern int func_021A2248(u8 *, int);
extern void func_021A2228(u8 *, int, int, int, int);
extern void func_021A25CC(u8 *);
extern void func_021A2390(u32 *p, int a, int b, int c);
extern int func_021A21BC(unsigned char *o);
extern void func_021A231C(u32 *, int);
extern void func_021A2120(u32 *, int);
extern unsigned char *func_021A2630(unsigned char *o);
extern unsigned int func_021A2638(unsigned char *o);
extern void func_021A2640(unsigned char *, struct PtS *);
extern int func_021A26C4(u32 a, u32 b);
extern void func_021A21E0(u32 *p);
extern void func_0204B908(int, int);
extern u32 func_020056EC(u32 v);
extern void *func_021A21C8(void *p, int a1);
extern void func_021A2154(u8 *p, unsigned int b, unsigned int c);
extern void func_021A2130(u8 *p, unsigned int b, unsigned int c, unsigned int d);
extern void func_021A25DC(u8 *p, int a);
extern int func_021A213C(u8 *p);
extern void func_021A2160(unsigned char *o, unsigned int v, int i);
extern void func_021A2190(unsigned char *o, unsigned int v, int i);
extern void func_021A21A0(unsigned char *o, unsigned int v, int i);
extern void func_0204B878(struct Obj_021EE740 *p, u16 value);
extern void func_0204B92C(struct Obj_021EE740 *, unsigned int);
extern void func_0204B954(struct Actor *a, u32 v);
extern void func_021A2170(unsigned char *o, unsigned int v, int i);
extern void func_021A2180(unsigned char *o, unsigned int v, int i);
extern int func_02006148(u32 a0);
extern int func_02006224(u32 a0);
extern void func_021A2604(u8 *p, int a, int b);
extern void func_02082BCC(void *, int, u32);
extern void func_021EFBA4(u16 *p);
extern void func_021EFBFC(u16 *p);
extern void func_021EFC3C(Obj_021EF9CC *p);
extern u16 func_021EFCD4(Obj_021EF9CC *p);
int func_021EE740(int a, int b);
int func_021EE790(int a, int b, int c);
int func_021EE814(int a, int b, u16 c);
int func_021EE888(u8 *a, int b, int c);
int func_021EE8B8(u8 *a);
int func_021EE8E4(int a, int b, int c);
int func_021EE95C(u8 *a, int b);
void func_021EE97C(int a);
void func_021EEA18(int a, int n, int idx);
int func_021EEAEC(int a, int b);
int func_021EEB44(u8 *a, int b, int c);
int func_021EEC5C(int a, int b, u16 c);
int func_021EECD8(u8 *a, int b, int c);
int func_021EED10(u8 *a);
int func_021EED44(int a, int b, int c);
int func_021EEDB0(u8 *a, int b);
void func_021EEDD8(int a);
void func_021EEE38(int a, int n, int idx);
void func_021EEF0C(int a, int *b);
int func_021EEF58(int a, int b);
int func_021EEFA8(int a, int b, int c);
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
void func_021EF4D0(void *a, const struct B *b, s16_021EF4D0 *c);
void func_021EF58C(int a, s16_021EF58C *b, s16_021EF58C *c, int d);
void func_021EF614(int a, u16 *p, int c, int d);
void func_021EF664(int a, s16_021EF664 *p, int b, int d);
void func_021EF830(int a, s16_021EF830 *p);
void func_021EF920(u8 *a, s16_021EF920 *p, int b, int c);
void func_021EF93C(s16_021EF93C *p);
void func_021EF950(int a, s16_021EF950 *p, int c);
void func_021EF9B0(u8 *p, int b);
void func_021EF9CC(int a0);
void func_021EF9D8(Obj_021EF9CC *p, int b);
extern int d_021EFD08[];
extern T3 d_021EFD74[];
extern T3 d_021EFD78[];
extern int d_021EFD3C[];
extern u8 d_021EFCF9[];










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










int func_021EE814(int a, int b, u16 c)
{
    func_021A21B8((int *)a);
    func_021A21F8((u8 *)a, 2, 0, 2, 0, -4, 2, 1, (int)func_021EEA18);
    func_021A22E0((u32 *)a, 8, 0x7F5F, b);
    func_021A2254((u8 *)a, (void (*)(u8 *, int,  u32))func_021EEA18, 0x14, 0xA, 1, c);
    func_021A25BC((unsigned char *)a, 0x691);
    func_021A2114(a, 0x3E, func_02014A10(2));
    return 1;
}










int func_021EE888(u8 *a, int b, int c)
{
    int x;
    int y;
    func_021A21B8((int *)a);
    func_021A2248(a, c);
    func_021A244C(a, &x, &y);
    func_021A2564((int)((Obj_021EE740 *)a), x, y);
    return 0;
}










int func_021EE8B8(u8 *a)
{
    int *p;
    p = func_021A21B8((int *)a);
    func_021A2228(a, 0, 8, 4, -1);
    *p = 1;
    func_021A25CC(a);
    return 1;
}









int func_021EE8E4(int a, int b, int c)
{
    int *p;
    int t;
    int ok;
    int x;
    int y;

    p = func_021A21B8((int *)a);
    t = func_021A223C((unsigned char *)a, c);
    if (*p > 0) {
        *p = *p - 1;
        if (*p == 0) {
            func_021A2390((u32 *)a, 0x7FDF, 0x32, b);
        }
    } else {
        if (b != 0) {
            ok = func_021A23B0(a);
        } else {
            ok = 1;
        }
        if (ok != 0 && t != 0 && func_021A21BC((unsigned char *)a) == 0) {
            return 1;
        }
    }
    func_021A244C((u8 *)a, &x, &y);
    func_021A2564(a, x, y);
    return 0;
}









int func_021EE95C(u8 *a, int b)
{
    func_021A21B8((int *)a);
    func_021A231C((u32 *)a, b);
    func_021A2120((u32 *)a, b);
    return 1;
}









void func_021EE97C(int a)
{
    int *p;
    int h;
    Pt pt;

    p = (int *)func_021A2630((unsigned char *)a);
    h = func_021A2638((unsigned char *)a);
    func_021A2640((unsigned char *)a, (struct PtS *)&pt);
    switch (p[3]) {
    case 0:
        pt.x = pt.x + (s16)p[4];
        pt.y = pt.y + (s16)p[2];
        p[0] = p[0] + 2;
        if (p[0] > p[1]) {
            if (p[5] < 7) {
                p[3] = 2;
            } else {
                p[3] = 1;
                p[0] = 4;
                func_0204B908(h, 3);
            }
        }
        func_021A26C4(a, (u32)(&pt));
        break;
    case 1:
        h = p[0];
        p[0] = h - 1;
        if (h <= 0) {
            p[3] = 2;
        }
        break;
    case 2:
        func_021A21E0((u32 *)a);
        break;
    }
}









void func_021EEA18(int a, int n, int idx)
{
    int i;
    int obj;
    int *e;
    int h;
    u32 r;
    u32 m;
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
        m = r % 3;
        func_0204B908(h, (u16)m);
        k = r % 20;
        e[2] = k + (m + 1) * 16;
        if (m == 2) {
            e[2] += 16;
        }
        e[4] = k / 8 + (m + 1) * 8;
        if (m == 2) {
            e[4] += 8;
        }
        e[3] = 0;
        e[1] = (r & 1) + 1;
        pt.x = (u8)r + (m * 15 - 0x48);
        pt.y = -0x60;
        func_021A26C4(obj, (u32)(&pt));
        e[4] = e[4] * 2;
        e[2] = e[2] * 2;
        e[5] = func_020056EC(10);
    }
}









int func_021EEAEC(int a, int b)
{
    s16 *p;

    p = (s16 *)func_021A21B8((int *)a);
    func_021EF9B0((u8 *)(p + 6), 2);
    func_021A21F8((u8 *)a, 1, 0xF, 2, 0, -3, 1, 1, (int)func_021EEE38);
    func_021A22E0((u32 *)a, 9, 0x7FDF, b);
    p[1] = 0;
    p[0] = 0;
    func_021A2424((u8 *)a);
    return 1;
}








int func_021EEB44(u8 *a, int b, int c)
{
    s16 *p;
    int t;
    int u;

    p = (s16 *)func_021A21B8((int *)a);
    switch (p[0]) {
    case 0:
        func_021A2108((unsigned int)a, 0x3E, func_02014A10(6));
        p[0] = p[0] + 1;
        p[1] = 0x5A;
        break;
    case 1:
        p[1] = p[1] - 1;
        if (p[1] < 0) {
            p[0] = p[0] + 1;
        }
        break;
    case 2:
        func_021A2154(a, 0x28C6, 8);
        p[1] = 0x10;
        p[0] = p[0] + 1;
        break;
    case 3:
        p[1] = p[1] - 1;
        if (p[1] < 0) {
            func_021A2130(a, 0x23DE, 4, 0x3C);
            func_021A25DC((u8 *)a, 0x692);
            p[0] = p[0] + 1;
        }
        break;
    case 4:
        if (func_021A213C((u8 *)a) == 0) {
            func_021A232C((u8 *)a, 9, 0x7F80, 0x50, b);
            p[0] = p[0] + 1;
            p[1] = 0x30;
        }
        break;
    case 5:
        p[1] = p[1] - 1;
        if (p[1] == 0) {
            func_021A25BC((unsigned char *)a, 0x690);
            func_021A2160((unsigned char *)a, 1, 0);
        }
        t = func_021A223C((unsigned char *)a, c);
        u = func_021A23B0((int)a);
        if (t != 0 && u != 0) {
            return 1;
        }
        break;
    }
    func_021EEF0C((int)a, (int *)p);
    return 0;
}








int func_021EEC5C(int a, int b, u16 c)
{
    func_021A21B8((int *)a);
    func_021A21F8((u8 *)a, 2, 0, 2, 0, -3, 1, 1, (int)func_021EEE38);
    func_021A22E0((u32 *)a, 9, 0x7F80, b);
    func_021A2254((u8 *)a, (void (*)(u8 *, int,  u32))func_021EEE38, 0x14, 5, 1, c);
    func_021A25BC((unsigned char *)a, 0x690);
    func_021A2114(a, 0x3E, func_02014A10(6));
    func_021A2160((unsigned char *)a, 1, 0);
    return 1;
}








int func_021EECD8(u8 *a, int b, int c)
{
    int *p;
    p = func_021A21B8((int *)a);
    p[2] = (p[2] + 1) % 300;
    func_021A2248(a, c);
    func_021EF9D8((Obj_021EF9CC *)(p + 3), (int)a);
    func_021EEF0C((int)a, p);
    return 0;
}








int func_021EED10(u8 *a)
{
    int *p;
    p = func_021A21B8((int *)a);
    func_021A2228(a, 0, 15, 3, -1);
    ((unsigned short *)p)[1] = 1;
    func_021A25CC(a);
    func_021A2160(a, 0, 0);
    return 1;
}








int func_021EED44(int a, int b, int c)
{
    s16 *p;
    int t;
    int ok;

    p = (s16 *)func_021A21B8((int *)a);
    t = func_021A223C((unsigned char *)a, c);
    if (p[1] > 0) {
        p[1] = p[1] - 1;
        if (p[1] == 0) {
            func_021A2390((u32 *)a, 0x7FDF, 0x32, b);
        }
    } else {
        if (b != 0) {
            ok = func_021A23B0(a);
        } else {
            ok = 1;
        }
        if (ok != 0 && t != 0 && func_021A21BC((unsigned char *)a) == 0) {
            return 1;
        }
    }
    func_021EEF0C(a, (int *)p);
    return 0;
}








int func_021EEDB0(u8 *a, int b)
{
    int *p;
    p = func_021A21B8((int *)a);
    func_021A231C((u32 *)a, b);
    func_021A2120((u32 *)a, b);
    func_021EF9CC((int)(p + 3));
    return 1;
}








void func_021EEDD8(int a)
{
    int *p;
    Pt pt;

    p = (int *)func_021A2630((unsigned char *)a);
    func_021A2638((unsigned char *)a);
    func_021A2640((unsigned char *)a, (struct PtS *)&pt);
    switch (p[3]) {
    case 0:
        pt.x = pt.x + (s16)p[4];
        pt.y = pt.y + (s16)p[2];
        if (pt.y >= 0xC0) {
            p[3] = 1;
        }
        func_021A26C4(a, (u32)(&pt));
        break;
    case 1:
        func_021A21E0((u32 *)a);
        break;
    }
}








void func_021EEE38(int a, int n, int idx)
{
    int i;
    int *w;
    int obj;
    int *e;
    int h;
    u32 r;
    u32 m;
    Pt pt;

    w = func_021A21B8((int *)a);
    for (i = 0; i < n; i++) {
        obj = (int)func_021A21C8((void *)a, idx);
        if (obj == 0) {
            return;
        }
        e = (int *)func_021A2630((unsigned char *)obj);
        h = func_021A2638((unsigned char *)obj);
        r = func_020056EC(0);
        m = r % 3;
        func_0204B908(h, (u16)m);
        e[2] = e[4] = (r & 15) + (m + 1) * 14;
        e[4] = d_021EFD08[w[2] / 60] * e[4] / 10;
        e[2] = d_021EFD08[w[2] / 60] * e[2] / 10;
        e[3] = 0;
        pt.x = r % 0x180 - 0x80;
        pt.y = r % 0x28 - 0x50;
        func_021A26C4(obj, (u32)(&pt));
    }
}








void func_021EEF0C(int a, int *b)
{
    int x;
    int y;

    func_021A244C((u8 *)a, &x, &y);
    func_021A2564(a, x, y);
    b[1] = (b[1] + 9) % 256;
    func_021A2190((unsigned char *)a, -(b[1] + x), 0);
    func_021A21A0((unsigned char *)a, y - b[1], 0);
}








int func_021EEF58(int a, int b)
{
    int *p;

    p = func_021A21B8((int *)a);
    func_021A21F8((u8 *)a, 1, 4, 1, 1, -4, 1, 1, (int)func_021EF220);
    func_021A22E0((u32 *)a, 9, 0x7FDF, b);
    func_021A2424((u8 *)a);
    func_021EF93C((s16_021EF93C *)((s16 *)p));
    return 1;
}








int func_021EEFA8(int a, int b, int c)
{
    s16 *p;
    int t;
    int u;

    p = (s16 *)func_021A21B8((int *)a);
    switch (p[0]) {
    case 0:
        func_021A2108(a, 0x3E, func_02014A10(7));
        p[1] = 0x5A;
        p[0] = p[0] + 1;
        break;
    case 1:
        p[1] = p[1] - 1;
        if (p[1] <= 0) {
            func_021EF614(a, (u16 *)p, b, 1);
            p[7] = 0x78;
            p[1] = 8;
            p[0] = p[0] + 1;
        }
        break;
    case 2:
        p[1] = p[1] - 1;
        if (p[1] == 0) {
            func_021A25BC((unsigned char *)a, 0x690);
            func_021A2160((unsigned char *)a, 1, 0);
            func_021A232C((u8 *)a, 9, 0x7F80, 10, b);
        }
        t = func_021A223C((unsigned char *)a, c);
        u = func_021A23B0(a);
        if (t == 1 && u == 1 && p[1] <= 0) {
            return 1;
        }
        break;
    }
    func_021EF664(a, (s16_021EF664 *)p, b, 0);
    func_021EF830(a, (s16_021EF830 *)p);
    return 0;
}







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
    func_021EF664((int)a, (s16_021EF664 *)p, b, 0);
    func_021EF830((int)a, (s16_021EF830 *)p);
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
    func_021EF664(a, (s16_021EF664 *)((s16_021EF180 *)x), b, 1);
    func_021EF830(a, (s16_021EF830 *)((s16_021EF180 *)x));
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
    func_0204B878((struct Obj_021EE740 *)d, 0);
    one = 1;
    func_0204B92C((struct Obj_021EE740 *)d, 1);
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
    func_0204B878((struct Obj_021EE740 *)d, 1);
    one = 1;
    func_0204B92C((struct Obj_021EE740 *)d, 1);
    func_0204B954((struct Actor *)d, one << 13);
}





/*
 * note: 2026-10-05 (wD8 lane04): closed. b is a const pointer (the struct is for readability; a
 *   const char * with casts gives the same bytes, a non-const one does not): the c[1] store then does
 *   not kill the CSE of c[3] + b->vy, so c[5] reuses the kept sum. Both sums are written inline
 *   (c[0] + (s16)(c[2] + vx)) and repeated for c[4]/c[5].
 *   EXACT* = 186 bytes compiled vs a 188-byte listing extent (2 bytes of padding).
 */
void func_021EF4D0(void *a, const struct B *b, s16_021EF4D0 *c)
{
    struct PtS pt;
    s16_021EF4D0 vx;
    func_021A2640(a, &pt);
    vx = b->vx;
    if (vx != 0) {
        c[0] = c[0] + (s16_021EF4D0)(c[2] + vx);
        c[1] = c[1] + (s16_021EF4D0)(c[3] + b->vy);
        pt.x = c[0] / 8;
        pt.y = c[1] / 8;
        c[4] = c[2] + vx;
        c[5] = c[3] + b->vy;
    } else {
        c[0] = c[0] + c[4];
        c[1] = c[1] + c[5];
        pt.x = c[0] / 8;
        pt.y = c[1] / 8;
    }
    if (pt.x >= 0x100 || pt.y >= 0xc0) {
        func_021A21E0(a);
    } else {
        func_021A26C4((u32)a, (u32)(&pt));
    }
}






void func_021EF58C(int a, s16_021EF58C *b, s16_021EF58C *c, int d)
{
    u32 r;
    s16_021EF58C v[2];
    int one;

    r = func_020056EC(0);
    c[2] = r % 24 + 0x50;
    c[3] = r % 24 + 0xE;
    c[4] = c[2] + b[11];
    c[5] = c[3] + b[12];
    v[0] = (r & 7) - 8;
    v[1] = r % 160 - 16;
    func_021A26C4(a, (u32)v);
    c[0] = v[0] << 3;
    c[1] = v[1] << 3;
    func_0204B878((struct Obj_021EE740 *)d, 2);
    one = 1;
    func_0204B92C((struct Obj_021EE740 *)d, 1);
    func_0204B954((struct Actor *)d, one << 13);
}






void func_021EF614(int a, u16 *p, int c, int d)
{
    u32 r = func_020056EC(0);
    p[8] = 1;
    p[7] = r % 400 + 0x3C;
    p[6] = 0;
    if (d == 0) {
        func_021A232C((u8 *)a, 9, 0x7F80, 10, c);
        func_021A2160((unsigned char *)a, 0, 1);
        func_021A25BC((unsigned char *)a, 0x690);
    }
}






void func_021EF664(int a, s16_021EF664 *p, int b, int d)
{
    u32 r;
    int i;

    switch (p[8]) {
    case 0:
        break;
    case 1:
        p[6] = p[6] + 1;
        func_021EF920((u8 *)a, (s16_021EF920 *)p, b, 0x71F);
        if (p[6] >= p[7]) {
            p[8] = 3;
            p[7] = 0x10;
            p[6] = 0;
            if (d == 0) {
                func_021A232C((u8 *)a, 9, 0x7F70, 10, b);
                func_021A25BC((unsigned char *)a, 0x720);
            }
        }
        break;
    case 2:
        p[6] = p[6] + 1;
        func_021EF920((u8 *)a, (s16_021EF920 *)p, b, 0x71F);
        func_021EF950(a, (s16_021EF950 *)p, b);
        if (p[6] >= p[7]) {
            p[8] = 4;
            p[7] = 0x10;
            p[6] = 0;
            if (d == 0) {
                func_021A2160((unsigned char *)a, 0, 1);
                func_021A2170((unsigned char *)a, 0x1000, 0);
                func_021A2180((unsigned char *)a, 0x1000, 0);
            }
        }
        break;
    case 3:
        p[6] = p[6] + 1;
        if (p[6] >= p[7]) {
            r = func_020056EC(0);
            p[8] = 2;
            p[7] = r % 400 + 0x3C;
            p[6] = 0;
            if (d == 0) {
                func_021A2160((unsigned char *)a, 1, 1);
                func_021A2170((unsigned char *)a, 0x800, 0);
                func_021A2180((unsigned char *)a, 0x1800, 0);
            }
        }
        break;
    case 4:
        p[6] = p[6] + 1;
        if (p[6] >= p[7]) {
            func_021EF614(a, (u16 *)p, b, d);
        }
        break;
    }
    switch (p[8]) {
    case 0:
        break;
    case 1:
        if (p[7] - p[6] >= 9) {
            p[11] = 0;
            p[12] = 0;
        } else {
            p[11] = 0xA0;
            p[12] = 0x10;
        }
        break;
    case 2:
        i = p[6] % 0x48 * 6 / 0x48;
        p[11] = d_021EFD74[i].a;
        p[12] = d_021EFD78[i].a;
        ((struct Obj00086 *)p)->f1C = d_021EFD3C[(p[6] % 0xE0u) * 14 / 0xE0u];
        break;
    case 3:
    case 4:
        p[11] = 0xA0;
        p[12] = 0x10;
        ((struct Obj00086 *)p)->f1C = 0x800;
        break;
    }
}






void func_021EF830(int a, s16_021EF830 *p)
{
    int x;
    int y;

    func_021A244C((u8 *)a, &x, &y);
    func_021A2564(a, x, y);
    if (p[11] != 0) {
        p[2] = (p[2] + 9) % 256;
        p[3] = (p[3] + 3) % 256;
        p[4] = (p[4] + 9) % 256;
        p[5] = (p[5] + 2) % 256;
    } else {
        p[2] = (p[2] + 3) % 256;
        p[3] = (p[3] + 8) % 256;
    }
    func_021A2190((unsigned char *)a, -(p[2] + x), 0);
    func_021A21A0((unsigned char *)a, y - p[3], 0);
    func_021A2190((unsigned char *)a, -(p[4] + x), 1);
    func_021A21A0((unsigned char *)a, y - p[5], 1);
    func_021A2170((unsigned char *)a, ((struct Obj00086 *)p)->f1C, 1);
    func_021A2180((unsigned char *)a, ((struct Obj00086 *)p)->f1C, 1);
}




void func_021EF920(u8 *a, s16_021EF920 *p, int b, int c)
{
    if (b != 0 && p[6] == p[7] - 24)
        func_021A25DC(a, c);
}




void func_021EF93C(s16_021EF93C *p)
{
    p[9] = 0;
    p[10] = func_020056EC(16) + 50;
}





void func_021EF950(int a, s16_021EF950 *p, int c)
{
    if (c == 0) {
        return;
    }
    if (p[6] > p[7] - 0x4A) {
        return;
    }
    p[9]++;
    if (p[9] < p[10]) {
        return;
    }
    if (func_02006224(func_02006148(0x71F)) == 0) {
        int t = func_020056EC(0x1B) + 0x64;
        func_021A2604((u8 *)a, 0x71E, t);
        func_021EF93C(p);
        return;
    }
    p[9] = p[10] - 10;
}


void func_021EF9B0(u8 *p, int b)
{
    func_02082BCC(p, 0, 64);
    ((struct Obj13039 *)p)->f38 = func_020056EC(3);
    p[1] = b;
}



void func_021EF9CC(int a0)
{
    func_02082BCC((void *)a0, 0, 0x40);
}



/*
 * State 6 re-reads `cur` into a local after the entry's decrement
 * (`p->ent[p->cur].d--; i = p->cur; if (p->ent[i].d <= 0) { if (p->count >
 * i + 1)`): spelled with `p->cur` throughout, every form tried (either
 * compare order, `p->cur++`, a temporary for cur + 1) colours count and
 * cur + 1 into r0/r1 swapped, 7 bytes out; the permuter was flat on it.
 * State 4 indexes the entry directly (`p->ent[i].e`); an `Ent *e` cursor
 * gives 100+ bytes out.
 */
void func_021EF9D8(Obj_021EF9CC *p, int b)
{
    u32 r;
    int i;

    switch (p->state) {
    case 0:
        if (--p->timer < 0) {
            p->state = 1;
        }
        break;
    case 1:
        r = func_020056EC(100);
        for (i = 0; i < 3; i++) {
            if (d_021EFCF9[i] >= r) {
                break;
            }
        }
        if (p->mode == 0) {
            func_021EFBA4((u16 *)p);
        } else {
            switch (i) {
            case 0:
                if (p->mode == 1) {
                    func_021EFBA4((u16 *)p);
                } else {
                    func_021EFBFC((u16 *)p);
                }
                break;
            case 1:
                func_021EFBFC((u16 *)p);
                break;
            case 2:
                func_021EFC3C((Obj_021EF9CC *)p);
                break;
            }
        }
        p->cur = 0;
        p->state = 2;
        break;
    case 2:
        if (p->mode != 2) {
            p->state = 4;
            break;
        }
        func_021A2154((u8 *)b, 0x3129, 4);
        p->timer = 10;
        p->state = 3;
        break;
    case 3:
        if (--p->timer <= 0) {
            p->state = 4;
        }
        break;
    case 4:
        if (p->mode != 0) {
            func_021A2130((u8 *)b, func_021EFCD4((Obj_021EF9CC *)p), p->ent[p->cur].a, p->ent[p->cur].b);
        }
        if (p->x2 == 2) {
            p->timer = p->ent[p->cur].a / 2 + func_020056EC(p->ent[p->cur].b);
        }
        i = p->cur;
        p->t3c = p->ent[i].e;
        p->t3e = p->ent[i].f;
        if (p->mode == 2) {
            if (i + 1 == p->count) {
                p->ent[i].d = p->ent[i].d / 3;
            }
        } else if (p->mode == 0) {
            p->ent[i].d = p->ent[i].d * 2;
        }
        p->state = 5;
        break;
    case 5:
        if (p->t3c > 0) {
            p->t3c--;
            if (p->t3c == 0) {
                func_021A25DC((u8 *)b, p->t3e);
            }
        }
        if (func_021A213C((u8 *)b) == 0) {
            p->state = 6;
        }
        break;
    case 6:
        if (p->t3c > 0) {
            p->t3c--;
            if (p->t3c == 0) {
                func_021A25DC((u8 *)b, p->t3e);
            }
        }
        p->ent[p->cur].d--;
        i = p->cur;
        if (p->ent[i].d <= 0) {
            if (p->count > i + 1) {
                p->cur = i + 1;
                p->state = 4;
            } else {
                p->state = 1;
            }
        }
        break;
    }
}
