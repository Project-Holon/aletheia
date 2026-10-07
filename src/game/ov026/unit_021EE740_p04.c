/*
 * file:     unit_021EE740_p04.c
 * unit:     yes
 * function: func_021EEB44, func_021EEC5C, func_021EECD8, func_021EED10, func_021EED44, func_021EEDB0, func_021EEDD8, func_021EEE38, func_021EEF0C, func_021EEF58, func_021EEFA8
 * address:  0x021EEB44
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
 *   func_02014A10  0x02014A10  thumb
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A2108  0x021A2108  thumb  ov021
 *   func_021A2154  0x021A2154  thumb  ov021
 *   func_021A2130  0x021A2130  thumb  ov021
 *   func_021A25DC  0x021A25DC  thumb  ov021
 *   func_021A213C  0x021A213C  thumb  ov021
 *   func_021A232C  0x021A232C  thumb  ov021
 *   func_021A25BC  0x021A25BC  thumb  ov021
 *   func_021A2160  0x021A2160  thumb  ov021
 *   func_021A223C  0x021A223C  thumb  ov021
 *   func_021A23B0  0x021A23B0  thumb  ov021
 *   func_021A21F8 0x021A21F8 thumb ov021
 *   func_021A22E0 0x021A22E0 thumb ov021
 *   func_021A2254 0x021A2254 thumb ov021
 *   func_021A2114 0x021A2114 thumb ov021
 *   func_021A2248 0x021A2248 thumb ov021
 *   func_021EF9D8 0x021EF9D8 thumb ov026
 *   func_021A2228 0x021A2228 thumb ov021
 *   func_021A25CC 0x021A25CC thumb ov021
 *   func_021A2390 0x021A2390 thumb ov021
 *   func_021A21BC 0x021A21BC thumb ov021
 *   func_021A231C 0x021A231C thumb ov021
 *   func_021A2120 0x021A2120 thumb ov021
 *   func_021EF9CC 0x021EF9CC thumb ov026
 *   func_021A2630 0x021A2630 thumb ov021
 *   func_021A2638 0x021A2638 thumb ov021
 *   func_021A2640 0x021A2640 thumb ov021
 *   func_021A26C4 0x021A26C4 thumb ov021
 *   func_021A21E0 0x021A21E0 thumb ov021
 *   func_020056EC  0x020056EC  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_0204B908  0x0204B908  arm
 *   func_021A21C8  0x021A21C8  thumb  ov021
 *   d_021EFD08     0x021EFD08  data  ov026  a4
 *   func_021A244C 0x021A244C thumb ov021
 *   func_021A2564 0x021A2564 thumb ov021
 *   func_021A2190 0x021A2190 thumb ov021
 *   func_021A21A0 0x021A21A0 thumb ov021
 *   func_021EF220 0x021EF220 thumb ov026
 *   func_021EF93C 0x021EF93C thumb ov026
 *   func_021A2424 0x021A2424 thumb ov021
 *   func_021EF614  0x021EF614  thumb  ov026
 *   func_021EF664  0x021EF664  thumb  ov026
 *   func_021EF830  0x021EF830  thumb  ov026
 */
struct PtS;
typedef signed short s16;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    s16 x;
    s16 y;
} Pt;

typedef signed int     s32;

extern int *func_021A21B8(int *p);
extern int func_021A2108(unsigned int a, int b, int c);
extern void func_021A2154(u8 *p, unsigned int b, unsigned int c);
extern void func_021A2130(u8 *p, unsigned int b, unsigned int c, unsigned int d);
extern void func_021A25DC(u8 *p, int a);
extern int func_021A213C(u8 *p);
extern void func_021A232C(u8 *p, int a, int b, int c, int d);
extern void func_021A25BC(unsigned char *o, int arg);
extern void func_021A2160(unsigned char *o, unsigned int v, int i);
extern int func_021A223C(unsigned char *o, int arg);
extern int func_021A23B0(unsigned int a);
extern u16 func_02014A10(u32 i);
extern void func_021A21F8(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
extern void func_021A22E0(u32 *p, int a, int b, int c);
extern void func_021A2254(u8 *p, void (*fn)(u8 *, int, u32), int n, int m, int k, u16 w);
extern int func_021A2114(u32 a, int b, u32 c);
extern int func_021A2248(u8 *, int);
extern void func_021EF9D8(void *, int);
extern void func_021A2228(u8 *, int, int, int, int);
extern void func_021A25CC(u8 *);
extern void func_021A2390(u32 *p, int a, int b, int c);
extern int func_021A21BC(unsigned char *o);
extern void func_021A231C(u32 *, int);
extern void func_021A2120(u32 *, int);
extern void func_021EF9CC(int);
extern unsigned char *func_021A2630(unsigned char *o);
extern unsigned int func_021A2638(unsigned char *o);
extern void func_021A2640(unsigned char *, struct PtS *);
extern int func_021A26C4(u32 a, u32 b);
extern void func_021A21E0(u32 *p);
extern u32 func_020056EC(u32 v);
extern void func_0204B908(int a0, int a1);
extern void *func_021A21C8(void *p, int a1);
extern void func_021A244C(u8 *o, s32 *outX, s32 *outY);
extern void func_021A2564(int, int, int);
extern void func_021A2190(unsigned char *o, unsigned int v, int i);
extern void func_021A21A0(unsigned char *o, unsigned int v, int i);
extern void func_021A2424(u8 *p);
extern void func_021EF93C(s16 *p);
extern void func_021EF220(int a, int n, int idx);
extern void func_021EF614(int, u16 *, int, int);
extern void func_021EF664(int, s16 *, int, int);
extern void func_021EF830(int, s16 *);
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
extern int d_021EFD08[];


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
    func_021EF9D8(p + 3, (int)a);
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
    func_021EF93C((s16 *)p);
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
    func_021EF664(a, p, b, 0);
    func_021EF830(a, p);
    return 0;
}
