/*
 * file:     field_place_name_p01.c
 * unit:     yes
 * function: func_021BBDD4, func_021BBE84
 * address:  0x021BBDD4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D5FC  0x0216D5FC  thumb  ov010
 *   func_021BBD84  0x021BBD84  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D804  0x0216D804  thumb  ov010
 *   func_0216D81C  0x0216D81C  thumb  ov010
 *   func_02164280  0x02164280  thumb  ov010
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021D9AF8     0x021D9AF8  data  a4
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_02050340  0x02050340  arm
 */
#include "../../matched/include/Obj20103.h"

struct Actor;
struct VecFx32;
struct BbActDesc;
struct BbActSys;
typedef unsigned short u16;

typedef struct Vec {
    int x;
    int y;
    int z;
} Vec;

typedef struct Arg {
    int a;
    u16 h;
} Arg;

typedef unsigned int   u32;

typedef signed char s8;

struct Head {
    unsigned char pad[4];
    void *h4;
    u16 tab[1];
};

typedef struct Src {
    struct Head *head;
    u16 idx;
    u16 x;
} Src;

typedef struct Res {
    struct Head *head;
    u16 idx;
    u16 x;
    u16 h8;
    unsigned char padA[4];
    short h0e;
} Res;

typedef struct Desc1 {
    u16 a, b, c;
    s8 d;
    int e, f;
} Desc1;

typedef struct Desc2 {
    int pad[3];
    int a;
    Res *b;
} Desc2;

int func_021ABEA0(u32 a, u32 b);
u16 func_0216D5F8(void *p);
u16 func_0216D5FC(void *p);
int func_021BBD84(int a, int n, int x, int y);
void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
int func_0216D804(void *p);
int func_0216D81C(void *p);
void func_02164280(int x, int y, int *p);
void func_021ABFA8(int a, void *b, Vec *c, int d, Arg *e, int f);
extern int func_021AC1AC(u32 a);
extern void func_021AC1B8(int a, Desc2 *d);
extern void func_021AC154(int a);
extern u16 func_02050340(struct BbActSys *o, u16 base, const struct BbActDesc *d, u32 count, u32 mode);
void func_021BBDD4(int a, int b, int c);
void func_021BBE84(int a0, Res *r);
extern int d_021D9AF8;


void func_021BBDD4(int a, int b, int c)
{
    int x;
    int t;
    int u;
    int w;
    Vec v;
    Arg s;

    x = func_021ABEA0(b, 5);
    s.a = x;
    t = func_0216D5F8((void *)a);
    u = func_0216D5FC((void *)a);
    w = (u16)func_021BBD84(x, c, t, u);
    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&v);
    t = func_0216D804((void *)a);
    func_02164280(t, func_0216D81C((void *)a), (int *)(&v));
    if (c == 0 && (u16)(w + 0xFFFE) <= 1) {
        v.z -= 0x2000;
    } else if (c == 4 && (u16)(w + 0xFFFE) <= 1) {
        v.z -= 0x2000;
    }
    if (c == 4) {
        v.y -= ((struct Obj20103 *)x)->f3C;
    }
    s.h = w;
    func_021ABFA8(b, &d_021D9AF8, &v, 0, &s, 0);
}


void func_021BBE84(int a0, Res *r)
{
    Desc2 d2;
    Desc1 d1;
    Src *s = (Src *)func_021AC1AC(a0);

    *(Src *)r = *s;
    r->h0e = 0x1f;
    d1.a = r->head->tab[r->idx];
    d1.b = 0x1000;
    d1.c = 0x1000;
    d1.d = r->h0e;
    d1.e = 1;
    d1.f = 1;
    d2.a = 0;
    d2.b = r;
    func_021AC1B8(a0, &d2);
    r->h8 = func_02050340(r->head->h4, 0, (const struct BbActDesc *)(&d1), 1, 3);
    if (r->h8 == 0xFFFF) {
        func_021AC154(a0);
    }
}
