/*
 * file:     unit_021EE740_p05.c
 * unit:     yes
 * function: func_021EECB0, func_021EECEC, func_021EED58, func_021EED78, func_021EEE04
 * address:  0x021EECB0
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
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A2228 0x021A2228 thumb ov021
 *   func_021EEEE0 0x021EEEE0 thumb ov025
 *   func_021A2160 0x021A2160 thumb ov021
 *   func_021A25CC 0x021A25CC thumb ov021
 *   func_021A223C  0x021A223C  thumb  ov021
 *   func_021A2390  0x021A2390  thumb  ov021
 *   func_021A23B0  0x021A23B0  thumb  ov021
 *   func_021A21BC  0x021A21BC  thumb  ov021
 *   func_021A231C 0x021A231C thumb ov021
 *   func_021A2120 0x021A2120 thumb ov021
 *   func_021A2630 0x021A2630 thumb ov021
 *   func_021A2638 0x021A2638 thumb ov021
 *   func_021A21E0 0x021A21E0 thumb ov021
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   func_020056EC  0x020056EC  thumb
 *   func_0204B908  0x0204B908  arm
 *   func_021A21C8  0x021A21C8  thumb  ov021
 *   d_021EF780     0x021EF780  data   a4
 *   d_021EF770     0x021EF770  data   a4
 */
struct Obj;
struct Vec2;
struct Actor;
struct PtS;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef signed short s16;

typedef unsigned short u16;

typedef struct {
    s16 x;
    s16 y;
} Pt;

extern int *func_021A21B8(int *);
extern void func_021A2228(u8 *, int, int, int, int);
extern void func_021EEEE0(int, int *);
extern void func_021A2160(u8 *, unsigned int, int);
extern void func_021A25CC(u8 *);
extern int func_021A223C(unsigned char *o, int arg);
extern void func_021A2390(u32 *p, int a, int b, int c);
extern int func_021A23B0(u32 a);
extern int func_021A21BC(unsigned char *o);
extern void func_021A231C(u32 *, int);
extern void func_021A2120(u32 *, int);
extern unsigned char *func_021A2630(unsigned char *o);
extern unsigned int func_021A2638(unsigned char *o);
extern void func_021A21E0(u32 *p);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern u32 func_020056EC(u32 v);
extern void func_0204B908(int a0, int a1);
extern void *func_021A21C8(void *p, int a1);
int func_021EECB0(u8 *a);
int func_021EECEC(int a, int b, int c);
int func_021EED58(u32 *p, int x);
void func_021EED78(int a);
void func_021EEE04(int a, int n, u16 idx);
extern const int d_021EF780[];
extern const int d_021EF770[];

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
