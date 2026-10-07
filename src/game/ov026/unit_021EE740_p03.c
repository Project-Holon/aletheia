/*
 * file:     unit_021EE740_p03.c
 * unit:     yes
 * function: func_021EE8E4, func_021EE95C, func_021EE97C, func_021EEA18, func_021EEAEC
 * address:  0x021EE8E4
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
 *   func_021A223C 0x021A223C thumb ov021
 *   func_021A2390 0x021A2390 thumb ov021
 *   func_021A23B0 0x021A23B0 thumb ov021
 *   func_021A21BC 0x021A21BC thumb ov021
 *   func_021A244C 0x021A244C thumb ov021
 *   func_021A2564 0x021A2564 thumb ov021
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
 *   func_021EEE38 0x021EEE38 thumb ov026
 *   func_021EF9B0 0x021EF9B0 thumb ov026
 *   func_021A21F8 0x021A21F8 thumb ov021
 *   func_021A22E0 0x021A22E0 thumb ov021
 *   func_021A2424 0x021A2424 thumb ov021
 */
struct PtS;
typedef signed int     s32;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed short s16;

typedef struct {
    s16 x;
    s16 y;
} Pt;

typedef unsigned short u16;

extern int *func_021A21B8(int *p);
extern int func_021A223C(unsigned char *o, int arg);
extern void func_021A2390(u32 *p, int a, int b, int c);
extern int func_021A23B0(u32 a);
extern int func_021A21BC(unsigned char *o);
extern void func_021A244C(u8 *o, s32 *outX, s32 *outY);
extern void func_021A2564(int, int, int);
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
extern void func_021EF9B0(u8 *p, int b);
extern void func_021A21F8(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
extern void func_021A22E0(u32 *p, int a, int b, int c);
extern void func_021A2424(u8 *p);
extern void func_021EEE38(int a, int n, int idx);
int func_021EE8E4(int a, int b, int c);
int func_021EE95C(u8 *a, int b);
void func_021EE97C(int a);
void func_021EEA18(int a, int n, int idx);
int func_021EEAEC(int a, int b);


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
