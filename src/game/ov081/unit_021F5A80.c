/*
 * file:     unit_021F5A80.c
 * unit:     yes
 * function: func_021F5A80, func_021F5ABC, func_021F5AEC, func_021F5B30, func_021F5B94, func_021F5BCC, func_021F5BFC, func_021F5C3C
 * address:  0x021F5A80
 * region:   ov081
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F5D00 0x021F5D00 data a4
 *   func_02189A08 0x02189A08 thumb ov021
 *   func_021CF580 0x021CF580 thumb ov021
 *   func_021F5260 0x021F5260 thumb ov075
 *   func_021F582C 0x021F582C thumb ov077
 *   func_021F5620  0x021F5620  thumb  ov077
 *   func_021F5CA0  0x021F5CA0  thumb  ov081
 */
#include "../../matched/include/Obj03673.h"
#include "../../matched/include/Obj06199.h"
#include "../../matched/include/Obj20797.h"
#include "../../matched/include/Obj20798.h"
#include "../../matched/include/Obj13220.h"
#include "../../matched/include/Obj20799.h"

struct Vec;
struct Param;
typedef struct { int x,y,z; } Vec;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct {
    int w;
    int h;
    void (*init)(void *);
    void (*step)(void *);
    int (*done)(void *);
} Cfg;

typedef unsigned short u16;

extern int func_02189A08(unsigned char *p);
extern void func_021CF580(void *);
extern void *func_021F5260(void *a, struct Vec *src, u32 b, u32 c);
extern void func_021F582C(u8 *p);
extern void *func_021F5620(void *task, const struct Param *p, int flag);
extern void func_021F5CA0(u8 *w);
void *func_021F5A80(void *p, int b);
void func_021F5ABC(void *a);
void func_021F5AEC(u8 *w);
void func_021F5B30(u8 *w);
int func_021F5B94(int *o);
int func_021F5BCC(int a, u32 p);
void func_021F5BFC(u8 *w, int x, int y);
void func_021F5C3C(u8 *w, int k);
extern const Vec d_021F5D00;

void *func_021F5A80(void *p, int b) {
    Vec v = d_021F5D00;
    func_021CF580((void *)func_02189A08((unsigned char *)b));
    return func_021F5260(p, (struct Vec *)(&v), (u32)((void (*)(void))func_021F5ABC), (u32)func_021F582C);
}


void func_021F5ABC(void *a)
{
    Cfg c;

    c.w = 2;
    c.h = 2;
    c.init = (void (*)(void *))func_021F5AEC;
    c.step = (void (*)(void *))func_021F5B30;
    c.done = (int (*)(void *))func_021F5B94;
    func_021F5620(a, (const struct Param *)(&c), 1);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021F5AEC(u8 *w)
{
    u8 *t = w + 0x300C;

    ((struct Obj03673 *)t)->f182 = 0;
    ((struct Obj03673 *)t)->f180 = 0;
    ((struct Obj03673 *)t)->fC0 = 0x33;
    (((struct Obj03673 *)t)->f182)++;
    ((struct Obj03673 *)t)->fC2 = 0x95;
    (((struct Obj03673 *)t)->f182)++;
    ((struct Obj03673 *)t)->fC4 = 0x5B;
    (((struct Obj03673 *)t)->f182)++;
}


void func_021F5B30(u8 *w)
{
    int *c = (int *)(w + 0x3000);
    u8 *t = w + 0x300C;

    if (c[0] < ((struct Obj06199 *)w)->f3008 * ((struct Obj06199 *)w)->f300A) {
        if (c[1] == 0) {
            int i;

            for (i = 0; i < ((struct Obj20797 *)t)->f180; i++)
                func_021F5C3C(w, *(u16 *)(t + i * 2));
            func_021F5CA0(w);
            c[1] = 1;
        } else {
            c[1]--;
        }
    }
}

int func_021F5B94(int *o)
{
    if (o[0] < 0x100000) {
        int a = o[0];
        int b = o[9];

        o[2] = 0x1000;
        o[0] = a + b;
        o[9] = b + 0x1000;
        if (o[7] < 0x8000)
            o[7] += 0x200;
        else
            o[7] = 0x8000;
    } else {
        o[14] = 1;
    }
    return o[14];
}

/*
 * Lever: declare index before bound to put index in r3 and bound in r4.
 */
int func_021F5BCC(int a, u32 p) {
    int i;
    int n = ((struct Obj20798 *)p)->f182;
    for (i=0; i<n; i++) {
        if (a == *(u16 *)(p+i*2+0xC0)) return 1;
    }
    return 0;
}


void func_021F5BFC(u8 *w, int x, int y)
{
    u8 *t = w + 0x300C;
    int k = x + y * ((struct Obj20799 *)w)->f3008;

    if (*(int *)(w + k * 64 + 0x34) == 0) {
        if (func_021F5BCC(k, (u32)t) == 0) {
            *(u16 *)(t + 0xC0 + ((struct Obj13220 *)t)->f182 * 2) = k;
            (((struct Obj13220 *)t)->f182)++;
        }
    }
}


void func_021F5C3C(u8 *w, int k)
{
    int wd = ((struct Obj06199 *)w)->f3008;
    int x = k % wd;
    int y = k / wd;

    if (y - 1 >= 0)
        func_021F5BFC(w, x, y - 1);
    if (x + 1 < ((struct Obj06199 *)w)->f3008)
        func_021F5BFC(w, x + 1, y);
    if (y + 1 < ((struct Obj06199 *)w)->f300A)
        func_021F5BFC(w, x, y + 1);
    if (x - 1 >= 0)
        func_021F5BFC(w, x - 1, y);
}
