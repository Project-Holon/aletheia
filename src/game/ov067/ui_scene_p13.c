/*
 * file:     ui_scene_p13.c
 * unit:     yes
 * function: func_021B8A88, func_021B8AB8, func_021B8AE4, func_021B8B74, func_021B8C14, func_021B8C4C
 * address:  0x021B8A88
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0202EE0C 0x0202EE0C thumb
 *   func_02035BA4  0x02035BA4  arm
 *   func_02035CB8  0x02035CB8  arm
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_021B8A44  0x021B8A44  thumb  ov067
 *   func_021B8434  0x021B8434  thumb  ov067
 *   func_021B8EA0  0x021B8EA0  thumb  ov067
 *   func_021B8DF0  0x021B8DF0  thumb  ov067
 */
#include "../../matched/include/Obj20623.h"
#include "../../matched/include/Obj09865.h"

struct PrintSys;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct Entry { u8 f0, f1; u8 pad2[2]; u32 f4; } Entry;

typedef unsigned short u16;

typedef signed short s16;

struct S_021B8AE4 {
    u8 _0[0x12];
    u8 f12;
    u8 _13[0x62 - 0x13];
    s16 f62;
    u16 f64;
    u8 _66[0x74 - 0x66];
    u32 f74;
    u8 _78[0x7f - 0x78];
    u8 f7f;
};

typedef signed char s8;

struct S_021B8B74 {
    u8 _0[0xb];
    u8 fb;
    u8 _c[0x34 - 0xc];
    int f34;
    u8 _38[0x48 - 0x38];
    u8 f48;
    u8 _49[0x4e - 0x49];
    u16 f4e;
    u8 _50[0x62 - 0x50];
    s16 f62;
    u8 _64[0x74 - 0x64];
    u32 f74;
    u8 _78[0x7f - 0x78];
    u8 f7f;
    int f80;
};

struct S_021B8C14 {
    u8 _0[0x4e];
    u16 f4e;
    u8 _50[0x54 - 0x50];
    u32 f54;
    u8 _58[0x70 - 0x58];
    u32 f70;
    u8 _74[0x84 - 0x74];
    u8 f84;
    u8 f85;
    u8 f86 : 5;
    u8 f86_5 : 3;
    u8 f87;
    u8 _88[0x8c - 0x88];
    u32 f8c;
    u32 f90;
};

struct Ent {
    u32 f0;
    u32 f4;
};

struct S_021B8C4C {
    u8 _0[0x1c];
    struct Ent *f1c;
    u8 _20[0x2c - 0x20];
    void *f2c;
    u8 _30[0x34 - 0x30];
    int f34;
    u8 _38[0x4e - 0x38];
    u16 f4e;
    u8 _50[0x54 - 0x50];
    u32 f54;
    u8 _58[0x70 - 0x58];
    u32 f70;
    u8 _74[0x84 - 0x74];
    u8 f84;
    s8 f85;
    u8 f86 : 5;
    u8 f86_5 : 1;
    u8 f86_6 : 2;
    u8 f87;
    u8 f88;
    u8 _89[0x8c - 0x89];
    u32 f8c;
    u32 f90;
};

extern u32 func_0202EE0C(u32 a, u32 b, u32 c, u32 d, u32 e);
extern int func_02035BA4(const void *p);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern u32 func_021B8A44(struct S_021B8B74 *s);
extern void func_021B8434(u8 *p, int a, u8 b, u16 c, u32 d);
extern int func_021B8EA0(struct S_021B8C4C *s);
extern int func_021B8DF0(struct S_021B8C4C *s, int a1);
void func_021B8A88(u8 *p, u8 *a, u8 *b);
int func_021B8AB8(u8 *p);
int func_021B8AE4(struct S_021B8AE4 *s, unsigned int v);
int func_021B8B74(struct S_021B8B74 *s);
void func_021B8C14(struct S_021B8C14 *s, int a);
int func_021B8C4C(struct S_021B8C4C *s);

void func_021B8A88(u8 *p, u8 *a, u8 *b)
{
    u8 i;
    Entry *entries;
    u8 value;
    entries = *(Entry * *)&((struct Obj20623 *)p)->f1C;
    for (i = 0; ; i++) {
        value = entries[i].f0;
        if (value == 0xff) break;
        if (entries[i].f4 == 1) {
            *a = value;
            *b = (*(Entry **)(p + 0x1c))[i].f1;
            return;
        }
    }
}

int func_021B8AB8(u8 *p)
{
    u8 b, a;
    func_021B8A88(p, &b, &a);
    return func_0202EE0C(((struct Obj09865 *)p)->f64, ((struct Obj09865 *)p)->f62, b, a, p[0x12]);
}


int func_021B8AE4(struct S_021B8AE4 *s, unsigned int v)
{
    u8 b, a;
    int o1, o2;
    unsigned int lo, hi;

    if (s->f7f == 1) {
        if (func_02035BA4(&s->f74) != -1) {
            func_02035CB8((u32 *)(&o1), (u32 *)(&o2));
            return o2;
        }
        return v;
    }
    func_021B8A88((u8 *)s, &b, &a);
    lo = func_0202EE0C(s->f64, s->f62, b, a, s->f12);
    if (s->f64 == s->f62)
        hi = a;
    else
        hi = func_0202EE0C(s->f64, s->f62 + 1, b, a, s->f12);
    if (v >= lo && v < hi)
        return v;
    return lo;
}


int func_021B8B74(struct S_021B8B74 *s)
{
    u32 x;
    u32 d;

    if (func_0201C6B4((const struct PrintSys *)s->f34) == 0)
        return 1;
    if (func_02035BA4(&s->f74) == -1 && s->f80 == -1) {
        s->f7f = 0;
        s->f4e = 0;
        return 0;
    }
    x = func_021B8A44(s);
    d = s->f62 - x;
    if ((int)d < 0)
        d = -d;
    if (d > s->f48)
        d = s->f48;
    if (s->f62 > x) {
        s->f62 = x + d;
        func_021B8434((u8 *)s, (s8)(-s->fb), d, 2, 1);
    } else if (s->f62 < x) {
        s->f62 = x - d;
        func_021B8434((u8 *)s, (s8)s->fb, d, 2, 1);
    }
    return 1;
}


void func_021B8C14(struct S_021B8C14 *s, int a)
{
    u32 v;

    s->f84 = 0;
    s->f87 = a;
    s->f86 = 0;
    v = s->f54;
    s->f70 = 0;
    s->f8c = v;
    s->f90 = v;
    s->f4e = 3;
}


int func_021B8C4C(struct S_021B8C4C *s)
{
    int r;

    if (func_0201C6B4((const struct PrintSys *)s->f34) == 0)
        return 1;
    r = func_02035BA4(s->f2c);
    switch (s->f84) {
    case 0:
        if (r == -1) {
            if (s->f8c != -1 && s->f90 != -1) {
                s->f85 = s->f90 - s->f8c;
                s->f86 = 0;
                if (func_021B8EA0(s) == 1)
                    break;
            }
            s->f70 = 0;
            s->f4e = 0;
            return 0;
        }
        if (s->f1c[r].f4 != 0) {
            if (s->f8c != -1 && s->f90 != -1) {
                s->f85 = s->f90 - s->f8c;
                s->f86 = 0;
                if (func_021B8EA0(s) == 1)
                    break;
            }
            s->f70 = 0;
            s->f4e = 0;
            return 0;
        }
        if (s->f87 != r) {
            s->f88 = r;
            s->f85 = s->f87 - r;
            s->f86 = 0;
            s->f84 = 1;
        }
        s->f90 = s->f8c;
        s->f8c = s->f54;
        break;
    case 1:
        if (r == -1) {
            s->f84 = 0;
            return func_021B8EA0(s);
        }
        if (s->f1c[r].f4 != 0) {
            s->f84 = 0;
            return func_021B8EA0(s);
        }
        if (s->f86 == 5) {
            s->f86 = 0;
            s->f84 = 0;
            if (func_021B8DF0(s, r) == 1)
                s->f86_5 = 1;
        } else {
            s->f88 = r;
            s->f8c = s->f54;
            s->f86++;
        }
        break;
    }
    return 1;
}
