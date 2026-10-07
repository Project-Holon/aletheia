/*
 * file:     unit_021B6100_p03.c
 * unit:     yes
 * function: func_021B68D8, func_021B6954, func_021B6994
 * address:  0x021B68D8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BA710  0x021BA710  thumb  ov093
 *   func_021BA128  0x021BA128  thumb  ov093
 *   func_021B9E7C  0x021B9E7C  thumb  ov093
 *   func_021B9E38  0x021B9E38  thumb  ov093
 *   func_0201AA18  0x0201AA18  thumb
 */
#include "../../matched/include/Obj06216.h"
#include "../../matched/include/Obj13266.h"

struct S;
struct A;
struct B;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct T {
    u8 pad00[0x24];
    void *f24[4];
};

struct S {
    u32 f00;
    u32 f04;
    u8 pad08[0x1a];
    u8 f22;
    u8 pad23;
    void *f24[4];
};

extern u8 func_021BA710(int a, int b);
extern void func_021BA128(struct S *p, int i, void *x);
extern void func_021B9E7C(struct A *p, struct B *src);
extern void func_021B9E38(char *p, int a, int b);
extern u32 func_0201AA18(void *p);
void func_021B68D8(u8 *s, struct T *t);
void func_021B6954(int a, int b);
int func_021B6994(struct S **pp, u32 b);


void func_021B68D8(u8 *s, struct T *t)
{
    int a, b, c, d;

    a = func_021BA710(s[0x46c], 0);
    b = func_021BA710(s[0x46c], 1);
    func_021BA128((struct S *)s, 0, t->f24[a]);
    func_021BA128((struct S *)s, 1, t->f24[b]);
    c = func_021BA710(s[0x46c], 2);
    d = func_021BA710(s[0x46c], 3);
    if (t->f24[c] != 0) {
        func_021BA128((struct S *)s, 2, t->f24[c]);
    }
    if (t->f24[d] != 0) {
        func_021BA128((struct S *)s, 3, t->f24[d]);
    }
}


void func_021B6954(int a, int b)
{
    char *p = (char *)a;
    int base = ((struct Obj06216 *)p)->f0;
    int idx = func_021BA710(((struct Obj06216 *)p)->f46C, b);
    char *q = (char *)(a + 0x20) + b * 0x28;
    char *e = (char *)base + idx * 4;
    int *r = (int *)((struct Obj13266 *)e)->f48;
    if (*r != 0)
        func_021B9E7C((struct A *)((int)q), (struct B *)((int)r));
    else
        func_021B9E38((char *)((int)q), ((struct Obj06216 *)p)->f468, ((struct Obj13266 *)e)->f34);
}


int func_021B6994(struct S **pp, u32 b)
{
    struct S *p = *pp;
    void *q;

    switch (p->f04) {
    case 0:
        return 1;
    case 3:
        return 1;
    case 2:
        return 3;
    case 1:
        if (p->f22 == 0) {
            return 2;
        }
        if (p->f00 == 3) {
            return 1;
        }
        q = p->f24[(u8)((b + 2) & 3)];
        if (q != 0 && (int)func_0201AA18(q) > 0) {
            return 1;
        }
        return 2;
    }
    return 1;
}
