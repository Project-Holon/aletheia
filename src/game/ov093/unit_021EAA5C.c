/*
 * file:     unit_021EAA5C.c
 * unit:     yes
 * function: func_021EAA5C, func_021EAA6C, func_021EAAD8, func_021EAB18, func_021EABC4
 * address:  0x021EAA5C
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
 *   func_0689B5A4  0x0689B5A4  thumb
 *   func_0689B558  0x0689B558  thumb
 *   func_021E9100  0x021E9100  thumb  ov093
 *   func_021B8BEC  0x021B8BEC  thumb  ov093
 *   func_021B8E70  0x021B8E70  thumb  ov093
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_021F8414  0x021F8414  thumb  ov094
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   func_021ED53C  0x021ED53C  thumb  ov093
 *   func_021ED554  0x021ED554  thumb  ov093
 *   func_020457B0  0x020457B0  arm
 *   func_021EA55C  0x021EA55C  thumb  ov093
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj21569.h"
#include "../../matched/include/Obj04382.h"
#include "../../matched/include/Obj10116.h"

struct U16Vec;
struct H;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct {
    u8 *battle;                /* 0x00 */
    u32 pad[6];
    int (*cb1)(void *, u32);   /* 0x1c */
    int (*cb2)(void *, u32);   /* 0x20 */
    u32 arg;                   /* 0x24 */
    u32 obj;                   /* 0x28 */
} CbSlot;

extern void func_0689B558(int a);
extern u8 *func_021E9100(u8 *p, int n);
extern u8 func_021B8BEC(u8 *p, u32 k, u8 n);
extern u8 func_021B8E70(u8 *p, u32 k);
extern u32 func_021CD9E0(u8 *p);
extern void func_021F8414(int a, int b, int c);
extern int func_021F7EB4(void);
extern void func_021ED53C(u8 *p, int k);
extern int func_021ED554(u8 *p, int k);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_021EA55C(struct H *p, int a);
extern void func_0689B5A4(u32 a, void *b);
extern u32 func_020307B0(void *p);
void func_021EAA5C(u8 *o);
void func_021EAA6C(CbSlot *s, u32 k, u32 n);
int func_021EAAD8(CbSlot *s);
int func_021EAB18(int *st, u8 *b);
void func_021EABC4(u8 *a, u32 x, u32 y, u32 z);


void func_021EAA5C(u8 *o)
{
    func_0689B558(((struct Obj21569 *)o)->f180);
}


void func_021EAA6C(CbSlot *s, u32 k, u32 n)
{
    u8 *t;

    if (n != 1) {
        t = func_021E9100((u8 *)s, 8);
        t[0] = k;
        t[1] = n;
        t[5] = func_021B8BEC(s->battle, k, 0);
        t[6] = func_021B8BEC(s->battle, k, 1);
        t[7] = func_021B8BEC(s->battle, k, 2);
        t[2] = func_021B8E70(s->battle, t[5]);
        t[3] = func_021B8E70(s->battle, t[6]);
        t[4] = func_021B8E70(s->battle, t[7]);
        s->cb1 = 0;
        s->cb2 = (int (*)(void *, u32))func_021EAB18;
        s->arg = (u32)s;
        s->obj = 0;
    }
}


int func_021EAAD8(CbSlot *s)
{
    if (s->cb1 != 0) {
        if (s->cb1(&s->obj, s->arg) != 0) {
            s->cb1 = 0;
            s->obj = 0;
        }
        return 0;
    }
    if (s->cb2 != 0) {
        if (s->cb2(&s->obj, s->arg) != 0) {
            s->cb2 = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}


int func_021EAB18(int *st, u8 *b)
{
    u8 *t = func_021E9100(b, 8);
    int r;

    switch (*st) {
    case 0:
        func_021F8414(t[1], t[2] & 1, func_021CD9E0(((struct Obj04382 *)b)->f4) == 0);
        *st = *st + 1;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            func_021ED53C((u8 *)(((struct Obj04382 *)b)->f17C), t[5]);
            func_021ED53C((u8 *)(((struct Obj04382 *)b)->f17C), t[6]);
            func_021ED53C((u8 *)(((struct Obj04382 *)b)->f17C), t[7]);
            *st = *st + 1;
        }
        break;
    case 2:
        r = 1;
        if (func_021ED554((u8 *)(((struct Obj04382 *)b)->f17C), t[5]) == 0) {
            r = 0;
        }
        if (func_021ED554((u8 *)(((struct Obj04382 *)b)->f17C), t[6]) == 0) {
            r = 0;
        }
        if (func_021ED554((u8 *)(((struct Obj04382 *)b)->f17C), t[7]) == 0) {
            r = 0;
        }
        if (r != 0) {
            return 1;
        }
        break;
    }
    return 0;
}


void func_021EABC4(u8 *a, u32 x, u32 y, u32 z)
{
    u32 *t = (u32 *)func_021E9100(a, 12);

    t[0] = (u32)func_020457B0(0x20, (u16)((((struct Obj10116 *)a)->f184 & 0x7fff) | 0x8000));
    t[1] = (u32)func_020457B0(0x20, (u16)((((struct Obj10116 *)a)->f184 & 0x7fff) | 0x8000));
    t[2] = z;
    func_021EA55C((struct H *)x, (int)((void *)t[0]));
    func_021EA55C((struct H *)y, (int)((void *)t[1]));
    func_0689B5A4(((struct Obj10116 *)a)->f180, t);
    func_020307B0((void *)t[0]);
    func_020307B0((void *)t[1]);
}
