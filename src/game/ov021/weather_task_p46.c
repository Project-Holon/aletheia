/*
 * file:     weather_task_p46.c
 * unit:     yes
 * function: func_021A4254, func_021A428C, func_021A43D8, func_021A4444, func_021A448C, func_021A44BC, func_021A44C8
 * address:  0x021A4254
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
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_021A3974  0x021A3974  thumb  ov021
 *   func_021A5318  0x021A5318  thumb  ov021
 *   func_02163E34  0x02163E34  thumb  ov010
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   d_021D8A00     0x021D8A00  data  ov021  a4
 *   d_021D8A0C     0x021D8A0C  data  ov021  a4
 *   d_021D89F4     0x021D89F4  data  ov021  a4
 *   d_021D8A2C     0x021D8A2C  data  a4
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_0202E83C  0x0202E83C  thumb
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02164208  0x02164208  thumb  ov010
 *   func_021A48C8  0x021A48C8  thumb  ov021
 *   func_021A4B00  0x021A4B00  thumb  ov021
 *   func_021A3AA0  0x021A3AA0  thumb
 *   func_021A5610  0x021A5610  thumb  ov021
 *   func_021A53BC  0x021A53BC  thumb  ov021
 *   func_021A46F0  0x021A46F0  thumb  ov021
 *   func_021A4544  0x021A4544  thumb  ov021
 *   func_021A4598  0x021A4598  thumb  ov021
 *   func_021A4664  0x021A4664  thumb  ov021
 *   func_021A4698  0x021A4698  thumb  ov021
 */
#include "../../matched/include/Obj00656.h"
#include "../../matched/include/Obj09565.h"
#include "../../matched/include/Obj18048.h"

struct Actor;
struct VecFx32;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u32 mask; int val; s16 a; s16 b; } T1;

typedef struct { int (*fn)(u16); u16 val; s8 a; s8 b; u8 kind; } T2;

void *func_021A3960(unsigned char *p);
int func_0216D3CC(int a0);
u16 func_0216D5F8(void *p);
extern u32 func_021A3974(u8 *p);
extern int func_021A5318(u32 *p, u32 m);
extern int func_02163E34(void *, int, u32 *);
extern u16 func_021AB0F8(u32);
extern void func_020061E4(u32 a);
extern void *func_02188C80(void *p);
extern int func_0202E83C(void *a0);
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern void func_02164208(int dir, int *p, int amt);
extern int func_021A48C8(u8 *, u32);
extern int func_021A4B00(u8 *, u32);
extern int func_021A3AA0(u32 a);
extern int func_021A5610(u32 *p);
extern int func_021A53BC(u32 a);
extern int func_021A46F0(u8 *, u32);
extern int func_021A4544(u8 *p, u32 r, u8 *q);
extern int func_021A4598(u8 *a, void *b, u8 *c);
extern int func_021A4664(int a, int b, u8 *c);
extern int func_021A4698(u8 *, void *, u32);
int func_021A4254(u32 *p, u32 a);
int func_021A428C(u8 *o, int unused, int c, int flag, int kind);
void func_021A43D8(u8 *p, int k, int dir);
int func_021A4444(u8 *p, u32 s);
int func_021A448C(u32 *p, int a);
void func_021A44BC(u8 *p);
int func_021A44C8(u8 *p, u32 s);
extern T1 d_021D8A00[];
extern T1 d_021D8A0C[];
extern T2 d_021D89F4[];
extern T2 d_021D8A2C[];


int func_021A4254(u32 *p, u32 a)
{
    void *h = func_021A3960((unsigned char *)p[3]);

    if (func_0216D3CC((int)h) == 1)
        return 1;
    if (a != 9 && p[0] == 3 && a != func_0216D5F8(h))
        return 1;
    return 0;
}


/*
 * Picks a sound id from two 12-byte-record tables (attribute-mask table,
 * then predicate-callback table), 0x546 meaning none, and plays it with a
 * repeat counter at +0x1a.
 *
 * Addresses are Black-image addresses.
 * d_021D8A2C carries no ov021 token: with it the hint reads as contested.
 */
int func_021A428C(u8 *o, int unused, int c, int flag, int kind)
{
    int lim;
    int sel;
    u32 id;
    int mode;
    T1 *t;
    T2 *u;
    u32 bits;

    sel = 0x546;
    lim = 0;
    mode = 0;
    if (func_021A3974((u8 *)(*(u32 *)&((struct Obj00656 *)o)->fC)) == 1) {
        mode = 2;
    } else if (func_021A5318((u32 *)o, 0x20) != 0) {
        mode = 1;
    }
    if (mode == 0) {
        ((struct Obj00656 *)o)->f18 = 0x546;
        ((struct Obj00656 *)o)->f1A = 0;
    }
    if (func_02163E34(func_021A3960(((struct Obj00656 *)o)->fC), c, &id) == 1) {
        bits = func_021AB0F8(id);
        if (flag == 0) {
            t = d_021D8A00;
        } else {
            t = d_021D8A0C;
        }
        for (; t->mask != 0; t++) {
            if (t->mask & bits) {
                sel = t->val;
                if (mode == 1) {
                    lim = t->a;
                } else if (mode == 2) {
                    lim = t->b;
                }
                break;
            }
        }
        if (sel == 0x546) {
            u = d_021D89F4;
            if (flag != 0) {
                u = d_021D8A2C;
            }
            for (; u->fn != 0; u++) {
                if (u->fn((u16)id) == 1 && (u->kind == 4 || u->kind == kind)) {
                    sel = u->val;
                    if (mode == 1) {
                        lim = u->a;
                    } else if (mode == 2) {
                        lim = u->b;
                    }
                    break;
                }
            }
        }
        if (sel == 0x546) {
            if (flag == 1) {
                ((struct Obj00656 *)o)->f1A = 0;
            }
        } else if (mode != 0) {
            if (((struct Obj00656 *)o)->f18 != sel) {
                ((struct Obj00656 *)o)->f1A = 0;
            }
            if (((struct Obj00656 *)o)->f1A != 0 && ((struct Obj00656 *)o)->f1A < lim) {
                sel = 0x546;
            }
            if (((struct Obj00656 *)o)->f1A >= lim) {
                ((struct Obj00656 *)o)->f1A = 0;
            }
            ((struct Obj00656 *)o)->f18 = sel;
            ((struct Obj00656 *)o)->f1A = ((struct Obj00656 *)o)->f1A + 1;
        }
        if (sel != 0x546) {
            func_020061E4(sel);
            return 1;
        }
    }
    return 0;
}


void func_021A43D8(u8 *p, int k, int dir)
{
    u32 buf[3];
    void *a;
    u32 r;

    if (k != 2) {
        ((struct Obj00656 *)p)->f18 = 0x546;
        ((struct Obj00656 *)p)->f1A = 0;
        return;
    }
    a = func_021A3960(((struct Obj00656 *)p)->fC);
    r = func_0202E83C(func_02188C80((void *)(((struct Obj00656 *)p)->f10)));
    func_0216D88C(a, (struct VecFx32 *)buf);
    if (func_021A428C(p, k, (int)buf, 0, r) == 0) {
        func_02164208(dir, (int *)buf, 0x10000);
        func_021A428C(p, k, (int)buf, 1, r);
    }
}


int func_021A4444(u8 *p, u32 s)
{
    int r;

    r = 0;
    switch (func_021A3974((u8 *)(*(u32 *)&((struct Obj09565 *)p)->fC))) {
    case 0:
        r = func_021A44C8(p, s);
        break;
    case 1:
        r = func_021A48C8(p, s);
        break;
    case 2:
    case 3:
        r = func_021A4B00(p, s);
        break;
    }
    return r;
}


int func_021A448C(u32 *p, int a)
{
    int r = func_0216D5F8(func_021A3960((unsigned char *)p[3]));

    if (a == 9)
        return 0;
    if (a != r && p[0] != 1 && p[0] != 3)
        return 2;
    return 1;
}


/*
 * Tail-call thunk: the object's word at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void func_021A44BC(u8 *p)
{
    func_021A3AA0(((struct Obj18048 *)p)->fC);
}


int func_021A44C8(u8 *p, u32 s)
{
    void *a;
    int r;

    a = func_021A3960(((struct Obj09565 *)p)->fC);
    r = 0;
    if (func_021A5610((u32 *)p) == 1 || func_021A53BC((u32)p) == 1) {
        return func_021A46F0(p, s);
    }
    switch (((struct Obj09565 *)p)->f0) {
    case 0:
        r = func_021A4544(p, (u32)a, (u8 *)s);
        break;
    case 1:
        r = func_021A4598(p, a, (u8 *)s);
        break;
    case 2:
        r = func_021A4664((int)p, (int)a, (u8 *)s);
        break;
    case 3:
        r = func_021A4698(p, a, s);
        break;
    }
    return r;
}
