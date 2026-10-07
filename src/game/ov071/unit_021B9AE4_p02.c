/*
 * file:     unit_021B9AE4_p02.c
 * unit:     yes
 * function: func_021BA01C, func_021BA0CC, func_021BA11C, func_021BA140, func_021BA1B0, func_021BA1DC, func_021BA1FC, func_021BA2CC
 * address:  0x021BA01C
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9FEC  0x021B9FEC  thumb  ov071
 *   func_021B6C30  0x021B6C30  thumb  ov071
 *   func_021B6C48  0x021B6C48  thumb  ov071
 *   func_021B6BEC  0x021B6BEC  thumb  ov071
 *   func_02041B6C  0x02041B6C  arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_0202590C  0x0202590C  thumb
 *   func_02043814  0x02043814  arm
 *   func_020257D0 0x020257D0 thumb
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021BA3B4  0x021BA3B4  thumb  ov071
 *   func_021BA420  0x021BA420  thumb  ov071
 *   func_021BA44C  0x021BA44C  thumb  ov071
 *   func_021BA4EC  0x021BA4EC  thumb  ov071
 *   func_021BA528  0x021BA528  thumb  ov071
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02040588  0x02040588  arm
 *   func_020434DC  0x020434DC  arm
 *   func_021BA5D4  0x021BA5D4  thumb  ov071
 */
#include "../../matched/include/Obj00044.h"
#include "../../matched/include/Obj20758.h"
#include "../../matched/include/Obj20759.h"
#include "../../matched/include/Obj13186.h"
#include "../../matched/include/Obj13187.h"
#include "../../matched/include/Obj06191.h"
#include "../../matched/include/Obj07706.h"
#include "../../matched/include/Obj20760.h"
#include "../../matched/include/Obj06192.h"
#include "../../matched/include/Obj09900.h"
#include "../../matched/include/Obj13188.h"

struct Bmp;
struct Grid;
struct Obj;
struct Obj0203159C;
struct Descriptor;
struct PrintSys;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef signed short   s16;

typedef enum { B_FALSE, B_TRUE } Bool;

extern void func_021B9FEC(void *p, int a);
extern void func_021B6C30(int *p, int flag, int index);
extern void func_021B6C48(void *p, int a);
extern void func_021B6BEC(void *p, int *tbl, int n, int sel, int c);
extern void func_02041B6C(u32 bit);
extern void func_02041EE4(unsigned, unsigned, unsigned);
extern void func_0202590C(struct Grid *g, s16 x, s16 y);
extern void func_02043814(struct Bmp *dst, const struct Bmp *src);
extern void func_020257D0(struct Obj *o);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *p, int v, int n);
extern void func_021BA3B4(void);
extern void func_021BA420(char *p);
extern void func_021BA44C(void *a, void *b);
extern void func_021BA4EC(char *p, char *q);
extern void func_021BA528(u32 **a, u8 *b, u8 *c);
extern void *func_02045770(struct Descriptor *a);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_021BA5D4(void *a, void *b, void *c);
void func_021BA01C(void *a, u8 *p);
int func_021BA0CC(u8 *p, int d);
void func_021BA11C(char *p);
void func_021BA140(u8 *p);
void func_021BA1B0(void *unused, char *p);
int func_021BA1DC(char *p, unsigned a);
int func_021BA1FC(struct Obj0203159C *a, int *b, u8 *o, u8 *c);
int func_021BA2CC(int a, int *b, u8 *o, u8 *c);


void func_021BA01C(void *a, u8 *p)
{
    int v;
    int m;

    if (((struct Obj00044 *)p)->f304 == 1) {
        func_021B9FEC(p, ((struct Obj00044 *)p)->f2F4);
        v = ((struct Obj00044 *)p)->f2F4;
        if (v == 0xffff) {
            func_021B6C30(a, 0, 1);
        } else {
            m = ((struct Obj00044 *)p)->f308;
            if ((m == 2 && v == ((struct Obj00044 *)p)->f2FC) || (m == 1 && v == ((struct Obj00044 *)p)->f2F8)) {
                if (*(int *)(p + 0x1b4 + v * 4) == 0) {
                    ((struct Obj00044 *)p)->f300 = v;
                    if (((struct Obj00044 *)p)->f308 == 1) {
                        func_021B6C48(a, 1);
                    } else {
                        func_021B6BEC(a, (int *)(p + 8), 1, 0, 3);
                    }
                } else if (m == 2) {
                    func_021B6C30(a, 1, 1);
                }
            } else {
                func_021B6C30(a, 1, 1);
            }
        }
        func_02041B6C(6);
        ((struct Obj00044 *)p)->f304 = 0;
    }
}


int func_021BA0CC(u8 *p, int d)
{
    int lim;
    int old;

    old = ((struct Obj00044 *)p)->f2D8;
    lim = p[0x27c] * 32 - 8;
    if (lim <= 0xc0) {
        return 0;
    }
    ((struct Obj00044 *)p)->f2D8 = old + d;
    if (((struct Obj00044 *)p)->f2D8 < 0x800) {
        ((struct Obj00044 *)p)->f2D8 = 0x800;
    } else if (((struct Obj00044 *)p)->f2D8 > (lim - 0xc0) << 8) {
        ((struct Obj00044 *)p)->f2D8 = (lim - 0xc0) << 8;
    }
    if ((((struct Obj00044 *)p)->f2D8 >> 8) != (old >> 8)) {
        return 1;
    }
    return 0;
}

void func_021BA11C(char *p) { func_02041EE4(6, 3, (((struct Obj20758 *)p)->f2D8 >> 8) % 64); }


void func_021BA140(u8 *p)
{
    int x = ((struct Obj20759 *)p)->f2D8 >> 8;
    int b = 8 - x % 32;
    u8 *q = p + (x / 32) * 4;
    int i;

    for (i = 0; i < 7; i++) {
        func_0202590C(*(void **)(p + i * 4 + 0x2a0), 0x20, b + i * 32);
        if (*(void **)(q + i * 4 + 0x24) != 0) {
            func_02043814(*(void **)(q + i * 4 + 0x24), *(void **)(p + i * 4 + 0x2bc));
        }
    }
}

void func_021BA1B0(void *unused, char *p) { int i; if (((struct Obj13186 *)p)->f2F0 == 1) { for (i = 0; i < 7; i++) func_020257D0(*(void **)(p + i * 4 + 0x2a0)); ((struct Obj13186 *)p)->f2F0 = 0; } }

int func_021BA1DC(char *p, unsigned a) { int x = ((((struct Obj13187 *)p)->f2D8 >> 8) + a) >> 5; if (x >= ((struct Obj13187 *)p)->f27C) x = 0xffff; return x; }


int func_021BA1FC(struct Obj0203159C *a, int *b, u8 *o, u8 *c)
{
    u8 *m;
    int busy;
    int i;
    u32 t;
    u8 *e;
    Bool f;

    switch (*b) {
    case 0:
        m = func_0203159C(a, 0x28, 0x61);
        func_02082BCC(m, 0, 0x28);
        ((struct Obj20760 *)m)->f24 = 0x30;
        func_021BA3B4();
        func_021BA420(((struct Obj07706 *)o)->f4);
        func_021BA44C(((struct Obj07706 *)o)->f4, m);
        func_021BA4EC(((struct Obj07706 *)o)->f4, (char *)m);
        func_021BA528((u32 **)o, ((struct Obj07706 *)o)->f4, m);
        *b = *b + 1;
        break;
    case 1:
        busy = 0;
        for (i = 0; i < 3; i++) {
            t = (*(u32 **)(o + 4))[2];
            e = c + i * 8;
            if (e[0x10] != 0) {
                if (func_0201C6C4((struct PrintSys *)t, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj06191 *)e)->fC))) == 0) {
                    func_02045334((struct Descriptor *)((struct Obj06191 *)e)->fC);
                    e[0x10] = 0;
                }
            }
            f = e[0x10] == 0 ? B_TRUE : B_FALSE;
            if (f == B_FALSE) {
                busy = 1;
            }
        }
        if (busy == 0) {
            func_02040588(0, 1);
            func_02040588(2, 1);
            func_020434DC(0x10, 1);
            return 1;
        }
        break;
    }
    return 0;
}


int func_021BA2CC(int a, int *b, u8 *o, u8 *c)
{
    int i;
    u8 f[3];
    u32 t;
    u8 *e;

    if (o[0x2d] == 1) {
        return 1;
    }
    for (i = 0; i < 3; i++) {
        t = (*(u32 **)(o + 4))[2];
        e = c + i * 8;
        if (e[0x10] != 0) {
            if (func_0201C6C4((struct PrintSys *)t, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj06192 *)e)->fC))) == 0) {
                func_02045334((struct Descriptor *)((struct Obj06192 *)e)->fC);
                e[0x10] = 0;
            }
        }
        f[i] = e[0x10] == 0;
    }
    if (*b == 0) {
        if ((*(u8 **)(o + 8))[3] == 1 && f[1] == 1) {
            func_021BA528((u32 **)o, ((struct Obj09900 *)o)->f4, c);
            (*(u8 **)(o + 8))[3] = 0;
        }
        if ((*(u8 **)(o + 8))[1] != ((struct Obj13188 *)c)->f24 && f[2] == 1) {
            func_021BA5D4(o, ((struct Obj09900 *)o)->f4, c);
            ((struct Obj13188 *)c)->f24 = (*(u8 **)(o + 8))[1];
        }
        return 0;
    }
    return 0;
}
