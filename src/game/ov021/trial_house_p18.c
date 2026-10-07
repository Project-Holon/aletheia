/*
 * file:     trial_house_p18.c
 * unit:     yes
 * function: func_021D0824, func_021D08B0, func_021D08BC, func_021D08D8, func_021D0914, func_021D096C, func_021D09D0, func_021D0A48
 * address:  0x021D0824
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
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 *   d_021DE628     0x021DE628  data  ov021  a4
 *   func_0204784C  0x0204784C  arm
 *   func_02047AC8  0x02047AC8  arm
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_0219E784  0x0219E784  thumb  ov021
 *   func_0207CDB8  0x0207CDB8  arm
 *   func_0200E588  0x0200E588  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02030734  0x02030734  arm
 *   func_0201A920  0x0201A920  thumb
 *   d_021DE674     0x021DE674  data  a4
 *   func_020072CC  0x020072CC  thumb
 *   func_020073D8  0x020073D8  thumb
 *   func_0200E5A0  0x0200E5A0  thumb
 *   func_0200E5CC  0x0200E5CC  thumb
 *   func_0200734C  0x0200734C  thumb
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj07595.h"
#include "../../matched/include/Obj20289.h"
#include "../../matched/include/Obj20290.h"
#include "../../matched/include/Obj20291.h"

struct Actor;
struct VecFx32;
struct AnmCtl;
struct Arg;
struct Big;
struct Ctx;
struct Party;
struct Sub020073D8Ctrl;
struct Sub02007324Ctrl;
typedef short s16;

typedef long long s64;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct Row {
    u32 f0;
    int f4;
    u32 f8[3];
} Row;

typedef struct Blk021D08D8 {
    u32 w[3];
} Blk021D08D8;

typedef signed int     s32;

extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern void func_02082BCC();
extern u32 func_0204784C(struct AnmCtl *c, u16 idx, s32 *frame);
extern int func_02047AC8(void *a0, struct Arg *a1);
extern u16 func_0216D5F8(void *p);
extern int func_0216D55C(int a, int b);
extern int func_021641E8(int a);
extern int func_021641F8(int a);
extern void func_0219E784(u32 o, u32 idx, s16 *v);
extern void func_0207CDB8(s16 *a, s16 *b);
extern u32 func_0200E588(void);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern struct Party *func_0201A920(u32 heap);
extern void func_020072CC(int a, int b, int c, void *d, int e);
extern void *func_020073D8(struct Sub020073D8Ctrl *ctrl, u32 id, u32 v);
extern int func_0200E5A0(void *a0);
extern int func_0200E5CC(void *p);
extern void func_0200734C(struct Sub02007324Ctrl *a, unsigned int b);
extern u32 func_020307B0(void *p);
void func_021D0824(int *p, int a);
void func_021D08B0(u32 a);
void func_021D08BC(Row *r, int v);
void func_021D08D8(Row *r, int a);
int func_021D0914(int a, s16 *v);
void *func_021D096C(int a);
void func_021D09D0(int a, char *out);
void func_021D0A48(void *a, u8 **pp);
extern Blk021D08D8 d_021DE628;
extern int d_021DE674;


void func_021D0824(int *p, int a)
{
    s16 v[3];
    int k;

    p[0] = 1;
    p[1] = 0;
    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)(p + 2));
    if (func_021D0914(a, v) == 0) {
        k = 0xE000;
    } else {
        k = 1 << 14;
    }
    p[3] += 0x7000;
    p[2] += (int)(((s64)v[0] * k + 0x800) >> 12);
    p[4] += (int)(((s64)v[2] * k + 0x800) >> 12);
}


/*
 * Tail-call thunk: pins arguments 2 and 3 to 0 and 20.
 *
 * Addresses are Black-image addresses.
 */
void func_021D08B0(u32 a)
{
    func_02082BCC(a, 0, 20);
}


void func_021D08BC(Row *r, int v)
{
    if (r->f0 != 0) {
        r->f4 += 0x1000;
        if (r->f4 > v) {
            func_021D08B0((u32)r);
        }
    }
}


void func_021D08D8(Row *r, int a)
{
    int i;

    if (r->f0 != 0) {
        d_021DE628 = *(Blk021D08D8 *)r->f8;
        for (i = 0; i < 2; i++) {
            func_0204784C((struct AnmCtl *)a, (u16)i, &r->f4);
        }
        func_02047AC8((void *)a, (struct Arg *)(&d_021DE628));
    }
}


int func_021D0914(int a, s16 *v)
{
    int r;

    r = func_0216D5F8((void *)a);
    if (func_0216D55C(a, 0x1000 * 2) == 0) {
        v[1] = 0;
        v[0] = func_021641E8(r);
        v[2] = func_021641F8(r);
        v[0] = v[0] << 16;
        v[2] = v[2] << 16;
    } else {
        func_0219E784(a, r, v);
        v[1] = 0;
    }
    func_0207CDB8(v, v);
    return r;
}


/*
 * Callee witnesses filed in wave A1 (witness lane).
 */
void *func_021D096C(int a)
{
    char *p;
    int r7;

    r7 = func_0200E588();
    func_02012EBC(func_020120F4((const struct Ctx *)a));
    p = func_02030734(5, 0x154, 1, (const char *)&d_021DE674, 0x5D);
    ((struct Obj07595 *)p)->f120 = 5;
    ((struct Obj07595 *)p)->f14C = (int)func_02030734(5, r7, 1, (const char *)&d_021DE674, 0x5F);
    func_021D09D0(a, p);
    ((struct Obj07595 *)p)->f128 = (int)func_0201A920(((struct Obj07595 *)p)->f120);
    return p;
}


void func_021D09D0(int a, char *out)
{
    int v;
    int t;
    int h;
    void *buf;

    h = (int)func_02012EBC(func_020120F4((const struct Ctx *)a));
    buf = func_02030734(0x8004, 0x8004 >> 3, 1, (const char *)&d_021DE674, 0x79);
    v = 0x8004 >> 3;
    func_020072CC(h, 5, 0x8004, buf, v);
    v = 0;
    t = (int)func_020073D8((struct Sub020073D8Ctrl *)h, 5, 0);
    if (func_0200E5A0((void *)t)) {
        int r = func_0200E5CC((void *)t);
        v = 1;
        if (r == 0) {
            v = 2;
        }
    }
    func_0200734C((struct Sub02007324Ctrl *)h, 5);
    func_020307B0(buf);
    ((struct Obj20289 *)out)->f150 = v;
}


void func_021D0A48(void *a, u8 **pp)
{
    if (*pp != 0) {
        func_020307B0(((struct Obj20290 *)(*pp))->f14C);
        func_020307B0(((struct Obj20291 *)(*pp))->f128);
        func_020307B0(*pp);
        *pp = 0;
    }
}
