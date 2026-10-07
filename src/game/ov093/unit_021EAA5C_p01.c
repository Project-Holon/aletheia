/*
 * file:     unit_021EAA5C_p01.c
 * unit:     yes
 * function: func_021EAA5C, func_021EAA6C
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
 *   func_0689B558  0x0689B558  thumb
 *   func_021E9100  0x021E9100  thumb  ov093
 *   func_021B8BEC  0x021B8BEC  thumb  ov093
 *   func_021B8E70  0x021B8E70  thumb  ov093
 *   func_021EAB18  0x021EAB18  thumb  ov093
 */
#include "../../matched/include/Obj21569.h"

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
extern int func_021EAB18(int *st, u8 *b);
void func_021EAA5C(u8 *o);
void func_021EAA6C(CbSlot *s, u32 k, u32 n);


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
