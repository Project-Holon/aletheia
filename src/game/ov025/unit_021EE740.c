/*
 * file:     unit_021EE740.c
 * unit:     yes
 * function: func_021EE740, func_021EE798, func_021EE810, func_021EE888, func_021EE8B0, func_021EE8EC, func_021EE968, func_021EE980, func_021EEA34, func_021EEB0C, func_021EEB74, func_021EEBE4, func_021EEC64, func_021EECB0, func_021EECEC, func_021EED58, func_021EED78, func_021EEE04, func_021EEEE0, func_021EEF94, func_021EEFF0, func_021EF068, func_021EF0D0, func_021EF100, func_021EF12C, func_021EF1A4, func_021EF1C4, func_021EF2D4, func_021EF3BC, func_021EF404, func_021EF47C, func_021EF4E4, func_021EF514, func_021EF538, func_021EF5B0, func_021EF5D0
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
 *   func_021A2254  0x021A2254  thumb  ov021
 *   func_021A2114  0x021A2114  thumb  ov021
 *   func_021A2248 0x021A2248 thumb ov021
 *   func_021A2228 0x021A2228 thumb ov021
 *   func_021A2390  0x021A2390  thumb  ov021
 *   func_021A21BC  0x021A21BC  thumb  ov021
 *   func_021A231C 0x021A231C thumb ov021
 *   func_021A2120 0x021A2120 thumb ov021
 *   func_021A2630  0x021A2630  thumb  ov021
 *   func_021A2638  0x021A2638  thumb  ov021
 *   func_021A2640  0x021A2640  thumb  ov021
 *   func_021A2654  0x021A2654  thumb  ov021
 *   func_021A21E0  0x021A21E0  thumb  ov021
 *   _u32_div_f  0x0209C2B0  arm
 *   d_021EF790  0x021EF790  data  ov025  a1
 *   func_020056EC  0x020056EC  thumb
 *   func_0204B908  0x0204B908  arm
 *   func_021A21C8  0x021A21C8  thumb  ov021
 *   func_021A25BC  0x021A25BC  thumb  ov021
 *   func_021A2160  0x021A2160  thumb  ov021
 *   d_021EF770  0x021EF770  data  ov025  a4
 *   func_021A25CC 0x021A25CC thumb ov021
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   d_021EF780     0x021EF780  data   a4
 *   func_021A2190 0x021A2190 thumb ov021
 *   func_021A21A0 0x021A21A0 thumb ov021
 *   _s32_div_f    0x0209C0A4 arm
 *   d_021EF765    0x021EF765 data a1
 *   d_021EF75C    0x021EF75C data ov025 a1
 *   func_021A26C4  0x021A26C4  thumb  ov021
 *   func_0204B918  0x0204B918  arm
 *   func_021EF634 0x021EF634 thumb ov025
 */
struct PtS;
struct Obj;
struct Vec2;
struct Actor;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed int     s32;

typedef unsigned short u16;

typedef struct { char pad[0x774]; int *list; } Obj;

typedef signed short s16;

typedef struct {
    s16 x;
    s16 y;
} Pt;

typedef signed char s8;

int *func_021A21B8(int *p);
void func_021A21F8(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
void func_021A22E0(u32 *p, int a, int b, int c);
void func_021A2424(u8 *p);
extern int func_021A223C(unsigned char *o, int arg);
extern void func_021A232C(u8 *p, int a, int b, int c, int d);
extern int func_021A2108(unsigned int a, int b, int c);
extern int func_021A23B0(unsigned int a);
extern void func_021A244C(u8 *o, s32 *outX, s32 *outY);
extern void func_021A2564(int, int, int);
extern u16 func_02014A10(u32 i);
extern void func_021A2254(int, void *, int, int, int, int);
extern int func_021A2114(unsigned int a, int b, unsigned int c);
extern int func_021A2248(u8 *, int);
extern void func_021A2228(u8 *, int, int, int, int);
extern void func_021A2390(u32 *p, int a, int b, int c);
extern int func_021A21BC(unsigned char *o);
extern void func_021A231C(u32 *, int);
extern void func_021A2120(u32 *, int);
extern unsigned char *func_021A2630(unsigned char *o);
extern unsigned int func_021A2638(unsigned char *o);
extern void func_021A2640(unsigned char *, struct PtS *);
extern void func_021A2654(int obj, unsigned short *src);
extern void func_021A21E0(u32 *p);
extern u32 func_020056EC(u32 v);
extern void func_0204B908(int a0, int a1);
extern void *func_021A21C8(void *p, int a1);
extern void func_021A25BC(unsigned char *o, int arg);
extern void func_021A2160(unsigned char *o, unsigned int v, int i);
extern void func_021A25CC(u8 *);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_021A2190(unsigned char *o, unsigned int v, int i);
extern void func_021A21A0(unsigned char *o, unsigned int v, int i);
extern int func_021A26C4(u32 a, u32 b);
extern u16 func_0204B918(struct Obj *p);
extern void func_021EF634(int *a, int n, int idx);
int func_021EE740(int a, int b);
int func_021EE798(int a, int b, int c);
int func_021EE810(unsigned int *a, int b, int c);
int func_021EE888(u8 *p, int unused, int arg);
int func_021EE8B0(u8 *a);
int func_021EE8EC(int a, int b, int c);
int func_021EE968(u32 *p, int x);
void func_021EE980(int a);
void func_021EEA34(int a, int n, int idx);
int func_021EEB0C(int a, int b);
int func_021EEB74(int a, int b, int c);
int func_021EEBE4(unsigned int *a, int b, int c);
int func_021EEC64(int a, int b, u16 c);
int func_021EECB0(u8 *a);
int func_021EECEC(int a, int b, int c);
int func_021EED58(u32 *p, int x);
void func_021EED78(int a);
void func_021EEE04(int a, int n, u16 idx);
void func_021EEEE0(int a, int *s);
int func_021EEF94(int a, int b);
int func_021EEFF0(int a, int b, int c);
int func_021EF068(unsigned int *a, int b, int c);
int func_021EF0D0(u8 *a, int b, int c);
int func_021EF100(u8 *a);
int func_021EF12C(int a, int b, int c);
int func_021EF1A4(u8 *a, int b);
void func_021EF1C4(int a);
void func_021EF2D4(int a, int n, int idx);
int func_021EF3BC(int a, int b);
int func_021EF404(int a, int b, int c);
int func_021EF47C(unsigned int *a, int b, int c);
int func_021EF4E4(u8 *a, int b, int c);
int func_021EF514(u8 *a);
int func_021EF538(int a, int b, int c);
int func_021EF5B0(u8 *a, int b);
void func_021EF5D0(int a);
extern signed char d_021EF790[];
extern const int d_021EF770[];
extern const int d_021EF780[];
extern const s8 d_021EF765[];
extern const s8 d_021EF75C[];










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










int func_021EE810(unsigned int *a, int b, int c)
{
    int *p = func_021A21B8((int *)a);

    func_021A21F8((u8 *)a, 1, 0x10, 1, 0x10, -3, 1, 0, (int)((void *)func_021EEA34));
    p[1] = 1;
    p[2] = 0;
    func_021A22E0(a, 8, 0x7F5F, b);
    func_021A2254((int)a, (void *)func_021EEA34, 0x14, 1, 0x12, c);
    func_021A2114((unsigned int)a, 0x3E, func_02014A10(1));
    return 1;
}









int func_021EE888(u8 *p, int unused, int arg)
{
    int x;
    int y;
    func_021A2248(p, arg);
    func_021A244C(p, &x, &y);
    func_021A2564((int)((Obj *)p), x, y);
    return 0;
}







int func_021EE8B0(u8 *a)
{
    int *p;
    int x;
    int y;
    p = func_021A21B8((int *)a);
    func_021A2228(a, 0, 18, 3, -1);
    *p = 16;
    func_021A244C(a, &x, &y);
    func_021A2564((int)((Obj *)a), x, y);
    return 1;
}







int func_021EE8EC(int a, int b, int c)
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
            func_021A2390((u32 *)a, 0x7FDF, 0x5A, b);
        }
    } else {
        if (b != 0) {
            ok = func_021A23B0(a);
        } else {
            ok = 1;
        }
        if (ok != 0 && t != 0) {
            p[2] = 1;
            if (func_021A21BC((unsigned char *)a) == 0) {
                return 1;
            }
        }
    }
    func_021A244C((u8 *)a, &x, &y);
    func_021A2564(a, x, y);
    return 0;
}






/*
 * extent: trailing two-byte zero alignment padding at 0x021EE97E.
 */
int func_021EE968(u32 *p, int x)
{
    func_021A231C(p, x);
    func_021A2120(p, x);
    return 1;
}







void func_021EE980(int a)
{
    int *p;
    int s;
    int *q;
    Pt pt;

    p = (int *)func_021A2630((unsigned char *)a);
    func_021A2638((unsigned char *)a);
    s = p[8];
    q = (int *)p[7];
    if (s == 0) {
        if (*q != 0) {
            p[8] = s + 1;
        }
    } else {
        p[9] = p[9] - 1;
        if (p[9] < 0) {
            func_021A21E0((u32 *)a);
            return;
        }
    }
    func_021A2640((unsigned char *)a, (struct PtS *)&pt);
    pt.x = pt.x + d_021EF790[p[5]];
    if (p[4] > p[3]) {
        pt.y = pt.y + 1;
        p[4] = p[4] % p[3];
    }
    func_021A2654(a, (short unsigned int *)(&pt));
    p[4] = p[4] + 8;
    p[5] = (unsigned)(p[5] + 1) % 337u;
    if ((pt.y < -284 && pt.y > -296) || (pt.y > 212 && pt.y < 232)) {
        *(int *)p[0] = 1;
        func_021A21E0((u32 *)a);
    }
}







void func_021EEA34(int a, int n, int idx)
{
    int *q;
    int i;
    int obj;
    int *e;
    int h;
    Pt pt;

    q = func_021A21B8((int *)a);
    for (i = 0; i < n; i++) {
        obj = (int)func_021A21C8((void *)a, idx);
        if (obj == 0) {
            return;
        }
        e = (int *)func_021A2630((unsigned char *)obj);
        h = func_021A2638((unsigned char *)obj);
        func_0204B908(h, (u16)func_020056EC(4));
        e[4] = 0;
        e[5] = 0;
        e[8] = 0;
        e[9] = (int)func_020056EC(0) % 30 + 2;
        e[3] = func_020056EC(8) + 12;
        e[0] = (int)(q + 1);
        e[7] = (int)(q + 2);
        pt.x = func_020056EC(0x19E) - 0x20;
        if (q[1] == 1 && i >= n / 2) {
            pt.y = -8 - 0x20 - func_020056EC(0x14);
        } else {
            pt.y = -8 - func_020056EC(0x14);
        }
        func_021A2654(obj, (short unsigned int *)(&pt));
    }
}






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




int func_021EEBE4(unsigned int *a, int b, int c)
{
    int *p = func_021A21B8((int *)a);

    func_021A21F8((u8 *)a, 1, 2, 1, 2, -2, 2, 1, (int)((void *)func_021EEE04));
    func_021A22E0(a, 4, 0x7B18, b);
    p[1] = 0;
    p[2] = 0;
    p[9] = 0;
    func_021A2254((int)a, (void *)func_021EEE04, 0x14, 2, 2, c);
    func_021A2160((unsigned char *)a, 1, 0);
    func_021A2114((unsigned int)a, 0x3E, func_02014A10(4));
    return 1;
}



int func_021EEC64(int a, int b, u16 c)
{
    int *p;

    p = func_021A21B8((int *)a);
    if (func_021A2248((unsigned char *)a, c) != 0) {
        if (d_021EF770[p[1] / 256] <= -8) {
            func_021EEE04(a, 1, c);
        }
    }
    func_021EEEE0(a, p);
    return 0;
}








int func_021EECB0(u8 *a)
{
    int *p;
    p = func_021A21B8((int *)a);
    func_021A2228(a, 0, 3, 1, -1);
    *p = 10;
    func_021EEEE0((int)a, p);
    func_021A2160(a, 0, 0);
    func_021A25CC(a);
    return 1;
}









int func_021EECEC(int a, int b, int c)
{
    int *p;
    int t;
    int ok;

    p = func_021A21B8((int *)a);
    t = func_021A223C((unsigned char *)a, c);
    if (*p > 0) {
        *p = *p - 1;
        if (*p == 0) {
            func_021A2390((u32 *)a, 0x7FFF, 0x3C, b);
        }
    } else {
        if (b != 0) {
            ok = func_021A23B0(a);
        } else {
            ok = 1;
        }
        if (ok != 0 && t != 0) {
            p[2] = 1;
            if (func_021A21BC((unsigned char *)a) == 0) {
                return 1;
            }
        }
    }
    func_021EEEE0(a, p);
    return 0;
}








/*
 * extent: trailing two-byte zero alignment padding at 0x021EED76.
 */
int func_021EED58(u32 *p, int x)
{
    func_021A21B8((int *)p);
    func_021A231C(p, x);
    func_021A2120(p, x);
    return 1;
}









void func_021EED78(int a)
{
    int *p;
    int q;
    s16 v[2];

    p = (int *)func_021A2630((unsigned char *)a);
    q = func_021A2638((unsigned char *)a);
    func_0204B454((struct Actor *)q, (struct PtS *)v, 0);
    switch (p[3]) {
    case 0:
        v[0] = v[0] + (s16)p[4];
        v[1] = v[1] + (s16)p[2];
        if (p[0]++ > p[1]) {
            p[3] = 1;
        }
        if (p[0] % 4 == 0) {
            p[4] = p[4] + p[5];
            if (p[2] > 1) {
                p[2] = p[2] - 1;
            }
        }
        func_0204B404((struct Obj *)q, (const struct Vec2 *)v, 0);
        break;
    case 1:
        func_021A21E0((u32 *)a);
        break;
    }
}









/*
 * note:     idx is narrow (u16/s16/u8 all give EXACT; int puts its home store
 *           third instead of first): func_021A21C8 only forwards it, so no
 *           callee fixes the exact width. const on the two tables lets the
 *           indexed loads hoist out of the loop past the stores through e.
 */
void func_021EEE04(int a, int n, u16 idx)
{
    int *q;
    int k;
    int i;
    int obj;
    int *e;
    int h;
    int m;
    Pt pt;

    q = func_021A21B8((int *)a);
    if (++q[1] >= 0x400) {
        q[1] = 0;
    }
    k = q[1] / 256;
    for (i = 0; i < n; i++) {
        obj = (int)func_021A21C8((void *)a, idx);
        if (obj == 0) {
            return;
        }
        e = (int *)func_021A2630((unsigned char *)obj);
        h = func_021A2638((unsigned char *)obj);
        e[0] = 0;
        e[1] = func_020056EC(3) + 9;
        m = func_020056EC(4);
        func_0204B908(h, (u16)m);
        e[4] = (m + 1) * d_021EF770[k];
        e[2] = d_021EF780[k] * (m + 1);
        e[3] = 0;
        if (m == 3) {
            e[4] = e[4] + d_021EF770[k];
            e[2] = e[2] + d_021EF780[k];
        }
        e[5] = d_021EF770[k];
        pt.x = -func_020056EC(0x18);
        pt.y = func_020056EC(0xA8) - 0x20;
        func_0204B404((struct Obj *)h, (const struct Vec2 *)(&pt), 0);
    }
}









/*
 * The remainder goes back into t before the store (`t = (t+1) % 252u;
 * s[8] = t;`): storing the expression directly lets the compiler sink
 * `i = t / 28` below the _u32_div_f call. `const` on the two s8 tables
 * schedules the second table's pool load above the s[2] store.
 */
void func_021EEEE0(int a, int *s)
{
    int w;
    int h;
    int i;
    int t;

    func_021A244C((u8 *)a, &w, &h);
    func_021A2564(a, w, h);
    t = s[8];
    i = t / 28;
    t = (unsigned)(t + 1) % 252u;
    s[8] = t;
    s[2] = s[2] + d_021EF765[i] - w / 2;
    s[9] = s[9] + d_021EF75C[i] - h / 2;
    if (s[2] < 0) {
        s[2] = s[2] + 256;
    }
    if (s[9] < 0) {
        s[9] = s[9] + 256;
    }
    s[2] = s[2] % 256;
    s[9] = s[9] % 256;
    func_021A2190((unsigned char *)a, -s[2], 0);
    func_021A21A0((unsigned char *)a, -s[9], 0);
}









int func_021EEF94(int a, int b)
{
    int *p;

    p = func_021A21B8((int *)a);
    func_021A21F8((u8 *)a, 0, 8, 1, 1, -4, 2, 1, (int)((void *)func_021EF2D4));
    func_021A22E0((u32 *)a, 9, 0x7FDF, b);
    *p = 1;
    func_021A2424((u8 *)a);
    func_021A25BC((unsigned char *)a, 0x6E4);
    return 1;
}









int func_021EEFF0(int a, int b, int c)
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
            func_021A232C((u8 *)a, 9, 0x7F80, 0x3C, b);
            func_021A2108(a, 0x3E, func_02014A10(5));
        }
    } else if (func_021A23B0(a) != 0 && t != 0) {
        return 1;
    }
    func_021A244C((u8 *)a, &x, &y);
    func_021A2564(a, x, y);
    return 0;
}









int func_021EF068(unsigned int *a, int b, int c)
{
    func_021A21B8((int *)a);
    func_021A21F8((u8 *)a, 1, 1, 1, 1, -4, 2, 1, (int)((void *)func_021EF2D4));
    func_021A22E0(a, 9, 0x7F80, b);
    func_021A2254((int)a, (void *)func_021EF2D4, 0x14, 10, 1, c);
    func_021A2114((unsigned int)a, 0x3E, func_02014A10(5));
    return 1;
}








int func_021EF0D0(u8 *a, int b, int c)
{
    int x;
    int y;
    func_021A21B8((int *)a);
    func_021A2248(a, c);
    func_021A244C(a, &x, &y);
    func_021A2564((int)((Obj *)a), x, y);
    return 0;
}








int func_021EF100(u8 *a)
{
    int *p;
    p = func_021A21B8((int *)a);
    func_021A2228(a, 0, 8, 4, -1);
    *p = 1;
    func_021A25CC(a);
    return 1;
}







int func_021EF12C(int a, int b, int c)
{
    int *p;
    int t;
    int x;
    int y;
    int ok;

    p = func_021A21B8((int *)a);
    t = func_021A223C((unsigned char *)a, c);
    if (*p > 0) {
        *p = *p - 1;
        if (*p == 0) {
            func_021A2390((u32 *)a, 0x7FDF, 0x3C, b);
        }
    } else {
        ok = (b != 0) ? func_021A23B0(a) : 1;
        if (ok != 0 && t != 0 && func_021A21BC((unsigned char *)a) == 0) {
            return 1;
        }
    }
    func_021A244C((u8 *)a, &x, &y);
    func_021A2564(a, x, y);
    return 0;
}







int func_021EF1A4(u8 *a, int b)
{
    func_021A21B8((int *)a);
    func_021A231C((u32 *)a, b);
    func_021A2120((u32 *)a, b);
    return 1;
}







void func_021EF1C4(int a)
{
    int *p;
    int h;
    Pt pt;

    p = (int *)func_021A2630((unsigned char *)a);
    h = func_021A2638((unsigned char *)a);
    func_021A2640((unsigned char *)a, (struct PtS *)&pt);
    switch (p[3]) {
    case 0:
        if (++p[0] > p[1]) {
            p[3] = 1;
            p[0] = (p[6] % 4) * 2 + 8;
            p[4] = 2;
            p[2] = 2;
            func_0204B908(h, (u16)(func_0204B918((struct Obj *)h) + 3));
            return;
        }
        pt.x = pt.x + (s16)p[4];
        pt.y = pt.y + (s16)p[2];
        func_021A2654(a, (short unsigned int *)(&pt));
        break;
    case 1:
        pt.x = pt.x + (s16)p[4];
        if (p[0] % 2 == 0) {
            pt.y = pt.y + (s16)p[2];
        } else {
            pt.y = pt.y - (s16)p[2];
        }
        if (p[0] % 4 == 0) {
            if (p[2] - 1 >= 0) {
                p[2] = p[2] - 1;
            }
            if (p[4] - 1 >= 0) {
                p[4] = p[4] - 1;
            }
        }
        func_021A26C4(a, (u32)(&pt));
        if (p[0]-- <= 0) {
            p[3] = 2;
        }
        break;
    case 2:
        func_021A21E0((u32 *)a);
        break;
    }
}






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





int func_021EF4E4(u8 *a, int b, int c)
{
    int x;
    int y;
    func_021A21B8((int *)a);
    func_021A2248(a, c);
    func_021A244C(a, &x, &y);
    func_021A2564((int)((Obj *)a), x, y);
    return 0;
}





int func_021EF514(u8 *a)
{
    int *p;
    p = func_021A21B8((int *)a);
    func_021A2228(a, 0, 16, 2, -2);
    *p = 100;
    return 1;
}




int func_021EF538(int a, int b, int c)
{
    int *p;
    int t;
    int x;
    int y;
    int ok;

    p = func_021A21B8((int *)a);
    t = func_021A223C((unsigned char *)a, c);
    if (*p > 0) {
        *p = *p - 1;
        if (*p == 0) {
            func_021A2390((u32 *)a, 0x7FFF, 0x78, b);
        }
    } else {
        ok = (b != 0) ? func_021A23B0(a) : 1;
        if (ok != 0 && t != 0 && func_021A21BC((unsigned char *)a) == 0) {
            return 1;
        }
    }
    func_021A244C((u8 *)a, &x, &y);
    func_021A2564(a, x, y);
    return 0;
}




int func_021EF5B0(u8 *a, int b)
{
    func_021A21B8((int *)a);
    func_021A231C((u32 *)a, b);
    func_021A2120((u32 *)a, b);
    return 1;
}




void func_021EF5D0(int a)
{
    int *p;
    s16 v[2];

    p = (int *)func_021A2630((unsigned char *)a);
    func_021A2638((unsigned char *)a);
    func_021A2640((unsigned char *)a, (struct PtS *)v);
    *p = *p + 1;
    if (*p % p[4] == 0) {
        v[0] = v[0] + (s16)p[2];
    }
    if (*p % p[5] == 0) {
        v[1] = v[1] + (s16)p[3];
    }
    if (*p >= p[1]) {
        func_021A21E0((u32 *)a);
    }
}
